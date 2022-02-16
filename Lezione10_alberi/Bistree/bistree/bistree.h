/* bistree.h */

#ifndef BISTREE_H
#define BISTREE_H

#include "../itemkey.h"
#include "bistree.h" 

typedef struct bit_node *Bit_node;

/********************************************************
* Funzioni generali per gli alberi binari 
*********************************************************/

Bit_node bit_new( Item );
void bit_destroy( Bit_node );

Item bit_item( Bit_node );
Bit_node bit_left( Bit_node );
Bit_node bit_right( Bit_node );

void bit_printnode( Bit_node );
void bit_printlnode( Bit_node p );

void bit_preorder( Bit_node );
void bit_inorder( Bit_node );
void bit_postorder( Bit_node );

/* bit_printassummary: visita in preordine e stampa il contenuto dell'albero
come nel sommario di un libro, indentando opportunamente */
void bit_printassummary( Bit_node p, int spaces );

/* bit_arr2tree: usando l'array a di lunghezza size, costruisce ricorsivamente 
 un albero con radice a[0] e tale che il nodo con chiave a[i] ha per figli
a[2*i+1] e a[2*i+2] */
Bit_node bit_arr2tree( Item *a, int size, int i );



/********************************************************
* Funzioni specifiche per alberi binari di ricerca 
*********************************************************/
/* bist_min: restituisce l'Item con chiave minima nel sottoalbero di radice p */
Item bist_min( Bit_node p );
Item bist_max( Bit_node p );

/* bist_orderprint: stampa il contenuto dell'albero di radice p in ordine crescente di
chiave. */
void bist_orderprint( Bit_node p );

/* bist_invorderprint: stampa il contenuto dell'albero di radice p in ordine decrescente di
chiave. */
void bist_invorderprint( Bit_node p );

/* bist_arr2tree: costruisce un albero binario di ricerca dall'array a: 
gli item sono inseriti partendo da a[0] e rispettando la
regola di inserimento per gli alberi di ricerca */
Bit_node bist_arr2tree( Item *a, int size );

/* bist_search: cerca il nodo con chiave k nell'albero di radice r. */
Item bist_search ( Bit_node r, Key k );

/* bist_search_it: versione ricorsiva di bist_search. */
Item bist_search_it( Bit_node p, Key k );

/* bist_insert: crea una foglia contenente item e la inserisce in ordine 
nell'albero di radice *r. Se esiste un nodo con la stessa chiave, non inserisce
niente.
NB: la radice *r può venire modificata, quindi ne passo l'indirizzo (in
alternativa si potrebbe restituire la nuova radice, modificando il prototipo
della funzione) */
void bist_insert( Bit_node *q, Item item );

/* bist_delete: cancella il nodo con chiave k (chiamiamo x tale nodo) dell'albero di radice *r. 
Restituisce -1 se non esiste nodo con chiave k.
Prima di cancellare x, viene scelto un nodo s che andrà a sostituire x:
  - se x non ha figli, x è sostituito dall’albero vuoto, quindi s vale NULL.
  - se x ha un unico figlio, s è il figlio di x.
  - se x ha due figli, allora s e` il maggiore fra i nodi minori di x; questo
    significa che s è il nodo più a destra nel sottoalbero sinistro di x.
NB: la radice *r può venire modificata, quindi ne passo l'indirizzo (in
alternativa si potrebbe restituire la nuova radice, modificando il prototipo
della funzione) */
int bist_delete( Bit_node *r, Key k );

#endif
