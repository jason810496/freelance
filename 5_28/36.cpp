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

int dfn[N] , Low[N] , Contract[N] , sccID , Time ;
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
    Time=0;
    while( stk.size() ) stk.pop();
}

void DFS(int cur ){
    dfn[ cur ] = Low[ cur ] = ++Time ;
    stk.push( cur );
    vis[ cur ]=1;

    for(int nxt : G[cur] ){
        if( !dfn[ nxt ] ){
            DFS( nxt );
            Low[ cur ] = min( Low[cur] , Low[nxt] );
        }
        else if( vis[ nxt ] ){
            Low[ cur ] = min( Low[ cur ] , dfn[ nxt] );
        }
    }

    if( Low[ cur ] == Low[cur] ){
        vis[ cur ]=0;
        Contract[ cur ]= ++sccID;

        while( stk.top()!=cur ){
            Contract[ stk.top() ] = sccID;
            vis[ stk.top() ] =0;
            stk.pop();
        }
        stk.pop();
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
        
        DFS(1);

        bool flag = true;

        for(int i=1;i<=n;i++){
            if( Low[i]!=1){
                flag=false;
                break;
            }
        }

        // for(int i=1;i<=n;i++){
        //     cout<<dfn[i]<<' ';
        // }
        // cout<<'\n';
        // for(int i=1;i<=n;i++){
        //     cout<<Low[i]<<' ';
        // }
        // cout<<'\n';
        // for(int i=1;i<=n;i++){
        //     cout<<Contract[i]<<' ';
        // }
        // cout<<'\n';
        // cout<<(sccID>1 ? 0:1)<<'\n';
        cout<<(flag ? 1:0)<<'\n';
    }

    return 0;
}