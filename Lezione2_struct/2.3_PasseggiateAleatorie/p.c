#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
  int size = 10;
  int matrix[size][size];

  //init
  for(int i=0; i<size; i++){
    for(int j=0; j<size; j++){
      matrix[i][j] = '.';
    }
  }

  //Passeggiata aleatoria
  char iter = 'B';
  int i,j = 0;
  matrix[i][j] = 'A';

  while(iter < 'Z'+1){
    int next = rand();
    switch(next%4) {
      case 0:
        j++;
        break;
      case 1:
        i++;
        break;
      case 2:
        j--;
        break;
      case 3:
        i--;
        break;
    }

    if(i<0 || i>=size || j<0 || j>=size || matrix[i][j] > '.'){
      switch(next%4) {
        case 0:
          j--;
          break;
        case 1:
          i--;
          break;
        case 2:
          j++;
          break;
        case 3:
          i++;
          break;
      }
      continue;
    }

    matrix[i][j] = iter;
    iter++;
  }

  //print matrix
  for(int i=0; i<size; i++){
    for(int j=0; j<size; j++) {
      printf(" %3c", matrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}
