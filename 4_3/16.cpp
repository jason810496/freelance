
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

typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

int arr[MAX_N] ;


void Erase(ordered_set &t,int v){
    int rk = t.order_of_key(v);
    auto it = t.find_by_order(rk);
}

// AC
signed main(){
    OAO

    int n , m , k; cin>>n>>m>>k;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int t=n-m+1;

    ordered_set S;
    for(int i=0;i<m;i++){
        S.insert(arr[i]);
    }
    
    for(int i=0;i<n-m+1;i++){

        cout<<*S.find_by_order(k-1)<<' ';

        // for(auto it:S){
        //     cout<<it<<' ';
        // }
        // cout<<"\n";
        // S.erase(S.find(arr[i]));
        int rk=S.order_of_key(arr[i]);
        S.erase( S.find_by_order(rk) );
        S.insert(arr[i+m]);
    }
    return 0;
    
}


/*
10 2
Margarita
OldFashion
Margarita
Margarita
OldFashion
Mojito
OldFashion
Mojito
Margarita
Margarita

*/

