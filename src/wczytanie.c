
#include "wczytanie.h"
#include <stdio.h>

int wczytanieMapy(char *nazwa, wchar_t mapa[MAX_ROWS][MAX_COLUMNS], int rows, int columns){
    FILE *f = fopen(nazwa, "r");
    if(f == NULL){
        printf("Nie udalo sie wczytac pliku");
        return -1;
    }
    fscanf(f,"%d,%d",rows,columns);

    for(int i=0; i<rows;i++){
        for(int j=0; j<columns; j++){
            if(fscanf(f,"%ls",&mapa[i][j])!=1){
                fclose(f);
                return -1;
            }
        }
    }
    fclose(f);
    return 0;
}

