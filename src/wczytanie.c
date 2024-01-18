
#include "wczytanie.h"
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

int wymiary(char *nazwa, int *szerokosc, int *wysokosc){
    FILE *plik;
    plik = fopen(nazwa, "r");
    int i = 0;
    int j = 0;
    while (fscanf(plik, "%lc", &j) != EOF){
        if (j == L'\n'){
            *szerokosc = i;
            i = 0;
        }
        else{
            i++;
        }
    }
    *wysokosc = j;
    fclose(plik);
    return 0;
}

void wczytanieMapy(char *nazwa, wchar_t **mapa, int *szerokosc, int *wysokosc){
    FILE *plik;
    plik = fopen(nazwa, "r");
    for (int i = 0; i < *wysokosc; i++){
        for (int j = 0; j < *szerokosc; j++){
            fscanf(plik, "%lc", &mapa[i][j]);
        }
    }
    fclose(plik);        
}


void znajdz_mrowke(wchar_t **mapa, int szerokosc, int wysokosc, int *x, int *y, char *kierunek){
    for (int i = 0; i < wysokosc; i++){
        for (int j = 0; j < szerokosc; j++){
            if (mapa[i][j] == L'▲' || mapa[i][j] == L'▶' || mapa[i][j] == L'▼' || mapa[i][j] == L'◀' || mapa[i][j] == L'△' || mapa[i][j] == L'▷' || mapa[i][j] == L'▽' || mapa[i][j] == L'◁'){
                *x = j;
                *y = i;
                if (mapa[i][j] == L'▲'){
                    *kierunek = 'N';
                }
                else if (mapa[i][j] == L'▶'){
                    *kierunek = 'E';
                }
                else if (mapa[i][j] == L'▼'){
                    *kierunek = 'S';
                }
                else if (mapa[i][j] == L'◀'){
                    *kierunek = 'W';
                }
                else if (mapa[i][j] == L'△'){
                    *kierunek = 'N';
                }
                else if (mapa[i][j] == L'▷'){
                    *kierunek = 'E';
                }
                else if (mapa[i][j] == L'▽'){
                    *kierunek = 'S';
                }
                else if (mapa[i][j] == L'◁'){
                    *kierunek = 'W';
                }
            }
        }
    }
}
