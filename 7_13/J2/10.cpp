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
#define PB push_back
typedef pair<int,int> pii;
const int MAX_N = 1e6+5;
const int INF = 1e9;


/*

    segment tree lazy tag
*/
signed main(){
    OAO
    int n , m;
    cin>>n>>m;
    
    // 0:up
    bitset<MAX_N> state;

    vector<int> Up(n+1) , Gap(n+1);

    for(int i=1;i<=n;i++){
        cin>>Up[i];
    }

    for(int i=1,x;i<=n;i++){
        cin>>x;
        Gap[i] = x-Up[i];
    }

    int t , l ,r; 
    while( m-- ){
        cin>>t>>l>>r;

        if(t){ // query 

        }
        else{ // modify 

        }
    }
    return 0;
}
