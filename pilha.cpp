#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 50

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//push - coloca um elemento da pilha
	//pop - retira um elemento da pilha
	//size - retorna o tamanho a pilha
	//stackpop - retorna um elemento ao topo, sem remove-lo
	//empty - retorna se a pilha esta vazia

typedef struct pilha {
	
	int topo;
	int elementos [TAMANHO];
	
} pilha;


int empty (pilha *p) {
	if(p->topo == -1) 
		return 1;
	return 0;
}

int size (pilha *p) {
	return p->topo+1;
}

int stackpop(pilha *p) {
	return p->elementos[p->topo];
}

int pop (pilha *p) {
	if(empty(p)) {
		printf("Pilha vazia");
		exit(1);
	}
	return p->elementos[p->topo--];
}

void push(pilha *p, int e) {
	if(p->topo == (TAMANHO -1)) {
		printf("Pilha cheia");
		exit(1);
	}
	p->elementos[++(p->topo)] = e;
}




int main () {
	pilha a;
	a.topo = -1;
	
	push(&a, 1);
	push(&a, 3);
	push(&a, 24);
	push(&a, 14);
	
	printf("\ntamanho da pilha: %d", size(&a));
	printf("\ntopo da pilha: %d", stackpop(&a));
	
	printf("\n----------------------------------------------------");
	
	pop(&a);
	printf("\ntamanho da pilha: %d", size(&a));
	printf("\ntopo da pilha: %d", stackpop(&a));
	
	printf("\n----------------------------------------------------");
	
	pop(&a);
	printf("\ntamanho da pilha: %d", size(&a));
	printf("\ntopo da pilha: %d", stackpop(&a));
	
	printf("\n----------------------------------------------------");
	
	pop(&a);
	printf("\ntamanho da pilha: %d", size(&a));
	printf("\ntopo da pilha: %d", stackpop(&a));
	
	return 0;
}


