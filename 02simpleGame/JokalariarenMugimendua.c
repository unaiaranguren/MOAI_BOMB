#include <stdio.h>
#include "imagen.h"
#include "graphics.h"
#include "game02.h"
#include "JokalariarenMugimendua.h"
#include "OurTypes.h"
#include "ebentoak.h"

#define BOMBA_SOINUA ".\\sound\\bonba.wav"

//Hulk Marraztu------------------------------------------
int JOKOA_jokalariaBiratuAurretik()
{
	int HulkId = 5;
	HulkId = irudiaKargatu(JOKOA_PLAYER_BIRATUAURRETIK);
	return HulkId;
}
int JOKOA_jokalariaBiratuEskuinera()
{
	int HulkId = 5;
	HulkId = irudiaKargatu(JOKOA_PLAYER_BIRATUESKUINERA);
	return HulkId;
}
int JOKOA_jokalariaBiratuEzkerrera()
{
	int HulkId = 5;
	HulkId = irudiaKargatu(JOKOA_PLAYER_BIRATUEZKERRERA);
	return HulkId;
}
int JOKOA_jokalariaBiratuAtzera()
{
	int HulkId = 5;
	HulkId = irudiaKargatu(JOKOA_PLAYER_BIRATUATZERA);
	return HulkId;
}
//BLOKEA-------------------------------------------------------------------------
int JOKOA_BlokeaMarraztu()
{
	int BlokeaId = 0;
	BlokeaId = irudiaKargatu(JOKOA_BLOKEA_APURTZEKOA);
	return BlokeaId;

}
//BONBA/EZTANDA------------------------------------------------------------------
int JOKOA_bonbaMarratu()
{
	int BonbaId = -1;
	BonbaId = irudiaKargatu(JOKOA_BONBA);
	return BonbaId;
}
int JOKOA_eztandaMarraztu()
{
	int EztandaId = 0;
	EztandaId = irudiaKargatu(JOKOA_EZTANDA);
	return EztandaId;
}
//Hulk Mugimendua----------------------------------------------------------------
JOKO_ELEMENTUA HULK;
int HulkPosX = 48;
int HulkPosY = 48;
int GoikoErtza = 48, BehekoErtza = 336, EskuinekoErtza = 48, EzkerrekoErtza = 336;

