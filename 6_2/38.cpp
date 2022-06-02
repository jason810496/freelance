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

int n ; 

struct E{
    int u,v,w;
    E(int U=0,int V=0,int W=0){
        u=U , v=V , w=W;
    }
};

vector<int> P ,Size;

inline int Find(int x){
    return ( x==P[x] ? x: P[x]=Find( P[x] ) );
}

void Union(int a,int b){
    a=Find(a);
    b=Find(b);
    if( a==b ) return ;

    if( Size[b] > Size[a] ) swap(a,b);

    Size[ a ]+=Size[ b ];
    P[b] = a;
}

signed main(){
    // OAO 
    cin>>n;
    for(int i=0;i<=n;i++) P.push_back(i);
    Size.resize(n+1,1);

    vector<E> edges;

    for(int i=1;i<=n;i++){
        for(int j=1 , wt ;j<i;j++){
            cin>>wt;
            edges.push_back( E(i,j,wt) );
        }
    }

    sort(all(edges) , [&](const E &a,const E &b){
        return (a.w < b.w );
    });

    int ans =0 ;
    for(auto &i:edges){
        cout<<i.w<<'\n';
        int u=i.u , v=i.v;
        if( Find( u )==Find(v) ) continue;
        ans+=i.w;
        cout<<u<<' '<<v<<' '<<i.w<<'\n';
        Union( u,v );
    }

    cout<<ans;
    return 0;
}