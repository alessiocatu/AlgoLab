//SommaNumeriNonNulli
#include <stdio.h>
int main(void){
	int a;
	a = 1;
	int conta;
	conta = 1;
	int somma;
	somma = 0;

	while(conta<11){
		printf("Inserire numero: \n");
		scanf("%d", &a);
		if (a!=0){
		somma = somma+a;
		conta++;
		}
	}

	printf("La somma è: %d", somma);
	printf("\n");
}