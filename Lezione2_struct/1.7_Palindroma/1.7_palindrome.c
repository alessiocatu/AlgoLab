#include <stdio.h>
void main(){
	char string [100];	//contiene la stringa
	char c;			//legge input da utente
	int palindroma=1;	//bool è palindroma?
	printf("Inserire la stringa da terminare con un punto\n");
	int i;			//contatore della stringa
	for (i=0; i<100; i++){
		scanf(" %c",&c);
		if (c=='.')
			break;
		string[i]=c;
	}

	for (int k=0; k<i; k++){	//controlla il primo e l'ultimo elemento della stringa
		i--;			//il primo e l'ultimo elemento vengono accantonati
		if (string[k]!=string[i]){
			palindroma=0;
			break;
		}
		
	}
	if (palindroma==1)
		printf("La stringa è palindroma\n");
	else 
		printf("La stringa non è palindroma\n");
}

