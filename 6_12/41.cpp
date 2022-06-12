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

int n; 

vector<int> P , sz;

inline int Find(int x){
    return (P[x]==x ? x:P[x] = Find( P[x] ) );
}

bool Union(int a,int b){
    a=Find(a);
    b=Find(b);
    if( a==b ) return false;
    if( sz[a]<sz[b]) swap(a,b);
    P[b] = a;
    sz[a]+=sz[b];
    
    return true;
}
signed main(){
    OAO
    cin>>n;
    vector< pii > vec(n);

    vector< pair<int , pair<int,int> > > edges;
    // init disjoint set
    P.resize( n );
    sz.resize( n );
    for(int i=0;i<n;i++) P[i]=i;
    for(int i=0;i<n;i++) sz[i]=1;
    for(auto &i:vec) cin>>i.F>>i.S;


    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            edges.PB( { abs(vec[i].F-vec[j].F)+abs(vec[i].S-vec[j].S) , { i,j } } );
        }
    }

    sort( all(edges) );

    ll ans=0;
    for(auto &e:edges){
        int wt = e.F;
        int a=e.S.F , b=e.S.S;

        if( Union(a,b) ){
            ans+=wt;
        }
    }

    cout<<ans;

    return 0;
}