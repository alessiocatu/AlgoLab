//ClassificazioneTriangoli
#include <stdio.h>
int main(void){
	int l1;
	int l2;
	int l3;
	printf("Inserire il primo lato: \n");
	scanf("%d", &l1);
	printf("Inserire il secondo lato: \n");
	scanf("%d", &l2);
	printf("Inserire il terzo lato: \n");
	scanf("%d", &l3);

	if(l1<(l2+l3) && l2<(l1+l3) && l3<(l2+l1)){
		if (l1==l2 && l2==l3){
			printf("Il triangolo è equilatero!\n");
		}else if(l1!=l2 && l2!=l3 && l1!=l3){
			printf("Il triangolo è scaleno!\n");
		}else{ 
			printf("Il triangolo è isoscele!\n");
		}
	}else {
		printf("Non è un triangolo!\n");
	}
}