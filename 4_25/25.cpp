
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

struct item{
    int val , ed , t;
};

struct CMP{
    bool operator()(item &a,item &b){
        return a.val < b.val;
    }
};

inline bool cmp(const item &a ,const item &b){
    // return ( a.ed < b.ed ? 1:(a.ed==b.ed ? a.t<b.t:0));

    // return (a.ed<b.ed ? 1: (a.ed==b.ed ? a.t<b.t:0));

    return a.ed < b.ed ;
};
signed main(){
    OAO
    
    int n ; cin>>n;
    int Mx_time = 0;
    vector< item > arr(n);

    for(auto &i:arr){
        cin>>i.val>>i.ed>>i.t;
        Mx_time = max( Mx_time , i.ed );
    }

    sort(range(arr), cmp);

    int ans=0;

    priority_queue< item , vector<int> , CMP > pq;

    for(int i=n-1 ; i>=0 ; i--){
        int Availble;
        if( !i ){
            Availble = arr[i].ed;
        }
        else{
            Availble = arr
        }
    }
    return 0;
}

