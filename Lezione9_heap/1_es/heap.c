#include "itemkey.h"
#include "pqueue.h"
#include <stdlib.h>
#include <stdio.h>

typedef queue *Heap;
struct queue{
  int i;
  struct queue *next;
};
struct pqueue{
  Heap h;
  int size, count;
};

Heap heapify_up(Heap h, int size, int i){

}

int main(void){
  return 0;
}

/* crea una coda di priorità vuota che potrà contenere al massimo n Item */
Pqueue pqueue_new( int n ){
  Pqueue p = malloc(sizeof(struct pqueue));
  p -> h = malloc(sizeof(Item));
  p -> size = n;
  p -> count = 0;
  return p;
}

/* distrugge la coda di priorità */
void pqueue_destroy( Pqueue p){}

/* restituisce la lunghezza della coda di priorità */
int pqueue_length( Pqueue p){
  if(p)
    return p -> size;
  else
    return 0;
}

/* inserisce l’Item nella coda di priorità */
void pqueue_insert( Pqueue, Item );

/* estrae dalla coda di priorità l’Item con chiave minima */
Item pqueue_extractmin( Pqueue );

/* restituisce l’Item con chiave minima nella coda di priorità */
Item pqueue_min( Pqueue );
