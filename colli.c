#include "collision.h"
#include "math.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

int collision_trigo(SDL_Surface *ecran , SDL_Surface *perso  ,SDL_Surface *enemy,SDL_Rect posPerso,SDL_Rect posEnnem )
{
SDL_Rect spawn;
int ra,rb,xb,xa,ya,yb,distance;
SDL_Surface*gameoveri;
gameoveri= IMG_Load("game over.jpg");
ra=(perso->w)/2;
xa=(posPerso.x+(perso->w/2));
ya=(posPerso.y+(perso->h/2));
rb=(enemy->w)/2;
xb=(posEnnem.x+(enemy->w/2));
yb=(posEnnem.y+(enemy->h/2));
distance=sqrt((xa-xb)*(xa-xb)+( ya+yb)*( ya+yb));
if(distance<=ra+rb)
{
SDL_BlitSurface(gameoveri,NULL,ecran,&spawn);
}
else
{
return 0;
}
}
