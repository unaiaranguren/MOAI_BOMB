#ifndef MUGIMENDUA_H
#define MUGIMENDUA_H
#include "SDL.h"

//HULK IRUDIAK-----------------------------------------------
#define JOKOA_PLAYER_BIRATUAURRETIK ".\\img\\Aurretik.bmp"
#define JOKOA_PLAYER_BIRATUESKUINERA ".\\img\\Eskumatik.bmp"
#define JOKOA_PLAYER_BIRATUEZKERRERA ".\\img\\Ezkerretik.bmp"
#define JOKOA_PLAYER_BIRATUATZERA ".\\img\\Atzetik.bmp"
#define JOKOA_BLOKEA_APURTZEKOA ".\\img\\apurtzekoa.bmp"
#define JOKOA_BONBA ".\\img\\Bonba.bmp"
#define JOKOA_EZTANDA ".\\img\\eztanda.bmp"
//SOINUAK--------------------------------------------------
#define BOMBA_SOINUA ".\\sound\\bonba.wav"


int JOKOA_eztandaMarraztu();
int JOKOA_bonbaMarratu();

//BONBA - EZTANDA ETA HAUEN KOLISIOAK BLOKEEKIN ETA ERASOTZAILEEKIN
BONBA_ELEMENTUA BonbarenSorrera(int ebentu, JOKO_ELEMENTUA HULK, BONBA_ELEMENTUA BONBA, BONBA_ELEMENTUA EZTANDA);
BONBA_ELEMENTUA EztandaSorrera(BONBA_ELEMENTUA BONBA, BONBA_ELEMENTUA EZTANDA, JOKO_ELEMENTUA BLOKEAAPURTZEKO, JOKO_ELEMENTUA ETSAIABOB, JOKO_ELEMENTUA ETSAIAKROKO, JOKO_ELEMENTUA HULK);
BONBA_ELEMENTUA KolisioaEztandaBlokea(BONBA_ELEMENTUA EZTANDA, JOKO_ELEMENTUA BLOKEAAPURTZEKO, BONBA_ELEMENTUA BONBA);
BONBA_ELEMENTUA KolisioaEztandaEtsaia(BONBA_ELEMENTUA EZTANDA, BONBA_ELEMENTUA BONBA, JOKO_ELEMENTUA ETSAIABOB, JOKO_ELEMENTUA ETSIAKROKO);
BONBA_ELEMENTUA KolisioaEztandaHulk(BONBA_ELEMENTUA EZTANDA, BONBA_ELEMENTUA BONBA, JOKO_ELEMENTUA HULK);

//HULK FUNTZIOAK---------------------------------------------
int HulkMugimenduaXardatza(int ebentu, int BlokeKolisioaX, BONBA_ELEMENTUA BONBA, int ApurtzekoaXEzkerretik, int ApurtzekoaXEskumatik);
int HulkMugimenduaYardatza(int ebentu, int BlokeKolisioaY);

int KolisioakErdikoBlokeekinX(int HulkPosX, int HulkPosY);
int KolisioakErdikoBlokeekinY(int HulkPosX, int HulkPosY);
int KolisioakApurtzekoBlokeekinEskumatik(int HulkPosX, int HulkPosY);
int KolisioakApurtzekoBlokeekinEzkerretik(int HulkPosX, int HulkPosY);
int KolisioaApurtzekoEtsaiaKroko(int KrokoPosX, int KrokoPosY);

void HasierakoIrudiaKendu(int ebentu, int HulkImg, int Kont);

int JOKOA_jokalariaBiratuAurretik();
int JOKOA_jokalariaBiratuEskuinera();
int JOKOA_jokalariaBiratuEzkerrera();
int JOKOA_jokalariaBiratuAtzera();

#endif // !MUGIMENDUA_H