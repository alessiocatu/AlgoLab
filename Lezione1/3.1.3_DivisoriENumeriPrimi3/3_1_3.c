#include <stdio.h> 
int main(void){
int n;
int cont=0;
printf("Inserisci un numero: ");
scanf("%d", &n);
printf("Scomposizione in fattori primi: ");
printf("1");
for (int g=2; g<=n; g++) {
	if((n%g)==0) {
		cont++;
		printf("*%d", g);
		n=n/g;
		g=2;
	}
}
if(cont==0) {
	printf("*%d \n", n);
} else {
	printf("\n");
}
}
