#include <stdio.h>

int main(void)
{
	int numeri[100];
	int n,i;
	printf("Inserisci i numeri (termina con 0):\n");
	for (i=0; i<100; i++){
		scanf(" %d", &n);
		if (n == 0)
			break;
		numeri[i]=n;
		}
	i--;
	while (i>=0){
		printf ("%d ", numeri[i--]);
		}
	return 0;
}

