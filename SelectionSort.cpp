#include <stdio.h> 
#include <stdlib.h> 
#include <sys/time.h>

void selection(int piItem[],int iQtdElementos) { 

    register int i,j, iMinimo, iAux; 

    for( i=0; i<iQtdElementos-1; i++) { 

        iMinimo=i; 
        for( j=i+1; j<iQtdElementos; j++) { 
            if (piItem[j] < piItem[iMinimo]) {

                iMinimo=j; 
            } 
        }

        iAux = piItem[i]; 
        piItem[i] = piItem[iMinimo]; 
        piItem[iMinimo] = iAux; 
    } 
    return; 
} 

int main(void) { 

    int iContador; 
    int const SIZE = 100000;
    
    int aSelect[SIZE];

    for(int i = 0; i < SIZE; i++){
        aSelect[i] = rand()%SIZE;
    }

    clock_t tStart = clock();
    selection(aSelect, SIZE);
    clock_t timer = (clock() - tStart)/(CLOCKS_PER_SEC/1000);

    printf("Ordenado:"); 

    for(iContador = 0; iContador < SIZE; iContador++) { 
        printf(" %d ", aSelect[iContador] ); 
    } 
    printf("\n");
    printf("time: %d msec", timer);
    return 0; 
}
