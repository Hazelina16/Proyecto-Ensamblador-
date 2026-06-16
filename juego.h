#ifndef JUEGO_H
#define JUEGO_H

void cargarMapa(char nombreArchivo[]);
void imprimirMapa();
void moverJugador(char tecla);
int contarCaracteres(char *mapa,int totalCeldas,char caracter);
int validarMovimiento(char *mapa, int columnas, int fila, int columna);
int calcularPuntaje(int maonedas, int pasos, int niveles);
int detectarObjeto(char *mapa, int columnas, int fila, int columna, char objeto);
int contarCeldasLibres(char *mapa, int totalCeldas);


#endif
