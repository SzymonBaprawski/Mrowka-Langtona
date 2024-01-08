#include "mapgen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generuj_mape(char **mapa, int szerokosc, int wysokosc, int ilosc_czarnych, int procent_zapelnienia){
    //wstępna generacja mapy - krawędzie i białe pola
}

void zapelnij_mape(char **mapa, int szerokosc, int wysokosc, int ilosc_czarnych, int procent_zapelnienia){
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
