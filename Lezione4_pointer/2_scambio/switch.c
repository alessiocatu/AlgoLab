#include <stdio.h>

void scambia(int *p, int *q);

int main(void) {
  int i = 10, j = 20;
  printf("%d, %d\n", i, j);
  scambia(&i, &j);
  printf("%d, %d\n", i, j);
}

void scambia(int *p, int *q){
  int temp = *q;
  *q = *p;
  *p = temp;
}
