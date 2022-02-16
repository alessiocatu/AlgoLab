#include <stdio.h>
int main(void){
int n;
printf("Inseisci un numerodi colonne: ");
scanf("%d", &n);
if(n>0) {
	for(int cont=0; cont<n; cont++) {
		if((cont%2)==0) {
			for(int cont1=0; cont1<n; cont1++) {
				if((cont1%2)==0) {
				printf("o ");
				} else {
				printf("+ ");
				}
			}
			printf("\n");
		} else {
			for(int cont2=0; cont2<n; cont2++) {
				if((cont2%2)==0) {
				printf("+ ");
				} else {
				printf("o ");
				}
			}
			printf("\n");
		}
	}
}
}
