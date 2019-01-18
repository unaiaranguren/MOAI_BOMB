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
#include "Botoiak.h"
#include "HasierakoMenua.h"
#include "Eskudoa.h"


#define ONGI_ETORRI_MEZUA "Sakatu return hasteko..."
#define JOKOA_SOUND_PLAY ""
//SOUND-----------------------------------------------------------------------
#define JOKOA_SOUND_WIN ".\\sound\\BugleCall.wav"
#define JOKOA_SOUND_LOOSE ".\\sound\\along.wav" 
//BUKAERA---------------------------------------------------------------------
#define BUKAERA_SOUND_1 ".\\sound\\128NIGHT_01.wav"
#define BUKAERA_IMAGE ".\\img\\gameover.bmp"
#define IRABAZIIMG ".\\img\\irabazi.bmp"
//----------------------------------------------------------------------------

//BUKAERA------------------------------------------------------------
int BUKAERA_irudiaBistaratu();
//HASIERAKO MEZUA-------------------------------------------------------------------
void sarreraMezuaIdatzi();

void jokoaAurkeztu(void)
{
  int ebentu = 0;

  sarreraMezuaIdatzi();
  do
  {
    ebentu = ebentuaJasoGertatuBada();
  } while (ebentu != TECLA_RETURN);
  pantailaGarbitu();
  pantailaBerriztu();
}

void sarreraMezuaIdatzi()
{
  pantailaGarbitu();
  textuaIdatzi(225, 200, ONGI_ETORRI_MEZUA);
  pantailaBerriztu();
}
//---------------------------------------------------------------------hasieratu---------------------------------------------------------

