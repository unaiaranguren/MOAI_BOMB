#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include "HasierakoMenua.h"
#include "Botoiak.h"

//---------------------------------------------------------------------------------

#include <stdio.h>

#include "ourTypes.h"
#include "game02.h"
#define JOKOA_SOUND_LOOSE ".\\sound\\atomsong.wav" 



int main(int argc, char * str[]) 
{
	int jarraitu = 0, ebentu = 0;
	

	if (sgHasieratu() == -1)
	{
		fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
		return 1;
	}
	
	do
	{
		BotoiakSortu();
		klik();
	} while (jarraitu);
	sgItxi();
	return 0;
}