#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

void bubble( int piItem[], int iQtdElementos ) { 

    register int i,j,x; 
    register int iAux; 
    bool bTroca; 

    for(i=0;i<iQtdElementos;i++) { 

        bTroca = 0;
        for(j=0;j<iQtdElementos;j++) { 

            if(piItem[j] > piItem[j+1]) { 

                iAux = piItem[j+1]; 
                piItem[j+1] = piItem[j]; 
                piItem[j] = iAux; 
                bTroca = 1;
            }
        } 
        for(x=iQtdElementos-1;x<=1;x--) { 

            if(piItem[x-1] > piItem[x]) { 

                iAux = piItem[x-1]; 
                piItem[x-1] = piItem[x]; 
                piItem[x] = iAux; 
                bTroca = 1;
            }
        } 
        if( !bTroca ) { return; } 
    } 
     
} 

int main(void) { 

    int iContador; 
    int SIZE = 1000;

    int aBubble[SIZE];

    for(int i = 0; i < SIZE; i++){
        aBubble[i] = rand()%SIZE;
    }

    clock_t tStart = clock();
    bubble(aBubble, SIZE);
    clock_t timer = (clock() - tStart)/(CLOCKS_PER_SEC/1000);
	printf("time: %d msec", timer);
    
	//printf("Ordenado:"); 

    for(iContador = 0; iContador < SIZE; iContador++) { 
        printf(" %d ", aBubble[iContador] ); 
    }  
    printf("\n");
    
    return 0; 
}
