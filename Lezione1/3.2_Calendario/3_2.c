#include <stdio.h>
int main(void) {
int mese, giorno;
printf("Inserisci il numero del mese (1=Gennaio,..., 12=Dicembre): ");
scanf("%d", &mese);
printf("Inserisci il numero di inizio mese (1=Lunedì,...,7=Domenica): ");
scanf("%d", &giorno);
printf(" L  M  M  G  V  S  D \n");
int riga=giorno;
if(mese>0 && mese<13 && giorno<8 && giorno>0) {
	if(mese==4 || mese==6 || mese==9 || mese==11) {
		mese=30;
	} else if(mese==2) {
		mese=28;
	} else {
		mese=31;
	}
	for(int cont=0; cont<=(3*(giorno-1)); cont++) {
		printf(" ");
	}
	for(int day=1; day<=mese; day++) {
		if(riga>7) { 
			printf("\n ");
			riga=1;
		}
		if(day>=10) {
		printf("%d ", day);
		} else {
		printf("%d  ", day);
		}
		riga++;
	}
	printf("\n");
}
}
