#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

struct stack{
  int value;
  struct stack *next;
};

typedef struct stack stack;
stack *s = NULL;

void make_empty(void){
  s = NULL;
}
int is_empty(void){
  return s == NULL;
}
int is_full(void);
int top(void){
  if(is_empty()){
    return 0;
  }
  return s -> value;
}
int pop(void){
  if(is_empty()){
    return 0;
  }
  int v = s -> value;
  s = s -> next;
  return v;
}
void push(int n){
  stack *p = malloc(sizeof(stack));
  p -> value = n;
  p -> next = s;
  s = p;
}

void print_stack(void){
  stack *tmp = s;
  while(s!=NULL){
    printf("%d ",s->value);
  }
  s = tmp;
}

int main(void){}
