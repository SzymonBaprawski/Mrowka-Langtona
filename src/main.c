#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //getopt
#include <string.h>

int main(int argc, char **argv){
    //deklaracja zmiennych
    int szerokosc = 0;
    int wysokosc = 0;
    int iteracje = 0;
    char wyjscie = 's';
    char nazwa_pliku_wyjsciowego[100] = "iteracja: ";
    char kierunek = 'N'; //North, East, South, East
    char plik_mapy[100] = "mapa.txt";
    double procent_zapelnienia = 0;
    int ilosc_czarnych = 0;



    //obłsługa argumentów
    int opt;
    while((opt = getopt(argc, argv, "hs:w:i:k:z:o:p:l:")) != -1){
        switch(opt){
            case 's':
                szerokosc = atoi(optarg);
                break;
            case 'w':
                wysokosc = atoi(optarg);
                break;
            case 'i':
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
                //wyświetelenie pomocy
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
                        break;
                    }else{
                        printf("Błąd określeniu miejsca do wypisania");
                        break;
                    }
            case 'p': //procent czarnych pól
                if(optarg != NULL){
                    procent_zapelnienia = atof(optarg);
                    break;
                } else{
                    printf("Nieprawidłowy procent\n");
                    return 0;
                }
            case 'l': //liczba czarnych pól
                if(optarg != NULL){
                    ilosc_czarnych = atoi(optarg);
                    break;
                } else{
                    printf("Nieprawidłowa ilość pól\n");
                    return 0;
                }
                
        }
    }

    //test wczytania parametrów
    printf("%d %d %d %c %s %s %d %lf\n", szerokosc, wysokosc, iteracje, kierunek, nazwa_pliku_wyjsciowego, plik_mapy, ilosc_czarnych, procent_zapelnienia);

    return 0;
}