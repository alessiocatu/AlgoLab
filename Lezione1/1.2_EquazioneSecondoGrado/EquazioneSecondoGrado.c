//Equazione di secondo grado
#include <stdio.h>
#include <math.h>
int main(void){
	int a;
	int b;
	int c;
	printf("Inserire primo numero: \n");
	scanf("%d", &a);
	printf("Inserire secondo numero: \n");
	scanf("%d", &b);
	printf("Inserire terzo numero: \n");
	scanf("%d", &c);
	printf("I numeri sono: %d %d %d", a, b, c);
	printf("\n");
	float ris = sqrt((b*b)-(4*a*c));
	float risultato1;
	float risultato2;
	risultato1 = ((0-b) + ris)/2*a;
	risultato2 = ((0-b) - ris)/2*a;
	printf("Risultato 1: %f", risultato1);
	printf("\n");
	printf("Risultato 2: %f", risultato2);
	printf("\n");
}