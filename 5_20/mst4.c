/*
Prim's Algorithm：
Prim's algorithm works by attaching a new edge to a single growing tree at each step:
Start with any vertex as a single-vertex tree; then add V-1 edges to it,
always taking next the minimum-weight edge that connects a vertex on the tree to a vertex not yet on the tree.

以下註解為參考，實際可依照自己邏輯完成 

*/


//完成.....  代表缺少一行關鍵

/*
  完成.....
  代表須完成此區塊
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 1000000

typedef struct node node;
typedef struct Graph Graph;
typedef struct mst mst;

struct node
{
  int vertex;
  int cost;
  struct node *next;
};

struct Graph
{
  node **adjLists;
};

int Size = 0 ;

struct  mst{
	int	start;
	int	end;
	int	cost;
};

mst pq[MAX];//Priority Queue
int pqIndex = -1;
int *visited;

//Prim's Algorithm using adjacency list
node *createNode(int,int);
Graph *graphInit(int);
void addEdge(Graph *graph, int, int ,int);
int getSize(Graph *graph, int);
node *getNode(Graph *graph, int, int);
void visit(Graph *graph, int);
void prim(Graph *graph, int);


/*
Priority Queue Operations 
此處操作上課說過，
每次加入新頂點後須要額外花費O(E)的時間找到最小成本的邊，
請將此處的處理方法改善成僅需(log V)的版本
(demo時必問，未改寫者滿分80)
*/
int isEmpty();
int isFull();
void enqueue(mst e);
int peek();
mst dequeue();
void display();



int main(int argc, char *argv[])
{

	int i, n, m;
	mst *e;
	mst *ptr;
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
	
	e = (mst *)malloc(sizeof(mst)*(m+1));
    Graph *graph = graphInit(n);

	// Graph size
	Size = n;

	int st , ed , wt ;
	for (i = 1; i <= m; i++) {
		ptr = &(e[i]);
		fscanf(fin, "%d, %d, %d", &st, &ed , &wt); //從txt讀入邊的資料
		printf("edge[%3d]: start = %3d, end = %3d, cost = %3d\n", i, st, ed , wt );//將讀入的邊印出
		
        addEdge( graph , st , ed , wt );
        addEdge( graph , ed , st , wt );

	}


    // debug

	// printf("debug : \n");

	// for(int i=0;i<n;i++){
	// 	node *adj = graph->adjLists[i];
	// 	printf( " %d , sz %d : " ,i,getSize(graph,i));
	// 	for(int j=0;j<getSize(graph,i) ;j++){
	// 		printf( "%d ", adj->vertex );
	// 		adj = adj->next;
	// 	}
	// 	printf("\n");
	// }


    printf("\ngrowing spanning trees...\n");
    //prim gogo~

 	visited = (int *)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
	{
	    visited[i] = 0;
	}

    
	for (i = 0; i < n ;i++)
	{
		if(!visited[i]){
            prim(graph, i);
        }
	}	
    fclose(fin);
    return 0;
}


Graph *graphInit(int vertices)
{
	// fix malloc error
	Graph *graph = (Graph*)malloc(sizeof(Graph));
	graph->adjLists = (node**)malloc(vertices * sizeof(node *));
	int i;
	for (i = 0; i < vertices; i++)
	{
    	graph->adjLists[i] = NULL;
	}
	return graph;
}

void Create(node **cur , int v ,int c){
    if( ! *cur ){
        *cur = (node*)malloc(sizeof(node));
        (*cur)->cost = c;
        (*cur)->vertex = v;
        (*cur)->next = NULL;

        // return cur;

        return;
    }

    Create( &(*cur)->next ,v,c);
}
void addEdge(Graph *graph, int i, int j,int cost)
{
	// node *newNode = 
	

	node **cur = &graph->adjLists[i];
	
    Create( cur,j,cost);
}

int getSize(Graph *graph, int v)
{
	int count = 0;
	node *temp = (node*)malloc(sizeof(node));
    temp = graph->adjLists[v];
	while(temp)
	{
		temp= temp->next;
		count++;
	}
	return count;
}

node *getNode(Graph *graph, int v, int index)
{
	int count = 0;
	node *temp = graph->adjLists[v];
	while (count < index)
	{
	    temp = temp->next;
	    count++;
	}
	//完成 將找到的頂點回傳

	return temp ;
}

void visit(Graph *graph, int v) {
    /*
	將選擇的頂點標記，
	並將此頂點相鄰的邊加入pq
	*/
	visited[v] = 1;

	int m = getSize(graph, v);

    node *adj = graph->adjLists[ v ];

    // printf( " visit : %d \n" ,v );
    for(int j=0;j<m;j++){
        
        if( !visited[ adj->vertex ] ){
            mst e;
            e.start = v;
            e.end = adj->vertex;
            e.cost = adj->cost;

            enqueue( e );

            // printf(" enq : %d " , adj->vertex );
        }

        adj = adj->next ; 
        // printf(" \n" );


    }
}

void prim(Graph *graph, int v)
{
	
	visit(graph, v);
    int weight = 0 ;

	while (!isEmpty())
	{
		mst e = dequeue();
        int v = e.start, w = e.end; 
        if (visited[v] && visited[w]) continue; 
        printf("start = %3d, end = %3d, cost = %3d\n", e.start, e.end, e.cost);//將選擇的最小成本邊印出
		
		//完成成本加總
		
        if (!visited[v]) visit(graph, v);
        if (!visited[w]) visit(graph, w);

        weight+=e.cost ;
	}
    printf("total cost: %d ", weight);//印出此生成樹總成本
}

int isEmpty(){
	
	return pqIndex<=0 ;
}

int isFull(){

	return pqIndex>= (Size-1) ;
}

void enqueue(mst e)
{
    if(!isFull())
    {
        pqIndex++;
        pq[pqIndex].start = e.start;
		pq[pqIndex].end = e.end;
		pq[pqIndex].cost = e.cost;
    }
}

int peek()
{
    int minCost = MAX;
    int edge = -1;
	
    for (int i = 0; i <= pqIndex; i++) 
    { 
        if (minCost == pq[i].cost ) // choose bigger edge
        {
            minCost = pq[i].cost;
            edge = i;
        }
        else if (minCost > pq[i].cost) {
            minCost = pq[i].cost;
            edge = i;
        }
    }
    
    return edge;
}

mst dequeue()
{
	mst e;
    if(!isEmpty())
    {
        int edge = peek();
		
        e.start = pq[edge].start;
        e.end = pq[edge].end;
        e.cost = pq[edge].cost;

        for (int i = edge; i < pqIndex; i++) {
            pq[i] = pq[i + 1];
        }
		//完成從pq移除最小邊

		pqIndex--;
    }

	return e;
}

/*
void display(){
    for (int i = 0; i <= pqIndex; i++) 
    {
        printf("(%d %d %d)\n",pq[i].start,pq[i].end,pq[i].cost);
    } 
}
*/