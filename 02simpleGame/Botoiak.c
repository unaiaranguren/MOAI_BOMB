#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#include "Eszenarioa.h"
#include "JokalariarenMugimendua.h"
#include "Bizitzak.h"
#include "EtsaienMugimendua.h"
#include "HasierakoMenua.h"
#include "Botoiak.h"
//--------------------------------------

void klik ()
{
	int egoera = 0, ebentu = 0, bolumena = 0;
	kantua(bolumena);
	do
	{
		
		ebentu = ebentuaJasoGertatuBada();
		if (ebentu == SAGU_BOTOIA_EZKERRA)
		{
			jolastenhasi(ebentu);
			NolaJolastu(ebentu);
			Kredituak(ebentu);
			bolumena=Bolumena(ebentu, bolumena);
			Irten(ebentu);
			
		}
		
	} while (!egoera);
}



//------------------------------------------------------------------------------------PLAY----------------------------------------------------------

void jolastenhasi(int ebentu)
{
	int hasi = 0, egoera=0, jarraitu=0;
	POSIZIOA pos;
	pos = saguarenPosizioa();
	
			if ((pos.x > 270) && (pos.x < 380) && (pos.y > 150) && (pos.y < 250))
			{
				
				irudiaKendu(1);
				do
				{
					/*irudiaKendu(PLAYbotoia);*/
					egoera = jokatu();
					/*jokoaAurkeztu();
					jarraitu = jokoAmaierakoa(egoera, HULK);*/
				} while (jarraitu);
			}
}
//-----------------------------------------------------------------------------------Nola Jolastu--------------------------------------------------
void NolaJolastu(int ebentu)
{
	int hasi = 0;
	POSIZIOA pos;
	

	pos = saguarenPosizioa();
	
		if ((pos.x > 196) && (pos.x < 464) && (pos.y > 284) && (pos.y < 308))
		{
			/*irudiaKendu(BOTOIA.id);*/
			int tutoid = -5;

			tutoid = irudiaKargatu(NolaJolastubotoia);

			irudiaMugitu(tutoid, 0, 0);

			pantailaGarbitu();
			irudiakMarraztu();
			pantailaBerriztu();
			ebentu = 0;
			do
			{
				ebentu = ebentuaJasoGertatuBada();
				if (ebentu == SAGU_BOTOIA_EZKERRA)
				{
					ebentu=irtenmenura(ebentu);
				}
			} while (ebentu!=SAGU_BOTOIA_EZKERRA);
		}

}
//--------------------------------------------------------------------------------------KREDITUAK----------------------------------------------------
void Kredituak(int ebentu)
{
	int hasi = 0;
	POSIZIOA pos;
	pos = saguarenPosizioa();

			if ((pos.x > 234) && (pos.x < 426) && (pos.y > 335) && (pos.y < 365))
			{
				/*irudiaKendu(PLAYbotoia);*/
				int egileid = -4;
				egileid = irudiaKargatu(Egileakbotoia);

				irudiaMugitu(egileid, 0, 0);
				
				pantailaGarbitu();
				irudiakMarraztu();
				pantailaBerriztu();
				ebentu = 0;
				do
				{
					ebentu = ebentuaJasoGertatuBada();
					if (ebentu == SAGU_BOTOIA_EZKERRA)
					{
						ebentu = irtenmenura(ebentu);
					}
				} while (ebentu != SAGU_BOTOIA_EZKERRA);
			}
}
//--------------------------------------------------------------------------------BOLUMENA----------------------------------------------------------
int Bolumena(int ebentu, int bolumena)
{
	int hasi = 0;
	POSIZIOA pos;
	pos = saguarenPosizioa();

	if ((pos.x > 295) && (pos.x < 346) && (pos.y > 380) && (pos.y < 438))
	{
		toggleMusic();
		bolumena++;
		if (bolumena % 2 == 0)
		{
			irudiaKendu(1);
			BotoiakSortu();
			
		}
		else
		{
			irudiaKendu(1);
			BotoiakSortu2();
			
		}
	}
	return bolumena;
}
//--------------------------------------------------------------------------------IRTEN------------------------------------------------------------------
int Irten(int ebentu)
{
	
	POSIZIOA pos;

		pos = saguarenPosizioa();
		if ((pos.x > 576) && (pos.x < 640) && (pos.y > 416) && (pos.y < 480))
		{
		
			sgItxi();
			return 0;
		}
}
int irtenmenura(int ebentu)
{
	int hasi = 0;
	POSIZIOA pos;

	

	pos = saguarenPosizioa();
	if ((pos.x > 576) && (pos.x < 640) && (pos.y > 416) && (pos.y < 480))
	{
		
		/*for (i = 0; i < 100; i++)
		{
			irudiaKendu(i);
		}*/
		pantailaGarbitu();
		BotoiakSortu();
		klik();
	}
	else
	{
		ebentu = 0;
	}
	return ebentu;
}

//------------------------------------------------------------ID-------------------------------------------------------------------
#define JOKOA_SOUND_LOOSE ".\\sound\\atomsong.wav" 
#define EZERREZ " "

void kantua(int bolumena)
{
	Mix_Music * musika = NULL;
	//int idOUT;

		audioInit();
		loadTheMusic(JOKOA_SOUND_LOOSE);
		playMusic();
	//if (bolumena == 1)
	//{
	//	
	//}
	//else
	//{
	//	idOUT = irudiaKargatu(PLAYOUT);
	//	toggleMusic();

	//	
	//	irudiaMugitu(idOUT, 0, 0);

	//	pantailaGarbitu();
	//	irudiakMarraztu();
	//	pantailaBerriztu();
	//}
}