#ifndef OURTYPES_H
#define OURTYPES_H

#include "ebentoak.h"

typedef enum { JOLASTEN, GALDU, IRABAZI }EGOERA;
typedef enum { IRUDIA, MARGOA, TESTUA } MOTA;

typedef struct
{
	POSIZIOA pos;
	int id, id2, id3, id4;
	int lehenengoaldiz, powerupdenbora, powerupkendu, poweruphartuta;
	MOTA mota;
}JOKO_ELEMENTUA;

typedef struct
{
	POSIZIOA pos;
	int id, id2, id3, id4, id5;
	MOTA mota;
	int egoera, egoera2, egoeraeztanda, eztandadenborabaiez, eztandamarraztu, eztandaprozesua, tokia, blokeaKenduDa, BobHilDa, KrokoHilDa, kontagailuaIrabazi;
	time_t denborabonba, denboraeztanda;
}BONBA_ELEMENTUA;

#endif