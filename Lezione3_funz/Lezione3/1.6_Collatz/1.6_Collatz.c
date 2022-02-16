#include <stdio.h>

int Collatz(int n);

int main (){
	int num;
	int cont=0;
	printf("Numero: "); 
		scanf ("%d", &num);
	while (num>1){
		printf ("%d ",num);
		cont++;
		num= Collatz(num);
	}
	printf ("1\n");
	cont++;
	printf ("Lunghezza: %d\n", cont);
	return 0;

}

int Collatz(int n){
if ((n%2)==0)
	return (n/2);
else return (n*3+1);
}