int HulkMugimenduaXardatza(int ebentu, int BlokeKolisioaX, BONBA_ELEMENTUA BONBA, int ApurtzekoaXEzkerretik, int ApurtzekoaXEskumatik)
{
	if (BONBA.blokeaKenduDa == 1)
	{
		ApurtzekoaXEskumatik = 0;
		ApurtzekoaXEzkerretik = 0;
	}
	if ((ebentu == TECLA_LEFT) && (HulkPosX > EskuinekoErtza) && (BlokeKolisioaX == 0) && (ApurtzekoaXEzkerretik == 0))
	{
		HulkPosX -= 48;
		irudiaKendu(HULK.id);
		HULK.id = JOKOA_jokalariaBiratuEzkerrera();
	}
	if ((ebentu == TECLA_RIGHT) && (HulkPosX < EzkerrekoErtza) && (BlokeKolisioaX == 0) && (ApurtzekoaXEskumatik == 0))
	{
		HulkPosX += 48;
		irudiaKendu(HULK.id);
		HULK.id = JOKOA_jokalariaBiratuEskuinera();
	}
	irudiaMugitu(HULK.id, HulkPosX, HulkPosY);

	return HulkPosX;
}
int HulkMugimenduaYardatza(int ebentu, int BlokeKolisioaY)
{
	if ((ebentu == TECLA_UP) && (HulkPosY > GoikoErtza) && (BlokeKolisioaY == 0))
	{
		HulkPosY -= 48;
		irudiaKendu(HULK.id);
		HULK.id = JOKOA_jokalariaBiratuAurretik();
	}
	if ((ebentu == TECLA_DOWN) && (HulkPosY < BehekoErtza) && (BlokeKolisioaY == 0))
	{
		HulkPosY += 48;
		irudiaKendu(HULK.id);
		HULK.id = JOKOA_jokalariaBiratuAtzera();
	}
	irudiaMugitu(HULK.id, HulkPosX, HulkPosY);

	return HulkPosY;
}
//KOLISIOAK JOKALARIAK-----------------------------------------------------------------------------
int KolisioakErdikoBlokeekinX(int HulkPosX, int HulkPosY)
{
	int blokea = 48, kolisioaX = 0;

	if ((HulkPosY == 2 * blokea) || (HulkPosY == 4 * blokea) || (HulkPosY == 6 * blokea))
	{
		kolisioaX = 1;
	}

	return kolisioaX;
}
int KolisioakErdikoBlokeekinY(int HulkPosX, int HulkPosY)
{
	int blokea = 48, kolisioaY = 0;

	if ((HulkPosX == 2 * blokea) || (HulkPosX == 4 * blokea) || (HulkPosX == 6 * blokea))
	{
		kolisioaY = 1;
	}

	return kolisioaY;
}
int KolisioakApurtzekoBlokeekinEskumatik(int HulkPosX, int HulkPosY)
{
	int KolisioaXEskumatik = 0, posizioax = 96, posizioay = 144;

	if ((HulkPosX + 48 >= posizioax) && (HulkPosX < posizioax + 48) && (HulkPosY + 48 > posizioay && HulkPosY < posizioay + 48))
	{
		KolisioaXEskumatik = 1;
	}

	return KolisioaXEskumatik;
}
int KolisioaApurtzekoEtsaiaKroko(int KrokoPosX, int KrokoPosY)
{
	int posizioax = 96, posizioay = 144, KolisioaEtsaiaX = 0;

	if ((KrokoPosX <= posizioax + 48) && (KrokoPosY > posizioay) && (KrokoPosY <= posizioay + 48))
	{
		KolisioaEtsaiaX = 1;
	}

	return KolisioaEtsaiaX;
}
int KolisioakApurtzekoBlokeekinEzkerretik(int HulkPosX, int HulkPosY)
{
	int KolisioaXEzkerretik = 0, posizioax = 96, posizioay = 144;

	if ((HulkPosX <= posizioax + 48) && (HulkPosX) && (HulkPosY + 48 > posizioay && HulkPosY < posizioay + 48))
	{
		KolisioaXEzkerretik = 1;
	}

	return KolisioaXEzkerretik;
}
//HASIERAKO_IRUDIA_KENDU-----------------------------------------------------------------------------------------
void HasierakoIrudiaKendu(int ebentu, int HulkImg, int Kont)
{
	if (((TECLA_RIGHT == ebentu) || (TECLA_LEFT == ebentu) || (TECLA_UP == ebentu) || (TECLA_DOWN == ebentu)) && (Kont == 0))
	{
		irudiaMugitu(HulkImg, 1000, 1000);
		Kont++;
	}
}
//BONBAK-----------------------------------------------------------------------------------------------------

BONBA_ELEMENTUA BonbarenSorrera(int ebentu, JOKO_ELEMENTUA HULK, BONBA_ELEMENTUA BONBA, BONBA_ELEMENTUA EZTANDA)
{
	time_t timestamp;
	timestamp = time(NULL);


	if ((ebentu == TECLA_SPACE) && (BONBA.egoera == 0) && (BONBA.eztandaprozesua == 0))
	{

		BONBA.id = JOKOA_bonbaMarratu();
		BONBA.denborabonba = timestamp;
		irudiaMugitu(BONBA.id, BONBA.pos.x = HULK.pos.x, BONBA.pos.y = HULK.pos.y);
		printf("%i ", (int)timestamp);
		BONBA.egoera = 1;

	}
	if ((timestamp - BONBA.denborabonba >= 2) && (BONBA.egoera == 1))
	{
		irudiaKendu(BONBA.id);
		BONBA.egoera = 0;
		BONBA.egoera2 = 0;
		BONBA.egoeraeztanda = 1;
		BONBA.eztandadenborabaiez = 1;
	}
	return BONBA;
}


