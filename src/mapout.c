#include "mapout.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>


void wypisz_mape (wchar_t **mapa, int szerokosc, int wysokosc){
    for (int i = 0; i < wysokosc; i++){
        for(int j = 0; j < szerokosc; j++){
            printf("%lc", mapa[i][j]);
        }
        printf("\n");
    }
}