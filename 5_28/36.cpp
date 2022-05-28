#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first 
#define S seccond 
#define all(x) x.begin(),x.end()

typedef pair<int,int> pii;

const int INF = 1e9;
const int N = 1005;

vector<int> G[N],G2[N];
bitset<N> vis;

int dfn[N] , Low[N] , Contract[N] , sccID;
stack<int> stk;

void Init(int n){
    for(int i=1;i<=n;i++){
        dfn[i]=0;
        Low[i]=0;
        Contract[ i ] =0;
        G[i].clear();
    }
    vis=0;
    sccID=0;
    while( stk.size() ) stk.pop();
}

void DFS(int cur){
    vis[ cur ]=1;

    for(int nxt : G[ cur ] ){
        if( !vis[nxt] ) DFS(nxt);
    }

    stk.push( cur );
}


void DFS2(int cur ,int k ){
    if( Contract[ cur ] ) return;

    Contract[ cur ] = k;

    for(int nxt:G2[cur] ){
        DFS2( nxt , k );
    }
}
signed main(){

    OAO
    int n  , m ;

    while(cin>>n>>m){
        if( n==0 || m==0 ) return 0;
        Init(n);

        int u , v, d;
        while(m--){
            cin>>u>>v>>d;
            if(d==1){
                G[u].push_back(v);
                G2[ v ].push_back( u );
            }
            else if(d==2){
                G[u].push_back(v);
                G[v].push_back(u);
                G2[ v ].push_back( u );
                G2[ u ].push_back( v );
            }
        }
        
        for(int i=1;i<=n;i++){
            if( !vis[i] ) DFS(i);
        }

        while( stk.size() ){
            if( !Contract[ stk.top() ] ){
                DFS2( stk.top() , ++sccID );
            }
            stk.pop();
        }

        // for(int i=1;i<=n;i++){
        //     cout<<Contract[i]<<' ';
        // }
        // cout<<"\n";

        cout<<(sccID>1 ? 0:1)<<'\n';

    }

    return 0;
}