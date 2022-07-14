#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;

#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define range(x) x.begin(),x.end()
#define MEM(x,i) memset(x,i,sizeof(x))
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,st,n) for(int i=st;i<=n;++i)
#define PB push_back
typedef pair<int,int> pii;
const int MAX_N = 1e6+5;
const int INF = 1e9;


vector< vector<pii> > G;
vector<int> dp;

int ans =0 ; 

void DFS(int  cur ,int par =-1){
    dp[ cur ]++;
    for(pii &p:G[cur] ){
        int nxt = p.S;
        if( nxt == par ) continue;
        DFS( nxt , cur );
        dp[cur]+= dp[nxt];
    }
}

void DFS2(int cur,int par,int last){
    
    int state = last ;
    // cout<<cur<<"\n";
    dp[cur] = (last>0 ? 0:1);

    for(pii &p:G[cur] ){
        int nxt = p.S;
        if( nxt == par ) continue ; 
        DFS2( nxt , cur , --last);
        dp[ cur ] += dp [ nxt ];
    }
    if( state >0 ){
        ans+=dp[ cur ];
    }
}

signed main(){
    OAO
    int n , k ,last;
    cin>>n>>k;
    last = n-k;

    G.resize( n+1 );
    dp.resize(n+1);

    for(int i =1 , u, v;i<n;i++){
        cin>>u>>v;
        G[u].push_back( {0,v} ); 
        G[v].push_back( {0,u} );
    }

    DFS(1);

    // for(int i=1;i<=n;i++) cout<<dp[i]<<' ';
    // cout<<"\n";

    for(int i=1;i<=n;i++){
        for(pii &p:G[i]){
            p.F = dp[ p.S ];
        }
        sort(range(G[i]) , greater<pii>());
    }
    
    DFS2(1 , -1 , last );

    // for(int i=1;i<=n;i++) cout<<dp[i]<<' ';
    // cout<<"\n";

    cout<<ans;
    return 0;
}
