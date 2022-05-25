
#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define D long double
#define range(x) x.begin(),x.end()
#define MEM(x,i) memset(x,i,sizeof(x))
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,st,n) for(int i=st;i<=n;++i)
#define PB emplace_back
typedef pair<int,int> pii;
const int MAX_N = 500005;
const int INF = 1e9;

signed main(){
    OAO
    
    int n , m ,k;
    cin>>n>>m>>k;

    vector<pii> vec(k);

    for(auto &i:vec){
        cin>>i.F>>i.S;
    }

    vec.push_back( { n,m } );

    sort( range(vec) ,[](const pii &a,const pii &b){
        return ( a.F==b.F ? a.S>b.S : a.F<b.F );
    });

    // cout<<"======\n";
    // for(auto i:vec){
    //     cout<<i.F<< ' '<<i.S<<'\n';
    // }
    vector<int> LIS;
    
    for(pii &P:vec ){
        int cur =  P.S ; 
        auto it = lower_bound(range(LIS) , cur ) ;
        if( LIS.empty() || LIS.back() < cur ) LIS.push_back( cur );
        else *it = cur ;
    }

    cout<<LIS.size()<<'\n';
    return 0;
}

