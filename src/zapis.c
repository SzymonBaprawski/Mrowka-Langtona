
#include "zapis.h"
#include <stdio.h>

void zapiszMape(char *nazwa,wchar_t mapa[MAX_ROWS][MAX_COLUMNS],int rows, int columns){
    FILE *f = fopen(nazwa,"w");
    if(f==NULL){
        printf("Nie udalo sie wczytac pliku");
        return;
    }
    fprintf(f,"%d%d\n",rows,columns);
    for(int i=0;i<rows;i++){
        for(int j=0; j<columns;j++){
            fprintf(f,"%ls",mapa[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
}