//------------------------------------------------------------------------hasieratu------------------------------------------------------------
EGOERA jokatu(void)
{
	int mugitu = 0, BizitzaKont = 0, KontHulkKentzeko = 0, ApurtzekoaXEzkerretik = 0, ApurtzekoaXEskumatik = 0, ApurtzekoaXEskumatikKroko = 0;
	int dPosY = 1, dPosX = 1; //ETSAIEN MUG
	int BlokeKolisioaX = 0, BlokeKolisioaY = 0;
	int BobJokalaria = 0, KrokoJokalaria = 0;
	EGOERA  egoera = JOLASTEN;
	int ebentu = 0, KOLISIOAETSAIA = 0, KOLISIOAETSAIAKROKO = 0;
	JOKO_ELEMENTUA HULK, ETSAIABOB, ETSAIAKROKO, Bizitzak, ESKUDOA, ESKUDOAPOWER, BLOKEAAPURTZEKO;
	BONBA_ELEMENTUA BONBA, EZTANDA;

	//POSIZIOA------------------------------------------------------
	HULK.pos.x = 48;
	HULK.pos.y = 48;
	ETSAIABOB.pos.x = 245;
	ETSAIABOB.pos.y = 50;
	ETSAIAKROKO.pos.x = 150;
	ETSAIAKROKO.pos.y = 245;
	EZTANDA.pos.x = 0;
	EZTANDA.pos.y = 0;

	//HASIERAKO EGOERA---------------------------------------------------------------------------------------
	EszenarioaSortu();
	BLOKEAAPURTZEKO.id = BLOKEA_apurtzekoaMarraztu();
	BLOKEAAPURTZEKO.pos.x = 96;
	BLOKEAAPURTZEKO.pos.y = 144;
	irudiaMugitu(BLOKEAAPURTZEKO.id, BLOKEAAPURTZEKO.pos.x, BLOKEAAPURTZEKO.pos.y);

	//JOKALARIAK-------------------------------------------------------------------------------------------
	HULK.id2 = JOKOA_jokalariaBiratuEskuinera();
	HULK.lehenengoaldiz = 0;
	HULK.powerupkendu = 0;
	HULK.poweruphartuta = 0;
	irudiaMugitu(HULK.id2, 48, 48);
	ETSAIABOB.id = JOKOA_etsaiaMarraztuBehera();
	ETSAIAKROKO.id = JOKOA_etsaia2MarraztuGora();
	//ESKUDOA----------------------------------------------------------------------------------------------
	ESKUDOA.lehenengoaldiz = 0;
	ESKUDOA.id = IRUDIA_EskudoaMarraztu();
	ESKUDOAPOWER.id = IRUDIA_Eskudo();
	irudiaMugitu(ESKUDOAPOWER.id, 1000, 1000);
	irudiaMugitu(ESKUDOA.id, 144, 96);
	//BIZITZAK---------------------------------------------------------------------------------------------
	Bizitzak.id = IRUDIA_bizitzaMarraztu();
	Bizitzak.id2 = IRUDIA_bizitzaMarraztu();
	Bizitzak.id3 = IRUDIA_bizitzaMarraztu();
	irudiaMugitu(Bizitzak.id, 460, 48);
	irudiaMugitu(Bizitzak.id2, 520, 48);
	irudiaMugitu(Bizitzak.id3, 580, 48);
	//BONBAK-------------------------------------------------------------------------------------------------
	BONBA.egoera = 0;
	BONBA.eztandamarraztu = 0;
	BONBA.eztandaprozesua = 0;
	BONBA.blokeaKenduDa = 0;
	BONBA.BobHilDa = 0;
	BONBA.KrokoHilDa = 0;
	BONBA.kontagailuaIrabazi = 0;
	//AUDIOA-----------------------------------------------------------------------------------------------------
	audioTerminate(JOKOA_SOUND_LOOSE);

	//JOKOA------------------------------------------------------------------------------------------------------
	do {
		Sleep(20);
		pantailaGarbitu();
		irudiakMarraztu();
		pantailaBerriztu();
		ebentu = ebentuaJasoGertatuBada();
		//IRUDIA_KENDU----------------------------------------------------------------------------------------------
		HasierakoIrudiaKendu(ebentu, HULK.id2, KontHulkKentzeko);
		//ESKUDOA---------------------------------------------------------------------------------------------------
		HULK = EskudoaEman(ebentu, BlokeKolisioaX, BlokeKolisioaY, ESKUDOAPOWER, HULK, BobJokalaria);
		ESKUDOA = PowerUp(HULK.pos.x, HULK.pos.y, ESKUDOA.id, ESKUDOA);
		//BIZITZAK--------------------------------------------------------------------------------------------------
		if ((BobJokalaria == 1) && (ESKUDOA.lehenengoaldiz == 0) || (BobJokalaria == 1) && (HULK.powerupkendu == 1))
		{
			ETSAIABOB.pos.x = 148;
			ETSAIABOB.pos.y = 50;

			if (BizitzaKont == 0)
			{
				irudiaKendu(Bizitzak.id);
			}
			if (BizitzaKont == 1)
			{
				irudiaKendu(Bizitzak.id2);
			}
			if (BizitzaKont == 2)
			{
				irudiaKendu(Bizitzak.id3);
			}
			BizitzaKont++;


		}
		if ((KrokoJokalaria == 1) && (ESKUDOA.lehenengoaldiz == 0) || (KrokoJokalaria == 1) && (HULK.powerupkendu == 1))
		{
			ETSAIAKROKO.pos.x = 300;
			ETSAIAKROKO.pos.y = 50;

			if (BizitzaKont == 0)
			{
				irudiaKendu(Bizitzak.id);
			}
			if (BizitzaKont == 1)
			{
				irudiaKendu(Bizitzak.id2);
			}
			if (BizitzaKont == 2)
			{
				irudiaKendu(Bizitzak.id3);
			}
			BizitzaKont++;
		}
		if (BizitzaKont > 2)
		{
			jokoAmaierakoa(egoera, HULK);
			/*BUKAERA_irudiaBistaratu();*/
		}
		//KOLISIOA_BLOKEEKIN-----------------------------------------------------------------------------------------
		BlokeKolisioaX = KolisioakErdikoBlokeekinX(HULK.pos.x, HULK.pos.y);
		BlokeKolisioaY = KolisioakErdikoBlokeekinY(HULK.pos.x, HULK.pos.y);
		ApurtzekoaXEzkerretik = KolisioakApurtzekoBlokeekinEzkerretik(HULK.pos.x, HULK.pos.y);
		ApurtzekoaXEskumatik = KolisioakApurtzekoBlokeekinEskumatik(HULK.pos.x, HULK.pos.y);
		ApurtzekoaXEskumatikKroko = KolisioaApurtzekoEtsaiaKroko(ETSAIAKROKO.pos.x, ETSAIAKROKO.pos.y);
		dPosX = KrokoKolisioa(ETSAIAKROKO.pos.x, dPosX);
		//KOLISIOA_ETSAIEKIN-----------------------------------------------------------------------------------------
		BobJokalaria = KolisioaBobJokalaria(ETSAIABOB.pos.x, ETSAIABOB.pos.y, HULK.pos.x, HULK.pos.y, HULK.lehenengoaldiz, BONBA);
		KrokoJokalaria = KolisioaKrokoJokalaria(ETSAIAKROKO.pos.x, ETSAIAKROKO.pos.y, HULK.pos.x, HULK.pos.y, HULK.lehenengoaldiz, BONBA);
		//MUGIMENDUA-------------------------------------------------------------------------------------------------
		ETSAIABOB.pos.y = BobMugimendua(ETSAIABOB.id, ETSAIABOB.pos.x, ETSAIABOB.pos.y, dPosY);
		dPosY = BobKolisioa(ETSAIABOB.pos.y, dPosY);
		HULK.pos.x = HulkMugimenduaXardatza(ebentu, BlokeKolisioaX, BONBA, ApurtzekoaXEzkerretik, ApurtzekoaXEskumatik);
		HULK.pos.y = HulkMugimenduaYardatza(ebentu, BlokeKolisioaY);
		ETSAIAKROKO.pos.x = KrokoMugimendua(ETSAIAKROKO.id, ETSAIAKROKO.pos.x, ETSAIAKROKO.pos.y, dPosX, ApurtzekoaXEskumatikKroko);
		//BONBAK-----------------------------------------------------------------------------------------------------	
		BONBA = BonbarenSorrera(ebentu, HULK, BONBA, EZTANDA);
		BONBA = EztandaSorrera(BONBA, EZTANDA, BLOKEAAPURTZEKO, ETSAIABOB, ETSAIAKROKO);
		if (BONBA.kontagailuaIrabazi == 2)
		{
			jokoAmaierakoaIRABAZI(egoera, HULK);
		}
	} while (egoera == JOLASTEN);

	/*irudiaKendu(HULK.id);*/
	toggleMusic();
	audioTerminate();
	pantailaGarbitu();
	pantailaBerriztu();
	return egoera;
}

