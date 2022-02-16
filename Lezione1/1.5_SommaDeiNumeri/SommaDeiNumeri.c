//SommaDeiNumeri
#include <stdio.h>
int main(void){
	int a;
	a = 1;
	int somma;
	somma = 0;

	while(a!=0){
		printf("Inserire numero: \n");
		scanf("%d", &a);
		somma = somma+a;
	}

	printf("La somma è: %d", somma);
	printf("\n");
}