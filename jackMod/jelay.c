#include <stdio.h>
#include <unistd.h>
#include <jack/jack.h>
#include <SDL/SDL.h>
#include "midi.c"

jack_port_t* input_port1;

jack_port_t* output_port1;

float delayLine[5000];
int curseur[3] = {0,0,0};
float fdbk[3] = {0.8,0.8,0.8};
int delay[3] = {1000,1200,900};
float mixValue = 0.5f;

/* Copie les entrées vers les sorties. */
int process(jack_nframes_t nframes, void*arg)
{
    /* Récupère les buffers liés au 4 ports. */
    float* in1 = jack_port_get_buffer(input_port1, nframes);

    float* out1 = jack_port_get_buffer(output_port1, nframes);

    /* Boucle de traitement sur les échantillons. */
    int i;
    int j;

    for (i = 0; i < nframes; i = i + 1) {
        // Traitement sur les échantillons
		out1[i] = in1[i]*mixValue + (delayLine[curseur[0]]+delayLine[curseur[1]]+delayLine[curseur[2]])*0.33*(1-mixValue);
		for (j=0;j<3;j++){
			delayLine[curseur[j]] = in1[i] + delayLine[curseur[j]]*fdbk[j];
			curseur[j] = (curseur[j] + 1)%delay[j];
		}
    }

    return 0;      
}

/*
Une application audio avec deux ports audio d'entrée et deux ports audio de sortie.
*/

int main()
{
	
if(SDL_Init(SDL_INIT_VIDEO)==-1)
	{
	fprintf(stderr,"erreur a l'initialisation de sdl : %s\n",SDL_GetError());
	exit(EXIT_FAILURE);
	}

SDL_Surface *ecran = NULL;
SDL_WM_SetCaption("BrokenResonator", NULL);
SDL_WM_SetIcon(SDL_LoadBMP("files/sdl_icone.bmp"),NULL);
ecran = SDL_SetVideoMode(254,180,32,SDL_HWSURFACE);
SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,50,50,60));

SDL_Surface *fond = NULL;
fond = SDL_LoadBMP("files/fond.bmp");
SDL_Rect fondPos;
fondPos.x = 0;
fondPos.y = 0;

SDL_Surface *delay0 = NULL;
delay0 = SDL_LoadBMP("files/slider0.bmp");
SDL_Rect delayPos0;
delayPos0.x = 20 - delay0->w / 2;
delayPos0.y = ecran->h/2 - delay0->h/2;

SDL_Surface *delay1 = NULL;
delay1 = SDL_LoadBMP("files/slider1.bmp");
SDL_Rect delayPos1;
delayPos1.x = 55 - delay1->w / 2;
delayPos1.y = ecran->h/2 - delay1->h/2;

SDL_Surface *delay2 = NULL;
delay2 = SDL_LoadBMP("files/slider2.bmp");
SDL_Rect delayPos2;
delayPos2.x = 90 - delay2->w / 2;
delayPos2.y = ecran->h/2 - delay2->h/2;

SDL_Surface *fdbk0 = NULL;
fdbk0 = SDL_LoadBMP("files/slider0.bmp");
SDL_Rect fdbkPos0;
fdbkPos0.x = 127 - fdbk0->w / 2;
fdbkPos0.y = ecran->h/2 - fdbk0->h/2;

SDL_Surface *fdbk1 = NULL;
fdbk1 = SDL_LoadBMP("files/slider1.bmp");
SDL_Rect fdbkPos1;
fdbkPos1.x = 162 - fdbk1->w / 2;
fdbkPos1.y = ecran->h/2 - fdbk1->h/2;

SDL_Surface *fdbk2 = NULL;
fdbk2 = SDL_LoadBMP("files/slider2.bmp");
SDL_Rect fdbkPos2;
fdbkPos2.x = 197 - fdbk2->w/2;
fdbkPos2.y = ecran->h/2 - fdbk2->h/2;

SDL_Surface *mix = NULL;
mix = SDL_LoadBMP("files/slider3.bmp");
SDL_Rect mixPos;
mixPos.x = 234 - mix->w/2;
mixPos.y = ecran->h/2 - mix->h/2;

int continuer = 1;
SDL_Event event;

