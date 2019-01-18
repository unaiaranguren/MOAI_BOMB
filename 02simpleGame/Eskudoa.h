#ifndef ESKUDOA_H
#define ESKUDOA_H
#include "SDL.h"

int IRUDIA_EskudoaMarraztu();
int IRUDIA_Eskudo();

#define IRUDIA_Eskudoa ".\\img\\ESKUDOA.bmp"
#define IRUDIA_EskudoaPowerUp ".\\img\\ESKUDOA_POWERUP.bmp"

JOKO_ELEMENTUA EskudoaEman(int ebentu, int KolisioaX, int KolisioaY, JOKO_ELEMENTUA ESKUDOAPOWER, JOKO_ELEMENTUA HULK, int BobJokalaria);
JOKO_ELEMENTUA PowerUp(int HULKX, int HULKY, int BizitzaExtraImg, JOKO_ELEMENTUA ESKUDOA);


#endif // !ESKUDOA_H