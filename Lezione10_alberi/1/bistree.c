/* bistree.c */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../itemkey.h"
#include "bistree.h"


struct bit_node {
  Item item;
  struct bit_node *l, *r;
};


/****************************************
 Funzioni generali su alberi binari 
****************************************/

Bit_node bit_new( Item item ) {
  Bit_node new = malloc( sizeof( struct bit_node ) );

  if ( new == NULL ) {
    printf( "err malloc\n" );
    exit(-1);
  }
  
  new -> l = new -> r = NULL;
  new -> item = item;
  return new;
}

void bit_destroy( Bit_node p ) {
  destroy_item( bit_item(p) );
  free(p);
}

Item bit_item( Bit_node p ) {
  if (p) return  p -> item;
  else return NULLitem;
}

Bit_node bit_left( Bit_node p ) {
  if (p) return  p -> l;
  else return NULL;
}

Bit_node bit_right( Bit_node p ) {
  if (p) return  p -> r;
  else return NULL;
}

void bit_printnode( Bit_node p ) {
  print_item ( bit_item(p) );
}

void bit_printlnode( Bit_node p ) {
  printl_item ( bit_item(p) );
}

void bit_preorder( Bit_node p ){
  if ( p ) {
    bit_printnode( p );
    bit_preorder( p -> l );
    bit_preorder( p -> r );
  }
}

void bit_inorder( Bit_node p ){
  if ( p ) {
    bit_inorder( p -> l );
    bit_printnode( p );
    bit_inorder( p -> r );
  }
}

void bit_postorder( Bit_node p ){
  if ( p ) {
    bit_postorder( p -> l );
    bit_postorder( p -> r );
    bit_printnode( p );
  }
}


void bit_printassummary( Bit_node p, int spaces ){
  int i;
  for ( i = 0; i < spaces; i++ )
    printf( "  " );
  printf( "*" );
  
  printl_item( bit_item( p ) );
  if ( bit_left(p) || bit_right(p) ) {
    bit_printassummary( bit_left(p), spaces + 1 ); 
    bit_printassummary( bit_right(p), spaces + 1 );
  }
}

Bit_node bit_arr2tree( Item *a, int size, int i ) {
  Bit_node p;

  if ( i >= size )
    return NULL;

  p = bit_new( a[i] );
  p -> l = bit_arr2tree( a, size, 2*i + 1 );
  p -> r = bit_arr2tree( a, size, 2*i + 2 );
  
  return p;
}

/*****************************************************
* Funzioni specifiche su alberi binari di ricerca
*****************************************************/

Item bist_min( Bit_node p ) {
  if ( p == NULL ) return NULLitem;
  while ( p -> l ) p = p -> l;
  return p -> item;
}


Item bist_max( Bit_node p ) {
  if ( p == NULL ) return NULLitem;
  while ( p -> r ) p = p -> r;
  return p -> item;
}


void bist_orderprint( Bit_node p ) {
  bit_inorder( p );
}

void bist_invorderprint( Bit_node p ) {
  if ( p ) {
    bist_invorderprint( p -> r );
    print_item( bit_item(p) );
    bist_invorderprint( p -> l );
  }
}

Bit_node bist_arr2tree( Item *a, int size ) {
  Bit_node r = NULL;
  int i;
  for ( i = 0; i < size; i++ )
    bist_insert( &r, a[i] );
  
  return r;
}


/* Funzione ausiliaria : bist_searchfather
cerca il nodo con chiave k nel sottoalbero di radice r,
ne memorizza l'indirizzo in p e memorizza l'indirizzo del padre in pf.
Nel caso in cui non esistano nodi con chiave k, restituisce -1, *p e' NULL
e *pf punta alla foglia alla quale attaccare eventualmente k */
int bist_searchfather ( Bit_node r, Key k, Bit_node *pf, Bit_node *p ) {

  int res;
  *pf = NULL;
  *p = r;
  if ( !r )
    return -1;

  while ( *p && ( res = cmp( k, key( (*p) -> item ) ) ) != 0 ) {
    *pf = *p;
    *p = res < 0 ? (*p) -> l : (*p) -> r;
  }

  if ( *p == NULL ) /* non ci sono nodi con chiave k */
    return -1;
  return 0;
}


Item bist_search ( Bit_node r, Key k ) {
  Bit_node pf = NULL, p = NULL;  
  if ( bist_searchfather ( r, k, &pf, &p ) == 0 )
    return p -> item;
  else
    return NULLitem;
}


Item bist_search_it( Bit_node p, Key k ) {
  if ( p ) {
    int res;
    while ( p && ( res = cmp( k, key( p -> item ) ) ) != 0 )
      p = res < 0 ? p -> l : p -> r;
  }
  if ( p == NULL ) return NULLitem;
  else return p -> item;
}


void bist_insert( Bit_node *r, Item item ) {
  Bit_node qf, q = *r, new = bit_new( item );
  Key k = key(item);

  if ( q == NULL ) { 
    /* inserisco nell'albero vuoto */
    *r = new;
    return;
  }
  
  if ( bist_searchfather ( *r, k, &qf, &q ) == 0 ) {
    /* la chiave c'e' gia' , non inserisco niente */
    printf( "%d c'e' gia' \n" );
    return;
  }
  
  /* qf e' il padre del nuovo nodo */
  if ( cmp (k, key( qf -> item ) ) < 0 )
    qf -> l = new;
  else 
    qf -> r = new; 
}


int bist_delete( Bit_node *r, Key k ) {
  Bit_node x, xf, s = NULL;
  
  if ( bist_searchfather ( *r, k, &xf, &x ) == -1 )
    /* non ci sono nodi con chiave k, non faccio niente! */
    return -1;

  /* cerco il nodo s che deve sostituire x */
  if ( x -> l == NULL && x -> r == NULL ) /* x non ha figli */
      s = NULL;
  else if ( x -> l == NULL || x -> r == NULL )
      s = x -> l != NULL ? x -> l : x -> r; /* x ha un solo figlio */
  else {  
    /* x ha due figli; cerco s, il massimo del sottoalbero di sinistra di x */
    Bit_node sf = x;
    s = x -> l;
    while ( s -> r ) {
      sf = s;
      s = s -> r;
    }

    /* s non ha figlio destro: avrÃ  come nuovo figlio destro il figlio destro di x */
    s -> r = x -> r;

    /* se s Ã¨ figlio destro di sf, di sicuro non ha figlio destro */
    if ( sf -> r == s ) {
      sf -> r = s -> l;
      s -> l = x -> l;
    }
  }

  /* sostituisco x con s. Se x e' la radice, diventa la nuova radice */
  if ( x == *r ) // x e' la radice 
    *r = s; // nuova radice 
  else if ( xf -> l == x) // x e' figlio sinistro
    xf -> l = s;
  else // x Ã¨ figlio destro
    xf -> r = s;

  bit_destroy(x);
  return 0;
}
