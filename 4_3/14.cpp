
#pragma GCC optimize("O2")
#include<bits/stdc++.h>
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
const int MAX_N = 100005;
const int INF = 1e9;

struct Cmp {
    bool operator()(const pair<int, int>& value,const int& key){
        return (value.first < key);
    }
    bool operator()(const int& key,const pair<int, int>& value){
        return (key < value.first);
    }
};

// AC
signed main(){
    OAO

    int n , k ; cin>>n>>k;

    int idx=0;
    vector<pair<D,int> > vec(n);
    vector<string> StrList(n); 

    for(auto &i:vec){
        int a,b;
        D c,sum;
        string str;
        cin>>a>>b>>c>>str;
        sum= a+b+c;

        StrList[idx] = str;
        i.F = -c/sum;
        i.S = idx++;
    }

    sort(range(vec) ) ;

    // for(auto i:vec){
    //     cout<<i.F<<' '<<StrList[i.S]<<'\n';
    // }

    cout<<StrList[ vec[k-1].S ];
    return 0;
}
/*

10 3
15 15 55 Margarita
10 15 45 WhiteLady
10 20 60 SilentThird
30 25 50 XYZ
20 20 60 SideCar
25 15 55 Balalaika
10 10 35 OldFashion
15 10 30 Mojito
25 20 60 CubaLibre
30 15 40 Highball
*/
