#include <stdio.h>
int main(void) {
printf("Inserisci un'espressione terminata da un punto: ");
char c='u';
int aperte=0;
int chiuse=0;
int cont=0;
while(c!='.') {
	c=getchar();
	cont++;
	if(c=='(') {
		aperte++;
	} else if(c==')') {
		chiuse++;
	}
	if(chiuse>aperte) {
		printf("Carattere %d: Troppe parentesi chiuse! \n", cont);
		break;
	} 
}
if(aperte>chiuse) {
	printf("Carattere %d: mancano parentesi chiuse! \n", cont);
} else if(aperte==chiuse) {
	printf("Espressione ben parentesizzata \n");
}

}
