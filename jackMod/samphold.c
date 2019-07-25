#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <jack/jack.h>




/* Copie les entrées vers les sorties. */
int process(jack_nframes_t nframes, void*arg)
{
    /* Récupère les buffers liés au 4 ports. */

    
    /* Boucle de traitement sur les échantillons. */
    int i;
    for (i = 0; i < nframes; i = i + 1) {
        // Traitement sur les échantillons
	if(in2[i]>0){
	sampled = in1[i];}
	out1[i] = sampled;
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
    jack_client_t* client = jack_client_open("sample & hold", options, &status);

    /* Ouvrir les ports en entrée et en sortie */
    
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
