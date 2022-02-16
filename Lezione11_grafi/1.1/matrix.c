#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 8

/* nodo di lista di adiacenza */
struct node {
    int v;
    struct node *next;
};
struct graph {
    int V;
    int E;
    struct node **A;
};
typedef struct node **arrayDiList;
typedef struct graph *Graph;

// crea l'effettivo grafo
Graph creategraph(int v, int e, arrayDiList adi);

// conta gli archi presenti in una lista di adiancenza
int countEdge(arrayDiList adi);

// converte da matrice a lista di adiacenza
arrayDiList matr2ArrayDiListe (int **matr, int n);

// aggiunge un nodo alla lista di adiacenza
struct node *add_vertex(struct node *who, int go);

// stampa info grafo
void print_g_info(Graph g);

// alloca e inizializza con 0 una matrice nxn e ne restituisce l’indirizzo
int **new_matr( int n );

// converte una matrice in un doppio puntatore
int **matrToDoublePointer(int a[MAX_SIZE][MAX_SIZE], int n);

// print matr
void print_matrix(int **matr, int size);

int **f_matr( int **matr, int n );

int main(void){
  int matrix[][MAX_SIZE] =
  {
      {0,0,1,0,0,1,0,0},
      {0,0,0,0,0,0,0,0},
      {0,1,0,0,0,1,0,0},
      {0,0,1,0,0,0,0,0},
      {0,0,0,0,0,1,0,0},
      {0,0,0,0,0,0,1,0},
      {0,0,0,0,1,0,0,0},
      {0,0,0,0,0,0,1,0}
  };

  arrayDiList adi = matr2ArrayDiListe(matrToDoublePointer(matrix,MAX_SIZE), MAX_SIZE);
  Graph g = creategraph(MAX_SIZE, countEdge(adi), adi);
  //print_g_info(g);

  int **matr = new_matr(MAX_SIZE);
  //print_matrix(matrToDoublePointer(matrix,MAX_SIZE), MAX_SIZE);
  printf("\n");
  matr = f_matr(matrToDoublePointer(matrix,MAX_SIZE), MAX_SIZE);
  //print_matrix(matr, MAX_SIZE);

  adi = matr2ArrayDiListe(matr, MAX_SIZE);
  g = creategraph(MAX_SIZE, countEdge(adi), adi);
  print_g_info(g);

  return 0;
}

Graph creategraph(int v, int e, arrayDiList adi){
  Graph g = malloc(sizeof(struct graph));
  g -> V = v;
  g -> E = e;
  g -> A = adi;
  return g;
}

arrayDiList matr2ArrayDiListe (int **matr, int n){
  arrayDiList a = calloc(n,sizeof(struct node *));

  for(int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      if(matr[i][j]){
        a[i] = add_vertex(a[i], j);
      }
    }
  }

  return a;
}

struct node *add_vertex(struct node *who, int go){
  struct node *new = malloc(sizeof(struct node));
  new -> v = go;
  new -> next = who;

  return new;
}


void print_g_info(Graph g){
  printf("Vertici: %d\n",g -> V);
  printf("Archi: %d\n",g -> E);
  printf("\nLISTA ARCHI ADIACENZA\n");
  struct node *t;
  for(int i=0; i<MAX_SIZE; i++){
    for(t=g -> A[i]; t!=NULL; t = t -> next){
      printf("(%d,%d)\n", i, t -> v);
    }
  }
  printf("\n");
}

int countEdge(arrayDiList adi){
  struct node *t;
  int c=0;
  for(int i=0; i<MAX_SIZE; i++){
    for(t=adi[i]; t!=NULL; t = t -> next){
      c++;
    }
  }
  return c;
}

int **matrToDoublePointer(int a[MAX_SIZE][MAX_SIZE], int n){
  int **m = malloc(n * sizeof(int *));
  for(int i = 0; i < n; i++)
    m[i] = a[i];
  return m;
}

int **new_matr(int n){
  int **m = malloc(n * sizeof(int *));
	for(int i = 0; i < n; i++)
		m[i] = calloc(n, sizeof(int));
  return m;
}

int **f_matr( int **matr, int n ){
  int **matr2 = new_matr( n );
  for ( int i = 0; i < n; i++ ){
    for ( int j = 0; j < n; j++ ){
      if ( matr[i][j] == 1 ){
        for ( int k = 0; k < n; k++ ){
          if ( matr[j][k] == 1 ){
            matr2[i][k] = 1;
          }
        }
      }
    }
  }
  return matr2;
}

void print_matrix(int **matr, int size){
  for(int i=0; i<size; i++){
    printf("[");
    for(int j=0; j<size; j++)
      printf("%d ", matr[i][j]);
    printf("]\n");
  }
}
