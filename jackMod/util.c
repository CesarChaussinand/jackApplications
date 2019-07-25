#include <stdio.h>
#include <unistd.h>
#include <jack/jack.h>
#include <SDL/SDL.h>
#include "midi.c"
#include <math.h>

jack_port_t* input_port1;
jack_port_t* input_port2;
jack_port_t* input_port3;
jack_port_t* input_port4;
jack_port_t* input_port5;
jack_port_t* input_port6;
jack_port_t* output_port1;
jack_port_t* output_port2;
jack_port_t* output_port3;
jack_port_t* output_port4;

jack_port_t* output_port5;
jack_port_t* input_port7;
jack_port_t* input_port8;

int count;

float sampled;

float randomOut(float max,int root){
	count = count + root;
	srand(count);
	return (float)rand()/(float)(RAND_MAX/2.0);
}
float gain0 = 1.0f;
float gain1 = 1.0f;
float gain2 = 1.0f;
int plugged0 = 0;
int plugged1 = 0;
int plugged2 = 0;
float mod;

/* Copie les entrées vers les sorties. */
int process(jack_nframes_t nframes, void*arg)
{
    /* Récupère les buffers liés au 4 ports. */
    float* in1 = jack_port_get_buffer(input_port1, nframes);
    float* inMod1 = jack_port_get_buffer(input_port2, nframes);
    float* in2 = jack_port_get_buffer(input_port3, nframes);
    float* inMod2 = jack_port_get_buffer(input_port4, nframes);
    float* in3 = jack_port_get_buffer(input_port5, nframes);
    float* inMod3 = jack_port_get_buffer(input_port6, nframes);

    float* out1 = jack_port_get_buffer(output_port1, nframes);
    float* out2 = jack_port_get_buffer(output_port2, nframes);
    float* out3 = jack_port_get_buffer(output_port3, nframes);
	float* out4 = jack_port_get_buffer(output_port4, nframes);

	float* inSnH1 = jack_port_get_buffer(input_port7, nframes);
    float* inSnH2 = jack_port_get_buffer(input_port8, nframes);
    float* outSnH = jack_port_get_buffer(output_port5, nframes);

    /* Boucle de traitement sur les échantillons. */
	int i;	

    for (i = 0; i < nframes; i = i + 1) {
        // Traitement sur les échantillons

	if(plugged0==0){mod = 1;}
	else{mod = inMod1[i];}
	out1[i] = in1[i]*mod*gain0;
	if(plugged1==0){mod = 1;}
	else{mod = inMod2[i];}
	out2[i] = in2[i]*mod*gain1;
	if(plugged2==0){mod = 1;}
	else{mod = inMod3[i];}
	out3[i] = in3[i]*mod*gain2;

	out4[i] = randomOut(1,i)-1;
	
	if(inSnH2[i]>0){
	sampled = inSnH1[i];}
	outSnH[i] = sampled;
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
SDL_WM_SetCaption("VCA", NULL);
ecran = SDL_SetVideoMode(110,200,32,SDL_HWSURFACE);
SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,50,50,60));

SDL_Surface *fond = NULL;
fond = SDL_LoadBMP("files/fondVca.bmp");
SDL_Rect fondPos;
fondPos.x = 0;
fondPos.y = 0;

SDL_Surface *slider0 = NULL;
slider0 = SDL_LoadBMP("files/slider3.bmp");
SDL_Rect sliderPos0;
sliderPos0.x = 20 - slider0->w / 2;
sliderPos0.y = ecran->h/2 - slider0->h/2;

SDL_Surface *slider1 = NULL;
slider1 = SDL_LoadBMP("files/slider3.bmp");
SDL_Rect sliderPos1;
sliderPos1.x = 55 - slider1->w / 2;
sliderPos1.y = ecran->h/2 - slider1->h/2;

SDL_Surface *slider2 = NULL;
slider2 = SDL_LoadBMP("files/slider3.bmp");
SDL_Rect sliderPos2;
sliderPos2.x = 90 - slider2->w / 2;
sliderPos2.y = ecran->h/2 - slider2->h/2;

