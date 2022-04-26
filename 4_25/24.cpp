
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
signed main(){
    OAO
    int n  , wt; cin>>n>>wt;

    vector<int> dp(wt+1);
    vector<int> W(n) , V(n);

    for(int i=0;i<n;i++){
        cin>>V[i]>>W[i];
    }

    for(int i=0;i<n;i++){
        for( int w=wt ; w-W[i]>=0 ; w--){
            dp[w] = max( dp[w] , dp[w-W[i]]+V[i]);
        }
    }
    
    cout<<dp[wt];
    return 0;
}

