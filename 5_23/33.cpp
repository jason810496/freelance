
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

int pos[4][2] = { {0,1} ,{1,0}, {0,-1} , {-1,0 } } ;

signed main(){
    OAO
    int n , m ;

    pii st ,ed ;

    cin>>n>>m;
    cin>>st.F>>st.S>>ed.F>>ed.S;

    vector< vector< int > > G(n+1, vector<int>(m+1 , false) );

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            bool x;
            cin>>x;
            if(x) G[i][j]=0;
            else G[i][j]=-1;
        }
    }

    // cout<<" = = = = = \n";
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<G[i][j]<<' ';
    //     }
    //     cout<<"\n";
    // }


    bool flag =false;

    queue<pii> q;

    if( G[st.F][st.S]>=0 && G[ed.F][ed.S]>=0 ){
        q.push( st );
        G[st.F][st.S] = 1;
    }

    while( q.size() && !flag ){
        int x=q.front().F;
        int y=q.front().S;
        q.pop();

        // cout<<x<<' '<<y<<'\n';
        if( x==ed.F && y==ed.S ){
            flag = true;
        }

        for(int k=0;k<4;k++){
            int i = x+pos[k][0] , j = y+pos[k][1];

            if( i<1 || j<1 || i>n || j>m ) continue;
            if( G[i][j]!=0) continue;

            q.push( {i,j} );
            G[i][j] = G[x][y]+1;
        }
    }


    cout<<( G[ed.F][ed.S]>0 ? "Success!\n":"Fail!\n");

    return 0 ;
}
