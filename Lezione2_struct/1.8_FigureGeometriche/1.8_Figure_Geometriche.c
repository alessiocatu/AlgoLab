#include <stdio.h>
void main(){
	//punto
	typedef struct{
	    int x;
	    int y;
	} punto;


	//rettangolo
	struct{
	    punto v1;
	    punto v2;
	} rettangolo;

	//cerchio
	struct{
	    punto centro; //tasformare in un punto
	    int r;
	} cerchio;

	char user='a';
	while (user != '.'){
		
		printf("Selezionare il comando\n");
		printf("1-Calcolare area rettangolo\n");
		printf("2-Calcolare area cerchio\n");
		printf(".-Esci\n");
		scanf (" %c", &user);

		switch (user){
			case '1':
				printf("Inserire il primo vertice del rettangolo\n");	
				scanf ("%d%d",&rettangolo.v1.x,&rettangolo.v1.y);
				printf("Inserire il secondo vertice del rettangolo\n");	
				scanf ("%d%d",&rettangolo.v2.x,&rettangolo.v2.y);
				int areaRett=(rettangolo.v1.x-rettangolo.v2.x)*(rettangolo.v1.y-rettangolo.v2.y);
				if (areaRett<0)
					areaRett=-areaRett;
				printf("L'area risulta %d",areaRett);
				printf("\n");
				break;
			case '2':
				printf("Inserire il centro del cerchio\n");	
				scanf ("%d%d",&cerchio.centro.x,&cerchio.centro.y);
				printf("Inserire il raggio del cerchio\n");	
				scanf ("%d",&cerchio.r);
				float areaCerchio=(cerchio.r*cerchio.r)*3.14f;
				printf("L'area risulta %f",areaCerchio);
				printf("\n");
				break;
			default:
				user='.';
				break;
		}
	} 

}

