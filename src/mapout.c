#include "mapout.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>


void wypisz_mape_z_pliku (wchar_t **mapa, int szerokosc, int wysokosc, int mrowka_x, int mrowka_y, char kierunek){
    for (int i = 0; i < wysokosc; i++){
        for (int j = 0; j < szerokosc; j++){
            if (i == mrowka_y && j == mrowka_x && mapa[i][j] == '█'){
                if (kierunek == 'N'){
                    printf("▲");
                }
                else if (kierunek == 'E'){
                    printf("▶");
                }
                else if (kierunek == 'S'){
                    printf("▼");
                }
                else if (kierunek == 'W'){
                    printf("◀");
                }
            }
            else if (i == mrowka_y && j == mrowka_x && mapa[i][j] == ' '){
                if (kierunek == 'N'){
                    printf("△");
                }
                else if (kierunek == 'E'){
                    printf("▷");
                }
                else if (kierunek == 'S'){
                    printf("▽");
                }
                else if (kierunek == 'W'){
                    printf("◁");
                }
            }
            else{
                printf("%lc", mapa[i][j]);
            }
        }
    }
}


void wypisz_mape (wchar_t **mapa, int szerokosc, int wysokosc, int mrowka_x, int mrowka_y, char kierunek){
    for (int i = 0; i < wysokosc; i++){
        for(int j = 0; j < szerokosc; j++){
            if (i == mrowka_y && j == mrowka_x && mapa[i][j] == '█'){
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
            } else if(i == mrowka_y && j == mrowka_x && mapa[i][j] == ' '){
                if (kierunek == 'N'){
                    printf("%lc", L'△');
                }
                else if (kierunek == 'E'){
                    printf("%lc", L'▷');
                }
                else if (kierunek == 'S'){
                    printf("%lc", L'▽');
                }
                else if (kierunek == 'W'){
                    printf("%lc", L'◁');
                }
            } else{
                printf("%lc", mapa[i][j]);

            }
        }
        printf("\n");
    }
}

void zapisz_do_pliku(wchar_t **mapa, int szerokosc, int wysokosc, int mrowka_x, int mrowka_y, char kierunek, char *nazwa, int iteracje){
    char tmp[100];
    sprintf(tmp, "%s%d.txt", nazwa, iteracje);
    FILE *plik = fopen(tmp, "w");
    if (plik == NULL){
        printf("Nie udało się otworzyć pliku - koniec działania programu\n");
        exit(0);
    }
    for (int i = 0; i < wysokosc; i++){
        for (int j = 0; j < szerokosc; j++){
            if (i == mrowka_y && j == mrowka_x && mapa[i][j] == '█'){
                if (kierunek == 'N'){
                    fprintf(plik, "%s", "▲");
                }
                else if (kierunek == 'E'){
                    fprintf(plik, "%s", "▶");
                }
                else if (kierunek == 'S'){
                    fprintf(plik, "%s", "▼");
                }
                else if (kierunek == 'W'){
                    fprintf(plik, "%s", "◀");
                }
            } else if (i == mrowka_y && j == mrowka_x && mapa[i][j] == ' '){
                if (kierunek == 'N'){
                    fprintf(plik, "%s", "△");
                }
                else if (kierunek == 'E'){
                    fprintf(plik, "%s", "▷");
                }
                else if (kierunek == 'S'){
                    fprintf(plik, "%s", "▽");
                }
                else if (kierunek == 'W'){
                    fprintf(plik, "%s", "◁");
                }
            } else{
                fprintf(plik, "%lc", mapa[i][j]);

            }
        }
    }
}

void zapisz_do_pliku2(wchar_t **mapa, int szerokosc, int wysokosc, int mrowka_x, int mrowka_y, char kierunek, char *nazwa, int iteracje){
    char tmp[100];
    sprintf(tmp, "%s%d.txt", nazwa, iteracje);
    FILE *plik = fopen(tmp, "w");
    if (plik == NULL){
        printf("Nie udało się otworzyć pliku - koniec działania programu\n");
        exit(0);
    }
    for (int i = 0; i < wysokosc; i++){
        for (int j = 0; j < szerokosc; j++){
            if (i == mrowka_y && j == mrowka_x && mapa[i][j] == '█'){
                if (kierunek == 'N'){
                    fprintf(plik, "%s", "▲");
                }
                else if (kierunek == 'E'){
                    fprintf(plik, "%s", "▶");
                }
                else if (kierunek == 'S'){
                    fprintf(plik, "%s", "▼");
                }
                else if (kierunek == 'W'){
                    fprintf(plik, "%s", "◀");
                }
            } else if (i == mrowka_y && j == mrowka_x && mapa[i][j] == ' '){
                if (kierunek == 'N'){
                    fprintf(plik, "%s", "△");
                }
                else if (kierunek == 'E'){
                    fprintf(plik, "%s", "▷");
                }
                else if (kierunek == 'S'){
                    fprintf(plik, "%s", "▽");
                }
                else if (kierunek == 'W'){
                    fprintf(plik, "%s", "◁");
                }
            } else{
                fprintf(plik, "%lc", mapa[i][j]);

            }
        }
        fprintf(plik, "\n");
    }
           
}

void map_out(wchar_t **mapa, int szerokosc, int wysokosc, int mrowka_x, int mrowka_y, char kierunek, int tryb, char wyjscie, char *nazwa, int iteracje){
    if (wyjscie == 's'){
        if (tryb == 0){
            wypisz_mape(mapa, szerokosc, wysokosc, mrowka_x, mrowka_y, kierunek);
        }
        else if (tryb == 1){
            wypisz_mape_z_pliku(mapa, szerokosc, wysokosc, mrowka_x, mrowka_y, kierunek);
        }
    }
    else if (wyjscie == 'p'){
        if (tryb == 0){
            zapisz_do_pliku2(mapa, szerokosc, wysokosc, mrowka_x, mrowka_y, kierunek, nazwa, iteracje);
        }
        else if (tryb == 1){
            zapisz_do_pliku(mapa, szerokosc, wysokosc, mrowka_x, mrowka_y, kierunek, nazwa, iteracje);
        }
    }
}