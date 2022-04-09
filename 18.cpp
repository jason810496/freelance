
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


void slove(){
    int n ,w ;
    cin>>n>>w;
    vector<int> vec;

    char tp;
    for(int x ,i=0 ;i<n;i++){
        cin>>tp>>x;
        if(tp=='s') continue;
        vec.push_back(x);
    }

    n=vec.size();
    int Last = 0 , MX=-1;
    for(int i=0;i<n;i++){
        MX=max(MX, vec[i] - Last);
        Last=vec[i];
    }
    MX=max(MX, w - Last);
    cout<<MX<<'\n';
}

signed main(){
    OAO
    int t ; cin>>t;
    while(t--){
        slove();
    }
    return 0;
    
}

