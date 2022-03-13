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
    
    vector<vector<int> > vec(K);
    map<int,int> M;
    for(int k=0;k<K;k++){
        int n; cin>>n;
        vec[k].resize(n);

        for(int &i:vec[k]){
            cin>>i;
            
            auto it = M.find(i);

            if(it==M.end()){
                M[i]=0;
            }
            else M[i]++;
        }
    }

    vector<int> Final;

    for( auto i:M){
        if(i.S >= K){
            Final.push_back(i.F);
        }
    }

    int n=Final.size() , r=INF;
    pii ans;
    for(int i=1,t;i<n;i++){
        t=Final[i]-Final[i-1];
        if(t<r){
            
        }
    }
    return 0;
}