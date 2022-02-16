#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

	printf("Pensa a un numero, alle domande rispondi con <,>,=\n");
	
	int min=0;
	int max=1000;
	char c='o';
	int r;
	
	while (c != '=') {
		r=(min+max)/2;
		printf("Il numero è %d ? ", r);
		scanf(" %c", &c);
		
			if(c=='>') {
				min=r;
			} else if(c=='<') {
				max=r;
			}
	}
}
