//================================================================
// Nome Do Arquivo: quick.c
// File Name: quick.c
//
// Descrição: Implementação do algoritmo quicksort
// Description: Quick sort Algorithm
//================================================================

// Libs
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define uma constante
// Define a constant


// Protótipo da função de ordenação
// Ordination function prototype
void quick_sort(int *a, int left, int right);

// Função main
// Main Function
int main(int argc, char** argv)
{
 int i,SIZE=1000, vet[SIZE];

 // Lê MAX ou 10 valores
 // Read MAX or 10 values
 for(int i = 0; i < SIZE; i++){
        vet[i] = rand()%SIZE;
    }

    clock_t tStart = clock();
     quick_sort(vet, 0, SIZE);
    clock_t timer = (clock() - tStart)/(CLOCKS_PER_SEC/1000);
	printf("time: %d msec " , timer);
 // Ordena os valores
 // Order values
 quick_sort(vet, 0, SIZE-1);

 // Imprime os valores ordenados
 // Print values in order ascendant
 printf("\nValores ordenados\n");
 for(i = 0; i < SIZE; i++)
 {
  printf("%d ", vet[i]);
 }
 return 0;
}

// Função de Ordenação por Seleção
// Quick sort function
void quick_sort(int *a, int left, int right) {
	int i, j, x, y;
	
	i = left;
	j = right;
	x = a[(left + right) / 2];
	
	while(i <= j) {
		while(a[i] < x && i < right) {
			i++;
		}
		while(a[j] > x && j > left) {
			j--;
		}
		if(i <= j) {
			y = a[i];
			a[i] = a[j];
			a[j] = y;
			i++;
			j--;
		}
	}
	
	if(j > left) {
		quick_sort(a, left, j);
	}
	if(i < right) {
		quick_sort(a, i, right);
	}
}
