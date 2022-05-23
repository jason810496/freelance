#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;

#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define D long double
#define range(x) x.begin(),x.end()
#define MEM(x,i) memset(x,i,sizeof(x))
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,st,n) for(int i=st;i<=n;++i)
#define PB emplace_back
typedef pair<int,int> pii;
const int MAX_N = 500005;
const int INF = 1e9;

int arr[MAX_N];

struct Node{
    int val , L , R ; 
    /*
        val : value of current Node
        L : left Range
        R : Right Range
    */

    Node(int v=0 , int l=0 ,int r=0){
        val=v, L=l , R=r;
    }
};


Node Tree[MAX_N<<1]; // 2N size of array

Node Merge(Node &Left , Node &Right ){

    return Node( max( Left.val ,Right.val ) , Left.L , Right.R );
        // return Node( max( Left.val ,Right.val ) ,min(Left.L,Right.R) , max(Left.R , Right.R) );
}

void Build(int n){
    for(int i=0;i<n;i++){
        Tree[ i+n ] = Node( arr[i] , i , i );
    }

    for(int i = n-1 ; i>0 ; i--){
        // Merge Segment 
        Tree[ i ] = Merge( Tree[ i<<1 ] , Tree[ i<<1|1 ] );
    }
}

// [ L, R ]
int Query(int L,int R,int root){
    int result = 0;

    // out of range
    if( Tree[ root ].R < L || Tree[ root ].L > R ) return -INF ;
    // current segment in [ L,R ]
    if( L<=Tree[ root ].L && Tree[ root ].R <= R ) return Tree[ root ].val ;

    int Mid = (L+R)>>1;

    return max( Query( L , Mid , root<<1 ) , Query( Mid+1 , R , root<<1|1 ) );
}

void Demo(){
    int n ,q; 
    cin>>n;

    for(int i=0;i<n;i++) cin>>arr[i];

    Build(n);

    cin>>q;

    int l ,r ;
    while(q--){
        cin>>l>>r;
        l-- , r--;
        if( l>r ) swap(l,r);
        cout<<Query(l,r,1)<<'\n';
    }

    for( int i=0;i<n*2;i++ ){
        cout<<i<<"  : "<<Tree[i].L<<' '<<Tree[i].R<<' '<<Tree[i].val<<'\n';
    }
}
int main(){
    OAO
    Demo();
    return 0;
}