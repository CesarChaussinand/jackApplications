#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <jack/jack.h>
#include <SDL/SDL.h>
#include <jack/midiport.h>

jack_client_t *client;
jack_port_t* output_port;

int qFlag = 0;
int zFlag = 0;
int wFlag = 0;
int sFlag = 0;
int eFlag = 0;
int xFlag = 0;
int dFlag = 0;
int rFlag = 0;
int cFlag = 0;
int fFlag = 0;
int tFlag = 0;
int vFlag = 0;
int gFlag = 0;
int yFlag = 0;
int bFlag = 0;
int hFlag = 0;
int uFlag = 0;
int nFlag = 0;
int jFlag = 0;
int iFlag = 0;
int virgFlag = 0;
int kFlag = 0;
int oFlag = 0;
int pointvirgFlag = 0;
int lFlag = 0;
int pFlag = 0;
int deuxpointsFlag = 0;
int mFlag = 0;
int upFlag = 0;
int downFlag = 0;
int supprFlag = 0;
int shiftFlag = 0;
int ctrlFlag = 0;
int tabFlag = 0;
int programme = 0;

int process(jack_nframes_t nframes, void*arg)
{
    int i;

	void *port_buf = jack_port_get_buffer(output_port, nframes);
	unsigned char *buffer;
	jack_midi_clear_buffer(port_buf);

	
    for (i = 0; i < nframes; i = i + 1) {

	if(qFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 64;
		buffer[1] = 50;
		buffer[0] = 0x90;
		qFlag = 0;}
	else if(qFlag == -1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 0;
		buffer[1] = 50;
		buffer[0] = 0x80;
		qFlag = 0;}
	if(zFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 64;
		buffer[1] = 51;
		buffer[0] = 0x90;
		zFlag = 0;}
	else if(zFlag == -1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 0;
		buffer[1] = 51;
		buffer[0] = 0x80;
		zFlag = 0;}
	if(wFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 64;
		buffer[1] = 52;
		buffer[0] = 0x90;
		wFlag = 0;}
	else if(wFlag == -1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 0;
		buffer[1] = 52;
		buffer[0] = 0x80;
		wFlag = 0;}
	if(sFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 64;
		buffer[1] = 53;
		buffer[0] = 0x90;
		sFlag = 0;}
	else if(sFlag == -1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 0;
		buffer[1] = 53;
		buffer[0] = 0x80;
		sFlag = 0;}
	if(eFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 64;
		buffer[1] = 54;
		buffer[0] = 0x90;
		eFlag = 0;}
	else if(eFlag == -1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 0;
		buffer[1] = 54;
		buffer[0] = 0x80;
		eFlag = 0;}
	if(xFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 64;
		buffer[1] = 55;
		buffer[0] = 0x90;
		xFlag = 0;}
	else if(xFlag == -1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 0;
		buffer[1] = 55;
		buffer[0] = 0x80;
		xFlag = 0;}
	if(dFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 64;
		buffer[1] = 56;
		buffer[0] = 0x90;
		dFlag = 0;}
	else if(dFlag == -1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 0;
		buffer[1] = 56;
		buffer[0] = 0x80;
		dFlag = 0;}
	if(rFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 64;
		buffer[1] = 57;
		buffer[0] = 0x90;
		rFlag = 0;}
	else if(rFlag == -1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 0;
		buffer[1] = 57;
		buffer[0] = 0x80;
		rFlag = 0;}
	if(cFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 64;
		buffer[1] = 58;
		buffer[0] = 0x90;
		cFlag = 0;}
	else if(cFlag == -1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 0;
		buffer[1] = 58;
		buffer[0] = 0x80;
		cFlag = 0;}
	if(fFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 64;
		buffer[1] = 59;
		buffer[0] = 0x90;
		fFlag = 0;}
	else if(fFlag == -1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 0;
		buffer[1] = 59;
		buffer[0] = 0x80;
		fFlag = 0;}
	if(tFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 64;
		buffer[1] = 60;
		buffer[0] = 0x90;
		tFlag = 0;}
	else if(tFlag == -1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 0;
		buffer[1] = 60;
		buffer[0] = 0x80;
		tFlag = 0;}
	if(vFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 64;
		buffer[1] = 61;
		buffer[0] = 0x90;
		vFlag = 0;}
	else if(vFlag == -1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 0;
		buffer[1] = 61;
		buffer[0] = 0x80;
		vFlag = 0;}
	if(gFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 64;
		buffer[1] = 62;
		buffer[0] = 0x90;
		gFlag = 0;}
	else if(gFlag == -1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 0;
		buffer[1] = 62;
		buffer[0] = 0x80;
		gFlag = 0;}
	if(yFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 64;
		buffer[1] = 63;
		buffer[0] = 0x90;
		yFlag = 0;}
	else if(yFlag == -1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 0;
		buffer[1] = 63;
		buffer[0] = 0x80;
		yFlag = 0;}
	if(bFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 64;
		buffer[1] = 64;
		buffer[0] = 0x90;
		bFlag = 0;}
	else if(bFlag == -1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 0;
		buffer[1] = 64;
		buffer[0] = 0x80;
		bFlag = 0;}
	if(hFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 64;
		buffer[1] = 65;
		buffer[0] = 0x90;
		hFlag = 0;}
	else if(hFlag == -1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 0;
		buffer[1] = 65;
		buffer[0] = 0x80;
		hFlag = 0;}
	if(uFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 64;
		buffer[1] = 66;
		buffer[0] = 0x90;
		uFlag = 0;}
	else if(uFlag == -1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 0;
		buffer[1] = 66;
		buffer[0] = 0x80;
		uFlag = 0;}
	if(nFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 64;
		buffer[1] = 67;
		buffer[0] = 0x90;
		nFlag = 0;}
	else if(nFlag == -1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 0;
		buffer[1] = 67;
		buffer[0] = 0x80;
		nFlag = 0;}
	if(jFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 64;
		buffer[1] = 68;
		buffer[0] = 0x90;
		jFlag = 0;}
	else if(jFlag == -1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 0;
		buffer[1] = 68;
		buffer[0] = 0x80;
		jFlag = 0;}
	if(iFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 64;
		buffer[1] = 69;
		buffer[0] = 0x90;
		iFlag = 0;}
	else if(iFlag == -1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 0;
		buffer[1] = 69;
		buffer[0] = 0x80;
		iFlag = 0;}
	if(virgFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 64;
		buffer[1] = 70;
		buffer[0] = 0x90;
		virgFlag = 0;}
	else if(virgFlag == -1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 0;
		buffer[1] = 70;
		buffer[0] = 0x80;
		virgFlag = 0;}
	if(kFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 64;
		buffer[1] = 71;
		buffer[0] = 0x90;
		kFlag = 0;}
	else if(kFlag == -1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 0;
		buffer[1] = 71;
		buffer[0] = 0x80;
		kFlag = 0;}
	if(oFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 64;
		buffer[1] = 72;
		buffer[0] = 0x90;
		oFlag = 0;}
	else if(oFlag == -1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 0;
		buffer[1] = 72;
		buffer[0] = 0x80;
		oFlag = 0;}
	if(pointvirgFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 64;
		buffer[1] = 73;
		buffer[0] = 0x90;
		pointvirgFlag = 0;}
	else if(pointvirgFlag == -1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 0;
		buffer[1] = 73;
		buffer[0] = 0x80;
		pointvirgFlag = 0;}
	if(lFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 64;
		buffer[1] = 74;
		buffer[0] = 0x90;
		lFlag = 0;}
	else if(lFlag == -1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 0;
		buffer[1] = 74;
		buffer[0] = 0x80;
		lFlag = 0;}
	if(pFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 64;
		buffer[1] = 75;
		buffer[0] = 0x90;
		pFlag = 0;}
	else if(pFlag == -1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 0;
		buffer[1] = 75;
		buffer[0] = 0x80;
		pFlag = 0;}
	if(deuxpointsFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 64;
		buffer[1] = 76;
		buffer[0] = 0x90;
		deuxpointsFlag = 0;}
	else if(deuxpointsFlag == -1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 0;
		buffer[1] = 76;
		buffer[0] = 0x80;
		deuxpointsFlag = 0;}
	if(mFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 64;
		buffer[1] = 77;
		buffer[0] = 0x90;
		mFlag = 0;}
	else if(mFlag == -1){
		buffer = jack_midi_event_reserve(port_buf,i,3);
		buffer[2] = 0;
		buffer[1] = 77;
		buffer[0] = 0x80;
		mFlag = 0;}
	if(upFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,2);
		programme = (programme+1)%128;
		buffer[1] = programme;
		buffer[0] = 0xC0;
		upFlag = -1;}
	if(downFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,2);
		programme = (programme-1)%128;
		buffer[1] = programme;
		buffer[0] = 0xC0;
		downFlag = -1;}
	if(supprFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,1);
		buffer[0] = 0xFF;
		supprFlag = -1;}
	if(shiftFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,1);
		buffer[0] = 0xFA;
		shiftFlag = -1;}
	if(ctrlFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,1);
		buffer[0] = 0xFB;
		ctrlFlag = -1;}
	if(tabFlag == 1){
		buffer = jack_midi_event_reserve(port_buf,i,1);
		buffer[0] = 0xFC;
		tabFlag = -1;}
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
SDL_WM_SetCaption("virtual midi keyboard", NULL);
SDL_WM_SetIcon(SDL_LoadBMP("clavier/icone.bmp"),NULL);
ecran = SDL_SetVideoMode(380,102,32,SDL_HWSURFACE);
SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));

