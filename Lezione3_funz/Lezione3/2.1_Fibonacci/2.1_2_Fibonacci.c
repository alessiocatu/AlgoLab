#include <stdio.h>

int Fib(int n);
int cont;

int main (){
	int num;
	cont=0;
	printf("Inserire numero: ");
	scanf ("%d",&num);
	printf ("%d\n",Fib(num-1));
	printf ("Operazioni: %d\n",cont);
	return 0;

}

int Fib(int n){
	cont++;
	if (n<2)
		return 1;
	else 
		return (Fib(n-1)+Fib(n-2));
}

