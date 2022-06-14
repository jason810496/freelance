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
    int n  , m , k;
    cin>>n>>m>>k;
    vector< vector< pii > > G(n+1);

    while( m-- ){
        int a,b,w;
        cin>>a>>b>>w;
        G[a].PB( {b,w} );
        G[b].PB( {a,w} );
    }

    vector<int> Target(k);
    for(int &i:Target) cin>>i;

    vector<int> Dis(n+1);
    vector<int> ans(n+1,INF);

    for(int &t : Target ){
        fill( all(Dis) , INF );
        Dis[ t ] = 0;
        priority_queue< pii , vector<pii> , greater<pii> > pq;
        pq.push( {Dis[t] , t } ); 

        while( pq.size() ) {
            int cur = pq.top().S;
            int D = pq.top().F;

            pq.pop();

            if( Dis[cur]!=D ) continue;

            for(auto &e:G[ cur ]){
                int nxt = e.F;
                int wt = e.S;

                    if( Dis[nxt] > Dis[cur] + wt ){
                        Dis[nxt] = Dis[cur]+wt;
                        pq.push( { Dis[nxt] , nxt } );
                }
            }
        }

        for(int i=1;i<=n;i++){
            ans[i] = min( ans[i] , Dis[i] );
        }
    }

    for(int i=1;i<=n;i++){
        cout<<(ans[i]==INF ? -1:ans[i])<<' ';
    }

    return 0;
}


/* case 1 :
10 13 2

2 8 8
1 4 4
4 3 4
3 7 7
6 1 15
7 1 2
4 5 8
8 7 9
7 5 3
10 1 12
5 10 13
4 9 4
3 6 10

9 2


*/

/* case 2:

15 14 4
11 1 17
8 9 14
3 7 28
3 10 10
2 13 24
9 11 17
3 12 25
11 2 29
11 14 7
11 3 18
7 5 16
11 5 7
6 4 21
7 11 7
1 2 11 14


*/