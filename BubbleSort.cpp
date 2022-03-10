#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void bubble( int piItem[], int iQtdElementos ) { 

    register int i,j; 
    register int iAux; 
    bool bTroca; 

    for(i=1;i<iQtdElementos;i++) { 

        bTroca = 0;
        for(j=iQtdElementos-1;j>=i;j--) { 

            if(piItem[j-1] > piItem[j]) { 

                iAux = piItem[j-1]; 
                piItem[j-1] = piItem[j]; 
                piItem[j] = iAux; 
                bTroca = 1;
            } 
        } 
        if( !bTroca ) { return; } 
    } 
    return; 
} 

int main(void) { 

    int iContador; 
    int const SIZE = 10;

    int aBubble[SIZE];

    for(int i = 0; i < SIZE; i++){
        aBubble[i] = rand()%SIZE;
    }

    clock_t tStart = clock();
    bubble(aBubble, SIZE);
    clock_t timer = (clock() - tStart)/(CLOCKS_PER_SEC/1000);

    printf("Ordenado:"); 

    for(iContador = 0; iContador < SIZE; iContador++) { 
        printf(" %d ", aBubble[iContador] ); 
    }  
    printf("\n");
    printf("time: %d msec", timer);
    return 0; 
}