//Amaiera-------------------------------------------------------------------------
int  jokoAmaierakoa(EGOERA egoera, JOKO_ELEMENTUA HULK)
{
  int ebentu = 0, id;
  
  audioTerminate();

  id=BUKAERA_irudiaBistaratu(HULK);
  return id;
}

int BUKAERA_irudiaBistaratu(JOKO_ELEMENTUA HULK) {
  int id = -1, backID=24, ebentu=0, amaitu=0;
  Sleep(200);
  id = irudiaKargatu(BUKAERA_IMAGE);
  irudiaMugitu(id, 0, 0);
  pantailaGarbitu();
  irudiakMarraztu();
  pantailaBerriztu();
  do
  {
	  ebentu = ebentuaJasoGertatuBada();
	  if (ebentu == SAGU_BOTOIA_EZKERRA)
	  {
		  amaitu=irtenmenura(ebentu);
		 
	  }
  } while (ebentu != SAGU_BOTOIA_EZKERRA);
  return id;
}

//--------------------------------------------IRABAZI-------------------
int  jokoAmaierakoaIRABAZI(EGOERA egoera, JOKO_ELEMENTUA HULK)
{
	int ebentu = 0, id;

	audioTerminate();

		id = BUKAERA_irudiaBistaratu1(HULK);
	return id;
}

int BUKAERA_irudiaBistaratu1(JOKO_ELEMENTUA HULK) {
	int id = -1, backID = 24, ebentu = 0, amaitu = 0;
	Sleep(200);
	id = irudiaKargatu(IRABAZIIMG);
	irudiaMugitu(id, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	do
	{
		ebentu = ebentuaJasoGertatuBada();
		if (ebentu == SAGU_BOTOIA_EZKERRA)
		{
			amaitu = irtenmenura(ebentu);

		}
	} while (ebentu != SAGU_BOTOIA_EZKERRA);
	return id;
}

