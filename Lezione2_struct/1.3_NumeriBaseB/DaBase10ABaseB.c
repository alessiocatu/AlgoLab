//
//  DaBase10ABaseB.c
//  Lezione2
//
//  Created by Andrea Girola on 06/10/16.
//  Copyright © 2016 Andrea Girola. All rights reserved.
//

//Scrivere un programma che legga una coppia di numeri interi b e n con scanf( “%d%d”, &b, &n ), quindi
//memorizzi in un array e stampi la rappresentazione di n in base b. Potete assumere che il numero di cifre in base
//b sia sempre minore di 100.

#include <stdio.h>

int main(void){
    int b, n, i=0, m;
    int vett[100];
    int nFinale=0;
    int temp;
    printf("Inserisci 2 numeri: \n");
    scanf("%d%d", &b, &n);
    
    printf("Numero : %d \n", n);
    printf("In base: %d \n", b);
    
    do{
        m=n%b;
        n=n/b;
        i++;
        vett[i] = m;
    }while(n!=0);
    while(i!=0){
        printf("%d", vett[i]);
        i--;
    }
    return 0;
}
