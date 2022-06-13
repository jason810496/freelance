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
const int N = 2005;

int n; 

int P[N] ,sz[N];
string arr[N];

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

void Init(){
    for(int i=0;i<n;i++) P[i]=i;
    for(int i=0;i<n;i++) sz[i]=1;
}

int diff(int a,int b){
    int ans=0;
    for(int i=0;i<7;i++){
        if( arr[a][i]!=arr[b][i] ) ans++;
    }
    return ans;
}

void solve(){
    Init();
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector< pair<int , pair<int,int> > > edges;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int wt = diff(i,j);
            edges.push_back( { wt , { i,j} } );
        }
    }

    // sort( all(edges) , greater<pair<int ,pair<int,int>>>() );
    sort( all(edges) );


    ll ans=0;
    for(auto &e:edges){
        int wt = e.F;
        int a=e.S.F , b=e.S.S;

        if( Union(a,b) ){
            ans+=wt;
        }
    }

    // cout<<ans;

    cout<<"The highest possible quality is 1/"<<ans<<".\n";
}

signed main(){
    OAO
    while( cin>>n && n){
        solve();
    }

    return 0;
}