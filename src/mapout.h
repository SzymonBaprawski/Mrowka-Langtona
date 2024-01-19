#ifndef _MAPOUT_H
#define _MAPOUT_H
#include <stddef.h>
#include <wchar.h>

void wypisz_mape_z_pliku (wchar_t **mapa, int szerokosc, int wysokosc, int mrowka_x, int mrowka_y, char kierunek);

void wypisz_mape(wchar_t **mapa, int szerokosc, int wysokosc, int mrowka_x, int mrowka_y, char kierunek);

void zapisz_do_pliku(wchar_t **mapa, int szerokosc, int wysokosc, int mrowka_x, int mrowka_y, char kierunek, char *nazwa, int iteracje);

void zapisz_do_pliku2(wchar_t **mapa, int szerokosc, int wysokosc, int mrowka_x, int mrowka_y, char kierunek, char *nazwa, int iteracje);

void map_out(wchar_t **mapa, int szerokosc, int wysokosc, int mrowka_x, int mrowka_y, char kierunek, int tryb, char wyjscie, char *nazwa, int iteracje);

#endif
