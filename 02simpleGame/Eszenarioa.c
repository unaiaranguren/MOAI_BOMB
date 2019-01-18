#include <stdio.h>
#include "imagen.h"
#include "graphics.h"
#include "game02.h"
#include "Eszenarioa.h"
#include "OurTypes.h"

void EszenarioaSortu()
{
	int laukiarenluzera = 432, posizioax = 0, posizioay = 0, SBLOKEA, AZALERABLOKEA, Fondoa, blokea = 48;

	SBLOKEA = BLOKEA_solidoaMarraztu();
	
	Fondoa = FONDO_azaleraMarraztu();
	AZALERABLOKEA = BLOKEA_azaleraMarraztu();
	irudiaMugitu(Fondoa, 0, 0);
	irudiaMugitu(AZALERABLOKEA, 0, 0);

	


	for (int posizioax = 0; posizioax < laukiarenluzera; posizioax += blokea)
	{
		for (int posizioay = 0; posizioay < laukiarenluzera; posizioay += blokea)
		{
			if ((posizioax == 0) || (posizioay == 0) || (posizioax == laukiarenluzera - blokea) || (posizioay == laukiarenluzera - blokea)) //Ertzak!
			{
				SBLOKEA = BLOKEA_solidoaMarraztu();
				irudiaMugitu(SBLOKEA, posizioax, posizioay);
			}
		}
	}
	for (posizioax = 2 * blokea; posizioax <= 6 * blokea; posizioax += blokea * 2)
	{
		for (posizioay = 2 * blokea; posizioay <= 6 * blokea; posizioay += blokea * 2)
		{
			SBLOKEA = BLOKEA_solidoaMarraztu();
			irudiaMugitu(SBLOKEA, posizioax, posizioay);
		}
	}
}
//BLOKEAK Marraztu-----------------------------------------
int BLOKEA_solidoaMarraztu()
{
	int BSolidoId = 0;
	BSolidoId = irudiaKargatu(BLOKEA_SOLIDOA);
	return BSolidoId;
}
int BLOKEA_apurtzekoaMarraztu()
{
	int BApurtzekoaId = 1;
	BApurtzekoaId = irudiaKargatu(BLOKEA_APURTZEKOA);
	return BApurtzekoaId;
}
int BLOKEA_azaleraMarraztu()
{
	int AzaleraId = -1;
	AzaleraId = irudiaKargatu(BLOKEA_AZALERA);
	return AzaleraId;
}
int FONDO_azaleraMarraztu()
{
	int FondoId = 18;
	FondoId = irudiaKargatu(FONDO);
	return FondoId;
}