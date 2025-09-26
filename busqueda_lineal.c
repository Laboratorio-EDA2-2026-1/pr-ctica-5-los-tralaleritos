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
    
    //Creamos un arreglo random
	int arr[] = {1,2,3,4,5, 2 ,6,7,8};

	int busq = 2;
	int i = 0;

	//Busqueda lineal Normal
	printf("Implementacion de la busqueda lineal: \n");
	for(i = 0; i < sizeof(arr); i++){
		if(arr[i] == busq){
			printf("Se encontro en la posicion [%d] el numero: %d\n", i, arr[i]);
		}

		if(i == 8){
			break;
		}
	}

	//Busqueda lineral mejorada
	printf("Implementacion de la busqueda lineal mejorada: \n");
	for(i = 0; i < sizeof(arr); i++){
		if(arr[i] == busq){
			printf("Se encontro en la posicion [%d] el numero: %d\n", i, arr[i]);
			break;
		}
	}
    
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