SDL_Surface *plugged = NULL;
plugged = SDL_LoadBMP("files/plugged.bmp");
SDL_Rect plugPos0;
plugPos0.x = 20 - plugged->w / 2;
plugPos0.y = 179;
SDL_Rect plugPos1;
plugPos1.x = 55 - plugged->w / 2;
plugPos1.y = 179;
SDL_Rect plugPos2;
plugPos2.x = 90 - plugged->w / 2;
plugPos2.y = 179;

int continuer = 1;
SDL_Event event;

int sliderActif = 0;
float maxY = 159.0f;
int minY = 35;


    jack_options_t options = JackNullOption;
    jack_status_t status;

    /* Ouvrir le client JACK */
    jack_client_t* client = jack_client_open("Utils", options, &status);

    /* Ouvrir les ports en entrée et en sortie */
    input_port1 = jack_port_register(client, "vcaIn1", JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0);
    input_port2 = jack_port_register(client, "mod1", JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0);
    input_port3 = jack_port_register(client, "vcaIn2", JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0);
    input_port4 = jack_port_register(client, "mod2", JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0);
    input_port5 = jack_port_register(client, "vcaIn3", JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0);
    input_port6 = jack_port_register(client, "mod3", JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0);

    output_port1 = jack_port_register(client, "vcaOut1", JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0);
    output_port2 = jack_port_register(client, "vcaOut2", JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0);
    output_port3 = jack_port_register(client, "vcaOut3", JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0);

	output_port4 = jack_port_register(client, "noise", JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0);

	input_port7 = jack_port_register(client, "s&hIn", JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0);
    input_port8 = jack_port_register(client, "s&hTrig", JACK_DEFAULT_AUDIO_TYPE, JackPortIsInput, 0);
    output_port5 = jack_port_register(client, "s&hOut", JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0);

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
		if(event.button.y < maxY+slider0->h){
			if(event.button.x<38){sliderActif = 1;}
			else if(event.button.x<73){sliderActif = 2;}
			else{sliderActif = 3;}
		}else{
			if(event.button.x<38){plugged0 = (plugged0+1)%2;}
			else if(event.button.x<73){plugged1 = (plugged1+1)%2;}
			else{plugged2 = (plugged2+1)%2;}
		}
		break;

		case SDL_MOUSEBUTTONUP:
		sliderActif = 0;
		break;

		case SDL_MOUSEMOTION:
		switch(sliderActif)
		{
			case 1:
			sliderPos0.y = event.motion.y - slider0->h/2;
			break;

			case 2:
			sliderPos1.y = event.motion.y - slider1->h/2;
			break;

			case 3:
			sliderPos2.y = event.motion.y - slider2->h/2;
			break;
		}
		break;
	}
	if(sliderPos0.y > maxY){sliderPos0.y = maxY;}
	if(sliderPos0.y < minY){sliderPos0.y = minY;}
	if(sliderPos1.y > maxY){sliderPos1.y = maxY;}
	if(sliderPos1.y < minY){sliderPos1.y = minY;}
	if(sliderPos2.y > maxY){sliderPos2.y = maxY;}
	if(sliderPos2.y < minY){sliderPos2.y = minY;}

	SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
	SDL_BlitSurface(fond,NULL,ecran,&fondPos);
	SDL_BlitSurface(slider0,NULL,ecran,&sliderPos0);
	SDL_BlitSurface(slider1,NULL,ecran,&sliderPos1);
	SDL_BlitSurface(slider2,NULL,ecran,&sliderPos2);
	if(plugged0==1){SDL_BlitSurface(plugged,NULL,ecran,&plugPos0);}
	if(plugged1==1){SDL_BlitSurface(plugged,NULL,ecran,&plugPos1);}
	if(plugged2==1){SDL_BlitSurface(plugged,NULL,ecran,&plugPos2);}

	gain0 = 10 - pow(10,(sliderPos0.y-minY) / (maxY-minY));
	gain1 = 10 - pow(10,(sliderPos1.y-minY) / (maxY-minY));
	gain2 = 10 - pow(10,(sliderPos2.y-minY) / (maxY-minY));

	SDL_Flip(ecran);
}

SDL_FreeSurface(fond);
SDL_FreeSurface(slider0);
SDL_FreeSurface(slider1);
SDL_FreeSurface(slider2);
SDL_FreeSurface(plugged);
SDL_Quit();

    jack_deactivate(client);
    jack_client_close(client);
    return 0;
}
