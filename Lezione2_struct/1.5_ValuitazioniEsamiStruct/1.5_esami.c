#include <stdio.h>
void main (){
	int i,n,m;
	struct{
	int matricola;
	int valutazione[5];
	} studente[5];
	for (i=0;i<5;i++){
		printf ("Inserire la matricola\n");
		scanf ("%d",&studente[i].matricola);
		printf ("Inserire le 5 valutazioni separate da spazio\n");
		scanf ("%d%d%d%d%d",&studente[i].valutazione[0],
					&studente[i].valutazione[1],
					&studente[i].valutazione[2],
					&studente[i].valutazione[3],
					&studente[i].valutazione[4]);
	}
	for (i=0; i<5; i++){
		m=0;
		for (n=0; n<5;n++){
			m=m+studente[i].valutazione[n];
		}
		printf("Lo studente di matricola %d",(studente[i].matricola));
		printf (" consegue una media di %d", (m/5));
		printf("\n");
	}
}
