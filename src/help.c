#include <stdio.h>
#include "help.h"

void pomoc(){
    printf("Pomoc programu: \n");
    printf("Dostępne paramtry oraz ich opis:\n");
    printf("-h - wyświetla pomoc\n");
    printf("-w - określa wysokość mapy - parametr wymagany jeżeli nie wczytuje się mapy z pliku\n");
    printf("-s - określa szerokość mapy - parametr wymagany jeżeli nie wczytuje się mapy z pliku\n");
    printf("-i - określa liczbę iteracji - domyślna wartość 1\n");
    printf("-k - określa w którą stronę na początku będzie skierowana mrówka - parametr wymagany jeżeli nie wczytuje się mapy z pliku\n");
    printf("-o - określa schemat nazywania plików wyjściowych - paramtr opcjonalny - wartość domyślna stdout\n");
    printf("-z - określa plik z którego ma być wczytana mapa - parametr opcjonalny - jeżeli nie podany program generuje mapę wg. parametrów\n");
    printf("-c - określa procent lub ilość czarnych pól na mapie - parametr wymagany jeżeli nie wczytuje się mapy z pliku\n");
    printf("\n");
    printf("Jeżeli podano parametr -z, to parametry -w, -s, -c,-k są ignorowane\n");
    printf("Jeżeli podano parametr -c, to parametr -z jest ignorowany\n");
    printf("\n");
    printf("Przykładowe wywołanie programu: ./run -w 10 -s 10 -i 100 -k n -o stdout -c 50\n");
    printf("Program wygeneruje mapę o wymiarach 10x10, wykona 100 iteracji, mrówka będzie skierowana na północ, wyjście zostanie wyświetlone na ekranie, a na mapie będzie 50%% czarnych pól\n");
}