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

// min dict : D , L ,R ,U

vector< vector<int> > Move = { {1,0} , {0,-1} , {0,1} , {-1,0} };

inline char Code(int i){
    if( i==0 ) return 'D';
    if( i==1 ) return 'L';
    if( i==2 ) return 'R';
    if( i==3 ) return 'U';
}

inline int inv(int i ){
    if( i==0 ) return 3;
    if( i==3 ) return 0;
    if( i==2 ) return 1;
    if( i==1 ) return 2;
}
signed main(){
    // OAO
    
    vector< vector<pii> > G( 102 , vector<pii>(102) );

    int n ; cin>>n;
    char c;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>c;
            if( c=='X') G[i][j]={-1,0};
        }
    }

    queue< pii> q;
    pii st={1,1} , ed={n,n};
    G[1][1] = { 1, -1 };
    q.push( st );

    while( q.size() ){
        pii cur = q.front();
        q.pop();

        if( cur==ed ){
            break;
        }

        for(int k=0;k<4;k++){
            int x=Move[k][0]+cur.F , y=Move[k][1]+cur.S;
            if( x<=0 || y<=0 || x>n || y>n ) continue;
            if( G[x][y].F!=0 ) continue;

            G[x][y].F = G[cur.F][cur.S].F+1;
            G[x][y].S = k;

            q.push( {x,y} );
        }
    }

    string ans;

    while( ed!=st ){
        int m = G[ed.F][ed.S].S;
        ans.push_back( Code(m) );
        // cout<<Code(m);
        ed.F += Move[ inv(m) ][0];
        ed.S += Move[ inv(m) ][1];
    }

    reverse(range(ans));
    cout<<ans;
    return 0;
}
