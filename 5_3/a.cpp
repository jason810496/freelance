
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
#define PB emplace_back
typedef pair<int,int> pii;
const int MAX_N = 50005;
const int INF = 1e9;

signed main(){
    OAO 
    ll dp[100];
    dp[1]=1;
    dp[2]=2;

    int n ; cin>>n;
    for(int i=3;i<=91;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    cout<<dp[n];
    return 0; 
}