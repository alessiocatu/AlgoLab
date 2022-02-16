#include <stdio.h>

int *smallest(int a[], int n);

int main(void) {
    int a[] = {9,29,3,4,55,7,43,2,11};
    printf("%d\n", *smallest(a, 9));
    return 0;
}

int *smallest(int a[], int n){
  int small = 0;
  for(int i=0; i<n; i++){
    if (a[i]<a[small])
      small = i;
  }
  return &a[small];
}
