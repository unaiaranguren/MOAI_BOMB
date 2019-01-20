#ifndef ESZENARIOA_H
#define ESZENARIOA_H
#include "SDL.h"

//ESZENARIOA-------------------------------------------
void EszenarioaSortu();

//BLOKEAK
int BLOKEA_solidoaMarraztu();
int BLOKEA_apurtzekoaMarraztu();
int BLOKEA_azaleraMarraztu();

int FONDO_azaleraMarraztu();

#define BLOKEA_SOLIDOA ".\\img\\solidoa.bmp"
#define BLOKEA_APURTZEKOA ".\\img\\apurtzekoa.bmp"
#define BLOKEA_AZALERA ".\\img\\azalera.bmp"

#define FONDO ".\\img\\fondo.bmp"

#endif // !ESZENARIOA_H