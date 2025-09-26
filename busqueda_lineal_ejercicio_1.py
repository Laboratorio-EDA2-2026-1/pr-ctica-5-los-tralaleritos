def busqueda_lineal(arr, num):
    if num in arr:
        return f"El numero que buscas esta en el indice: {arr.index(num)}"
    else:
        return f"El numero que buscas no esta en el arreglo"


arreglo = [12,3434,678,14,789,1,6,8,9,0,11]

print(busqueda_lineal(arreglo, 14))








// Escribe aquí la implementación de los ejercicios de búsqueda lineal.
#include <stdio.h>

int busqueda_lineal_cent(int arr[], int n, int clave) {

    int temp = arr[n-1];
    arr[n-1] = clave; 
    
    int i = 0;
    while (arr[i] != clave) {
        i++;
    }

    arr[n-1] = temp;
    
    if (i < n-1 || arr[n-1] == clave) {
        return i;
    }
    
  
    return -1;
}


void imprimir(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {34, 12, 78, 56, 89, 23, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    int clave = 56;

    printf("Array: ");
    imprimir(arr, n);

    int resultado = busqueda_lineal_cent(arr, n, clave);

    if (resultado != -1) {
        printf("Elemento %d encontrado en el índice %d\n", clave, resultado);
    } else {
        printf("Elemento %d no encontrado\n", clave);
    }

    return 0;
}
