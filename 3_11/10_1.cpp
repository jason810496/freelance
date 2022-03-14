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
#define PB emplace_back
typedef pair<int,int> pii;
const int N = 6;
const int INF = 1e9;

signed main(){
    int K;
    cin>>K;
    
    vector<pii> vec;
    for(int k=0;k<K;k++){
        int n ,x; cin>>n;
        for(int i=0;i<n;i++){
            cin>>x;
            vec.push_back({x,k});
        }

    }

    sort(range(vec));
    unordered_map<int,int> Window;
    int n = vec.size() , l=0;
    pii ans={-INF,INF} , init = {-INF,INF};

     int i = 0, k = 0;
    unordered_map<int, int> window;
    for (int j = 0; j < vec.size(); ++j) {
        window[vec[j].S]++;
        if (window.size() == K ) { 
            while (window[vec[i].S] > 1) --window[vec[i++].S]; 
            if (ans==init || ans.S-ans.F > vec[j].F - vec[i].F) {
                ans = {vec[i].F, vec[j].F};
            }
        }
    }

    cout<<ans.F<<' '<<ans.S;

    
    return 0;
}