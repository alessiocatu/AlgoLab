#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "itemkey.h"

#define MAX_SIZE 9

struct bit_node{
  int i;
  struct bit_node *l, *r;
};

typedef struct bit_node *Bit_node;

void generator(int *a);
void print_tree(int *a);

Bit_node bit_new( int i);
void bit_preorder( Bit_node b);
void bit_inorder( Bit_node b);
void bit_postorder( Bit_node b);
void bit_printassummary( Bit_node p, int spaces );

Bit_node bit_arr2tree( int a[], int size, int i);

int main(void){
  Bit_node b;
  int *a = malloc(sizeof(int) * MAX_SIZE);
  generator(a);
  //int a[] = {69, 89, 28, 39, 66, 44, 12, 2, 71};
  b = bit_arr2tree(a, MAX_SIZE, 0);
  bit_printassummary(b,0);
  return 0;
}

void generator(int *a){
  srand(time(NULL));
  for(int i=0; i<MAX_SIZE; i++){
    a[i] = rand()%30;
  }
}

Bit_node bit_new(int i){
  Bit_node b = malloc(sizeof (struct bit_node));
  b -> i = i;
  b -> l = NULL;
  b -> r = NULL;
  return b;
}

void bit_preorder(Bit_node b){
  if(!b){
    printf("%d ", b -> i);
    bit_preorder(b -> l);
    bit_preorder(b -> r);
  }
}

void bit_inorder(Bit_node b){
  if(!b){
    bit_preorder(b -> l);
    printf("%d ", b -> i);
    bit_preorder(b -> r);
  }
}

void bit_postorder(Bit_node b){
  if(!b){
    bit_preorder(b -> l);
    bit_preorder(b -> r);
    printf("%d ", b -> i);
  }
}

void bit_printassummary(Bit_node b, int spaces){
  if(b){
    char sp[spaces+1];
    for(int i=0; i<=spaces; i++){
      sp[i] = ' ';
    }
    printf("%s * %d\n", sp,b -> i);
    bit_printassummary(b -> l, spaces+1);
    bit_printassummary(b -> r, spaces+1);
  }
}

Bit_node bit_arr2tree(int a[], int size, int i){
  if(i<size){
    Bit_node b = malloc(sizeof(struct bit_node));
    b -> i = a[i];
    b -> l = bit_arr2tree(a, size, i*2+1);
    b -> r = bit_arr2tree(a, size, i*2+2);

    return b;
  }
  return NULL;
}
