//
// Created by Bartek on 1/18/2024.
//

#ifndef KOD_MROWKA_H
#define KOD_MROWKA_H

#include <stdio.h>
#include <wchar.h>
#include <locale.h>


enum ways {N,S,E,W};

struct mrowka {
    enum ways way;
    int x,y;
};
void mrowkaStart(struct mrowka m, int a, int b, enum ways w);
void moveMrowka(struct mrowka m, wchar_t **mapa);
void drawMrowka(struct mrowka m, wchar_t **mapa);

#endif //KOD_MROWKA_H
