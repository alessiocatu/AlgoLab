#include <stdio.h> 
int main(void){
int n, cont;
printf("Inserisci un numero: ");
scanf("%d", &n);
printf("I suoi divisori sono: ");
printf("%d, ", n);
for (int g=(n/2); g>=1; g--) {
	if((n%g)==0) {
		cont++;
		printf("%d, ", g);
	}
}
printf("\n Numero di divisori: %d \n", (cont+1));
}