SDL_Surface *fond = NULL;
fond = SDL_LoadBMP("clavier/fond.bmp");
SDL_Rect fondPos;
fondPos.x = 0;
fondPos.y = 0;

SDL_Surface *q = NULL;
q = SDL_LoadBMP("clavier/q.bmp");
SDL_Rect qPos;
qPos.x = 2;
qPos.y = 36;

SDL_Surface *z = NULL;
z = SDL_LoadBMP("clavier/z.bmp");
SDL_Rect zPos;
zPos.x = 11;
zPos.y = 3;

SDL_Surface *w = NULL;
w = SDL_LoadBMP("clavier/w.bmp");
SDL_Rect wPos;
wPos.x = 20;
wPos.y = 69;

SDL_Surface *s = NULL;
s = SDL_LoadBMP("clavier/s.bmp");
SDL_Rect sPos;
sPos.x = 29;
sPos.y = 36;

SDL_Surface *e = NULL;
e = SDL_LoadBMP("clavier/e.bmp");
SDL_Rect ePos;
ePos.x = 38;
ePos.y = 3;

SDL_Surface *x = NULL;
x = SDL_LoadBMP("clavier/x.bmp");
SDL_Rect xPos;
xPos.x = 47;
xPos.y = 69;

SDL_Surface *d = NULL;
d = SDL_LoadBMP("clavier/d.bmp");
SDL_Rect dPos;
dPos.x = 56;
dPos.y = 36;

