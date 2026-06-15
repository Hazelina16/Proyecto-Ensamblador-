#include <stdio.h>
#include <stdlib.h>
#include "juego.h"

int main() {

    char tecla;

    cargarMapa("mapas/nivel1.txt");

    while(1){
        imprimirMapa();
        printf("Ingrese una tecla (w/a/s/d para mover, q para salir): \n");
        scanf(" %c", &tecla);
        if(tecla == 'q'){
            break;
        }
        moverJugador(tecla);
    }
    return 0;
}
