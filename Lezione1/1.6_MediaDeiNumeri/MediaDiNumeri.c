//MediaDiNumeri
#include <stdio.h>
int main(void){
	int a;
	a = 1;
	int somma;
	somma = 0;
	int conta;
	conta = 0;

	while(a!=0){
		printf("Inserire numero: \n");
		scanf("%d", &a);
		somma = somma+a;
		conta++;
	}
	printf("\n");
	conta--;
	float media;
	media = somma/conta;
	printf("La media è: %d", somma/conta);
	printf("\n");
}