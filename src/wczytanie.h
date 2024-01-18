//
// Created by Bartek on 1/18/2024.
//

#ifndef SRC_WCZYTANIE_H
#define SRC_WCZYTANIE_H
#include <wchar.h>
#define MAX_ROWS 1000
#define MAX_COLUMNS 1000

int wczytanieMapy(char *nazwa, wchar_t mapa[MAX_ROWS][MAX_COLUMNS], int *rows, int *columns);

#endif //SRC_WCZYTANIE_H
