#include <stdio.h>
#include "imagen.h"
#include "graphics.h"
#include "game02.h"
#include "Bizitzak.h"
#include "OurTypes.h"

JOKO_ELEMENTUA BizitzakExtra, ESKUDOA;
int IRUDIA_bizitzaMarraztu()
{
	int BizitzaID = 0;
	BizitzaID = irudiaKargatu(IRUDIA_bizitza);
	return BizitzaID;
}