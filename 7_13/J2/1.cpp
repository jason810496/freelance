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
const int MAX_N = 1e6+5;
const int INF = 1e9;

signed main(){
    OAO
    int n , ans=1 , x;
    unordered_map<int,int> Map; 
    cin>>n;
    while(n--){
        cin>>x;
        Map[x]++;
        ans = max( ans , Map[x] );
    }

    cout<<ans<<"\n";
    return 0;
}
