
#pragma GCC optimize("O2")
#include<bits/stdc++.h>
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

struct Elevetor{
    int Move , Capacity , Open;
    Elevetor(int m =0  ,int c=0  ,int o = 0){
        Move = m ; 
        Capacity = c; 
        Open = o;
    }
};
signed main(){
    OAO
    int Start , Target ,Stair ;
    int move,capacity,open;
    int People[3];
    cin>>Start>>Target>>move>>capacity>>open>>Stair;

    for(int i=0;i<3;i++) cin>>People[i];

    int span = abs( Start- Target );

    vector<int> ans;

    ans.push_back( span*Stair ); // move by stair

    if( Start)
    return 0;
}

