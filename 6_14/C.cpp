#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first 
#define S second 
#define all(x) x.begin(),x.end()
#define PB push_back 
typedef pair<int,int> pii;
const int INF = 1e9;
const int N = 1005;

// Dijkstra 

signed main(){
    OAO
    int n  , m;
    cin>>n>>m;
    vector< vector< pii > > G(n+1);

    while( m-- ){
        int a,b,w;
        cin>>a>>b>>w;
        G[a].PB( {b,w} );
        G[b].PB( {a,w} );
    }

    vector<int> Dis(n+1 , INF);

    Dis[1] = 0;
    priority_queue< pii , vector<pii> , greater<pii> > pq;
    pq.push( {Dis[1] , 1 } ); 

    ll ans=0;

    while( pq.size() ) {
        int cur = pq.top().S;
        int D = pq.top().F;

        pq.pop();

        if( Dis[cur]!=D ) continue;

        bool flag = true;
        for(auto &e:G[ cur ]){
            int nxt = e.F;
            int wt = e.S;

            if( Dis[nxt] > Dis[cur] + wt ){
                Dis[nxt] = Dis[cur]+wt;
                pq.push( { Dis[nxt] , nxt } );

                flag = false;
            }
        }

        if( flag ) ans+=Dis[cur];
    }

    
    cout<<ans;

    return 0;
}