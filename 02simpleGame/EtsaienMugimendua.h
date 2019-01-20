#ifndef ETSAIENMUGIMENDUA_H
#define ETSAIENMUGIMENDUA_H
#include "SDL.h"

//ETSAIEN IRUDIAK
//BOB-------------------------------------------------------------------------
#define JOKOA_PLAYER_ETSAIAGORA ".\\img\\EtsaiaGora.bmp"
#define JOKOA_PLAYER_ETSAIABEHERA ".\\img\\EtsaiaBehera.bmp"
//KROKO-----------------------------------------------------------------------
#define JOKOA_PLAYER_ETSAIA2GORA ".\\img\\Etsaia2Gora.bmp"
#define JOKOA_PLAYER_ETSAIA2BEHERA ".\\img\\Etsaia2Behera.bmp"

//ETSAIAK SORTU-------------------------------------------------------------
int JOKOA_etsaiaMarraztuGora();
int JOKOA_etsaiaMarraztuBehera();
int JOKOA_etsaia2MarraztuGora();
int JOKOA_etsaia2MarraztuBehera();

//ETSAIEN MUGIMENDUA eta KOLISIOA--------------------------------------------
int BobMugimendua(int BobId, int BobPosX, int BobPosY, int dPosY);
int BobKolisioa(int posizioaY, int dPosY);

int KrokoMugimendua(int KrokoId, int KrokoPosX, int KrokoPosY, int dPosX, int Kolisioa);
int KrokoKolisioa(int KrokoPosizioaX, int dPosX);

//ETSAIEN KOLISIOA JOKALARIAREKIN--------------------------------------------
int BobKolisioa(int BobPosizioaY, int dPosY);
int KrokoKolisioa(int KrokoPosizioaX, int dPosX);
int KolisioaBobJokalaria(int BobPosX, int BobPosY, int HulkPosX, int HulkPosY, int PowerUp, BONBA_ELEMENTUA BONBA);
int KolisioaKrokoJokalaria(int KrokoPosX, int KrokoPosY, int HulkPosX, int HulkPosY, int PowerUp, BONBA_ELEMENTUA BONBA);

#endif // !ETSAIENMUGIMENDUA_H