#include <stdio.h>
int main(void){
int n;
int c=1;
int go;
printf("Inseisci un numerodi colonne: ");
scanf("%d", &n);
if(n>0 && (n%2)!=0) {
	for(go=0; go<=((n-1)/2); go++) {
		for(int cont=0; cont<((n-c)/2); cont++) {
			printf("| ");
		}
		for(int ce=0; ce<c; ce++) {
			printf("o ");
		}
		for(int cont1=0; cont1<((n-c)/2); cont1++) {
			printf("| ");
		}
		c=c+2;
		printf("\n");
	}
	c=c-4;
	while(go<=n) {
		if(c<1) {
			break;
		} else {
		for(int cont=0; cont<((n-c)/2); cont++) {
			printf("| ");
		}
		for(int ce=0; ce<c; ce++) {
			printf("o ");
		}
		for(int cont1=0; cont1<((n-c)/2); cont1++) {
			printf("| ");
		}
		c=c-2;
		printf("\n");
		}
	}
}
}
