#include <stdio.h>

int main (){
	char string[100];
	char v=' ';
	int i;
	while ((v!='a')&&(v!='e')&&(v!='i')&&(v!='o')&&(v!='u')){
		printf("Inserire vocale, spazio, stringa, .\n"); 
		scanf (" %c", &v);
		for (i=0; i<100; i++){
			scanf ("%c", &string[i]);
			if (string[i]=='.')
				break;
		}
	}
	for (int n=1; n<i; n++){
		if ((string[n]=='a')||(string[n]=='e')||(string[n]=='i')||(string[n]=='o')||(string[n]=='u'))
			string[n]=v;
	printf("%c",string[n]);
	}
	printf("\n");
	return 0;

}

