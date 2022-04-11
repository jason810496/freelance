
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

/*
codeforce 1295C
*/
void slove(){
    string A,B;
    cin>>A>>B; 
    int n=A.size() , m=B.size();
    vector<vector<int> > dp(n+1,vector<int>(27,-1));

    for(int i=n-1;i>=0;i--){
        for(int j=0;j<26;j++){
            dp[i][j]=dp[i+1][j];
        }
        dp[i][ A[i]-'a' ] = i;
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<26;j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }

    int cnt=0 , idx=0 ,ans=1;

    while(cnt < m){
        if(dp[idx][ B[cnt]-'a' ] ==-1 ){
            if(idx==0 ){
                ans=-1;
                break;
            }
            else{
                idx=0;
                ans++;
                continue;
            }
        }

        idx = dp[idx][ B[cnt]-'a' ]+1;
        cnt++;
    }

    cout<<ans<<'\n';
}

signed main(){
    OAO
    int t ; cin>>t;
    while(t--){
        slove();
    }
    return 0;
    
}