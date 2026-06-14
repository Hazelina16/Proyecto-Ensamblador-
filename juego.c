#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "juego.h"
#include "mapas.h"

int filaJugador = 1;
int colJugador =1;
int monedas = 0;
bool llave = false;

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
    printf("\nMonedas: %d\n", monedas);
    printf("Llave: ");
    if(llave){
        printf("1\n");
    }else{
        printf("0\n");
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

    if(mapa[nuevaFila][nuevaCol] == 'K'){
        llave = true;
        mapa[nuevaFila][nuevaCol] = '.';
    }
    if(mapa[nuevaFila][nuevaCol] == 'D' && llave){
        printf("Has ganado!\n");
        exit(0);
    }else if(mapa[nuevaFila][nuevaCol] == 'D' && !llave){
        printf("Encuentra la llave!\n");
        return;
    }
    if(mapa[nuevaFila][nuevaCol] != '#'){
        if(mapa[nuevaFila][nuevaCol] == 'M'){
        monedas++;
        mapa[nuevaFila][nuevaCol] = '.';
        }
        filaJugador = nuevaFila;
        colJugador = nuevaCol;
    }
}