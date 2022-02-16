/* arra2tree.c 
Genera a caso una sequenza di interi (Item), li memorizza in un vettore, e da questo costruisce un albero binario.
Poi stampa l'albero come in un sommario ed effettua le tre visite preorder, inorder, postorder.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../itemkey.h"
#include "bistree.h"

#define N 20

int main( void ) {
  Item a[N];
  int n, i;
  Bit_node root = NULL;

  srand( time(NULL) );
  n = rand() % N;

  for ( i = 0; i < n; i++ ) {
    a[i] = 1 + rand() % 100;
    printf( "%d ", a[i] );
  }
  
  printf( "\n" );
  root = bit_arr2tree( a, n, 0  );

  bit_printassummary( root, 0 );
  printf( "\n" );
  
  printf( "preordine: " );
  bit_preorder( root );
  printf( "\n" );

  printf( "inordine: " );
  bit_inorder( root );
  printf( "\n" );
  
  printf( "postordine: " );
  bit_postorder( root );
  printf( "\n" );

  return 0;
}







