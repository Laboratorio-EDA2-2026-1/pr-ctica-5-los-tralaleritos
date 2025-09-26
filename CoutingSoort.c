#include <stdio.h>
#include <stdlib.h>

int *countingSort(int param[], int size);
int findMax(int arr[], int size);

int main() {
    // Pedimos el tamaño del arreglo y lo llenamos

    printf("ingresa el tamaño del arreglo\n");
    int size;
    scanf("%d", &size);
    int *array = (int *)malloc(size * sizeof(int));
    // Verificamos si el malloc fue exitoso
    if (array == NULL) {
        printf("Memoria insifuciente\n");
        return -1; // Salida si el malloc falla
    } else {
        // Llenamos el arreglo
        for (int i = 0; i < size; i++) {
            printf("ingresa el valor %d del arreglo\n", i + 1);
            scanf("%d", &array[i]);
        }
        printf("Arreglo original:\n");
        for (int i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }
        // Llamamos a la función countingSort
        int *sortedArray = countingSort(array, size);

        // Imprimimos el arreglo ordenado
        printf("\nArreglo ordenado:\n");
        for (int i = 0; i < size; i++) {
            printf("%d ", sortedArray[i]);
        }
        printf("\n");
        free(sortedArray);
        free(array);
    }

    return 0;
}

int *countingSort(int param[], int size) {
    int maximo = findMax(param, size);
    // Creamos un arreglo para contar las ocurrencias
    // El tamañao sera igual al maximo elemento del arreglo que pasamos como parametro
    int *countArray = (int *)malloc((maximo + 1) * sizeof(int));
    if (countArray == NULL) {
        return NULL; //
    }
    // Inicializamos el arreglo de conteo en 0
    for (int i = 0; i <= maximo; i++) {
        countArray[i] = 0;
    }
    // Contamos las ocurrencias de cada elemento
    for (int i = 0; i < size; i++) {
        if (param[i] < 0 || param[i] > maximo) {
            printf("Error: Elemento %d fuera de rango (0-%d)\n", param[i], maximo);
            free(countArray);
            return NULL;
        }
        countArray[param[i]]++;
    }
    // Modificamos el arreglo de conteo para que cada elemento contenga la suma de los elementos anteriores
    for (int i = 1; i <= maximo; i++) {
        countArray[i] += countArray[i - 1];
    }
    // Construimos el arreglo ordenado
    int *sortedArray = (int *)malloc(size * sizeof(int));
    if (sortedArray == NULL) {
        free(countArray);
        return NULL;
    }
 // Llenamos el arreglo ordenado en orden inverso para mantener la estabilidad
    for (int i = size - 1; i >= 0; i--) {
        sortedArray[countArray[param[i]] - 1] = param[i];
        countArray[param[i]]--;
    }
    free(countArray);
    //Retornamos el array sorteado
    return sortedArray;
}
// Funcion para encontrar el maximo elemento en un arreglo
int findMax(int arr[], int size) {
    // Asumimos que el arreglo tiene al menos un elemento
    int max = arr[0];
    // Recorremos el arreglo para encontrar el maximo
    for (int i = 1; i < size; i++) {
        // Si encontramos un elemento mayor, actualizamos max
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;

}
