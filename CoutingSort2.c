#include <stdio.h>
#include <stdlib.h>

// Definimos los colores como constantes simbólicas
#define ROJO 0
#define BLANCO 1
#define AZUL 2

// Función para ordenar con Counting Sort especializado
void ordenarColores(int arreglo[], int size) {
    // Contadores de cada color
    int contadorRojo = 0, contadorBlanco = 0, contadorAzul = 0;

    // Paso 1: Contar cuántos hay de cada color
    for (int i = 0; i < size; i++) {
        if (arreglo[i] == ROJO)
            contadorRojo++;
        else if (arreglo[i] == BLANCO)
            contadorBlanco++;
        else if (arreglo[i] == AZUL)
            contadorAzul++;
        else {
            printf("Error: Valor %d no corresponde a un color válido (0=Rojo, 1=Blanco, 2=Azul)\n", arreglo[i]);
            return;
        }
    }

    // Paso 2: Sobrescribir el arreglo en orden rojo → blanco → azul
    int indice = 0;
    for (int i = 0; i < contadorRojo; i++)
        arreglo[indice++] = ROJO;
    for (int i = 0; i < contadorBlanco; i++)
        arreglo[indice++] = BLANCO;
    for (int i = 0; i < contadorAzul; i++)
        arreglo[indice++] = AZUL;
}

int main() {
    int size;

    printf("Ingresa el tamaño del arreglo:\n");
    scanf("%d", &size);

    // Reservamos memoria dinámicamente
    int *arreglo = (int *)malloc(size * sizeof(int));
    if (arreglo == NULL) {
        printf("Memoria insuficiente\n");
        return -1;
    }

    // Llenamos el arreglo
    for (int i = 0; i < size; i++) {
        printf("Ingresa el valor %d (0=Rojo, 1=Blanco, 2=Azul):\n", i + 1);
        scanf("%d", &arreglo[i]);
    }

    // Mostramos el arreglo original
    printf("Arreglo original:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arreglo[i]);
    }

    // Ordenamos con Counting Sort especializado
    ordenarColores(arreglo, size);

    // Mostramos el arreglo ordenado
    printf("\nArreglo ordenado (Rojo=0, Blanco=1, Azul=2):\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    free(arreglo);
    return 0;
}