int sliderActif = 0;
float maxY = 159.0f;
int minY = 35;



    jack_options_t options = JackNullOption;
    jack_status_t status;

    /* Ouvrir le client JACK */
    jack_client_t* client = jack_client_open("BrokenResonator", options, &status);

    /* Ouvrir les ports en entrée et en sortie */
    input_port1 = jack_port_register(client, "input1", JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0);

    output_port1 = jack_port_register(client, "output1", JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0);

    /* Enregister le traitement qui sera fait à chaque cycle */
    jack_set_process_callback(client, process, NULL);

    jack_activate(client);

    /* Fonctionne jusqu'à ce que Ctrl+C soit utilisé */
    printf("Utiliser 'echap' pour quitter l'application...\n");


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
			case SDLK_ESCAPE:
			continuer = 0;
			break;
		}
		break;

		case SDL_MOUSEBUTTONDOWN:
		if(event.button.x<38){sliderActif = 1;}
		else if(event.button.x<73){sliderActif = 2;}
		else if(event.button.x<109){sliderActif = 3;}
		else if(event.button.x<145){sliderActif = 4;}
		else if(event.button.x<180){sliderActif = 5;}
		else if(event.button.x<215){sliderActif = 6;}
		else {sliderActif = 7;}
		break;

		case SDL_MOUSEBUTTONUP:
		sliderActif = 0;
		break;

		case SDL_MOUSEMOTION:
		switch(sliderActif)
		{
			case 1:
			delayPos0.y = event.motion.y - delay0->h/2;
			break;

			case 2:
			delayPos1.y = event.motion.y - delay1->h/2;
			break;

			case 3:
			delayPos2.y = event.motion.y - delay2->h/2;
			break;

			case 4:
			fdbkPos0.y = event.motion.y - fdbk0->h/2;
			break;

			case 5:
			fdbkPos1.y = event.motion.y - fdbk1->h/2;
			break;

			case 6:
			fdbkPos2.y = event.motion.y - fdbk2->h/2;
			break;

			case 7:
			mixPos.y = event.motion.y - mix->h/2;
			break;
		}
		break;
	}
	if(delayPos0.y > maxY){delayPos0.y = maxY;}
	if(delayPos0.y < minY){delayPos0.y = minY;}
	if(delayPos1.y > maxY){delayPos1.y = maxY;}
	if(delayPos1.y < minY){delayPos1.y = minY;}
	if(delayPos2.y > maxY){delayPos2.y = maxY;}
	if(delayPos2.y < minY){delayPos2.y = minY;}
	if(fdbkPos0.y > maxY){fdbkPos0.y = maxY;}
	if(fdbkPos0.y < minY){fdbkPos0.y = minY;}
	if(fdbkPos1.y > maxY){fdbkPos1.y = maxY;}
	if(fdbkPos1.y < minY){fdbkPos1.y = minY;}
	if(fdbkPos2.y > maxY){fdbkPos2.y = maxY;}
	if(fdbkPos2.y < minY){fdbkPos2.y = minY;}
	if(mixPos.y > maxY){mixPos.y = maxY;}
	if(mixPos.y < minY){mixPos.y = minY;}

	SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
	SDL_BlitSurface(fond,NULL,ecran,&fondPos);
	SDL_BlitSurface(delay0,NULL,ecran,&delayPos0);
	SDL_BlitSurface(delay1,NULL,ecran,&delayPos1);
	SDL_BlitSurface(delay2,NULL,ecran,&delayPos2);
	SDL_BlitSurface(fdbk0,NULL,ecran,&fdbkPos0);
	SDL_BlitSurface(fdbk1,NULL,ecran,&fdbkPos1);
	SDL_BlitSurface(fdbk2,NULL,ecran,&fdbkPos2);
	SDL_BlitSurface(mix,NULL,ecran,&mixPos);
	
	int midi[3]={32,32,32};
	midi[0] = 56 - (24*(delayPos0.y-minY) / (maxY-minY));
	midi[1] = 56 - (24*(delayPos1.y-minY) / (maxY-minY));
	midi[2] = 56 - (24*(delayPos2.y-minY) / (maxY-minY));

	fdbk[0] = 1 - (0.2*(fdbkPos0.y-minY) / (maxY-minY));
	fdbk[1] = 1 - (0.2*(fdbkPos1.y-minY) / (maxY-minY));
	fdbk[2] = 1 - (0.2*(fdbkPos2.y-minY) / (maxY-minY));

	mixValue = (mixPos.y-minY) / (maxY-minY);

	delay[0] = (44100/midi2freq(midi[0]));
	delay[1] = (44100/midi2freq(midi[1]));
	delay[2] = (44100/midi2freq(midi[2]));
	SDL_Flip(ecran);
}

SDL_FreeSurface(fond);
SDL_FreeSurface(delay0);
SDL_FreeSurface(delay1);
SDL_FreeSurface(delay2);
SDL_FreeSurface(mix);
SDL_FreeSurface(fdbk0);
SDL_FreeSurface(fdbk1);
SDL_FreeSurface(fdbk2);
SDL_Quit();

    jack_deactivate(client);
    jack_client_close(client);
    return 0;
}
