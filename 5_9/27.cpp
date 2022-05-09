
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
    int n ; cin>>n;
    vector<ll> arr(n+1);
    vector<ll> Right(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    ll MX = -INF;
    ll ans = -INF ;
    ll sum = 0 ;
    int L=1, ansL ,ansR;

    for(int i=n;i>=1;i--){
        
        sum = max( sum +arr[i],arr[i] );

        MX = max(MX , sum );

        Right[i] = MX;
    }

    MX = -INF ; 
    sum =0;

    for(int i=1;i<n;i++){

        sum = max( sum +arr[i],arr[i] );

        MX = max(MX , sum );

        ans=max(ans , MX + Right[i+1] );
    }
    
    cout<<ans;
    return 0;
}

