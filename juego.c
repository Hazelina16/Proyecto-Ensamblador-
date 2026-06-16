#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "juego.h"
#include "mapas.h"
#define MAPA_SIZE 60
#define VISTA_SIZE 20

int filaJugador = 1;
int colJugador =1;
int monedas = 0;
int totalMonedas = 0;
int pasos = 0;
bool llave = false;
int nivelActual = 1;

void cargarMapa(char nombreArchivo[]){
    FILE *archivo;

    int i,j;

    archivo = fopen(nombreArchivo, "r");

    if(archivo == NULL){
        printf("No se pudo cargar el mapa\nArchivo: %s\n", nombreArchivo);
        return;
    }
    
    for(i=0; i<60; i++){
        for(j=0; j<60; j++){
            fscanf(archivo, " %c", &mapa[i][j]);
        }
        fscanf(archivo, "%*c");
    }
    totalMonedas = contarCaracteres(&mapa[0][0], 3600, 'M');
    fclose(archivo);
}

void imprimirMapa() {

    int i;
    int j;

    int inicioFila;
    int inicioCol;

    int finFila;
    int finCol;

    inicioFila = filaJugador - (VISTA_SIZE / 2);
    inicioCol = colJugador - (VISTA_SIZE / 2);

    //evitar negativos
    if(inicioFila < 0) {
        inicioFila = 0;
    }
    if(inicioCol < 0) {
        inicioCol = 0;
    }

    //evitar que la vista se salga del mapa
    finFila = inicioFila + VISTA_SIZE;
    finCol = inicioCol + VISTA_SIZE;

    if(finFila > MAPA_SIZE) {
        finFila = MAPA_SIZE;
        inicioFila = MAPA_SIZE - VISTA_SIZE;
    }
    if(finCol > MAPA_SIZE) {
        finCol = MAPA_SIZE;
        inicioCol = MAPA_SIZE - VISTA_SIZE;
    }

    for(i = inicioFila; i < finFila; i++) {
        for(j = inicioCol; j < finCol; j++) {
            if(i == filaJugador && j == colJugador) {
                printf("P ");
            }
            else {
                printf("%c ", mapa[i][j]);
            }
        }
        printf("\n");
    }
    printf("\nMonedas: %d/%d\n", monedas, totalMonedas);
    printf("Pasos: %d\n", pasos);
    printf("Celdas libres: %d\n", contarCeldasLibres(&mapa[0][0], 3600));
    printf("Puntaje: %d\n", calcularPuntaje(monedas, pasos, nivelActual));
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

    if(detectarObjeto(&mapa[0][0], 60, nuevaFila, nuevaCol, 'M')){
        monedas++;
        mapa[nuevaFila][nuevaCol] = '.';
    }
    if(detectarObjeto(&mapa[0][0], 60, nuevaFila, nuevaCol, 'K')){
        llave = true;
        mapa[nuevaFila][nuevaCol] = '.';
    }
    if(detectarObjeto(&mapa[0][0], 60, nuevaFila, nuevaCol, 'D')) {
        if(llave) {
            filaJugador = nuevaFila;
            colJugador = nuevaCol;
        }
        else {
            printf("\nNecesitas la llave!\n");
        }
        return;
    }
    if(detectarObjeto(&mapa[0][0], 60, nuevaFila, nuevaCol, 'X')) {
        nivelActual++;
        if(nivelActual == 2) {
            printf("\nNivel 1 completado! Pasando al nivel 2...\n");
            cargarMapa("mapas/nivel2.txt");
        }
        else if(nivelActual == 3) {
            printf("\nNivel 2 completado! Pasando al nivel 3...\n");
            cargarMapa("mapas/nivel3.txt");
        }
        else {
            printf("\nGANASTE TODO EL JUEGO\n");
            exit(0);
        }
        filaJugador = 1;
        colJugador = 1;
        llave = false;
        return;
    }
    if(!validarMovimiento(&mapa[0][0], 60, nuevaFila, nuevaCol)){
        printf("No puedes pasar por una pared!\n");
        return;
    }

    pasos++;
    filaJugador = nuevaFila;
    colJugador = nuevaCol;
}