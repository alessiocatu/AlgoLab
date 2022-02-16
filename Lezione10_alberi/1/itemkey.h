/**************************************************************************
*   itemkey.h - Interfaccia per l'oggetto Item con chiave di tipo Key 
*
*   NB: per semplicita', il tipo Item e' definito qui anche se dipende
*   dalla scelta di implementazione!
*
**************************************************************************/

#ifndef ITEM_H
#define ITEM_H

/* Definizioni dei tipi - vanno modificate a seconda dell'implementazione 
Bisogna definire la costante ITEMTYPE. Valori possibili:
    ITEMTYPE == 1 -> int
    ITEMTYPE == 2 -> occ
    ITEMTYPE == 3 -> node
    ITEMTYPE == 4 -> interval
*/
#define ITEMTYPE 1

/* ITEMTYPE == int : Item interi con chiave intera */
#if ITEMTYPE == 1
  
  typedef int Key;
  #define NULLkey 0
  typedef Key Item;
  #define NULLitem 0

#endif 


/* ITEMTYPE == occ : Item e' un puntatore a occorrenza */
#if ITEMTYPE == 2
  
  struct occorrenza{
    char *word;
    int n;
  };
  typedef struct occorrenza *Item;
  #define NULLitem NULL
  typedef char *Key;
  #define NULLkey NULL

#endif
  
/* ITEMTYPE == node : Item e' un puntatore a nodo contenente chiave intera */
#if ITEMTYPE == 3
  
  typedef int Key;
  #define NULLkey 0
  
  typedef struct node {
    int info;
    struct node *next;
  }* Item;
  #define NULLitem NULL

#endif


  /* ITEMTYPE == interval : Item e' puntatore a intervallo, la chiave e' la fine dell'intervallo */
#if ITEMTYPE == 4
  
  typedef int Key;
  #define NULLkey 0
  
  typedef struct interval {
    int start;
    int end;
  }* Item;
  #define NULLitem NULL

#endif

/* Prototipi di funzione - non devono essere MAI modificati */
Item new_item( Key );
void destroy_item( Item );

void print_item ( Item );
void printl_item ( Item );

Key key( Item );
int cmp( Key, Key ) ;

void print_key ( Key );
void printl_key ( Key );

#endif
