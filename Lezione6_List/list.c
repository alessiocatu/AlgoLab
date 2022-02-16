#include <stdio.h>
#include <stdlib.h>

struct element{
  int value;
  struct element *next;
};
typedef struct element element;

int isMemeber (int n, element *h){
  printf("Controllo se l'elemento %d è nella lista\n", n);
  while(h != NULL){
    if(h -> value == n){
      printf("%d è nella lista\n", n);
      return 1;
    }
    h = h -> next;
  }
  printf("%d NON è nella lista\n", n);
  return 0;
}

void delete(int n, element **h){
  printf("Cancello l'elemento %d dalla lista\n", n);
  element *head = *h, *prev=NULL, *cur = *h;

  while(*h != NULL){
    if((*h) -> value == n){
      if(prev == NULL)
        head = (*h) -> next;
      else
        *prev -> next = *cur -> next;
      break;
    }
    cur = (*h) -> next;
    prev = *h;
    *h = cur;
  }
  *h = head;
}

void insert(int n, element **h){
  printf("Inserisco l'elemento %d nella lista\n", n);
  element *new_node = malloc(sizeof(h));
  new_node -> value = n;
  new_node -> next = *h;
  *h = new_node;
}

void printList (element *h) {
  printf("##### STAMPO LA LISTA #####\n");
  while(h != NULL){
    printf("%d ", h -> value);
    h = h -> next;
  }
  printf("\n");
}

void destroy(element *h){
  element *tmp;

  while(h != NULL){
    tmp = h;
    h = h -> next;
    free(tmp);
  }
}

void printInv(element *h){
  if(h == NULL)
    return;
  if(h -> next != NULL){
    printInv(h -> next);
    printf("%d ", h -> value);
  } else
    printf("%d ", h -> value);
}

int main(void){
  element *head = NULL;
  char c;
  int n, count = 0;

  while((c = getchar()) != 'f'){
    switch(c){
      case '+':
        scanf(" %d", &n);
        if(1-isMemeber(n, head)){
          insert(n, &head);
          count++;
        }
        break;
      case '-':
        scanf(" %d", &n);
        if(isMemeber(n, head)){
          delete(n, &head);
          count--;
        }
        break;
      case '?':
        scanf(" %d", &n);
        isMemeber(n, head);
        break;
      case 'c':
        printf("Elementi: %d\n", count);
        break;
      case 'p':
        if(count > 0)
          printList(head);
        break;
      case 'o':
        if(count > 0){
          printInv(head);
          printf("\n");
        }
        break;
      case 'd':
        destroy(head);
        head = NULL;
        count = 0;
        break;
    }
  }
  return 0;
}
