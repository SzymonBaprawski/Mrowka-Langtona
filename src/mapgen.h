#ifndef _MAPGEN_H
#define _MAPGEN_H
#include <stddef.h>

//generator mapy
void generuj_mape (wchar_t **mapa, int szerokosc, int wysokosc, int ilosc_czarnych, int procent_zapelnienia);
void zapelnij_mape (wchar_t **mapa, int szerokosc, int wysokosc, int ilosc_czarnych, int procent_zapelnienia);

#endif
