
#pragma GCC optimize("O2")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// #include<iostream>
// #include<algorithm>
// #include<utility>
// #include<vector>
// #include<set>
// #include<map>
// #include<vector>
// #include<queue>
// #include<stack>
// #include<string>
// #include<sstream>
// #include<limits>
// #include<math.h>
// #include<unordered_map>
// #include <iomanip>
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

struct item{
    int val , ed , t;
};

inline bool cmp(const item &a ,const item &b){
    return ( a.ed < b.ed ? 1:(a.ed==b.ed ? a.t<b.t:0));
};
signed main(){
    OAO
    
    int n ; cin>>n;
    vector< item > arr(n);

    for(auto &i:arr){
        cin>>i.val>>i.ed>>i.t;
    }

    sort(range(arr), cmp);

    // cout<<"======\n";
    // for(auto &i:arr){
    //     cout<<i.val<<' '<<i.ed<<' '<<i.t<<'\n';
    // }
    // cout<<"======\n";

    vector<int> dp(n),Time(n);

    dp[0] = (arr[0].t<=arr[0].ed ? arr[0].val:0);
    Time[0] = (dp[0]==0 ? 0:arr[0].t);
    for(int i=1;i<n;i++){
        int L=0 , R=i-1 ,idx=-1;

        int Inclusive = arr[i].val;

        while( L<= R){
            int mid=(L+R)/2;

            if( arr[i].ed >= Time[mid]+arr[i].t){
                idx=mid;
                L=mid+1;
            }
            else R=mid-1;
        }

        if( idx!=-1 ) Inclusive+=dp[idx];

        // dp[i]=max( dp[i-1] , Inclusive );

        if( dp[i-1] > Inclusive ){
            Time[i] = Time[i-1];
            dp[i]=dp[i-1];
        }
        else{
            Time[i] = Time[i-1]+arr[i].t;
            dp[i]=Inclusive;
        }
    }

    cout<<dp[n-1];

    return 0;
}

