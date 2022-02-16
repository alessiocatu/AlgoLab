#include <stdio.h> 
int main(void){
int n, cont;
printf("Inserisci un numero: ");
scanf("%d", &n);
for (int g=(n/2); g>=2; g--) {
	if((n%g)==0) {
		cont++;
		break;
	}
}
if(cont>0){
	printf("Non è un numero primo \n");
} else {
	printf("E' un numero primo \n");
}
}
