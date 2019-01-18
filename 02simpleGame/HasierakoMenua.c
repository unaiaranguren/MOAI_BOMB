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
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
void BotoiakSortu()
{
	int HasierakoArgazkiaId = 0;
	
	HasierakoArgazkiaId = irudiaKargatu(PLAYbotoia);
	irudiaMugitu(HasierakoArgazkiaId, 0, 0);
	printf("%d", HasierakoArgazkiaId);
	irudiakMarraztu();
	pantailaBerriztu();
}

void BotoiakSortu2()
{
	int idOUT = 21;
	idOUT = irudiaKargatu(PLAYOUT);
	irudiaMugitu(idOUT, 0, 0);
	printf("%d", idOUT);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
}






























int PLAYBotoia()
{
	int PlayId = 18;
	PlayId = irudiaKargatu(PLAYbotoia);
	return PlayId;
}
int PLAYBotoiaBI()
{
	int PlayId2 = 18;
	PlayId2 = irudiaKargatu(PLAYOUT);
	return PlayId2;
}
