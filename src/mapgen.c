#include "mapgen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <locale.h>

void generuj_mape(wchar_t **mapa, int szerokosc, int wysokosc, int ilosc_czarnych, int procent_zapelnienia){
    //wstępna generacja mapy - krawędzie i białe pola
    mapa[0][0] = L'┌';
    mapa[0][szerokosc-1] = L'┐';
    mapa[wysokosc-1][0] = L'└';
    mapa[wysokosc-1][szerokosc-1] = L'┘';

    for (int i = 1; i < szerokosc-1; i++){
        mapa[0][i] = L'─';
        mapa[wysokosc-1][i] = L'─';
    }
    for (int i = 1; i < wysokosc-1; i++){
        mapa[i][0] = L'│';
        mapa[i][szerokosc-1] = L'│';
    }

    for (int i = 1; i < wysokosc-1; i++){
        for (int j = 1; j < szerokosc-1; j++){
            mapa[i][j] = L' ';
        }
    }
    
}

void zapelnij_mape(wchar_t **mapa, int szerokosc, int wysokosc, int ilosc_czarnych, int procent_zapelnienia){
    //generator liczb losowych
    srand(time(NULL));
    if (ilosc_czarnych > procent_zapelnienia){
        //generowania wg ilosci czarnych pól

        printf("%d\n", ilosc_czarnych);

    } else{
        //generowanie wg % zapełnienia

        float tmp = szerokosc * wysokosc;
        tmp *= procent_zapelnienia;
        tmp = tmp / 100;
        int ilosc = (int)tmp;

        printf("%d\n", ilosc);

    }

}
