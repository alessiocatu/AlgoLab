//
//  CifreRipetute.c
//  Lezione2
//
//  Created by Andrea Girola on 06/10/16.
//  Copyright © 2016 Andrea Girola. All rights reserved.
//

#include <stdio.h>
//1.2 Cifre ripetute di un numero
//Scrivete un programma che legga in input un numero intero n usando scanf( “%d”, &n ) e stabilisca se n
//contiene cifre ripetute e in caso affermativo quali.
int main(void){
    int n, i;
    int val;
    int vett[]= {0,0,0,0,0,0,0,0,0,0};
    printf("Inserire un numero: ");
    scanf("%d", &n);
    do{
        val = n%10;
        printf("%d\n", val);
        n = n/10;
        vett[val] ++;
    }while(val!=0);
    printf("Numeri ripetuti: \n");
    for(i=0; i<10; i++){
        n = vett[i];
        if(n>1){
            printf("%d -> %d \n", i, n);
        }
    }
    return 0;
}
