#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;

#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define range(x) x.begin(),x.end()
#define MEM(x,i) memset(x,i,sizeof(x))
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,st,n) for(int i=st;i<=n;++i)
#define PB push_back
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> P;
const int MAX_N = 1e6+5;
const int INF = 1e9;

signed main(){
    OAO
    
    int Len , n;
    cin>>Len>>n ;

//  P : { {ed ,st} , val }
    vector<P> arr(n);
    for(auto &i:arr){
        cin>>i.F.S>>i.F.F;
        i.S = (i.F.F-i.F.S+1 );
    }

    sort(range(arr));

    vector<int> dp(n);

    dp[0] = arr[0].S;

    for(int i=1;i<n;i++){
        int L=0 , R=i-1 , contain=0;

        while( L<=R ){
            int mid =  (L+R)/2;
            if( arr[ mid ].F.F < arr[i].F.S ){
                contain = dp[ mid ];
                L=mid+1;
            }
            else R =mid-1;
        }

        dp[i] = max( contain +arr[i].S, dp[i-1] );
    }

    cout<<dp.back();
    return 0;
}
