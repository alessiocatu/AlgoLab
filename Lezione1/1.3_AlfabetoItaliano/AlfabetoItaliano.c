//Alfabeto italiano
#include <stdio.h>
#include <ctype.h>
int main(void){
	char c;
	printf("Inserire un carattere: \n");
	scanf("%c", &c);
	c = tolower(c);
	if(isdigit(c)){
		printf("E' un numero!");
	} else if (isalpha(c)) {
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
		printf("E' una vocale!\n");
	else if(c=='j' | c=='x' | c=='y' | c=='w' | c=='k')
		printf("Il carattere inserito non fa parte dell'alfabeto italiano!\n");
	else
		printf("Il carattere inserito è una consonante!\n");
	}
}