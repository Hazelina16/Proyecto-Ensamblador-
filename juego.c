#include <stdio.h>
#include "juego.h"
#include "mapas.h"

int filaJugador = 1;
int colJugador =1;

void imprimirMapa(){
    int i;
    int j;

    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            if(i == filaJugador && j == colJugador){
                printf("P ");
            }else{
                printf("%c ", mapa[i][j]);
            }
        }
        printf("\n");
    }
}

void moverJugador(char tecla){
    int nuevaFila = filaJugador;
    int nuevaCol = colJugador; 

    if(tecla == 'w'){
        nuevaFila--;
    }else if(tecla == 's'){
        nuevaFila++;
    }else if(tecla == 'a'){
        nuevaCol--;
    }else if(tecla == 'd'){
        nuevaCol++;
    }
    if(mapa[nuevaFila][nuevaCol] != '#'){
        filaJugador = nuevaFila;
        colJugador = nuevaCol;
    }
}