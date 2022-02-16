#include <stdio.h>
#include <ctype.h>
void main(){
	int v [26];
	char stringa[100];
	int i=0;
	printf ("Inserire la stringa\n");

	for (i=0; i<26; i++)
		v[i]=0;

	for (i=0; i<100; i++){
		scanf ("%c",&stringa[i]);
		if (stringa[i]=='.'){
			break;
		}
	}
	for (int k=0; k<i; k++){
		stringa[k]=toupper(stringa[k]);
		for (int n=0; n<26; n++)
			if ((stringa[k]+0)==('A'+n)){ 	//se il k-esimo elemento di stringa è l'n-esimo elemento dell'alfabeto
				v[n]++;			//incrementa le occorrenze dell'n-esima lettera dell'alfabeto
				break;
			}		
	}
	for (int m=0; m<26; m++)
		if (v[m]>0)					//per tutte le lettere che occorrono almeno una volta
			printf ("%c : %d \n",('A'+m),v[m]);	//stampa a schermo ciascuna m-esima lettera dell'alfabeto con le sue occorrenze
}

