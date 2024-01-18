#include "mrowka.h"
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

int przesun_mrowke(wchar_t **mapa, int szerokosc, int wysokosc, int *x, int *y, char *kierunek){
    
    if (mapa[*y][*x] == L'█'){
        if (*kierunek == 'N'){
            *kierunek = 'E';
        } else if (*kierunek == 'E'){
            *kierunek = 'S';
        } else if (*kierunek == 'S'){
            *kierunek = 'W';
        } else if (*kierunek == 'W'){
            *kierunek = 'N';
        }
        mapa[*y][*x] = L' ';
    }
    else{
        if (*kierunek == 'N'){
            *kierunek = 'W';
        } else if (*kierunek == 'E'){
            *kierunek = 'N';
        } else if (*kierunek == 'S'){
            *kierunek = 'E';
        } else if (*kierunek == 'W'){
            *kierunek = 'S';
        }
        mapa[*y][*x] = L'█';
    }

    if (*kierunek == 'N'){
        if (*y == 0){
            return 1;
        }
        else{
            *y = *y - 1;
        }
    }
    else if (*kierunek == 'E'){
        if (*x == szerokosc - 1){
            return 1;
        }
        else{
            *x = *x + 1;
        }
    }
    else if (*kierunek == 'S'){
        if (*y == wysokosc - 1){
            return 1;
        }
        else{
            *y = *y + 1;
        }
    }
    else if (*kierunek == 'W'){
        if (*x == 0){
            return 1;
        }
        else{
            *x = *x - 1;
        }
    }
    
    return 0;
}