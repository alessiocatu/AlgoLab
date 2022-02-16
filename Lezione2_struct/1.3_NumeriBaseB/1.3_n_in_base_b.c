#include <stdio.h>
void main (){
	int v[100];
	int b,n,i;	
	printf("Inserisci un intero b e un numero in base 10 da convertire in base b: ");
	scanf("%d%d", &b, &n );
	for (i=0;i<100;i++){
		v[i]=n%b;
		n=n/b;
		if (n<1)
			break;
	}
	printf("Il numero risulta ");
	while (i>=0){
		if (v[i]<10)
			printf ("%d",v[i]);
		else
		switch (v[i]){
			case 10:
				printf ("A");
				break;
			case 11:
				printf ("B");
				break;
			case 12:
				printf ("C");
				break;
			case 13:
				printf ("D");
				break;
			case 14:
				printf ("E");
				break;
			case 15:
				printf ("F");
				break;
			case 16:
				printf ("G");
				break;
			case 17:
				printf ("H");
				break;
		}
		i--;
	
	}
	printf("\n");
}

