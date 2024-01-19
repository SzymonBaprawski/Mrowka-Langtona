#include "mrowka.h"
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

int przesun_mrowke(wchar_t **mapa, int szerokosc, int wysokosc, int *x, int *y, char *kierunek){
    if (*x == 0 || *x == szerokosc-1 || *y == 0 || *y == wysokosc-1){
        return 1;
    }
    if (mapa[*y][*x] == L'█'){
        if (*kierunek == 'N'){
            *kierunek = 'E';
            mapa[*y][*x] = L' ';
            *x += 1;
            return 0;
        }
        else if (*kierunek == 'E'){
            *kierunek = 'S';
            mapa[*y][*x] = L' ';
            *y += 1;
            return 0;
        }
        else if (*kierunek == 'S'){
            *kierunek = 'W';
            mapa[*y][*x] = L' ';
            *x -= 1;
            return 0;
        }
        else if (*kierunek == 'W'){
            *kierunek = 'N';
            mapa[*y][*x] = L' ';
            *y -= 1;
            return 0;
        }
    }
    else if (mapa[*y][*x] == L' '){
        if (*kierunek == 'N'){
            *kierunek = 'W';
            mapa[*y][*x] = L'█';
            *x -= 1;
            return 0;
        }
        else if (*kierunek == 'E'){
            *kierunek = 'N';
            mapa[*y][*x] = L'█';
            *y -= 1;
            return 0;
        }
        else if (*kierunek == 'S'){
            *kierunek = 'E';
            mapa[*y][*x] = L'█';
            *x += 1;
            return 0;
        }
        else if (*kierunek == 'W'){
            *kierunek = 'S';
            mapa[*y][*x] = L'█';
            *y += 1;
            return 0;
        }
    }
}