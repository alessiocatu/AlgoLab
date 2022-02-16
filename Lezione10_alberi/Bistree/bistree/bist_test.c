/* bist_test.c 
Genera a caso una sequenza di interi (Item), li memorizza in un vettore, e da questo costruisce un albero binario di ricerca.
Poi stampa l'albero come in un sommario e testa le funzioni min, max, print_order, print_inveorder, search, delete...
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../itemkey.h"
#include "bistree.h"

#define N 5

int main( void ) {
  Item a[N+10] = { 69, 28, 89, 10, 7, 12, 71, 70, 120, 78, 83, 80 };
  int n = 12, i;
  Bit_node root = NULL, p;

  srand( time(NULL) );
//   n = 10 + rand() % N;
  printf( "n = %d\n", n );
  for ( i = 0; i < n; i++ ) {
//     a[i] = 1 + rand() % 100;
    printf( "i = %d, a[i] = %d\n", i, a[i] );
    bist_insert( &root, a[i] );
  }
  bit_printassummary( root, 0 );

  printf( "\nmin: " );
  printl_item( bist_min(root) );
  
  printf( "max: " );
  printl_item( bist_max(root) );
  
  printf( "in ordine: " );
  bist_orderprint( root );
  printf( "\n" );
  
  printf( "in ordine inverso: " );
  bist_invorderprint( root );
  printf( "\n" );
  
  bist_delete( &root, 89 );
  bit_printassummary( root, 0 );
  
  return 0;
   /*
  for ( i = 0; i < n; i++ ) {
    int j = rand() % n/2;
    int res = bist_delete( &root, a[j] );
    printf( "delete %d: \n", a[j] );

    if ( res == 0 ) {
      printf( "in ordine: " );
      bist_orderprint( root );
      printf( "\n" );
    }

  }
  bit_printassummary( root, 0 );*/
    /*
  for ( i = 0; i < n; i++ ) {
    int j = rand() % n;
    printf( "delete %d: ", a[j] );
    bist_delete( &root, a[j] );
  }
    
  for ( i = 0; i < 3; i++ ) {
    int j = rand() % n;
    printf( "delete %d: ", j );
    bist_delete( &root, j );
  }
    */
  
  
/*  printf( "radice: " );
  print_node( root );
  printf( " - cerco: " );
  p = bit_right(bit_right(bit_right(root)));
  printl_node( p );
  printl_node( bist_father( root, root ) );*/
  
  return 0;
}







