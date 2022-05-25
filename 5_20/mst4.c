#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Pair Pair;
typedef struct List List;
typedef struct PQ PQ;
typedef struct Graph Graph;

struct Pair{
    int vertex , wt;
};


struct List{
    int Size,idx;
    Pair *arr;
};

void List_Init(List *self){
    self->idx=0;
    self->Size=1;
    self->arr = NULL;
}

void List_Resize(List *self,int n){
    self->arr = (Pair*)malloc( n* sizeof(Pair ));
    self->Size = n ;
}

int List_Empty(List *self){
    return self->Size;
}

void List_Push(List *self,Pair e){
    self->arr[ self->idx++ ] = e;
    self->Size++;
}

void List_Pop(List *self ){
    self->idx--;
}

struct Graph{
    List *adj;
    int *visited;
    int Size;
};


/*  Graph */
void Graph_Init(Graph *G,int n){

    G->adj = (List*)malloc( n*sizeof(List));
    for(int i=0;i<n;i++){
        Resize( &G->adj[i] , n);
    }

    G->visited = (int*)malloc( n*sizeof(int) );
    for (int i = 0; i < n; i++){
	    G->visited[i] = 0;
	}

    G->Size = n ;
}

void addEdge(Graph *G,int u, int v ,int wt){
    Pair e1;
    e1.vertex = v;
    e1.wt = wt;
    List_Push( &G->adj[u] , e1 );

    Pair e2;
    e2.vertex = u;
    e2.wt = wt;
    List_Push( &G->adj[v] , e2 );
}


/* PQ */
struct PQ{
    int Size;
    List arr;
};

inline int par(int i ){
    return (i-1)/2;
}

inline int lc(int i){
    return i<<1 + 1;
}

inline int rc(int i){
    return i<<1 + 2;
}

inline int PQ_Size(PQ *self){
    return self->Size;
}

void Heap_Up(PQ *self,int i){
    
    if( i && self->arr.arr[ par(i) ].wt > self->arr.arr[i].wt ){
        swap( self->arr.arr[i] , self->arr.arr[ par(i) ] );

        Heap_Up( self , par(i) );
    }
}

void Heap_Down(PQ *self ,int i ){
    int l = lc(i) , r = rc(i) ;
    int largest = i;

    if( l<= self->arr.idx && self->arr.arr[ l ].wt < self->arr.arr[ i ].wt ){
        largest = l;
    }
    if( r<=self->arr.idx && self->arr.arr[ r ].wt < self->arr.arr[ i ].wt ){
        largest = i;
    }

    if( largest!=i ){
        swap( self->arr.arr[i] , self->arr.arr[largest] );
        Heap_Down( self , largest );
    }
}

void PQ_Push(PQ *self,Pair e){
    List_Push( &self->arr , e );

    Heap_Up(self , self->arr.idx);
}

Pair PQ_Top(PQ *self){
    return self->arr.arr[0];
}

void PQ_Pop(PQ *self){
    self->arr.arr[0] = self->arr.arr[ self->arr.idx-1 ];
    List_Pop(&self->arr);
    Heap_Down(self,0);
}

/* Data Structure Finish */



int main(int argc, char *argv[])
{

	int i, n, m;

	FILE* fin;
	
	if (argc < 1) {
		fin = stdin;
	}
	else {
		fin = fopen(argv[1], "rt");
		if (!fin) {
			fprintf(stderr, "file %s not found\n", argv[1]);
			exit(1);
		}
	}
	fscanf(fin, "%d, %d", &n, &m);
	printf("nodes = %3d, edges = %3d\n", n, m);
	

    Graph graph;
    Graph_Init(&graph,n);


	int st , ed , wt ;
	for (i = 1; i <= m; i++) {
		fscanf(fin, "%d, %d, %d", &st, &ed , &wt); //從txt讀入邊的資料
		printf("edge[%3d]: start = %3d, end = %3d, cost = %3d\n", i, st, ed , wt );//將讀入的邊印出
		
        addEdge( &graph , st , ed , wt );
        addEdge( &graph , ed , st , wt );
	}

	printf("debug : \n");

	for(int i=0;i<n;i++){
		List adj = graph.adj[i];
		printf( " %d : " ,i);
		// printf( " size : %d\n" ,getSize(&graph,i) );
		for(int j=0;j<adj.idx ;j++){
			printf( "%d ", adj.arr[j] );
		}
		printf("\n");
	}

    //prim gogo~
	for (i = 0; i < n ;i++)
	{
		// if(!visited[i]) prim(&graph, i);
	}	
    fclose(fin);
    return 0;
}

