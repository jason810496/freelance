
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


signed main(){
    OAO
    
    string str; cin>>str;
    int n ; cin>>n;

    const char L_B = '(' , P = '#' , R_B = ')';

    // stack<char> LB,Pack;

    int LB=0  ,Pack=0;

    int ans = 0 ,idx=0;
    for(char &c :str ){
        if( c==L_B ){
            LB=1;
            Pack=0;
        }
        else if( c==P ) Pack++;
        else if( c==R_B ){
            if( LB && Pack==n ){
                ans++;
                LB--;
                Pack=0;
            }
        }
        else{
            Pack=0;
            LB=0;
        }

    }

    cout<<ans;
    return 0;
}

