#include <stdio.h>

int Fib(int n);

int main (){
	int num;
	printf("Inserire numero: ");
	scanf ("%d",&num);
	printf ("%d\n",Fib(num-1));
	return 0;

}

int Fib(int n){
	if (n<2)
		return 1;
	else 
		return (Fib(n-1)+Fib(n-2));
}

