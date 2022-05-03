
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

void slove(){
    int n ;
    cin >> n;
    vector<pii> v(n);
    for (auto &i : v){
        cin >> i.F >> i.S;
    }
    sort(range(v), [](const auto &l, const auto &r)
         { return l.S < r.S; });
    
    int Last = -INF ,  ans=0;
    for (const auto &i : v)
        if (i.F >= Last){
            ans++;
            Last = i.S;
        }
    cout << ans << '\n';
}
signed main(){
    OAO 
    int T; cin>>T;
    while(T--){
        slove();
    }
    return 0; 
}