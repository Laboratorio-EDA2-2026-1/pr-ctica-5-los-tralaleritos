//Implementa el algoritmo de búsqueda binaria (recuerda que es un algoritmo recursivo).

#include <stdio.h>
#include <stdlib.h> 


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


int esta_ordenado(int A[], int n) {
    for (int i = 1; i < n; i++) {
        if (A[i - 1] > A[i]) {
            return 0; 
        }
    }
    return 1;
}

int main() {
    int A[] = {-5, -1, 0, 7, 23, 45};
    int n = sizeof(A) / sizeof(A[0]);
    int x = 0;

    if (esta_ordenado(A, n) == 0) {
        printf("El arreglo no está ordenado. Implementar un algoritmo de ordenamiento.\n");
        
    } else {
        printf("El arreglo está ordenado.\n");
        printf("Arreglo en el que se buscará el elemento:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", A[i]);
        }
        printf("\n");
    
        int indice = busqueda_binaria(A, 0, n - 1, x);
    
        if (indice == -1) {
            printf("Elemento %d no encontrado\n", x);
        } else {
            printf("Elemento %d encontrado en el indice %d\n", x, indice);
        }
    }
    
    return 0;
    
}
