/* nodo di lista di adiacenza */
struct node {
    int v;
    struct node *next;
};
struct graph {        /* struttura associata a ogni grafo */
    int V;            /* numero nodi  */
    int E;            /* numero archi */
    struct node **A;  /* array di liste di adiacenza */
};

//CREAZIONE GRAFICO
struct graph *creategraph(int nv, int ne){
    //alloco spazio per il grafo
    struct graph *g = malloc(sizeof(struct graph));
    if(!g) {
        fprintf(stderr,"Errore di Allocazione\n");
        exit(-1);
    }
    //setto il numero di edge
    g->E = ne;
    //setto il numero di vertex
    g->V = nv;
    //Alloco per ogni vertice nv spazio di un array di nodi
    //(così mi preparo alla lista di adiacenza)
    if(!(g->A = calloc(nv,sizeof(struct node *))))  {
        fprintf(stderr,"Errore di Allocazione\n");
        exit(-2);
    }
  return g;
}

//RIEMPIO GRAFO da file tramite fscanf
void readgraph(struct graph *g, FILE *fp) {
    int i,v1, v2;
    for(i = 0; i < g->E; i++) {
        fscanf(fp,"%d %d",&v1,&v2);
        //Qui devo inserire sia nella lista v che nella lista w
        //perche se esiste un legame tra (v,w) allora entrambi i verici avranno
        //l'adiacenza
        g->A[v1-1] = vertexinsert(g->A[v1-1],v2);
        g->A[v2-1] = vertexinsert(g->A[v2-1],v1);
    }
}

//Inserisco in testa il vertice (per liste di adiancenza)
struct node *vertexinsert(struct node *p, int k) {
    struct node *q = malloc(sizeof(struct node));
    if(!q) {
      fprintf(stderr,"Errore di Allocazione\n"); exit(-3);
    }
    q->v = k;
    q->next = p;
    return q;
}

//ATTRAVERSAMENTO in PROFONDITA' (pila)
//######### DFS ############
void dfs1(struct graph *g, int i, int *aux) {
    struct node *t;
    aux[i] = 1;
    //qui mi processo tutti i nodi nella lista di adiacenza
    for(t = g->A[i]; t; t = t->next)
        if(!aux[t->V - 1]) {
            printf("%d,",t->v);
            dfs1(g,t->V - 1,aux);
        }
}

void dfs(struct graph *g) {
    int i, *aux = calloc(g->V,sizeof(int)); //Allocazione di memoria per array di res
    if(!aux) {
      fprintf(stderr,"Errore di Allocazione\n");
      exit(-4);
    }
    for(i = 0; i < g->V; i++)
        if(!aux[i]) {
            printf("\n%d,",i+1);
            //per ogni vertice chiamo dfs1 con
            //g = GRAFO
            //i = nodo analizzato
            //aux = array di risultato
            dfs1(g,i,aux); //Per ogni vertice chiamo
        }
    free(aux);
}

//ATTRAVERSAMENTO in AMPIEZZA (Queue)
//######### BFS ############
void bfs1(struct graph *g, int i, int *aux) {
    struct node *t;
    intqueue *q = createqueue();
    enqueue(q,i);
    while(!emptyq(q)) {
        i = dequeue(q);
        aux[i] = 1;
        for(t = g->A[i]; t; t = t->next)
            if(!aux[t->v - 1]) {
                enqueue(q,t->v -1);
                printf("%d,",t->v);
                aux[t->v-1] = 1;
            }
    }
    destroyqueue(q);
}

//Analisi uguale al dfs
void bfs(struct graph *g) {
    int i, *aux = calloc(g->V,sizeof(int));
    if(!aux) { fprintf(stderr,"Errore di Allocazione\n"); exit(-4); }
    for(i = 0; i < g->V; i++)
        if(!aux[i]) {
            printf("\n%d,",i+1);
            bfs1(g,i,aux);
        }
    free(aux);
}
