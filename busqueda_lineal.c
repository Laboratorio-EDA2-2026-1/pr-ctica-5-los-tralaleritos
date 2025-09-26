// Escribe aquí la implementación de los ejercicios de búsqueda lineal.

#include <stdio.h>
int busqueda_lineal_recursiva(int A[], int n, int k, int indice) {
    if (indice >= n) {
        return -1;
    }

    if (A[indice] == k) {
        return indice;
    }
    return busqueda_lineal_recursiva(A, n, k, indice + 1);
}

int main() {
    int A[] = {5, 7, 0, -1, 45, -5, 23};
    int n = sizeof(A) / sizeof(A[0]);
    int k = -5;

    printf("Arreglo en el que se buscará el elemento:\n");
    for (int i = 0; i < n; i++) {
       printf("%d ", A[i]);
    }
    printf("\n");

    int indice = busqueda_lineal_recursiva(A, n, k, 0);

    printf("Por busqueda lineal recursiva:\n");

    if (indice == -1) {
        printf("Elemento %d no encontrado", k);
    } else {
        printf("Elemento %d encontrado en el indice %d\n", k, indice);
    }

    return 0;

}
