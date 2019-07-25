#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <jack/jack.h>

jack_port_t* output_port1;

int count;

float randomOut(float max,int root){
	count = count + root;
	srand(count);
	return (float)rand()/(float)(RAND_MAX/2.0);
}

/* Copie les entrées vers les sorties. */
int process(jack_nframes_t nframes, void*arg)
{
    /* Récupère les buffers liés au 4 ports. */
    float* out1 = jack_port_get_buffer(output_port1, nframes);

    /* Boucle de traitement sur les échantillons. */
    int i;

    for (i = 0; i < nframes; i = i + 1) {
        // Traitement sur les échantillons
	out1[i] = randomOut(1,i)-1;
    }
    return 0;
}

/*
Une application audio avec deux ports audio d'entrée et deux ports audio de sortie.
*/

int main()
{

    jack_options_t options = JackNullOption;
    jack_status_t status;

    /* Ouvrir le client JACK */
    jack_client_t* client = jack_client_open("noise", options, &status);

    /* Ouvrir les ports en entrée et en sortie */
    output_port1 = jack_port_register(client, "output1", JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0);

    /* Enregister le traitement qui sera fait à chaque cycle */
    jack_set_process_callback(client, process, NULL);

    jack_activate(client);

    /* Fonctionne jusqu'à ce que Ctrl+C soit utilisé */

char c;

while((c=getchar())!='q'){
	sleep(1);
}
    jack_deactivate(client);
    jack_client_close(client);
    return 0;
}
