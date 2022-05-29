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

/*
    SCC : 
    AC by Kosaraju Algo

*/
vector<int> G[N],GT[N];
bitset<N> vis;

void Init(int n){
    for(int i=1;i<=n;i++){
        G[i].clear();
        GT[i].clear();
        vis[i]=0;
    }
}

void dfs(int cur,vector<int> *graph){
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
            
            G[u].push_back(v);
            GT[ v ].push_back( u );
            
            if(d==2){
                G[v].push_back(u);
                GT[ u ].push_back( v );
            }
        }
        
        int cnt1=0,cnt2=0;

        for(int i=1;i<=n;i++){
            if( !vis[i] ){
                dfs(i,G);
                cnt1++;
            }
            if( cnt1 >1 ) break;
        }

        vis=0;

        for(int i=1;i<=n ;i++){
            if( cnt2 >1 || cnt1 >1 ) break;
            if( !vis[i] ){
                dfs(i,GT);
                cnt2++;
            }
            
        }

        
        cout<<((cnt1>1 || cnt2>1) ? "0\n":"1\n");
    }

    return 0;
}