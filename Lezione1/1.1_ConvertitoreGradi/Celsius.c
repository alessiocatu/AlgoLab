#include <stdio.h>

int main(void){
	printf("Inserire numero in celsius: ");
	int gradi;
	int conversione;
	float fattore = 5.0f/9.0f;
	scanf("%d", &gradi);
	conversione = (gradi - 32)*(fattore);
	printf("Convertito: %d", conversione);
	printf("\n");
}
