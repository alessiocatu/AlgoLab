#include <stdio.h>

int main(void) {
  //int size;
  int size;
  printf("Inserisci la dimensione del quadrato: ");
  scanf(" %d", &size);

  int quad[size][size];
  //init
  for(int i=0; i<size; i++){
    for(int j=0; j<size; j++){
      quad[i][j] = 0;
    }
  }

  //
  int row = 0;
  int col = size/2;
  int val = 1;
  quad[row][col] = val;

  while(++val<=size*size){
    row-1<0 ? row=size-1 : row--;
    col+1>size-1 ? col=0 : col++;

    if(quad[row][col]>0){
      row+1<size ? row++ : (row=0);
      row+1<size ? row++ : (row=0);
      col-1>=0 ? col-- : (col=size-1);
    }
    quad[row][col] = val;
  }

  //printing Matrix
  for(int i=0; i<size; i++){
    for(int j=0; j<size; j++){
      printf(" %3d", quad[i][j]);
    }
    printf("\n");
  }

  return 0;
}
