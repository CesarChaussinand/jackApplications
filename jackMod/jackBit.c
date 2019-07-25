#include <stdio.h>
#include <unistd.h>
#include <jack/jack.h>
#include <SDL/SDL.h>

jack_port_t* input_port1;
jack_port_t* input_port2;

jack_port_t* output_port1;
jack_port_t* output_port2;

float fact = 5.0f;


/* Copie les entrées vers les sorties. */
int process(jack_nframes_t nframes, void*arg)
{
    /* Récupère les buffers liés au 4 ports. */
    float* in1 = jack_port_get_buffer(input_port1, nframes);
    float* in2 = jack_port_get_buffer(input_port2, nframes);

    float* out1 = jack_port_get_buffer(output_port1, nframes);
    float* out2 = jack_port_get_buffer(output_port2, nframes);

    /* Boucle de traitement sur les échantillons. */
    int i;

    for (i = 0; i < nframes; i = i + 1) {
        // Traitement sur les échantillons
		out1[i] = ((int)(in1[i]*fact))/fact;
		out2[i] = ((int)(in2[i]*fact))/fact;
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
    jack_client_t* client = jack_client_open("FarFromEarth", options, &status);

    /* Ouvrir les ports en entrée et en sortie */
    input_port1 = jack_port_register(client, "input1", JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0);
    input_port2 = jack_port_register(client, "input2", JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0);

    output_port1 = jack_port_register(client, "output1", JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0);
    output_port2 = jack_port_register(client, "output2", JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0);

    /* Enregister le traitement qui sera fait à chaque cycle */
    jack_set_process_callback(client, process, NULL);

    jack_activate(client);

    /* Fonctionne jusqu'à ce que Ctrl+C soit utilisé */
    printf("échap pour quitter l'application,\n");
	printf("Utliser la flèche du haut pour décoller,\net celle du bas pour attérir\n");


//SDL	SDL	SDL

if(SDL_Init(SDL_INIT_VIDEO)==-1)
	{
	fprintf(stderr,"erreur a l'initialisation de sdl : %s\n",SDL_GetError());
	exit(EXIT_FAILURE);
	}
SDL_Surface *ecran = NULL;

SDL_WM_SetCaption("FarFromEarth", NULL);
SDL_WM_SetIcon(SDL_LoadBMP("files/sdl_icone.bmp"),NULL);

ecran = SDL_SetVideoMode(60,400,32,SDL_HWSURFACE); 

SDL_Surface *terre = NULL;
terre = SDL_LoadBMP("files/sdl_icone.bmp");
SDL_Rect terrePos;
terrePos.x = ecran->w / 2 - terre->w / 2;
terrePos.y = ecran->h - terre->h;

SDL_Surface *fusee = NULL;
fusee = SDL_LoadBMP("files/fusee.bmp");
SDL_Rect fuseePos;
fuseePos.x = ecran->w / 2 - fusee->w / 2;
fuseePos.y = ecran->h - fusee->h - terre->h;

int continuer = 1;
SDL_Event event;

SDL_EnableKeyRepeat(30,30);

while (continuer)
{
	SDL_WaitEvent(&event);
	switch(event.type)
	{
		case SDL_QUIT:
		continuer = 0;
		break;

		case SDL_KEYDOWN:
		switch(event.key.keysym.sym)
		{
			case SDLK_UP:
			fuseePos.y = fuseePos.y - 2;
			break;

			case SDLK_DOWN:
			fuseePos.y = fuseePos.y + 2;
			if (fuseePos.y > ecran->h - fusee->h - terre->h){fuseePos.y = ecran->h - fusee->h - terre->h;}
			break;

			case SDLK_ESCAPE:
			continuer = 0;
			break;
		}
		break;
	}
	SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));

	SDL_BlitSurface(terre,NULL,ecran,&terrePos);

	SDL_BlitSurface(fusee,NULL,ecran,&fuseePos);

	SDL_Flip(ecran);
	
	fact = fuseePos.y / 20.0;
}

SDL_FreeSurface(fusee);
SDL_Quit();
    jack_deactivate(client);
    jack_client_close(client);
    return 0;
}
