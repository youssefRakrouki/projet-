#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "collision.h"

int main()
{
int x=0;
SDL_Surface *ecran = NULL , *back = NULL ,*perso=NULL,*enemy=NULL;
SDL_Rect posBack;
SDL_Rect posPerso;
SDL_Rect posEnemy;
SDL_Event event;
int continuer =1;

SDL_Init(SDL_INIT_VIDEO);

back=IMG_Load("123.png");
perso=IMG_Load("detective.png");
enemy=IMG_Load("enemy.png");

posBack.x=0;
posBack.y=0;

posPerso.w=200;
posPerso.h=200;
posPerso.x = 0;
posPerso.y = 0;

posEnemy.w=200;
posEnemy.h=200; 
posEnemy.x = (500) ;
posEnemy.y = (600/2) ;

ecran= SDL_SetVideoMode(800,600,32, SDL_HWSURFACE | SDL_DOUBLEBUF);



while(continuer)
{
SDL_WaitEvent (&event);
switch(event.type)
{
case SDL_QUIT:
continuer = 0;
break;
case SDL_KEYDOWN:
switch(event.key.keysym.sym)
{
case SDLK_UP:
posPerso.y--;
break;
case SDLK_DOWN:
posPerso.y++;
break;
case SDLK_RIGHT:
posPerso.x++;
break;
case SDLK_LEFT:
posPerso.x--;
break;
}

x=collision_trigo(ecran,perso,enemy,posPerso,posEnemy);
break;
}
SDL_BlitSurface(back, NULL, ecran, &posBack);

SDL_BlitSurface(perso, NULL, ecran, &posPerso);
SDL_Flip(ecran);
}
SDL_Quit();
return 0;
}