SDL_Surface *r = NULL;
r = SDL_LoadBMP("clavier/r.bmp");
SDL_Rect rPos;
rPos.x = 65;
rPos.y = 3;

SDL_Surface *c = NULL;
c = SDL_LoadBMP("clavier/c.bmp");
SDL_Rect cPos;
cPos.x = 74;
cPos.y = 69;

SDL_Surface *f = NULL;
f = SDL_LoadBMP("clavier/f.bmp");
SDL_Rect fPos;
fPos.x = 83;
fPos.y = 36;

SDL_Surface *t = NULL;
t = SDL_LoadBMP("clavier/t.bmp");
SDL_Rect tPos;
tPos.x = 92;
tPos.y = 3;

SDL_Surface *v = NULL;
v = SDL_LoadBMP("clavier/v.bmp");
SDL_Rect vPos;
vPos.x = 101;
vPos.y = 69;

SDL_Surface *g = NULL;
g = SDL_LoadBMP("clavier/g.bmp");
SDL_Rect gPos;
gPos.x = 110;
gPos.y = 36;

SDL_Surface *y = NULL;
y = SDL_LoadBMP("clavier/y.bmp");
SDL_Rect yPos;
yPos.x = 119;
yPos.y = 3;

SDL_Surface *b = NULL;
b = SDL_LoadBMP("clavier/b.bmp");
SDL_Rect bPos;
bPos.x = 128;
bPos.y = 69;

SDL_Surface *h = NULL;
h = SDL_LoadBMP("clavier/h.bmp");
SDL_Rect hPos;
hPos.x = 137;
hPos.y = 36;

SDL_Surface *u = NULL;
u = SDL_LoadBMP("clavier/u.bmp");
SDL_Rect uPos;
uPos.x = 146;
uPos.y = 3;

SDL_Surface *n = NULL;
n = SDL_LoadBMP("clavier/n.bmp");
SDL_Rect nPos;
nPos.x = 155;
nPos.y = 69;

SDL_Surface *j = NULL;
j = SDL_LoadBMP("clavier/j.bmp");
SDL_Rect jPos;
jPos.x = 164;
jPos.y = 36;

SDL_Surface *i = NULL;
i = SDL_LoadBMP("clavier/i.bmp");
SDL_Rect iPos;
iPos.x = 173;
iPos.y = 3;

