#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

typedef struct Pair Pair;
typedef struct List List;
typedef struct PQ PQ;
typedef struct Graph Graph;

/* PQ define */
#define par(i) (i-1)/2

#define lc(i) i<<1+1

#define rc(i) i<<1+2

struct Pair{
    int vertex , wt;
};


struct List{
    int Cap,Size,idx;
    Pair *arr;
};

void Swap(void *a,void *b ,size_t t){
    void *temp = malloc(t);

    memcpy(temp,a,t);
    memcpy(a,b,t);
    memcpy(b,temp,t);
}

void List_Init(List *self){
    self->idx=-1;
    self->Size=0;
    self->arr = NULL;
}

void List_Expand(List *self){
    Pair temp[self->idx];
    self->Cap = self->Size*2+10;

    for(int i=0;i<self->Size;i++){
        temp[i] = self->arr[i];
    }
    // copy old 

    self->arr = (Pair*)malloc( self->Cap *sizeof(Pair) );

    for(int i=0;i<self->Size;i++){
        self->arr[i] = temp[i];
    }
}

void List_Resize(List *self,int n){

    if( n < self->Cap ) return ;
    
    while( self->Cap < n ){
        List_Expand( self );
    }
}

int List_Size(List *self){
    return self->Size;
}

void List_Push(List *self,Pair e){
    if( self->idx >= self->Size-1 ){
        List_Expand( self );
    }

    self->arr[ ++self->idx ] = e;
    self->Size++;
}

Pair List_back(List *self){
    return self->arr[ self->idx ];
}

Pair List_Front(List *self){
    return self->arr[0];
}

void List_Pop(List *self ){
    self->idx--;
    self->Size--;
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
        List_Resize( &G->adj[i] , n);
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

inline int PQ_Size(PQ *self){
    return self->Size;
}

void Heap_Up(PQ *self,int i){
    
    if( i && self->arr.arr[ par(i) ].wt > self->arr.arr[i].wt ){
        // swap( self->arr.arr[i] , self->arr.arr[ par(i) ] );
        Swap( &self->arr.arr[i] , &self->arr.arr[ par(i) ] , sizeof(self->arr.arr[i]) );

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
        // swap( self->arr.arr[i] , self->arr.arr[largest] );
        Swap( &self->arr.arr[i] , &self->arr.arr[largest] , sizeof( self->arr.arr[i] ) );
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


int main(){
    int n; 
    scanf( "%d" , &n);

    int x; 
    PQ pq;

    for(int i=0 ;i<n;i++){
        scanf( "%d" , &x);
        Pair p;
        p.vertex =x;
        p.wt =x ;
        PQ_Push( &pq , p);
    }

    for(int i=0;i<n;i++){
        Pair p = PQ_Top( &pq);
        printf( "%d\n" , p.vertex );
        PQ_Pop( &pq );
    }
    return 0 ;
}