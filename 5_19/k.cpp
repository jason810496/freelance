
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


// AC


ll C(int x,int y){
    int y2 = x-y;
    y = min ( y ,y2 );

    ll Top =1 , Base = 1;
    ll T = x;
    ll B = 1;
    while( y--){
        Base*=B++;
        Top*=T--;
    }

    return Top / Base ;
}
signed main(){
    OAO
    int n ,  m ;
    ll k;
    cin>>n>>m>>k;
    // n members
    // k different lock 
    // reach security level m

    cout<<( C(n,m-1)<=k ? "YES":"NO" );

    return 0;
}

