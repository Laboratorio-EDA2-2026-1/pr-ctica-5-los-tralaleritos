// Escribe aqui la implementación de los ejercicios de búsqueda binaria.

#include <stdio.h>

int busqueda_binaria(int A[], int indiceIzq, int indiceDer, int x) {
    if (indiceIzq > indiceDer) {
        return -1;
    }

    int medio = indiceIzq + (indiceDer - indiceIzq) / 2;

    if (A[medio] == x) {
        return medio;
    }

    if (x < A[medio]) {
        return busqueda_binaria(A, indiceIzq, medio - 1, x);
    }

    return busqueda_binaria(A, medio + 1, indiceDer, x);
}

int main() {
    int A[] = {5, 7, 0, -1, 45, -5, 23};
    int n = sizeof(A) / sizeof(A[0]);
    int x = -5;

    printf("Arreglo en el que se buscará el elemento:\n");
    for (int i = 0; i < n; i++) {
       printf("%d ", A[i]);
    }
    printf("\n");

    int indice = busqueda_binaria(A, 0, n - 1, x);

    if (indice == -1) {
        printf("Elemento %d no encontrado", x);
    } else {
        printf("Elemento %d encontrado en el indice %d\n", x, indice);
    }

    return 0;

}
