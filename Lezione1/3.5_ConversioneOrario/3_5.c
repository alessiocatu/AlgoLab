#include <stdio.h>
int main(void) {
int h, m;
printf("Convertitore orario. Inserire un orario nel formato 24H \n");
printf("Ora: ");
scanf("%d", &h);
printf("Minuti: ");
scanf("%d", &m);
if(m>=10) {
	if(h<=0 || h>24 || m>59) {
	printf("Hai sbagliato qualcosa \n");
	} else if(h>=13 && h<=23) {
	printf("Sono le %d:%d PM \n", (h-12), m);
	} else if(h==24) {
	printf("Sono le 00:%d AM \n", m);
	} else if(h>0 && h<13) {
	printf("Sono le %d:%d AM \n", h,m);
	}
} else {
	if(h<=0 || h>24 || m<0) {
	printf("Hai sbagliato qualcosa \n");
	} else if(h>=13 && h<=23) {
	printf("Sono le %d:0%d PM \n", (h-12), m);
	} else if(h==24) {
	printf("Sono le 00:0%d AM \n", m);
	} else if(h>0 && h<13) {
	printf("Sono le %d:0%d AM \n", h,m);
	}
}
}