SDL_Surface *virg = NULL;
virg = SDL_LoadBMP("clavier/virg.bmp");
SDL_Rect virgPos;
virgPos.x = 182;
virgPos.y = 69;

SDL_Surface *k = NULL;
k = SDL_LoadBMP("clavier/k.bmp");
SDL_Rect kPos;
kPos.x = 191;
kPos.y = 36;

SDL_Surface *o = NULL;
o = SDL_LoadBMP("clavier/o.bmp");
SDL_Rect oPos;
oPos.x = 200;
oPos.y = 3;

SDL_Surface *pointvirg = NULL;
pointvirg = SDL_LoadBMP("clavier/pointvirg.bmp");
SDL_Rect pointvirgPos;
pointvirgPos.x = 209;
pointvirgPos.y = 69;

SDL_Surface *l = NULL;
l = SDL_LoadBMP("clavier/l.bmp");
SDL_Rect lPos;
lPos.x = 218;
lPos.y = 36;

SDL_Surface *p = NULL;
p = SDL_LoadBMP("clavier/p.bmp");
SDL_Rect pPos;
pPos.x = 227;
pPos.y = 3;

SDL_Surface *deuxpoints = NULL;
deuxpoints = SDL_LoadBMP("clavier/deuxpoints.bmp");
SDL_Rect deuxpointsPos;
deuxpointsPos.x = 236;
deuxpointsPos.y = 69;

SDL_Surface *m = NULL;
m = SDL_LoadBMP("clavier/m.bmp");
SDL_Rect mPos;
mPos.x = 245;
mPos.y = 36;

SDL_Surface *shift = NULL;
shift = SDL_LoadBMP("clavier/shift.bmp");
SDL_Rect shiftPos;
shiftPos.x = 283;
shiftPos.y = 51;

SDL_Surface *ctrl = NULL;
ctrl = SDL_LoadBMP("clavier/ctrl.bmp");
SDL_Rect ctrlPos;
ctrlPos.x = 348;
ctrlPos.y = 51;

SDL_Surface *tab = NULL;
tab = SDL_LoadBMP("clavier/tab.bmp");
SDL_Rect tabPos;
tabPos.x = 316;
tabPos.y = 51;

SDL_Surface *up = NULL;
up = SDL_LoadBMP("clavier/up.bmp");
SDL_Rect upPos;
upPos.x = 348;
upPos.y = 76;

SDL_Surface *down = NULL;
down = SDL_LoadBMP("clavier/down.bmp");
SDL_Rect downPos;
downPos.x = 348;
downPos.y = 76;

SDL_Surface *suppr = NULL;
suppr = SDL_LoadBMP("clavier/suppr.bmp");
SDL_Rect supprPos;
supprPos.x = 348;
supprPos.y = 26;

