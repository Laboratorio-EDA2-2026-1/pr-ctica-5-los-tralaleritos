// Escribe aquí la implementación de los ejercicios de Counting Sort.

#include <stdio.h>
#include <string.h>

void counting_Sort(char s[], int largo, int max);

void counting_Sort(char s[], int largo, int max){
	int count[max+1];
	int salida[largo];
	int i;

	for(i = 0; i <= max; i++){
		count[i] = 0;
	}

	for(i = 0; i < largo; i++){
		count[s[i]]++;
	}

	for(i = 1; i <= max ; i++){
		count[i] += count[i-1];
	}

	//Recorriendo al reves:
	for(i = largo - 1; i >= 0; i--){
		salida[count[s[i]] - 1] = s[i];
		count[s[i]]--;
	}
	
	for(i = 0; i < largo; i++){
		s[i] = salida[i];
	}


	//Era para ver mi arreglo de count
	for(i = 0; i < largo; i++){
		char caracter = (char)salida[i];
		printf("%c",caracter);
	}
	printf("\n");
	

}

int main(){
	//Cadena
	char s[] = "caracter";
	
	//Consiguiendo el max
	int max = s[0];
	int largo = strlen(s);

	for(int i = 1; i < strlen(s); i++){
		if(max < s[i]){
			max = s[i];
		}

		else{
		}
	}


	counting_Sort(s, largo, max);
}
