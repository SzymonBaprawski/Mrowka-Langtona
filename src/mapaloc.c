#include <stdlib.h>
#include <wchar.h>

wchar_t** alokuj_mape(int szerokosc, int wysokosc) {
    wchar_t** mapa = (wchar_t**)malloc(wysokosc * sizeof(wchar_t*));
    for (int i = 0; i < wysokosc; i++) {
        mapa[i] = (wchar_t*)malloc(szerokosc * sizeof(wchar_t));
    }
    return mapa;
}

void zwolnij_mape(wchar_t** mapa, int wysokosc) {
    for (int i = 0; i < wysokosc; i++) {
        free(mapa[i]);
    }
    free(mapa);
}