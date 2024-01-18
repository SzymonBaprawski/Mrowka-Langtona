//
// Created by Bartek on 1/18/2024.
//

#ifndef SRC_WCZYTANIE_H
#define SRC_WCZYTANIE_H
#include <wchar.h>
#include <locale.h>

int wymiary(char *nazwa, int *szerokosc, int *wysokosc);

void wczytanieMapy(char *nazwa, wchar_t **mapa, int *szerokosc, int *wysokosc);

void znajdz_mrowke(wchar_t **mapa, int szerokosc, int wysokosc, int *x, int *y, char *kierunek);

#endif //SRC_WCZYTANIE_H
