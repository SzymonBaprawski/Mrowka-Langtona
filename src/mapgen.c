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

void zapelniacz(wchar_t **mapa, int szerokosc, int wysokosc, int ilosc_czarnych){
    //generator liczb losowych
    srand(time(NULL));

    //printf("Ilość czarnych pól: %d\n", ilosc_czarnych);

    //zapelnianie mapy czarnymi polami
    while(ilosc_czarnych > 0){
        int x = rand() % (szerokosc-2) + 1;
        int y = rand() % (wysokosc-2) + 1;
        if (mapa[y][x] == L' '){
            mapa[y][x] = L'█';
        
            ilosc_czarnych--;
        }
    }
}


void zapelnij_mape(wchar_t **mapa, int szerokosc, int wysokosc, int ilosc_czarnych, int procent_zapelnienia){
    //zapelnianie mapy czarnymi polami
    if (procent_zapelnienia == 0){
        int ilosc_pol = (szerokosc-2)*(wysokosc-2);
        if (ilosc_czarnych > ilosc_pol){
            printf("Liczba czarnych pól jest większa niż liczba pól na mapie\n");
            printf("Zmniejszono liczbę czarnych pól do maksymalnej możliwej\n");
            ilosc_czarnych = ilosc_pol;
        }
        zapelniacz(mapa, szerokosc, wysokosc, ilosc_czarnych);
    }
    else{
        int ilosc_pol = (szerokosc-2)*(wysokosc-2);
        ilosc_czarnych = (ilosc_pol*procent_zapelnienia)/100;
        zapelniacz(mapa, szerokosc, wysokosc, ilosc_czarnych);
    }
}
