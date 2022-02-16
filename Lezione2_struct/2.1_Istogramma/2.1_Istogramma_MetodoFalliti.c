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
		switch (stringa[k]){
			stringa[k]=putchar(tolower(stringa[k]));;
			case 'a':
				v[0]++;
				break;
			case 'b':
				v[1]++;
				break;
			case 'c':
				v[2]++;
				break;
			case 'd':
				v[3]++;
				break;
			case 'e':
				v[4]++;
				break;
			case 'f':
				v[5]++;
				break;
			case 'g':
				v[6]++;
				break;
			case 'h':
				v[7]++;
				break;
			case 'i':
				v[8]++;
				break;
			case 'j':
				v[9]++;
				break;
			case 'k':
				v[10]++;
				break;
			case 'l':
				v[11]++;
				break;
			case 'm':
				v[12]++;
				break;
			case 'n':
				v[13]++;
				break;
			case 'o':
				v[14]++;
				break;
			case 'p':
				v[15]++;
				break;
			case 'q':
				v[16]++;
				break;
			case 'r':
				v[17]++;
				break;
			case 's':
				v[18]++;
				break;
			case 't':
				v[19]++;
				break;
			case 'u':
				v[20]++;
				break;
			case 'v':
				v[21]++;
				break;
			case 'w':
				v[22]++;
				break;
			case 'x':
				v[23]++;
				break;
			case 'y':
				v[24]++;
				break;
			case 'z':
				v[25]++;
				break;
		}
	}
	printf ("a: %d",v[0]);
	printf ("\nb: %d",v[1]);
	printf ("\nc: %d",v[2]);
	printf ("\nd: %d",v[3]);
	printf ("\ne: %d",v[4]);
	printf ("\nf: %d",v[5]);
	printf ("\ng: %d",v[6]);
	printf ("\nh: %d",v[7]);
	printf ("\ni: %d",v[8]);
	printf ("\nj: %d",v[9]);
	printf ("\nk: %d",v[10]);
	printf ("\nl: %d",v[11]);
	printf ("\nm: %d",v[12]);
	printf ("\nn: %d",v[13]);
	printf ("\no: %d",v[14]);
	printf ("\np: %d",v[15]);
	printf ("\nq: %d",v[16]);
	printf ("\nr: %d",v[17]);
	printf ("\ns: %d",v[18]);
	printf ("\nt: %d",v[19]);
	printf ("\nu: %d",v[20]);
	printf ("\nv: %d",v[21]);
	printf ("\nw: %d",v[22]);
	printf ("\nx: %d",v[23]);
	printf ("\ny: %d",v[24]);
	printf ("\nz: %d",v[25]);	

	
}

