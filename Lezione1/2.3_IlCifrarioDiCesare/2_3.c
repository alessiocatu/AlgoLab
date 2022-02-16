#include <stdio.h>
#include <ctype.h>
int main(void){
int n;
char c='i';
printf("inserisci un numero per cifrare: ");
scanf("%d", &n);
printf("inserisci la frase (terminata con un punto): ");
while(c!='.') {
	c=getchar();
	if(isalpha(c)) {
		if(isupper(c)) {
			c=tolower(c);
			c=toascii(c);
				if((c+n)>toascii('z')) {
					c=c-(26-n);
				} else {
					c=c+n;
				}
			c=toupper(c);
		} else {
			c=toascii(c);
			if((c+n)>toascii('z')) {
				c=c-(26-n);
				} else {
					c=c+n;
				}
		}
	}
	printf("%c", c);
}
printf("\n");
}
