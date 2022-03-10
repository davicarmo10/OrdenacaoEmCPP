#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

void insert(int piItem[], int iQtdElementos)
{
register int i,j, iAux;
for( i=1; i<iQtdElementos; i++)
{
iAux = piItem[i];

for( j=i-1; j>=0 && iAux < piItem[j]; j--)
{
piItem[j+1]=piItem[j];
}
piItem[j+1]=iAux;
}
return;
}
int main(void)
{
int iContador;
int SIZE = 100000;
int aInsert[SIZE];
 insert(aInsert, SIZE);
 
 for(int i = 0; i < SIZE; i++){
        aInsert[i] = rand()%SIZE;
    }

    clock_t tStart = clock();
    insert(aInsert, SIZE);
    clock_t timer = (clock() - tStart)/(CLOCKS_PER_SEC/1000);
    
printf("Ordenado:");
for(iContador = 0; iContador < SIZE; iContador++)
{
printf(" %d ", aInsert[iContador] );
}
printf("\n");
printf("time: %d msec", timer);
 return 0;
}

