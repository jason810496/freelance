
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
signed main(){
    OAO
    int n ; cin>>n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    ll MX = -INF;
    ll sum = 0 ;
    int L=1, ansL ,ansR;

    for(int i=1;i<=n;i++){

        sum+=arr[i];
        if( arr[i] > sum ){
            L=i;
            sum = arr[i];
        }

        if( sum > MX ){
            MX = sum ;
            ansL = L ;
            ansR = i ;
        }
    }
    cout<<MX<<' '<<ansL<<' '<<ansR;
    return 0;
}

