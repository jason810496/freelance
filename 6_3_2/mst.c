/*
Prim's Algorithm：
Prim's algorithm works by attaching a new edge to a single growing tree at each step:
Start with any vertex as a single-vertex tree; then add V-1 edges to it,
always taking next the minimum-weight edge that connects a vertex on the tree to a vertex not yet on the tree.

*/


/*
    建議先看的先備知識：

    真的要稍微看一下 Prim's Algorithm 是怎麼找 「 最小生成樹 （ 在後面稱作 MST ） 」 的
    還有實際 priority_queue ( 在後面都稱做 pq ) 優先隊列是做什用的 （ 比較正確的說是要去看一下 「 heap 」 這個資料結構的特性
    
    這邊簡單講 prim's 的話就是：

    先從隨變選取一個點做為起點，然後將 「 所有連到這個點的邊」 都放到 pq 中
    每次都從 pq 拿出 「 邊權最小的邊 」 並 「 經過檢查後 」加入 「 MST」中

    那需要檢查什麼？
    需要檢查加入 MST 的邊 「 是否會讓當前的 MST 形成環 ( cycle ) 」

    因為我們知道「 樹 」是不會有「 環 」 的 !
    所以
     if ( 當前的邊會使 MST 形成 cycle ) -> 這個邊不能選
    else : 加入 MST 中

    而我們將新的邊加入 MST 後
    又可以再遍歷到下一個點 又可以再重複剛才步驟 ( 將附近的邊加入 pq ，每次選最小的邊檢查後加入 MST ，又遍歷到新的點... )
    直到我們的 MST 完成為止 ！ 

*/


#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 1000000

typedef struct node node;
typedef struct Graph Graph;
typedef struct mst mst;

/*
    node 是 「鍊結串練 ( linked list )」的一個節點：

    可以看成這樣 ： 

        node 0x01               node 0x02
    |---------------|       |---------------|
    |   vertex      |       | vertex        |
    |   cost        |  ---> | cost          |   --> ...
    |   *next=0x02  |       | *next=...     |
    |---------------|       |---------------|

    而我們每個節點包含的資訊有：

    vertex : 當前節點 ( 這邊的節點跟上面鍊結串練的節點不同 ， 這邊的是指「 圖 」中的節點 )
    cost : 邊的權重

    * next : 指向下一個鍊結串練節點的「 指標 」 
*/
struct node
{
  int vertex;
  int cost;
  struct node *next;
};

/*
    Graph 是圖

   這邊是使用 「 接連串練 」來當作儲存的方式 （ 建議可以上網看一下圖，會比較有概念 ）
*/
struct Graph
{
  node **adjLists;
};

int Size = 0 ;

/*
    這邊的 mst 其實是 edge ( 就是「 邊 」 )

    如下 :
                    cost 
    ( start )------------------>( end )

    包含的資訊有： 

    start , end ： 一個邊連接的兩個端點 （ 所以 end 跟 start 交換也沒有關系 ） 
    cost : 邊權 

*/
struct  mst{
	int	start;
	int	end;
	int	cost;
};

/*
    這邊是在最上面提到的 Priority Queue
    因為 c 不像 c++ 有 「 class 」
    可以把 pq 包成一個 class 來使用
    所以就把 pq 的資訊開在 「 全域 」 （ 就是 main 之外的範圍 ）來使用

    mst pq[MAX] : 拿來當作 pq 的陣列 然後 type 是 mst ( 剛剛有說是拿來存 edge 的資訊 )
    pqIndex : 當前 pq 的 index ( 索引值 ) 就是現在 pq 最末端的 index 
*/
mst pq[MAX];//Priority Queue
int pqIndex = -1;

/*
    vistited :
    如字面所示，用來存 「 當前這個節點是否被拜訪過 」
*/
int *visited;

//Prim's Algorithm using adjacency list

/*
    這邊就是先宣告各個函式
    等一下才會寫到各個函式在幹麻
*/
node *createNode(int,int);
Graph *graphInit(int);
void addEdge(Graph *graph, int, int ,int);
int getSize(Graph *graph, int);
void visit(Graph *graph, int);
void prim(Graph *graph, int);


/*
    Priority Queue  的操作
    isEmpty ： 檢查當前優先隊列是否為空
    isFull : 檢查隊列滿了沒
    peek : 回傳當前隊列中 最小邊權的邊 的「 index 」
    dequeue : 將最小邊權的邊 從隊列中移出 並回傳
    display : 後來沒有用到
*/
int isEmpty();
int isFull();
void enqueue(mst e);
int peek();
mst dequeue();
void display();


