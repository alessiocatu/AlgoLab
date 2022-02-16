#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *my_malloc(size_t size);
void *my_realloc(void *p, size_t size);

int main(void){
  int size, pos=0;
  printf("dimensione sequenza: ");
  scanf(" %d", &size);

  int *seq = my_malloc(sizeof(int) * size);
  printf("sequenza di interi: ");
  while(pos++ < size){
    scanf(" %d", seq+pos);
  }
  pos = 0;
  seq=seq+size;
  while(pos++ < size){
    printf("%d ", *seq--);
  }
  printf("\n");
  return 0;
}

void *my_malloc(size_t size){
  void *p = malloc(size);
  if(p == NULL){
    printf("Error\n");
    exit(EXIT_FAILURE);
  }
  return p;
}

void *my_realloc(void *p, size_t size){
  void *tmp;

  tmp = realloc(p, size);
  if(tmp == NULL){
    printf("Error\n");
    exit(EXIT_FAILURE);
  }
  return p = tmp;
}
