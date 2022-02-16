#include <stdio.h>
void main(){
	int v [100];	
	int i=0;
	int k;		//posizione dell'ultimo numero inserito all'interno dell'array
	int j;		//partendo dal fondo dell'array, fa spostare tutti gli elementi v[j] più grandi del numero inserito a destra nell'array
	int num; 	//memorizza il numero inserito
	for (i=0; i<100; i++)
		v[i]=0;	//inizializza l'array a 0

	printf("Inserire numero: ");
	scanf ("%d", &num);
	
	if (num!=0){	
		v[0]=num;

		for (i=1; i<100; i++){
			printf("Inserire numero: ");
			scanf ("%d", &num);
			if (num==0)
				break; 	//interrompe l'inserimento e salva l'indice i dell'array se è inserito 0
			k=0;		//posizione all'interno dell'array di num inizializzata a 0
			j=i;		//indice elementi v[j] più grandi di num da shiftare inizializzato all'ultima posizione dell'array
			while ((num>v[k])&&(k<i)){
				k++;	//incrementa k finchè non trova la posizione dove inserire num
			}

			for (j=i; j>k; j--){
				v[j]=v[j-1];	//sposta a destra l'elemento v[j], per tutti i v[j] di posizione maggiore di k
			}

			v[k]=num;		//salva num nella corretta posizione

		} 	
		for (k=0; k<i; k++){
			printf("%d", v[k]);	//stampa l'array ordinato
			printf(" ");
		}
	printf("\n");
	}
}

