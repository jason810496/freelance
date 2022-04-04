
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

unordered_map<string,int> Map;
vector< pair<int,string> > vec;

int idx=0;
void Upd(string str){

    if(Map.find(str)==Map.end()){
        vec[idx] = {-1,str};
        Map[str] = idx++;
    }

    int id = Map[str];
    vec[id].F--;
}

signed main(){
    OAO

    int n , k ; cin>>n>>k;
    int idx=0 , Mx=0;
    
    vec.resize(n);
    while(n--){
        string str;
        cin>>str ; 
        Upd(str);
    }

    sort(range(vec));

    cout<<vec[k-1].S;

    // for(auto i:vec){
    //     cout<<-i.F<<' '<<StrList[i.S]<<'\n';
    // }
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

