//
//  Da10ABase.c
//  Lezione2
//
//  Created by Andrea Girola on 06/10/16.
//  Copyright © 2016 Andrea Girola. All rights reserved.
//

#include <stdio.h>
#include <math.h>
int main(void){
    int b,n, temp;
    int i=0;
    int nFinale=0;
    printf("Inserisci il numero da convertire e la base");
    scanf("%d%d", &b, &n);
    
    do{
        temp = n%10;
        nFinale = nFinale + (pow(b, i)*temp);
        n=n/10;
        i++;
    }while(n!=0);
    
    printf("%d \n", nFinale);
    return 0;
}
