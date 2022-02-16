/*****************************************************************************
*   itemkey_int.c - implementazione dell'interfaccia item_key.h 
*   nel caso in cui Item e' intero e la chiave dell'Item e' l'intero stesso  
*
*   NB: per semplicita', i tipi sono definiti in itemkey.h
*****************************************************************************/

#include <stdio.h>
#include "itemkey.h"

Item new_item( Key k ) {
  return k;
}

void destroy_item( Item item ) {
}

void print_item ( Item item ) {
  if (item != NULLitem )
    printf( "%d ", item  );
}

void printl_item ( Item item ) {
  print_item( item );
  printf("\n"); 
}


Key key( Item item ) {
  if ( item == NULLitem )
    return NULLkey;
  return item;
}

int cmp( Key k1, Key k2 ) {
  return k1 - k2;
}

void print_key ( Key k ) {
  printf( "%d ", k );
}
void printl_key ( Key k ) {
  print_key( k );
  printf( "\n" );
}


