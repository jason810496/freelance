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

int n  , m ;

vector< vector<int> > G;

int P[N],Sz[N],Group;

void Init(){
    for(int i=1;i<=n;i++){
        P[i] = i;
        Sz[i]=0;
    }
    G.resize(n+1);
    G.clear();
}

inline int Find(int x){
    return (P[x]==x ? x: P[x]=Find(x) );
}

void Union(int a,int b){
    a=Find(a);
    b=Find(b);
    if( a==b ) return ;
    
    if( Sz[a] < Sz[b] ) swap(a,b);

    Sz[a]+=Sz[b];
    Sz[b]=0;
    P[b]=a;
}

signed main(){


    while(cin>>n>>m&&n&&m){
        Init();
        int u , v, d;
        while(m--){
            cin>>u>>v>>d;
            G[u].push_back(v);
            if(d==2) G[v].push_back(u);
        }

    }

    return 0;
}