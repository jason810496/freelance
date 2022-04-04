
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

struct Cmp {
    bool operator()(const pair<int, int>& value,const int& key){
        return (value.first < key);
    }
    bool operator()(const int& key,const pair<int, int>& value){
        return (key < value.first);
    }
};

signed main(){
    OAO

    int n , q ; cin>>n>>q;

    vector<pii> vec(n);

    for(auto &i:vec){
        cin>>i.S>>i.F; 
        // pos , val 
    }

    sort(range(vec));
    // cout<<"-------\n";
    // for(auto i :vec){
    //     cout<<i.F<<' '<<i.S<<'\n';
    // }
    // cout<<"-------\n";
    while(q--){
        int v,x;  cin>>x>>v;

        auto it = lower_bound(range(vec),v,Cmp() );

        if(it==vec.end()){
            cout<<"-1\n";
        }
        else{
            int Dis=INF, ans=INF;

            for(;it!=vec.end();it++){
                int cur=abs(it->S-x);
                if(cur < Dis){
                    Dis=cur;
                    ans=it->S;
                    continue;
                }
                if( cur == Dis){
                    ans=min(ans,it->S);
                }
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
    
}

