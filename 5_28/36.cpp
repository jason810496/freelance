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

vector<int> G[N];
bitset<N> InStk;

int dfn[N] , Low[N] , Contract[N], Time , sccID;
stack<int> stk;

void Init(int n){
    for(int i=1;i<=n;i++){
        dfn[i]=0;
        Low[i]=0;
        G[i].clear();
    }
    InStk=0;
    Time=1;
    sccID=0;
    while( stk.size() ) stk.pop();
}

void DFS(int cur, int par ){
    cout<<cur<<'\n';
    dfn[ cur ] = Low [ cur ] = Time++;

    stk.push( cur );
    InStk[cur]=1;

    for(int nxt : G[cur] ){
        if( nxt==par ) continue ;

        if( !dfn[ nxt ] ){
            DFS( nxt , cur );

            // Low[cur] = min( Low[cur] , Low[nxt] );
        }
        if( InStk[ nxt ] ){
            Low[ cur ] = min( Low[cur] , Low[ nxt ] );
        }
    }

    if( dfn[ cur ] == Low[ cur ] ){
        int x;
        do{
            x=stk.top();
            InStk[ x ] = 0;
            Contract[ x ] = sccID;

        }while( x!=cur);

        sccID++;
    }
}

signed main(){

    int n  , m ;

    while(cin>>n>>m){
        if( n==0 || m==0 ) return 0;
        Init(n);

        int u , v, d;
        while(m--){
            cin>>u>>v>>d;
            if(d==1){
                G[u].push_back(v);
            }
            else if(d==2){
                G[u].push_back(v);
                G[v].push_back(u);
            }
        }
        DFS( 1,0 );
        cout<<( sccID >0 ? 1:0)<<'\n';
    }

    return 0;
}