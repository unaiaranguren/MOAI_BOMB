#include <stdio.h>
#include "imagen.h"
#include "graphics.h"
#include "game02.h"
#include "OurTypes.h"
#include "Eskudoa.h"
#include "Bizitzak.h"
#include <time.h>
#include "soinua.h"

JOKO_ELEMENTUA ESKUDOA, ESKUDOAPOWER;
#define ESKUDOA_SOINUA ".\\sound\\audioeskudoa.wav"

int IRUDIA_Eskudo()
{
	int ESKUDOAID = 0;
	ESKUDOAID = irudiaKargatu(IRUDIA_EskudoaPowerUp);
	return ESKUDOAID;
}
int IRUDIA_EskudoaMarraztu() //MAPAKOA-------------------------------------------
{
	int ESKUDOAID = 0;
	ESKUDOAID = irudiaKargatu(IRUDIA_Eskudoa);
	return ESKUDOAID;
}

JOKO_ELEMENTUA EskudoaEman(int ebentu, int KolisioaX, int KolisioaY, JOKO_ELEMENTUA ESKUDOAPOWER, JOKO_ELEMENTUA HULK, int BobJokalaria)
{
	time_t timestamp;
	timestamp = time(NULL);

	if (HULK.poweruphartuta == 0)
	{
		if ((HULK.pos.x + 48 > 144 && HULK.pos.x < 144 + 36 && HULK.pos.y + 48 > 96 && HULK.pos.y < 96 + 36) && (BobJokalaria == 0))
		{
			irudiaMugitu(ESKUDOAPOWER.id, 460, 96);
			HULK.poweruphartuta = 1;
			audioInit();
			loadTheMusic(ESKUDOA_SOINUA);
			playMusic(ESKUDOA_SOINUA);

			if (HULK.lehenengoaldiz == 0)
			{
				HULK.powerupdenbora = timestamp;
				printf("%d ", HULK.powerupdenbora);
				HULK.lehenengoaldiz = 1;
			}
		}
	}

	if (HULK.lehenengoaldiz == 1)
	{
		if (timestamp - HULK.powerupdenbora >= 1)
		{
			audioTerminate();
		}
		if (timestamp - HULK.powerupdenbora >= 5)
		{
			irudiaMugitu(ESKUDOAPOWER.id, 1000, 1000);
			HULK.powerupkendu = 1;
			HULK.lehenengoaldiz = 0;
		}
	}
	return HULK;
}
JOKO_ELEMENTUA PowerUp(int HULKX, int HULKY, int EskudoaImg, JOKO_ELEMENTUA ESKUDOA)
{
	int EskudoaKont = 0;

	if ((HULKX + 48 > 144 && HULKX < 144 + 36 && HULKY + 48 > 96 && HULKY < 96 + 36) && (ESKUDOA.lehenengoaldiz == 0)) //Power-Up-a kentzeko
	{
		irudiaMugitu(EskudoaImg, 1000, 1000);
		ESKUDOA.lehenengoaldiz = 1;
	}

	return ESKUDOA;
}