//
//  EsamiEStudenti.c
//  Lezione2
//
//  Created by Andrea Girola on 06/10/16.
//  Copyright © 2016 Andrea Girola. All rights reserved.
//

#include <stdio.h>
int main(void){
    int vett[5][5]; //Colonne e Righe
    int i, j;
    float media=0;
    
    //Inserimento
    printf("Inserire i voti per ogni esame: \n");
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            printf("Inseri in %d voto dello studente %d: ", j+1, i+1);
            scanf("%d", &vett[i][j]);
        }
    }
    
    //Visualizzazione
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            printf("%d ", vett[i][j]);
        }
        printf("\n");
    }
    
    //Media degli studenti
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            media += vett[i][j];
        }
        media = media/5;
        printf("Media dello studente %d : %f \n", i+1, media);
        media=0;
    }
    
    //Media degli esami
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            media += vett[j][i];
        }
        media = media/5;
        printf("Media dell'esame %d : %f \n", j+1, media);
        media=0;
    }

}
