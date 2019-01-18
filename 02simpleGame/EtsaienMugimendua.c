#include <stdio.h>
#include "imagen.h"
#include "graphics.h"
#include "game02.h"
#include "EtsaienMugimendua.h"
#include "OurTypes.h"

JOKO_ELEMENTUA BOB, KROKO;
POSIZIOA aux;

//Etsaia BOB Marraztu-------------------------------------
int JOKOA_etsaiaMarraztuGora()
{
	int BobId = 0;
	BobId = irudiaKargatu(JOKOA_PLAYER_ETSAIAGORA);
	return BobId;
}
int JOKOA_etsaiaMarraztuBehera()
{
	int BobId = 1;
	BobId = irudiaKargatu(JOKOA_PLAYER_ETSAIABEHERA);
	return BobId;
}

//Etsaia KROKO Marraztu------------------------------------
int JOKOA_etsaia2MarraztuGora()
{
	int KrokoId = 0;
	KrokoId = irudiaKargatu(JOKOA_PLAYER_ETSAIA2GORA);
	return KrokoId;
}
int JOKOA_etsaia2MarraztuBehera()
{
	int KrokoId = -1;
	KrokoId = irudiaKargatu(JOKOA_PLAYER_ETSAIA2BEHERA);
	return KrokoId;
}
//MUGIMENDUA BOB ETA KROKO----------------------------------
int BobMugimendua(int BobId, int BobPosX, int BobPosY, int dPosY)
{
	BobPosY += dPosY;
	irudiaMugitu(BobId, BobPosX, BobPosY);

	return BobPosY;
}
int KrokoMugimendua(int KrokoId, int KrokoPosX, int KrokoPosY, int dPosX, int Kolisioa)
{
	int i = 0;

	if (Kolisioa == 0)
	{
		KrokoPosX += dPosX;
		irudiaMugitu(KrokoId, KrokoPosX, KrokoPosY);
	}
	if (Kolisioa == 1)
	{

	}


	return KrokoPosX;
}
//KOLISIOAK-------------------------------------------------
int BobKolisioa(int BobPosizioaY, int dPosY)
{
	int behekoErtza = 384, goikoErtza = 48;

	if ((BobPosizioaY + 36 >= behekoErtza) || (BobPosizioaY <= goikoErtza))
	{
		dPosY = -dPosY;
	}
	return dPosY;
}
int KrokoKolisioa(int KrokoPosizioaX, int dPosX)
{
	int ezkerrekoErtza = 48, eskumakoErtza = 384;

	if ((KrokoPosizioaX <= ezkerrekoErtza) || (KrokoPosizioaX + 36 >= eskumakoErtza))
	{
		dPosX = -dPosX;
	}

	return dPosX;
}
//KOLISIOAK ETSAIEN AURKA------------------------------------------------------------------------------
int KolisioaBobJokalaria(int BobPosX, int BobPosY, int HulkPosX, int HulkPosY, int PowerUp, BONBA_ELEMENTUA BONBA)
{
	int kolisioa = 0;

	if (BONBA.BobHilDa == 0)
	{
		if ((HulkPosX + 48 > BobPosX && HulkPosX < BobPosX + 36 && HulkPosY + 48 > BobPosY  && HulkPosY < BobPosY + 36) && (PowerUp == 0))
		{
			kolisioa = 1;
		}
	}

	return kolisioa;
}
int KolisioaKrokoJokalaria(int KrokoPosX, int KrokoPosY, int HulkPosX, int HulkPosY, int PowerUp, BONBA_ELEMENTUA BONBA)
{
	int kolisioa = 0;

	if (BONBA.KrokoHilDa == 0)
	{
		if ((HulkPosX + 48 > KrokoPosX && HulkPosX < KrokoPosX + 36 && HulkPosY + 48> KrokoPosY  && HulkPosY < KrokoPosY + 36) && (PowerUp == 0))
		{
			kolisioa = 1;
		}
	}

	return kolisioa;
}