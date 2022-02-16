#include <stdio.h>
#include <math.h>
int main(void){
	printf("Inserire raggio cerchio:\n");
	float rag=0;
	float area=0;
	scanf("%f", &rag);
	area=(rag*rag)*(M_PI);
	printf("Il risultato è:%f\n", area);
}	
