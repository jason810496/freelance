#include<bits/stdc++.h>
using namespace std;

#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first 
#define S second 
#define ll long long 
#define all(x) x.begin(),x.end()
const int INF = 1e9;
const int N = 1e5+5;

typedef pair<int,int> pii;

int n ,  m; 

vector< vector<int> > G;
signed main(){
    OAO 

    cin>>n>>m;
    G.resize( n+1 , vector<int>(n+1 , INF ) );

    for(int i=0 , a,b,w;i<m;i++){
        cin>>a>>b>>w;
        G[a][b] = G[b][a] = w;
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<G[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }

    priority_queue< pii , vector<pii>  , greater<pii> > pq;

    pq.push( {0,1} );
    vector<int> Dis(n+1,INF);
    Dis[1]=0;

    while(pq.size() ){
        int cur = pq.top().S;
        int d = pq.top().F;
        pq.pop();

        if( Dis[cur]!=d ) continue;

        for(int nxt=1; nxt<=n; nxt++ ){
            if( Dis[nxt] > d+G[cur][nxt] ){
                pq.push( { Dis[nxt]=d+G[cur][nxt] , nxt } );
            }
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        // cout<<Dis[i]<<' ';
        ans = max( ans , Dis[i] );
    }
    cout<<ans;
    
    return 0;
}

/*
5 4
1 2 4
2 3 3
1 4 2
4 5 1

*/