/*
    主程式開始
*/
int main(int argc, char *argv[])
{

	int i, n, m;
	mst *e;
	mst *ptr;
	FILE* fin;
	
    /* 這邊是題目要讀入 「 檔名」， 在跑程式的時候會向這樣用：

        ./a.out g1.txt
        ./a.out g2.txt 
    
    */
	if (argc < 1) { // 判斷有沒有後面的參數 （ g1.txt 等 ）
		fin = stdin;
	}
	else {
		fin = fopen(argv[1], "rt");
		if (!fin) {
			fprintf(stderr, "file %s not found\n", argv[1]);
			exit(1);
		}
	}

    /*
        接著開始讀檔
        n 是題目的節點數量 （ 同時也是最大節點編號 ）
        m 是等一下要輸入幾個邊 
    */
	fscanf(fin, "%d, %d", &n, &m);
	printf("nodes = %3d, edges = %3d\n", n, m);
	
    /*
        這邊的 e 是 edges 的意思 ， 拿來存所有的邊的陣列
        而 e 是有在 main 函式最上方宣告 ， 並且是 mst* ( mst pointer )的 type  
    */
	e = (mst *)malloc(sizeof(mst)*(m+1));
    Graph *graph = graphInit(n); // 利用 graphInit 來初始化 graph 指標

	// Graph size
	Size = n;

	int st , ed , wt ;
	for (i = 1; i <= m; i++) {
		ptr = &(e[i]);
		fscanf(fin, "%d, %d, %d", &st, &ed , &wt); //從txt讀入邊的資料
		printf("edge[%3d]: start = %3d, end = %3d, cost = %3d\n", i, st, ed , wt );//將讀入的邊印出
		
        // 把邊加入圖中 , addEdge 在後面才會寫到
        addEdge( graph , st , ed , wt );
        addEdge( graph , ed , st , wt );
        /*
            因為是 「 無向圖 」 所以需要 st 指向 ed 的邊和 ed 指向 st 的邊 ,才是無向圖
            像這樣：

            st ----wt----> ed
            st <---wt----- ed 
        
        */
	}


    /*
        這邊是先 Debug 
        把整個「圖」先輸出出來檢查 
    
    */

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

    /*
        把 visited 陣列開好
    */
 	visited = (int *)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
	{
	    visited[i] = 0;
        // 初始化 visited 陣列
	}

    /*
        如果當前這個點沒有被拜訪 ， 就進行 Prim's 
        ( 但是以這些範例都只會執行一次 ，因為給的範例都是「一個連通圖 」 )
    
    */
	for (i = 0; i < n ;i++)
	{
		if(!visited[i]){
            prim(graph, i);
        }
	}
    // 結束讀檔
    fclose(fin);
    return 0;
}

/*
    初始化「圖 」 的函式，並回傳 「 圖的指標 」
*/
Graph *graphInit(int vertices)
{
	// 配置 「 圖」 的記憶體
	Graph *graph = (Graph*)malloc(sizeof(Graph));
    /*
        adjList 代表 adjacency list ( 相鄰列表 ) ， 可以看成一條一條的鍊結串練 （ 可以上網看一下示意圖 會比較好理解 ）

        不過大致會如下 ： 
        []->[]->[]->[]
        []->[]
        []->[]->[]->[]->[]->[]->[]
        []->[]
        []->[]->[]->[]->[]


        名詞比較 ： 
        「 相鄰列表 」 ： adjacency list ，是除存圖的一種方式 ，透過 「 接連串練 」實做
        「 接連串練 」 ： linked list ， 是透過指標構成牽後關係的資料結構
    */
	graph->adjLists = (node**)malloc(vertices * sizeof(node *));
	int i;
	for (i = 0; i < vertices; i++)
	{
    	graph->adjLists[i] = NULL;
        // 把鍊結串練初始好 
	}
	return graph;
    //  回傳剛剛配置的「 圖 」
}

/*
    這邊 Create 是把節點在「 圖中的相鄰列表的接連串練 」 建立起來的函式 
    這邊是透過 「 指標的指標 」 來達到 C++ 中 pass by reference 的效果 （ 可以查一下 pass by reference 的意思 ）
    並且用「 遞迴 」 來遍歷鍊竭串練  
    而 cur 就是存鍊結串練「 指標的指標 」 
    v : vertex ( 節點編號 )
    c : cost ( 邊的權重 ) 
    next : 當前鍊結串練 指向的瞎一個位置 （ 因為當前會是鍊結串練中的最後一個 ， 所以把 next 設為 NULL ） 
*/
void Create(node **cur , int v ,int c){

    // 遞迴停止條件 ： 當前是 「 空指標 ( NULL )」
    if( ! *cur ){
        // 配置記憶體 
        *cur = (node*)malloc(sizeof(node));
        (*cur)->cost = c;
        (*cur)->vertex = v;
        (*cur)->next = NULL;
        // 把當前節點的資訊設定好 

        return;
    }

    // 當前不是空節點的時候，記繼續遞迴 
    Create( &(*cur)->next ,v,c);
    /*
        &(*cur)->next : 這個看起來非常複雜的東西（ 建議先去看一下 deference 跟 pointer 相關的東西

        因為 cur 現在是 「 指標的指標 」
        所以 (*cur) 是 「 指標 」
        (*cur)->next 存取下一個節點的指標 ， 所以型態還是 「 指標 」
        因為傳值的方式是 「 指標的指標 」
        所以需要透過 & operator 取得 「 (*cur)->next  」這個東西的指標
        最後就是這串東西 ：   &(*cur)->next
        後面的函式也有透過這種技巧完成 
    */
}


