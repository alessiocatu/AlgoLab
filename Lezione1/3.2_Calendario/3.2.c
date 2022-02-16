#include <stdio.h>
#include <ctype.h>
void main(){
	int m;	//numero inserito dall'utente (mese)
	int g; 	//giorno della settimana di inizio
	printf ("Selezionare un numero intero da 1 a 12\n");	
	scanf ("%d",&m);	
	printf ("Selezionare un numero intero da 1 a 12\n");
	scanf ("%d",&g);
	printf ("\nMese di ");	
	switch (m) {
		case 1:
		   printf ("Gennaio\n");
		   break; 
		case 2:
		   printf ("Febbraio\n");
		   break; 
		case 3:
		   printf ("Marzo\n");
		   break; 
		case 4:
		   printf ("Apile\n");
		   break;
		case 5:
		   printf ("Maggio\n");
		   break; 
		case 6:
		   printf ("Giugno\n");
		   break; 
		case 7:
		   printf ("Luglio\n");
		   break; 
		case 8:
		   printf ("Agosto\n");
		   break;
		case 9:
		   printf ("Settembre\n");
		   break; 
		case 10:
		   printf ("Ottobre\n");
		   break; 
		case 11:
		   printf ("Novembre\n");
		   break; 
		case 12:
		   printf ("Dicembre\n");
		   break;
		} 

	printf ("L  M  M  G  V  S  D\n");
	int i; //contatore settimana
	int n=1; //giorno corrente
	for (i=1; i<g; i++){
		printf("   ");
	}	
	while (n<31){	
		while (i<8){
		printf("%d",n);
		if (n<10)
			printf(" ");
		printf(" ");
		i++;
		if (n>30) break;
		n++;
		}
	i=1;
	printf ("\n");		
	}

}

