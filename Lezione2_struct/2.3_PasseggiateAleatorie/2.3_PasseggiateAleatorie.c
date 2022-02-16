#include <stdio.h>
//#include <conio.h>
void main(){
	char matrix[10][10];
	int i=0;
	int j=0;
	for (int i2=0; i2<10; i2++)
		for (int j2=0; j2<10; j2++)
			matrix[i2][j2]='.';
	matrix[0][0]='A';
	for (int i2=0; i2<10; i2++){
		for (int j2=0; j2<10; j2++)
			printf ("%c ",matrix[i2][j2]);
		printf("\n");
	}

	

	char l='B';
	int canMoveA=1;		//1=ci si può muovere a sinistra
	int canMoveS=1;		//1=ci si può muovere a sinistra
	int canMoveD=1;		//1=ci si può muovere a destra
	int canMoveW=1;		//1=ci si può muovere in alto
	char move='.';

	while ((canMoveA+canMoveS+canMoveD+canMoveW)>0){ //per tutta la durata del gioco
		//determina le direzioni che possono e non possono esser prese
		if ((i==9)||(matrix[i+1][j]!='.'))
			canMoveS=0;
		else 	
			canMoveS=1;
		if ((i==0)||(matrix[i-1][j]!='.'))
			canMoveW=0;
		else 	
			canMoveW=1;
		if ((j==0)||(matrix[i][j-1]!='.'))
			canMoveA=0;
		else 	
			canMoveA=1;
		if ((j==9)||(matrix[i][j+1]!='.'))
			canMoveD=0;
		else 	
			canMoveD=1;
		//finchè non è determinata
		while (
			  ((move!='a')||(canMoveA==0))
			&&((move!='s')||(canMoveS==0))
			&&((move!='d')||(canMoveD==0))
			&&((move!='w')||(canMoveW==0))
		       ){
		if ((canMoveA+canMoveS+canMoveD+canMoveW)==0)
			break;
			scanf(" %c",&move);
		}
		switch (move){
			case 'a':
				j--;
				matrix[i][j]=l;
				break;
			case 'd':
				j++;
				matrix[i][j]=l;
				break;
			case 's':
				i++;
				matrix[i][j]=l;
				break;
			case 'w':
				i--;
				matrix[i][j]=l;
				break;
		}
		l++;
		//clrscr();
		for (int i3=0; i3<10; i3++){
			for (int j3=0; j3<10; j3++){
				printf ("%c ",matrix[i3][j3]);
			}
			printf("\n");
		}
		move='.';
	}
	printf("FINE\n");
}
		



