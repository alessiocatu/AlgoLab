#include <stdio.h>
int main(void){
int n;
int c=0;
int cerchi;
printf("Inseisci un numerodi colonne: ");
scanf("%d", &n);
if(n>0) {
	for(int cont=0; cont<n; cont++) {
			for(cerchi=0; cerchi<c; cerchi++) {
				printf("o ");
			}
			printf("| ");
			for(int croci=0; croci<((n-1)-cerchi); croci++) {
				printf("+ ");
			}
			printf("\n");
			c++;
	}
}
}
