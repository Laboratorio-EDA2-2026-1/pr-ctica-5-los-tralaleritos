#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int encontrar_maximo(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void radix_couting(int arr[], int n, int exp) {
    int output[n]; 
    int count[10] = {0}; 

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radix_sort(int arr[], int n) {

    int max = encontrar_maximo(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        radix_couting(arr, n, exp);
    }
}

void imprimir(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    
    int arr[] = {111, 3, 777, 96, 1, 1111, 22, 66, 56, 117};
    int n = sizeof(arr) / sizeof(arr[0]);

    
    printf("Array original: ");
    imprimir(arr, n);

    
    radix_sort(arr, n);

    
    printf("Array ordenado: ");
    imprimir(arr, n);

    return 0;
}
