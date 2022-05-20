
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
const int MAX_N = 1e5+5;
const int INF = 1e9;

signed main(){
    OAO
    int n ; cin>>n ;

    vector<ll> process(n) , Start(n) , End(n);

    for(int i=0;i<n;i++){
        cin>>process[i]>>Start[i]>>End[i];
    }

    int q; cin>>q;

    while( q-- ){
        int L , R ;
        ll ans = 0 , t ;
        cin>>L>>R>>t;
        L--;
        R--;
        

        for(int j=  L  ;j<=R  ; j++){
            t = max( t, Start[j] ) + process[j];
            ans += max( 0LL , t - End[j] );
        }

        cout<<ans<<"\n";
        
    }

    return 0;
}

