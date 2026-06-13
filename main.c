#include <stdio.h>
extern long long sumar();

int main() {

    long long resultado;

    resultado = sumar();

    printf("Resultado: %lld\n", resultado);

    return 0;
}