int continuer = 1;
SDL_Event event;

    jack_options_t options = JackNullOption;
    jack_status_t status;

    /* Ouvrir le client JACK */
    jack_client_t* client = jack_client_open("virtual midi keyboard", options, &status);

    /* Ouvrir les ports en entrée et en sortie */
    output_port = jack_port_register(client, "output", JACK_DEFAULT_MIDI_TYPE, JackPortIsOutput, 0);

    /* Enregister le traitement qui sera fait à chaque cycle */
    jack_set_process_callback(client, process, NULL);

    jack_activate(client);

    /* Fonctionne jusqu'à ce que Ctrl+C soit utilisé */
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

			case SDLK_DELETE:
			supprFlag = 1;
			break;

			case SDLK_q:
			qFlag = 1;
			//send midi note on
			break;

			case SDLK_z:
			zFlag = 1;
			//send midi note on
			break;

			case SDLK_w:
			wFlag = 1;
			//send midi note on
			break;

			case SDLK_s:
			sFlag = 1;
			//send midi note on
			break;

			case SDLK_e:
			eFlag = 1;
			//send midi note on
			break;

			case SDLK_x:
			xFlag = 1;
			//send midi note on
			break;

			case SDLK_d:
			dFlag = 1;
			//send midi note on
			break;

			case SDLK_r:
			rFlag = 1;
			//send midi note on
			break;

			case SDLK_c:
			cFlag = 1;
			//send midi note on
			break;

			case SDLK_f:
			fFlag = 1;
			//send midi note on
			break;

			case SDLK_t:
			tFlag = 1;
			//send midi note on
			break;

			case SDLK_v:
			vFlag = 1;
			//send midi note on
			break;

			case SDLK_g:
			gFlag = 1;
			//send midi note on
			break;

			case SDLK_y:
			yFlag = 1;
			//send midi note on
			break;

			case SDLK_b:
			bFlag = 1;
			//send midi note on
			break;

			case SDLK_h:
			hFlag = 1;
			//send midi note on
			break;

			case SDLK_u:
			uFlag = 1;
			//send midi note on
			break;

			case SDLK_n:
			nFlag = 1;
			//send midi note on
			break;

			case SDLK_j:
			jFlag = 1;
			//send midi note on
			break;

			case SDLK_i:
			iFlag = 1;
			//send midi note on
			break;

			case SDLK_COMMA:
			virgFlag = 1;
			//send midi note on
			break;

			case SDLK_k:
			kFlag = 1;
			//send midi note on
			break;

			case SDLK_o:
			oFlag = 1;
			//send midi note on
			break;

			case SDLK_SEMICOLON:
			pointvirgFlag = 1;
			//send midi note on
			break;

			case SDLK_l:
			lFlag = 1;
			//send midi note on
			break;

			case SDLK_p:
			pFlag = 1;
			//send midi note on
			break;

			case SDLK_COLON:
			deuxpointsFlag = 1;
			//send midi note on
			break;

			case SDLK_m:
			mFlag = 1;
			//send midi note on
			break;

			case SDLK_UP:
			upFlag = 1;
			break;

			case SDLK_DOWN:
			downFlag = 1;
			break;

			case SDLK_LSHIFT:
			shiftFlag = 1;
			break;

			case SDLK_LCTRL:
			ctrlFlag = 1;
			break;

			case SDLK_TAB:
			tabFlag = 1;
			break;

		}
		break;
		case SDL_KEYUP:
		switch(event.key.keysym.sym){
			case SDLK_q:
			qFlag = -1;
			//send note off
			break;

			case SDLK_z:
			zFlag = -1;
			break;

			case SDLK_w:
			wFlag = -1;
			break;

			case SDLK_s:
			sFlag = -1;
			break;

			case SDLK_e:
			eFlag = -1;
			break;

			case SDLK_x:
			xFlag = -1;
			break;

			case SDLK_d:
			dFlag = -1;
			break;

			case SDLK_r:
			rFlag = -1;
			break;

			case SDLK_c:
			cFlag = -1;
			break;

			case SDLK_f:
			fFlag = -1;
			break;

			case SDLK_t:
			tFlag = -1;
			break;

			case SDLK_v:
			vFlag = -1;
			break;

			case SDLK_g:
			gFlag = -1;
			break;

			case SDLK_y:
			yFlag = -1;
			break;

			case SDLK_b:
			bFlag = -1;
			break;

			case SDLK_h:
			hFlag = -1;
			break;

			case SDLK_u:
			uFlag = -1;
			break;

			case SDLK_n:
			nFlag = -1;
			break;

			case SDLK_j:
			jFlag = -1;
			break;

			case SDLK_i:
			iFlag = -1;
			break;

			case SDLK_COMMA:
			virgFlag = -1;
			break;

			case SDLK_k:
			kFlag = -1;
			break;

			case SDLK_o:
			oFlag = -1;
			break;

			case SDLK_SEMICOLON:
			pointvirgFlag = -1;
			break;

			case SDLK_l:
			lFlag = -1;
			break;

			case SDLK_p:
			pFlag = -1;
			break;

			case SDLK_COLON:
			deuxpointsFlag = -1;
			break;

			case SDLK_m:
			mFlag = -1;
			break;

			case SDLK_LSHIFT:
			shiftFlag = 0;
			break;

			case SDLK_LCTRL:
			ctrlFlag = 0;
			break;

			case SDLK_TAB:
			tabFlag = 0;
			break;

			case SDLK_DELETE:
			supprFlag = 0;
			break;

			case SDLK_UP:
			upFlag = 0;
			break;

			case SDLK_DOWN:
			downFlag = 0;
			break;

		}
		break;
	}
	SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
	SDL_BlitSurface(fond,NULL,ecran,&fondPos);
	if(qFlag==1){SDL_BlitSurface(q,NULL,ecran,&qPos);}
	if(zFlag==1){SDL_BlitSurface(z,NULL,ecran,&zPos);}
	if(wFlag==1){SDL_BlitSurface(w,NULL,ecran,&wPos);}
	if(sFlag==1){SDL_BlitSurface(s,NULL,ecran,&sPos);}
	if(eFlag==1){SDL_BlitSurface(e,NULL,ecran,&ePos);}
	if(xFlag==1){SDL_BlitSurface(x,NULL,ecran,&xPos);}
	if(dFlag==1){SDL_BlitSurface(d,NULL,ecran,&dPos);}
	if(rFlag==1){SDL_BlitSurface(r,NULL,ecran,&rPos);}
	if(cFlag==1){SDL_BlitSurface(c,NULL,ecran,&cPos);}
	if(fFlag==1){SDL_BlitSurface(f,NULL,ecran,&fPos);}
	if(tFlag==1){SDL_BlitSurface(t,NULL,ecran,&tPos);}
	if(vFlag==1){SDL_BlitSurface(v,NULL,ecran,&vPos);}
	if(gFlag==1){SDL_BlitSurface(g,NULL,ecran,&gPos);}
	if(yFlag==1){SDL_BlitSurface(y,NULL,ecran,&yPos);}
	if(bFlag==1){SDL_BlitSurface(b,NULL,ecran,&bPos);}
	if(hFlag==1){SDL_BlitSurface(h,NULL,ecran,&hPos);}
	if(uFlag==1){SDL_BlitSurface(u,NULL,ecran,&uPos);}
	if(nFlag==1){SDL_BlitSurface(n,NULL,ecran,&nPos);}
	if(jFlag==1){SDL_BlitSurface(j,NULL,ecran,&jPos);}
	if(iFlag==1){SDL_BlitSurface(i,NULL,ecran,&iPos);}
	if(virgFlag==1){SDL_BlitSurface(virg,NULL,ecran,&virgPos);}
	if(kFlag==1){SDL_BlitSurface(k,NULL,ecran,&kPos);}
	if(oFlag==1){SDL_BlitSurface(o,NULL,ecran,&oPos);}
	if(pointvirgFlag==1){SDL_BlitSurface(pointvirg,NULL,ecran,&pointvirgPos);}
	if(lFlag==1){SDL_BlitSurface(l,NULL,ecran,&lPos);}
	if(pFlag==1){SDL_BlitSurface(p,NULL,ecran,&pPos);}
	if(deuxpointsFlag==1){SDL_BlitSurface(deuxpoints,NULL,ecran,&deuxpointsPos);}
	if(mFlag==1){SDL_BlitSurface(m,NULL,ecran,&mPos);}
	if(shiftFlag!=0){SDL_BlitSurface(shift,NULL,ecran,&shiftPos);}
	if(ctrlFlag!=0){SDL_BlitSurface(ctrl,NULL,ecran,&ctrlPos);}
	if(tabFlag!=0){SDL_BlitSurface(tab,NULL,ecran,&tabPos);}
	if(upFlag!=0){SDL_BlitSurface(up,NULL,ecran,&upPos);}
	if(downFlag!=0){SDL_BlitSurface(down,NULL,ecran,&downPos);}
	if(supprFlag!=0){SDL_BlitSurface(suppr,NULL,ecran,&supprPos);}

	SDL_Flip(ecran);
}

