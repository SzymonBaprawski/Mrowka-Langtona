#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <wchar.h>
#include <locale.h>

#include "mapaloc.h"
#include "mapgen.h"
#include "mapout.h"
#include "help.h"
#include "mrowka.h"
#include "wczytanie.h"

// LINE_VERTICAL:│
// LINE_HORIZONTAL:─
// LINE_DOWN_RIGHT:┌
// LINE_DOWN_LEFT:┐
// LINE_UP_RIGHT:└
// LINE_UP_LEFT:┘
// SQUARE_WHITE: 
// SQUARE_BLACK:█
// ARROW_NORTH_WHITE:△
// ARROW_NORTH_BLACK:▲
// ARROW_EAST_WHITE:▷
// ARROW_EAST_BLACK:▶
// ARROW_SOUTH_WHITE:▽
// ARROW_SOUTH_BLACK:▼
// ARROW_WEST_WHITE:◁
// ARROW_WEST_BLACK:◀

int main(int argc, char **argv){
    //deklaracja zmiennych
    int iteracje = 1;
    int szerokosc =0;
    int wysokosc = 0;
    char wyjscie = 's';
    char nazwa_pliku_wyjsciowego[100] = "iteracja: ";
    char kierunek = 'N'; //North, East, South, East
    char plik_mapy[100] = "mapa.txt";
    double procent_zapelnienia = 0;
    int ilosc_czarnych = 0;
    char mapa_z_pliku = '0';
    int mrowka_x = 0;
    int mrowka_y = 0;


    //ustawienie lokalizacji
    setlocale(LC_ALL, "C.UTF-8");

    //obłsługa argumentów
    int opt;
    while((opt = getopt(argc, argv, "hs:w:i:k:z:o:c:")) != -1){
        switch(opt){
            case 's':
                if (atoi(optarg) < 1){
                    printf("Szerokość nie może być mniejsza od 1 - koniec działania programu\n");
                    return 0;
                }
                szerokosc = atoi(optarg);
                break;
            case 'w':
                if (atoi(optarg) < 1){
                    printf("Wysokość nie może być mniejsza od 1 - koniec działania programu\n");
                    return 0;
                }
                wysokosc = atoi(optarg);
                break;
            case 'i':
                if (atoi(optarg) < 1){
                    printf("Liczba iteracji nie może być mniejsza od 1 - koniec działania programu\n");
                    return 0;
                }
                iteracje = atoi(optarg);
                break;
            case 'k':
                if (optarg != NULL && (strcmp(optarg, "n") == 0 || strcmp(optarg, "N") == 0)) {
                    kierunek = 'N';
                    break;
                } else if (optarg != NULL && (strcmp(optarg, "e") == 0 || strcmp(optarg, "E") == 0)) {
                    kierunek = 'E';
                    break;
                } else if (optarg != NULL && (strcmp(optarg, "w") == 0 || strcmp(optarg, "W") == 0)) {
                    kierunek = 'W';
                    break;
                } else if (optarg != NULL && (strcmp(optarg, "s") == 0 || strcmp(optarg, "S") == 0)) {
                    kierunek = 'S';
                    break;
                } else {
                    printf("Nieprawidłowy argument kierunku - koniec działania programu\n");
                    return 0;
                }
            case 'h':
                pomoc();
                return 1;
                break;
            case 'o':
                if (optarg != NULL && (strcasecmp(optarg, "stdout") == 0)) {
                    wyjscie = 's'; //Wyświetlenie wyjscia
                    break;
                } else {
                    wyjscie = 'p'; //zapis do pliku
                    if (optarg != NULL) {
                        strncpy(nazwa_pliku_wyjsciowego, optarg, sizeof(nazwa_pliku_wyjsciowego) - 1);
                        nazwa_pliku_wyjsciowego[sizeof(nazwa_pliku_wyjsciowego) - 1] = '\0';
                        break;
                    }else{
                        printf("Błąd określeniu miejsca do wypisania");
                        break;
                    }
                }
            case 'z': //plik zródłowy mapy 
                if (optarg != NULL) {
                        strncpy(plik_mapy, optarg, sizeof(plik_mapy) - 1);
                        plik_mapy[sizeof(plik_mapy) - 1] = '\0';
                        mapa_z_pliku = '1';
                        break;
                    }else{
                        printf("Błąd określenia pliku źródłowego mapy");
                        break;
                    }
            case 'c': //procent lub ilosc czarnych pól
                if(optarg != NULL){
                    //jeżeli ostatni znak to %, to parametr przekazany do zmiennej procentowej, jeżeli brak procenta parametr traktowany jako ilość całkowita
                    if (optarg[strlen(optarg) - 1] == '%'){
                        optarg[strlen(optarg) - 1] = '\0';
                        procent_zapelnienia = atof(optarg);
                        //printf("procent %f \n", procent_zapelnienia);
                    } else{
                        ilosc_czarnych = atof(optarg);
                        //printf("liczba %d \n", ilosc_czarnych);
                    }
                    break;
                } else{
                    printf("Nieprawidłowy parametr ilosci czarnych pól\n");
                    return 0;
                }                
        }
    }

    //test wczytania wszystkich parametrów
    printf("Szerokość: %d\n", szerokosc);
    printf("Wysokość: %d\n", wysokosc);
    printf("Ilość iteracji: %d\n", iteracje);
    printf("Kierunek: %c\n", kierunek);
    printf("Wyjście: %c\n", wyjscie);
    printf("Nazwa pliku wyjściowego: %s\n", nazwa_pliku_wyjsciowego);
    printf("Plik mapy: %s\n", plik_mapy);
    printf("Procent zapelnienia: %f\n", procent_zapelnienia);
    printf("Ilość czarnych pól: %d\n", ilosc_czarnych);
    printf("Mapa z pliku: %c\n", mapa_z_pliku);

    //sprawdzenie paramtrów

    wchar_t **mapa;

    if (mapa_z_pliku == '1'){
        if (wymiary(plik_mapy, &szerokosc, &wysokosc) == 1){
            printf("Nie można otworzyć pliku - koniec działania programu\n");
            return 0;
        }
        szerokosc += 2; //+2 na krawędzie
        wysokosc += 2; //+2 na krawędzie

        mapa = alokuj_mape(szerokosc, wysokosc);
        wczytanieMapy(plik_mapy, mapa, &szerokosc, &wysokosc);

        //znalezienie mrówki na mapie, jeżeli jej nie ma, to ustawienie jej na środku
        znajdz_mrowke(mapa, szerokosc, wysokosc, &mrowka_x, &mrowka_y, &kierunek);
        if (mrowka_x == 0 && mrowka_y == 0){
            mrowka_x = szerokosc/2;
            mrowka_y = wysokosc/2;
        } else if (mapa[mrowka_y][mrowka_x] == L'▲' || mapa[mrowka_y][mrowka_x] == L'▶' || mapa[mrowka_y][mrowka_x] == L'▼' || mapa[mrowka_y][mrowka_x] == L'◀'){
            mapa[mrowka_y][mrowka_x] = L'█';
        } else if (mapa[mrowka_y][mrowka_x] == L'△' || mapa[mrowka_y][mrowka_x] == L'▷' || mapa[mrowka_y][mrowka_x] == L'▽' || mapa[mrowka_y][mrowka_x] == L'◁'){
            mapa[mrowka_y][mrowka_x] = L' ';
        }

        wypisz_mape_z_pliku(mapa, szerokosc, wysokosc, mrowka_x, mrowka_y, kierunek);
        for (int i = 0; i < iteracje; i++){
          if (przesun_mrowke(mapa, szerokosc, wysokosc, &mrowka_x, &mrowka_y, &kierunek) == 1){
              printf("Mrowka wyszla poza mape - koniec programu\n");
              return 0;
          }
        wypisz_mape_z_pliku(mapa, szerokosc, wysokosc, mrowka_x, mrowka_y, kierunek);
    }

    } else if (szerokosc != 0 && wysokosc != 0  ){
        szerokosc += 2; //+2 na krawędzie
        wysokosc += 2;

        //alokacja pamięci na mapę
        mapa = alokuj_mape(szerokosc, wysokosc);

        //generowanie mapy
        generuj_mape(mapa, szerokosc, wysokosc, ilosc_czarnych, procent_zapelnienia);

        //zapelnienie mapy czarnymi polami
        zapelnij_mape(mapa, szerokosc, wysokosc, ilosc_czarnych, procent_zapelnienia);

        mrowka_x = szerokosc/2;
        mrowka_y = wysokosc/2;

        wypisz_mape(mapa, szerokosc, wysokosc, mrowka_x, mrowka_y, kierunek);
        for (int i = 0; i < iteracje; i++){
            if (przesun_mrowke(mapa, szerokosc, wysokosc, &mrowka_x, &mrowka_y, &kierunek) == 1){
                printf("Mrowka wyszla poza mape - koniec programu\n");
                return 0;
            }
        wypisz_mape(mapa, szerokosc, wysokosc, mrowka_x, mrowka_y, kierunek);
        }
    } else{
        printf("Nie podano wymiarów mapy - koniec działania programu\n");
        return 0;
    }

    //zwolnienie pamięci
    zwolnij_mape(mapa, wysokosc);
    
    return 0;
}