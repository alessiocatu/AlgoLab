#include <stdio.h>

int Fib(int n);
int cont;

int main (){
	int num;
	cont=0;
	printf("Inserire numero: ");
	scanf ("%d",&num);
	printf ("%d\n",Fib(num));
	printf ("Operazioni: %d\n",cont);
	return 0;

}

int Fib(int n){
	int a=1;
	int b=1;
	int c;
	cont++;
	if (n<2)
		return 1;
	else{ 
		for (int i=2; i<n; i++){
			c=a+b;
			a=b;
			b=c;
			cont++;
		}
		return c;
	}
}

