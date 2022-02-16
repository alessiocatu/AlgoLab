#include <stdio.h>

void stampa(int a[], int lung);
void scambia(int a[], int i, int j);
void selectionsort(int a[], int n);
void mergesort(int a[], int sx, int dx);
void merge(int a[], int sx, int dx, int mid);
int main(void){
  int size = 9, sel;
  int a[] = {5,4,3,65,7,8,9,1,2};
  scanf(" %d", &sel);
  if(sel){
    printf("SELECTION SORT \n");
    stampa(a, size);
    selectionsort(a, size-1);
    stampa(a, size);
  } else {
    printf("\nMERGE SORT \n");
    mergesort(a, 0, size-1);
    stampa(a, size);
  }
  return 0;
}

void selectionsort(int a[], int n){
  if(n==2) return;
  int k=0;
  for(int i = 0;i<n;i++){
    if(a[k]<a[i])
      k = i;
  }
  scambia(a, k, n);
  selectionsort(a, n-1);
}

void merge(int a[], int sx, int dx, int mid){
  int pipe[dx-sx];
  int i=sx, j=mid+1, c=0;

  while(i<=mid && j<=dx){
    if(a[i]<a[j]){
      pipe[c]=a[i];
      i++;
    } else {
      pipe[c]=a[j];
      j++;
    }
    c++;
  }

  if(i>mid){
    for(;j<=dx;j++){
      pipe[c]=a[j];
      c++;
    }
  } else {
    for(;i<=mid;i++){
      pipe[c]=a[i];
      c++;
    }
  }
  c = 0;
  for(int x = sx; x <= dx; x++){
      a[x] = pipe[c];
      c++;
  }
}

void mergesort(int a[], int sx, int dx){
  printf("dx: %d e sx: %d\n", sx, dx);
  if(dx - sx > 0){
      printf("if\n");
      mergesort(a, sx, sx+(dx-sx)/2);
      mergesort(a, (sx+(dx-sx)/2)+1, dx);
  }
  merge(a, sx, dx, sx+(dx-sx)/2);
}

void scambia(int a[], int i, int j){
  printf("SCAMBIO i=%d con j=%d\n", a[i],a[j]);
  int tmp = a[j];
  a[j] = a[i];
  a[i] = tmp;
}

void stampa(int a[], int lung){
  printf("[");
  for(int i=0; i<lung; i++){
    if(i+1 == lung)
      printf("%d", a[i]);
    else
      printf("%d,", a[i]);
  }
  printf("]\n");
}
