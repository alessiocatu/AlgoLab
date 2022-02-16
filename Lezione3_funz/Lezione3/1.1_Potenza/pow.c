#include <stdio.h>

int pow2(int b, int e);

int main(void) {
  int b,e;
  scanf(" %d %d", &b, &e);

  printf("%d\n", pow2(b,e));
  return 0;
}

int pow2(int b, int e){
  if(e == 0)
    return 1;
  if(e == 1)
    return b;
  return b * pow2(b, e-1);
}
