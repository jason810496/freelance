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

vector<int> G[N],GT[N];
// bitset<N> vis;
bool vis[N];

// int dfn[N] , Low[N] , Contract[N] , sccID , Time ;
// stack<int> stk;

void Init(int n){
    for(int i=1;i<=n;i++){
        // dfn[i]=0;
        // Low[i]=0;
        // Contract[ i ] =0;
        G[i].clear();
        GT[i].clear();
        vis[i]=0;
    }
    // vis=0;
    // sccID=0;
    // Time=0;
    // while( stk.size() ) stk.pop();
}

// void DFS(int cur ){
//     dfn[ cur ] = Low[ cur ] = ++Time ;
//     stk.push( cur );
//     vis[ cur ]=1;

//     for(int nxt : G[cur] ){
//         if( !dfn[ nxt ] ){
//             DFS( nxt );
//             Low[ cur ] = min( Low[cur] , Low[nxt] );
//         }
//         else if( vis[ nxt ] ){
//             Low[ cur ] = min( Low[ cur ] , dfn[ nxt] );
//         }
//     }

//     if( Low[ cur ] == Low[cur] ){
//         vis[ cur ]=0;
//         Contract[ cur ]= ++sccID;

//         while( stk.top()!=cur ){
//             Contract[ stk.top() ] = sccID;
//             vis[ stk.top() ] =0;
//             stk.pop();
//         }
//         stk.pop();
//     }
// }

void dfs(int cur,vector<int> *graph){
    // cout<<cur<<' ';
    vis[cur]=1;
    for(int nxt : graph[cur] ){
        if( !vis[nxt] ) dfs(nxt, graph );
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
                GT[ v ].push_back( u );
            }
            else if(d==2){
                G[u].push_back(v);
                G[v].push_back(u);
                GT[ v ].push_back( u );
                GT[ u ].push_back( v );
            }
        }
        
        // DFS(1);
        int cnt1=0,cnt2=0;

        for(int i=1;i<=n;i++){
            if( !vis[i] ){
                dfs(i,G);
                cnt1++;
                // cout<<" cnt1"<<i<<'\n';
            }
        }

        // vis=0;
        for(int i=1;i<=n;i++) vis[i]=0;

        for(int i=1;i<=n;i++){
            if( !vis[i] ){
                dfs(i,GT);
                cnt2++;
                // cout<<" cnt2"<<i<<'\n';
            }
        }

        
        cout<<((cnt1>1 || cnt2>1) ? "0\n":"1\n");
    }

    return 0;
}