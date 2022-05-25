
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

#define Fix 870000
#define Wt 1000
ll ans = 0 ;

vector< vector<int> > G;
set<int> Target;
vector<int> Dis ; 

int cnt =0 , Mx=INF , Node=INF , root ;

int DFS(int cur , int par){
    cout<<cur<<' ';

    int child = 0 , smallest = INF , temp ; 
    for(int nxt : G[cur] ){
        if( nxt == par ) continue ;

        temp = DFS( nxt , cur );
        
        if( temp!=0 && smallest > temp ){
            temp = smallest;
        }

        child+=temp ;
    }

    cnt+= child ; 
    
    return child + (Target.find( cur )!=Target.end() ? 1:0) ;
}

signed main(){
    OAO
    
    int  n ,q ;

    cin>>n>>q;
    G.resize(n+1);
    Dis.resize(n+1);

    for(int i=1;i<n;i++){
        int u , v ; cin>>u>>v;
        G[u].push_back( v );
        G[v].push_back( u );
    }

    for(int i=0 , x ;i<q;i++){
        cin>>x;
        Target.insert( x );
    }

    ans+= Fix*q;

    
    for(auto &it:Target){
        cnt = 0;
        
        root = it ;
        cout<<"rt : "<<root<<'\n';
        cout<<" DFS :\n";
        DFS( it , -1 );
        cout<<"===\n";

        if( cnt < Mx ){
            Mx = cnt;
            Node = it ;
        }
        if( cnt == Mx ){
            Node = min( Node , it );
        }

        cout<<it<<' '<<cnt<<'\n';
    }


    // cout<<ans; 

    cout<<'\n';
    for(int i=1;i<=n ; i++){
        cout<<i<<" :  "<<Dis[i]<<'\n';
    }


    return 0 ;
}
