/* programa_merge_02.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void mergesort(int v[],int inicio,int im)
{
int i,j,k,meio,*auxiliar;
if(inicio == im)
{ 
return;
}
/* ordenação recursiva das duas metades */
meio = (inicio+im)/2;
mergesort(v,inicio,meio);
mergesort(v,meio+1,im);

/* intercalação no vetor temporário auxiliar */
i = inicio;
j = meio+1;
k = 0;
auxiliar = (int *) malloc(sizeof(int) * (im-inicio+1));
while(i<meio+1 || j<im+1)
{
if( i == meio+1) /* i passou do inal da primeira metade, pegar v[j] */
{
auxiliar[k] = v[j];
j++; k++;
}
else if ( j == im+1) /* j passou do inal da segunda metade, pegar v[i] */
{
auxiliar[k] = v[i];
i++; k++;
}
else if (v[i] < v[j]) /* v[i]<v[j], pegar v[i] */
{
auxiliar[k] = v[i];
i++; k++;
}
else /* v[j]<=v[i], pegar v[j] */
{

auxiliar[k] = v[j];
j++; k++;
}
}
/* copia vetor intercalado para o vetor original */
for( i=inicio; i<=im; i++)
{
v[i] = auxiliar[i-inicio];
}
free(auxiliar);
return ;
}
int main(void)
{
int iContador;
int SIZE=100000;
int aMerge[SIZE];
mergesort(aMerge, 0, SIZE);

for(int i = 0; i < SIZE; i++){
        aMerge[i] = rand()%SIZE;
    }

    clock_t tStart = clock();
     mergesort(aMerge, 0, SIZE);
    clock_t timer = (clock() - tStart)/(CLOCKS_PER_SEC/1000);


printf("Ordenado:");
for(iContador = 0; iContador < SIZE; iContador++)
{
printf(" %d ", aMerge[iContador] );
}
printf("time: %d msec " , timer);
printf("\n");
 return 0;
}
