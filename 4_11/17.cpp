
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

/*  AC */
signed main(){
    OAO
    int n; cin>>n;
    vector<int> vec(n);
    vector<vector<int> > ans;
    for(int &i:vec){
        cin>>i;
    }

    priority_queue<int,vector<int>,greater<int> > pq(range(vec));

    while(pq.size()){
        int v= pq.top();
        pq.pop();

        bool flag=true;
        for(auto &i:ans){
            if(i.back() < v){
                i.push_back(v);
                flag = false;
                break;
            }
        }

        if(flag){
            ans.push_back(vector<int>(1,v));
        }
    }

    for(auto i:ans){
        for(int j:i){
            cout<<j<<' ';
        }
        cout<<'\n';
    }
    return 0;
    
}

