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

int n  , k;
vector<int> val ,dp;
vector< vector<pii> > G;
priority_queue<int> ans;

void DFS(int cur , int par=-1){
    int child=0;
    dp[ cur ]+=val[cur];
    for(pii p:G[cur] ){
        int nxt=p.S;
        if( nxt == par ) continue;
        if(!child) dp[ nxt ] = dp[ cur ];
        child++;
        DFS(nxt,cur);
    }

    if( !child ){
        ans.push( dp[cur] );
    }
}

signed main(){
    OAO
    
    cin>>n>>k;
    val.resize(n+1);
    dp.resize(n+1);
    G.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }

    if( n==1 ){
        cout<<val[1]<<"\n";
        return 0;
    }

    for(int i=1 , u, v ;i<n;i++){
        cin>>u>>v;
        G[u].PB( {val[v],v });
        G[v].PB( {val[u],u } );
    }

    for(int i=1;i<=n;i++){
        sort(range(G[i]),greater<pii>());
    }

    DFS(1);

    int total=0;

    while(k--){
        // cout<<ans.top().F<<' '<<ans.top().S<<"\n";
        total+=ans.top();
        ans.pop();
    }

     cout<<total<<"\n";

    return 0;
}
