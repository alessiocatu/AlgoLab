//
//  main.c
//  Es7
//
//  Created by Marco Colussi on 10/11/16.
//  Copyright © 2016 Marco Colussi. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#define N 10

void stampa( int a[], int lung ){
    for(int i = 0; i < lung; i++){
        printf("%d° elemento: %d\n", i+1, a[i]);
    }
}
void scambia(int a[], int i, int j ){
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void merge(int a[], int sx, int dx, int mid){
    printf("inizio merge\n");
    int b[(dx-sx)+1];
    int counter = 0;
    int i = sx;
    int j = mid + 1;
    while(i <= mid && j <= dx){
        if(a[i] > a[j]){
            b[counter] = a[j];
            j++;
        }else{
            b[counter] = a[i];
            i++;
        }
        counter ++;
    }
    
    if(i > mid){
        for( ;j <= dx; j++){
            b[counter] = a[j];
            counter++;
        }
    }else{
        for( ; i <= mid; i++){
            b[counter] = a[i];
            counter++;
        }
    }
    counter = 0;
    for(int x = sx; x <= dx; x++){
        a[x] = b[counter];
        counter++;
    }
    printf("fine merge\n");
}

void mrgesort(int a[], int sx, int dx){
    printf("inizio mergesort\n");
    if(dx - sx > 0){
        mrgesort(a, sx, sx+(dx-sx)/2);
        mrgesort(a, (sx+(dx-sx)/2)+1, dx);
    }
    merge(a, sx, dx, sx+(dx-sx)/2);
    printf("fine mergesort\n");
}

//WORKING XD
void selectionsort (int a[], int n){
    int max = 0;
    int indice = 0;
    for(int i = 0; i < n; i ++){
        if(max <= a[i]){
            max = a[i];
            indice = i;
        }
    }
    scambia(a, n-1, indice);
    if(n-1 != 0){
        selectionsort(a, n-1);
    }
}


int main(void) {
    int  a[N];
    int scelta;
    //CREAZIONE
    printf("Inserire gli elementi dell'array: \n");
    for(int i = 0; i < N; i++){
        printf("Inserire il %d° elemento: ", i+1);
        scanf("%d", &a[i]);
    }
    
    //ORDINAMENTO
    printf("Scegliere: \n1- Selectionsort:1\n2- Mergesort: ");
    scanf("%d", &scelta);
    bool ok = false;
        while(ok == false){
        scanf("%d", &scelta);
        if(scelta == 1){
            ok = true;
            selectionsort(a, N);
        }else if(scelta == 2){
            ok = true;
            mrgesort(a, 0, N);
        }else{
            printf("Inserimento errato, riptovato");
        }
    }
    //STAMPA
    stampa(a, N);
    return 0;
}