SDL_FreeSurface(fond);
SDL_FreeSurface(q);
SDL_FreeSurface(z);
SDL_FreeSurface(w);
SDL_FreeSurface(s);
SDL_FreeSurface(e);
SDL_FreeSurface(x);
SDL_FreeSurface(d);
SDL_FreeSurface(r);
SDL_FreeSurface(c);
SDL_FreeSurface(f);
SDL_FreeSurface(t);
SDL_FreeSurface(v);
SDL_FreeSurface(g);
SDL_FreeSurface(y);
SDL_FreeSurface(b);
SDL_FreeSurface(h);
SDL_FreeSurface(u);
SDL_FreeSurface(n);
SDL_FreeSurface(j);
SDL_FreeSurface(i);
SDL_FreeSurface(virg);
SDL_FreeSurface(k);
SDL_FreeSurface(o);
SDL_FreeSurface(pointvirg);
SDL_FreeSurface(l);
SDL_FreeSurface(p);
SDL_FreeSurface(deuxpoints);
SDL_FreeSurface(m);
SDL_FreeSurface(shift);
SDL_FreeSurface(ctrl);
SDL_FreeSurface(tab);
SDL_FreeSurface(down);
SDL_FreeSurface(up);
SDL_FreeSurface(suppr);
SDL_Quit();

    jack_deactivate(client);
    jack_client_close(client);
    return 0;
}
