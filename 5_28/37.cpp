#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first 
#define S second 
#define all(x) x.begin(),x.end()

typedef pair<int,int> pii;

const int INF = 1e9;
const int N = 1005;

/*
    SCC : 
    AC by Kosaraju Algo

*/
vector< vector<int> > G;
vector<int> Dfn , Low ;
vector<pii> AP , Bridge;
bitset<N> vis;

int n , m , Time=0;

void DFS(int cur ,int par ){
    Dfn[ cur ] = Low[ cur ] = ++Time;

    int child=0;
    bool isAP = false;

    for(int nxt : G[cur] ){
        if( nxt == par ) continue;

        if( !Dfn[ nxt ] ){
            DFS( nxt , cur );
            child++;

            if( Dfn[ cur ] <= Low[ nxt ] ) isAP = true ;

            Low [ cur ] = min( Low[ cur ] , Low[ nxt ] );
        }
        Low[ cur ] = min( Low [ cur ] , Dfn[ nxt ] );
    }

    // if( cur==par && child<2 ) isAP = false;
    if( isAP ) AP.push_back( {cur , 0 } );
}

void check(int cur,int i){
    vis[cur]=1;
    for(int nxt : G[cur] ){
        if( nxt == i ) continue;
        if( !vis[ nxt ] ) check(nxt ,i);
    }
}

int Score(int ith ){
    vis=0;
    int cnt=0;

    for(int i=0;i<n;i++){
        if( !vis[i] &&i!=ith ){
            check(i,ith );
            cnt++;
        }
    }

    return cnt;
}

signed main(){
    OAO
    cin>>n>>m;

    G.resize(n);
    Dfn.resize(n);
    Low.resize(n);

    int u , v;

    while( cin>>u>>v ){
        if(u<0 || v<0 ) break;
        G[u].push_back( v );
        G[v].push_back( u );

    }

    DFS(0,0);

    for(auto &i:AP){
        i.S = Score(i.F) ;
    }

    sort(all(AP) , [&](const pii &a,const pii &b){
        return (a.S==b.S ? a.F<b.S: a.S>b.S);
    });

    for(int i=0;i<m;i++){
        cout<<AP[i].F<<' '<<AP[i].S<<'\n';
    }

    // cout<<"== Bridge ==\n";

    // for(auto i: Bridge ){
    //     cout<<i.F<<' '<<i.S<<'\n';
    // }
    

    return 0;
}