BONBA_ELEMENTUA EztandaSorrera(BONBA_ELEMENTUA BONBA, BONBA_ELEMENTUA EZTANDA, JOKO_ELEMENTUA BLOKEAAPURTZEKO, JOKO_ELEMENTUA ETSAIABOB, JOKO_ELEMENTUA ETSAIAKROKO)
{
	int blokea = 48;
	int EzkerrekoErtza = 48, EskuinekoErtza = 336, GoikoErtza = 48, BehekoErtza = 336;

	time_t timestamp;
	timestamp = time(NULL);

	EZTANDA.pos.x = BONBA.pos.x;
	EZTANDA.pos.y = BONBA.pos.y;

	if (BONBA.eztandadenborabaiez == 1)
	{
		audioInit();
		loadTheMusic(BOMBA_SOINUA);
		BONBA.denboraeztanda = timestamp;
		BONBA.eztandadenborabaiez = 0;
		BONBA.eztandaprozesua = 1;
		playMusic(BOMBA_SOINUA);
	}
	if ((BONBA.egoeraeztanda == 1) && (BONBA.egoera2 == 0))
	{
		if (BONBA.eztandamarraztu == 0)
		{
			BONBA.id = JOKOA_eztandaMarraztu(); //ERDIKO EZTANDA
			EZTANDA.tokia = 1;
			irudiaMugitu(BONBA.id, EZTANDA.pos.x, EZTANDA.pos.y);
			BONBA = KolisioaEztandaBlokea(EZTANDA, BLOKEAAPURTZEKO, BONBA);
			BONBA = KolisioaEztandaEtsaia(EZTANDA, BONBA, ETSAIABOB, ETSAIAKROKO);
		}
		if ((timestamp - BONBA.denboraeztanda >= 1) && (BONBA.egoeraeztanda == 1))
		{
			irudiaKendu(BONBA.id);
		}

		if ((EZTANDA.pos.x - blokea >= EzkerrekoErtza) && ((EZTANDA.pos.y == blokea) || (EZTANDA.pos.y == 3 * blokea) || (EZTANDA.pos.y == 5 * blokea) || (EZTANDA.pos.y == 7 * blokea))) //EZKERREKO EZTANDA
		{
			if (BONBA.eztandamarraztu == 0)
			{
				BONBA.id2 = JOKOA_eztandaMarraztu();
				EZTANDA.tokia = 2;
				irudiaMugitu(BONBA.id2, EZTANDA.pos.x - blokea, EZTANDA.pos.y);
				BONBA = KolisioaEztandaBlokea(EZTANDA, BLOKEAAPURTZEKO, BONBA);
				BONBA = KolisioaEztandaEtsaia(EZTANDA, BONBA, ETSAIABOB, ETSAIAKROKO);
			}
			if ((timestamp - BONBA.denboraeztanda >= 1) && (BONBA.egoeraeztanda == 1))
			{
				irudiaKendu(BONBA.id2);
			}
		}
		if ((EZTANDA.pos.x + blokea <= EskuinekoErtza) && ((EZTANDA.pos.y == blokea) || (EZTANDA.pos.y == 3 * blokea) || (EZTANDA.pos.y == 5 * blokea) || (EZTANDA.pos.y == 7 * blokea))) //ESKUINEKO EZTANDA
		{
			if (BONBA.eztandamarraztu == 0)
			{
				BONBA.id3 = JOKOA_eztandaMarraztu();
				EZTANDA.tokia = 3;
				irudiaMugitu(BONBA.id3, EZTANDA.pos.x + blokea, EZTANDA.pos.y);
				BONBA = KolisioaEztandaBlokea(EZTANDA, BLOKEAAPURTZEKO, BONBA);
				BONBA = KolisioaEztandaEtsaia(EZTANDA, BONBA, ETSAIABOB, ETSAIAKROKO);
			}
			if ((timestamp - BONBA.denboraeztanda >= 1) && (BONBA.egoeraeztanda == 1))
			{
				irudiaKendu(BONBA.id3);
			}
		}
		if ((EZTANDA.pos.y - blokea >= GoikoErtza) && ((EZTANDA.pos.x == blokea) || (EZTANDA.pos.x == 3 * blokea) || (EZTANDA.pos.x == 5 * blokea) || (EZTANDA.pos.x == 7 * blokea))) // GOIKO EZTANDA
		{
			if (BONBA.eztandamarraztu == 0)
			{
				BONBA.id4 = JOKOA_eztandaMarraztu();
				EZTANDA.tokia = 4;
				irudiaMugitu(BONBA.id4, EZTANDA.pos.x, EZTANDA.pos.y - blokea);
				BONBA = KolisioaEztandaBlokea(EZTANDA, BLOKEAAPURTZEKO, BONBA);
				BONBA = KolisioaEztandaEtsaia(EZTANDA, BONBA, ETSAIABOB, ETSAIAKROKO);
			}
			if ((timestamp - BONBA.denboraeztanda >= 1) && (BONBA.egoeraeztanda == 1))
			{
				irudiaKendu(BONBA.id4);
			}
		}
		if ((EZTANDA.pos.y + blokea <= BehekoErtza) && ((EZTANDA.pos.x == blokea) || (EZTANDA.pos.x == 3 * blokea) || (EZTANDA.pos.x == 5 * blokea) || (EZTANDA.pos.x == 7 * blokea))) // BEHEKO EZTANDA
		{
			if (BONBA.eztandamarraztu == 0)
			{
				BONBA.id5 = JOKOA_eztandaMarraztu();
				EZTANDA.tokia = 5;
				irudiaMugitu(BONBA.id5, EZTANDA.pos.x, EZTANDA.pos.y + blokea);
				BONBA = KolisioaEztandaBlokea(EZTANDA, BLOKEAAPURTZEKO, BONBA);
				BONBA = KolisioaEztandaEtsaia(EZTANDA, BONBA, ETSAIABOB, ETSAIAKROKO);
			}
			if ((timestamp - BONBA.denboraeztanda >= 1) && (BONBA.egoeraeztanda == 1))
			{
				irudiaKendu(BONBA.id5);
			}
		}
		BONBA.eztandamarraztu = 1;
	}

	if ((timestamp - BONBA.denboraeztanda >= 1) && (BONBA.egoeraeztanda == 1))
	{
		audioTerminate(BOMBA_SOINUA);
		BONBA.egoeraeztanda = 0;
		BONBA.egoera2 = 1;
		BONBA.eztandamarraztu = 0;
		BONBA.eztandaprozesua = 0;
	}

	return BONBA;
}
BONBA_ELEMENTUA KolisioaEztandaBlokea(BONBA_ELEMENTUA EZTANDA, JOKO_ELEMENTUA BLOKEAAPURTZEKO, BONBA_ELEMENTUA BONBA)
{
	int blokea = 48, blokeaKendu = 0;

	if (BONBA.blokeaKenduDa == 0)
	{
		if (EZTANDA.tokia == 1) // ERDIKO EZTANDA
		{
			if ((EZTANDA.pos.x == BLOKEAAPURTZEKO.pos.x) && (EZTANDA.pos.y == BLOKEAAPURTZEKO.pos.y))
			{
				blokeaKendu = 1;
			}
		}
		if (EZTANDA.tokia == 2) //EZKERREKO EZTANDA 
		{
			if ((EZTANDA.pos.x - blokea == BLOKEAAPURTZEKO.pos.x) && (EZTANDA.pos.y == BLOKEAAPURTZEKO.pos.y))
			{
				blokeaKendu = 1;
			}
		}
		if (EZTANDA.tokia == 3) //ESKUINEKO EZTANDA
		{
			if ((EZTANDA.pos.x + blokea == BLOKEAAPURTZEKO.pos.x) && (EZTANDA.pos.y == BLOKEAAPURTZEKO.pos.y))
			{
				blokeaKendu = 1;
			}
		}
		if (EZTANDA.tokia == 4) //GOIKO EZTANDA
		{
			if ((EZTANDA.pos.x == BLOKEAAPURTZEKO.pos.x) && (EZTANDA.pos.y - blokea == BLOKEAAPURTZEKO.pos.y))
			{
				blokeaKendu = 1;
			}
		}
		if (EZTANDA.tokia == 5) //BEHEKO EZTANDA
		{
			if ((EZTANDA.pos.x == BLOKEAAPURTZEKO.pos.x) && (EZTANDA.pos.y + blokea == BLOKEAAPURTZEKO.pos.y))
			{
				blokeaKendu = 1;
			}
		}
	}
	if (blokeaKendu == 1)
	{
		irudiaKendu(BLOKEAAPURTZEKO.id);
		BONBA.blokeaKenduDa = 1; // HULK blokea zegoen tokitik pasatzeko parametroa erabiliko da. 
	}

	return BONBA;

}
BONBA_ELEMENTUA KolisioaEztandaEtsaia(BONBA_ELEMENTUA EZTANDA, BONBA_ELEMENTUA BONBA, JOKO_ELEMENTUA ETSAIABOB, JOKO_ELEMENTUA ETSAIAKROKO)
{
	int blokea = 48, etsaiaBobKendu = 0, etsaiaKrokoKendu = 0;

	if (BONBA.BobHilDa == 0)
	{
		if (EZTANDA.tokia == 1) // ERDIKO EZTANDA
		{
			if ((EZTANDA.pos.x + blokea >= ETSAIABOB.pos.x) && (EZTANDA.pos.x <= ETSAIABOB.pos.x) && (EZTANDA.pos.y + blokea >= ETSAIABOB.pos.y) && (EZTANDA.pos.y <= ETSAIABOB.pos.y))
			{
				etsaiaBobKendu = 1;
			}
		}
		if (EZTANDA.tokia == 2) // EZKERREKO EZTANDA
		{
			if ((EZTANDA.pos.x - blokea <= ETSAIABOB.pos.x) && (EZTANDA.pos.x >= ETSAIABOB.pos.x + 36) && (EZTANDA.pos.y + blokea >= ETSAIABOB.pos.y) && (EZTANDA.pos.y <= ETSAIABOB.pos.y))
			{
				etsaiaBobKendu = 1;
			}
		}
		if (EZTANDA.tokia == 3) // ESKUINEKO EZTANDA
		{
			if ((EZTANDA.pos.x + 2 * blokea >= ETSAIABOB.pos.x) && (EZTANDA.pos.x + blokea <= ETSAIABOB.pos.x) && (EZTANDA.pos.y + blokea >= ETSAIABOB.pos.y) && (EZTANDA.pos.y <= ETSAIABOB.pos.y))
			{
				etsaiaBobKendu = 1;
			}
		}
		if (EZTANDA.tokia == 4) // GOIKO EZTANDA
		{
			if ((EZTANDA.pos.x + blokea >= ETSAIABOB.pos.x) && (EZTANDA.pos.x <= ETSAIABOB.pos.x) && (EZTANDA.pos.y - blokea <= ETSAIABOB.pos.y) && (EZTANDA.pos.y >= ETSAIABOB.pos.y + 36))
			{
				etsaiaBobKendu = 1;
			}
		}
		if (EZTANDA.tokia == 5) // BEHEKO EZTANDA
		{
			if ((EZTANDA.pos.x + blokea >= ETSAIABOB.pos.x) && (EZTANDA.pos.x <= ETSAIABOB.pos.x) && (EZTANDA.pos.y + 2 * blokea >= ETSAIABOB.pos.y) && (EZTANDA.pos.y <= ETSAIABOB.pos.y - 36))
			{
				etsaiaBobKendu = 1;
			}
		}
	}
	if (etsaiaBobKendu == 1)
	{
		irudiaKendu(ETSAIABOB.id);
		BONBA.BobHilDa = 1;
		BONBA.kontagailuaIrabazi++;
	}

	if (BONBA.KrokoHilDa == 0)
	{
		if (EZTANDA.tokia == 1) // ERDIKO EZTANDA
		{
			if ((EZTANDA.pos.x + blokea >= ETSAIAKROKO.pos.x) && (EZTANDA.pos.x <= ETSAIAKROKO.pos.x) && (EZTANDA.pos.y + blokea >= ETSAIAKROKO.pos.y) && (EZTANDA.pos.y <= ETSAIAKROKO.pos.y))
			{
				etsaiaKrokoKendu = 1;
			}
		}
		if (EZTANDA.tokia == 2) // EZKERREKO EZTANDA
		{
			if ((EZTANDA.pos.x - blokea <= ETSAIAKROKO.pos.x) && (EZTANDA.pos.x >= ETSAIAKROKO.pos.x + 36) && (EZTANDA.pos.y + blokea >= ETSAIAKROKO.pos.y) && (EZTANDA.pos.y <= ETSAIAKROKO.pos.y))
			{
				etsaiaKrokoKendu = 1;
			}
		}
		if (EZTANDA.tokia == 3) // ESKUINEKO EZTANDA
		{
			if ((EZTANDA.pos.x + 2 * blokea >= ETSAIAKROKO.pos.x) && (EZTANDA.pos.x + blokea <= ETSAIAKROKO.pos.x) && (EZTANDA.pos.y + blokea >= ETSAIAKROKO.pos.y) && (EZTANDA.pos.y <= ETSAIAKROKO.pos.y))
			{
				etsaiaKrokoKendu = 1;
			}
		}
		if (EZTANDA.tokia == 4) // GOIKO EZTANDA
		{
			if ((EZTANDA.pos.x + blokea >= ETSAIAKROKO.pos.x) && (EZTANDA.pos.x <= ETSAIAKROKO.pos.x) && (EZTANDA.pos.y - blokea <= ETSAIAKROKO.pos.y) && (EZTANDA.pos.y >= ETSAIAKROKO.pos.y + 36))
			{
				etsaiaKrokoKendu = 1;
			}
		}
		if (EZTANDA.tokia == 5) // BEHEKO EZTANDA
		{
			if ((EZTANDA.pos.x + blokea >= ETSAIAKROKO.pos.x) && (EZTANDA.pos.x <= ETSAIAKROKO.pos.x) && (EZTANDA.pos.y + 2 * blokea >= ETSAIAKROKO.pos.y) && (EZTANDA.pos.y <= ETSAIAKROKO.pos.y - 36))
			{
				etsaiaKrokoKendu = 1;
			}
		}
	}
	if (etsaiaKrokoKendu == 1)
	{
		irudiaKendu(ETSAIAKROKO.id);
		BONBA.KrokoHilDa = 1;
		BONBA.kontagailuaIrabazi++;

	}

	return BONBA;

}