/*
    addEdge ： 把「 邊 」的資訊存到 「 圖 」中

*/
void addEdge(Graph *graph, int i, int j,int cost)
{
    // 取得 「 接連串練 」 指標的指標
	node **cur = &graph->adjLists[i];
	// 透過剛剛的 Create 在鍊結串練中建立節點
    Create( cur,j,cost);
}

/*
    getSize : 取得「 相鄰列表 」中與 「 編號 v 的節點 」有連接其它節點的數量 
    （ 從圖論來講 ： 就是取得 v 的「度數」的函式 ）

*/
int getSize(Graph *graph, int v)
{
	int count = 0; // 紀錄接連串練的大小
	node *temp = (node*)malloc(sizeof(node)); // 宣告 node pointer 的變數 ， 用來遍歷接連串練 
    temp = graph->adjLists[v];
    // 利用 while 遍歷串練
	while(temp)
	{
		temp= temp->next; // 移到下一個指標
		count++;
	}
    // 回傳大小
	return count;
}

void visit(Graph *graph, int v) {
    /*
	將選擇的頂點標記，
	並將此頂點相鄰的邊加入pq
	*/
	visited[v] = 1;

    // 有 m 個點與 v 相連
	int m = getSize(graph, v);
    // 取得接連串練的 head
    node *adj = graph->adjLists[ v ];

    /*
        檢查與當前的點「 相鄰 」的點 是否被 「 拜訪過 」
        if ( 沒有被拜訪 ) 加入 pq 中
    */ 
    for(int j=0;j<m;j++){
        
        if( !visited[ adj->vertex ] ){
            mst e;
            e.start = v;
            e.end = adj->vertex;
            e.cost = adj->cost;

            enqueue( e );
            // 加入 pq 中

        }
        // 繼續遍歷串練 
        adj = adj->next ; 
    }
}

/*
    prim's 主程式

*/
void prim(Graph *graph, int v)
{
	
    // 先把節點 v 相鄰的邊都放入 pq 中
	visit(graph, v);
    // MST 大小
    int weight = 0 ;

    // 當前 pq 還有 edge
	while (!isEmpty())
	{
        // 把最小邊權的邊拿出來 
		mst e = dequeue();
        int v = e.start, w = e.end; 
        // 如果不會形成「 環 」 
        if (visited[v] && visited[w]) continue; 
        // 選擇這條邊
        printf("start = %3d, end = %3d, cost = %3d\n", e.start, e.end, e.cost);//將選擇的最小成本邊印出
		
		// 再把附近的邊都納入 pq 
        if (!visited[v]) visit(graph, v);
        if (!visited[w]) visit(graph, w);

        weight+=e.cost ;
        //完成成本加總
	}
    printf("total cost: %d ", weight);//印出此生成樹總成本
}

// pq 是否為空
int isEmpty(){
	
	return pqIndex<=0 ;
}

// pq 是否超過最大限制
int isFull(){

	return pqIndex>= (Size-1) ;
}

// 把邊加入 pq 中
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

/*
    peek 回傳「 最小邊權 」 的 index 

*/
int peek()
{
    int minCost = MAX; // 最小邊權的權重 
    int edge = -1; // index 
	
    for (int i = 0; i <= pqIndex; i++) 
    { 
        if (minCost == pq[i].cost ) // 如果邊權的最小的一樣 ， 就選比較後面的 
        {
            // 更新邊權 ＆ index 
            minCost = pq[i].cost;
            edge = i;
        }
        else if (minCost > pq[i].cost) { // 發現更小的邊權 
            // 更新邊權 ＆ index 
            minCost = pq[i].cost;
            edge = i;
        }
    }
    
    return edge; // 回傳 index 
}

/*
    dequeue : 
    回傳 pq 中最小的邊權的邊
*/
mst dequeue()
{
	mst e;
    if(!isEmpty())
    {
        /*
            剛剛的 peek是回傳最小邊權的邊的 index 
        */
        int edge = peek(); // 最小邊
		
        e.start = pq[edge].start;
        e.end = pq[edge].end;
        e.cost = pq[edge].cost;

        for (int i = edge; i < pqIndex; i++) {
            pq[i] = pq[i + 1];
        }
		//完成從pq移除最小邊 （ 把最小邊覆蓋掉

		pqIndex--;
        // 更新 pq 大小 
    }

	return e;
}
