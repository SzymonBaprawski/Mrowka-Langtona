#include "mapout.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>


void wypisz_mape (wchar_t **mapa, int szerokosc, int wysokosc, int mrowka_x, int mrowka_y, char kierunek){
    for (int i = 0; i < wysokosc; i++){
        for(int j = 0; j < szerokosc; j++){
            if (i == mrowka_y && j == mrowka_x){
                if (kierunek == 'N'){
                    printf("%lc", L'▲');
                }
                else if (kierunek == 'E'){
                    printf("%lc", L'▶');
                }
                else if (kierunek == 'S'){
                    printf("%lc", L'▼');
                }
                else if (kierunek == 'W'){
                    printf("%lc", L'◀');
                }
            }
            else{
                printf("%lc", mapa[i][j]);
            }

        }
        printf("\n");
    }
}