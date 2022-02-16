#include <stdio.h>

int main(void) {
  int min = 0;
  int max = 1000;
  char ans;

  printf("Pensa ad un numero compreso tra 1 e 1000\n");

  do{
      int r = (min+max)/2;
      printf("Il numero è %d? ", r);
      scanf(" %c", &ans);
      switch(ans){
        case '<':
          max = r;
          break;
        case '>':
          min = r;
          break;
      }
  }while(ans != '=');

  return 0;
}
