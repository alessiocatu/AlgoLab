#include <stdio.h>

//Array a
//Lunghezza n
void max_secondmax(int a[], int n, int *max, int *second_max);

int main(void){
  int a[] = {10,22,35,49,35,96,67,68,9};
  int max, second_max;

  max_secondmax(a, 9, &max, &second_max);
  printf("%d, %d\n", max, second_max);
  return 0;
}

void max_secondmax(int a[], int n, int *max, int *second_max){
  for(int i=0; i<n; i++){
    if (*max < a[i])
      *max = a[i];
  }

  for(int i=0; i<n; i++){
    if (*second_max < a[i] && *max > a[i])
      *second_max = a[i];
  }
}
