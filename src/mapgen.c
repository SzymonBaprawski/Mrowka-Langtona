#include "mapgen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generuj_mape (char (*mapa)[], int szerokosc, int wysokosc, int ilosc_czarnych, int procent_zapelnienia){
    if (ilosc_czarnych > procent_zapelnienia){
        //generowania wg ilosci czarnych pól

        printf("%d\n", ilosc_czarnych);

        for (int i = 0; i < ilosc_czarnych; i++){

        }
    } else{
        //generowanie wg % zapełnienia

        float tmp = szerokosc * wysokosc;
        tmp *= procent_zapelnienia;
        tmp = tmp / 100;
        int ilosc = (int)tmp;

        printf("%d\n", ilosc);

        for(int i = 0; i < ilosc; i++){

        }
    }

}
