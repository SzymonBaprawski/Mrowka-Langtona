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
    int szerokosc = 0;
    int wysokosc = 0;
    int iteracje = 1;
    char wyjscie = 's';
    char nazwa_pliku_wyjsciowego[100] = "iteracja: ";
    char kierunek = 'N'; //North, East, South, East
    char plik_mapy[100] = "mapa.txt";
    double procent_zapelnienia = 0;
    int ilosc_czarnych = 0;
    char mapa_z_pliku = '0';
    struct mrowka mrowka;
    enum ways way = N;


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
                        mapa_z_pliku = '1';
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
            //wczytanie mapy z pliku i ustawienie rozmiarów planszy

    } else if (szerokosc == 0 || wysokosc == 0  ){
        int x = szerokosc/2;
        int y = wysokosc/2;
        szerokosc += 2; //+2 na krawędzie
        wysokosc += 2;

        //alokacja pamięci na mapę
        mapa = alokuj_mape(szerokosc, wysokosc);

        //generowanie mapy
        generuj_mape(mapa, szerokosc, wysokosc, ilosc_czarnych, procent_zapelnienia);

        //zapelnienie mapy czarnymi polami
        zapelnij_mape(mapa, szerokosc, wysokosc, ilosc_czarnych, procent_zapelnienia);
        mrowkaStart(mrowka,x,y,)
    }



    for (int i = 0; i < iteracje; i++){
        drawMrowka(mrowka, mapa);
        wypisz_mape(mapa, szerokosc, wysokosc);
        moveMrowka(mrowka,mapa);
        //generowanie kolejnej iteracji
    }


    //zwolnienie pamięci
    zwolnij_mape(mapa, wysokosc);
    
    return 0;
}