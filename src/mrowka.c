#include "mrowka.h"
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

void mrowkaStart(struct mrowka m, int a, int b, enum ways w){
    m.x = a;
    m.y =b;
    m.way = w;
}
void moveMrowka(struct mrowka m, wchar_t **mapa){
    if(mapa[m.x][m.y]==L'▲'||mapa[m.x][m.y]==L'▼'||mapa[m.x][m.y]==L'◀'||mapa[m.x][m.y]==L'▶'){
        switch (m.way) {
            case N:
                m.way = W;
                m.x--;
                break;
            case S:
                m.way = E;
                m.x++;
                break;
            case W:
                m.way = S;
                m.y++;
                break;
            case E:
                m.way = N;
                m.y--;
                break;

            
        }
    }else if(mapa[m.x][m.y]==L'△'||mapa[m.x][m.y]==L'▽'||mapa[m.x][m.y]==L'◁'||mapa[m.x][m.y]==L'▷'){
        switch (m.way) {
            case N:
                m.way = E;
                m.x++;
                break;
            case S:
                m.way = W;
                m.x--;
                break;
            case W:
                m.way = S;
                m.y++;
                break;
            case E:
                m.way = N;
                m.y--;
                break;


        }
    }else
        printf("zle");
}
void drawMrowka(struct mrowka m, wchar_t **mapa){
    if(mapa[m.x][m.y]==L'█'){
        switch (m.way) {
            case N:
                mapa[m.x][m.y]=L'▲';
                break;
            case S:
                mapa[m.x][m.y]=L'▼';
                break;
            case W:
                mapa[m.x][m.y]=L'◀';
                break;
            case E:
                mapa[m.x][m.y]=L'▶';
                break;


        }
    }else if(mapa[m.x][m.y]==L' '){
        switch (m.way) {
            case N:
                mapa[m.x][m.y]=L'△';
                break;
            case S:
                mapa[m.x][m.y]=L'▽';
                break;
            case W:
                mapa[m.x][m.y]=L'◁';
                break;
            case E:
                mapa[m.x][m.y]=L'▷';
                break;

        }

    }
}
