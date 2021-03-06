
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
const int MAX_N = 1e5+5;
const int INF = 1e9;

// typedef pair<int,int> P; // clr , size 

int Move[4][2] = { {0,1},  {1,0} , {0,-1} ,{-1,0 } };
int n , m ; 
int MX_Local=0 ,MX_loc_Player=0, ND_Total = 0 , MX_Total= 1 , MX_Total_Player = 0; 

vector< vector<int> > G;

unordered_map<int,int> Mp;

// int BFS(int x,int y){
    
    
// }

signed main(){
    OAO
    cin>>n>>m;

    int Area=0;

    G.resize(n , vector<int>(m) );

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>G[i][j];
    }  

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if( G[i][j]>0 ){
                
                // BFS(i,j);

                int clr = G[i][j];
                G[i][j] = -1;
                int sz = 0;
                bool flag = false;

                queue<pii> q; 

                q.push({i,j});

                while( q.size() ) {
                    int x=q.front().F;
                    int y=q.front().S;
                    q.pop();
                    sz++;

                    for(int k=0;k<4;k++){
                        int I = x+Move[k][0] , J=  y+Move[k][1];
                        if( I<0 || J<0 || I>=n || J>=m ) continue;
                        if( G[I][J]==1 ) flag = true;
                        if( G[I][J]<0 || G[I][J]!=clr ) continue;
                        q.push( { I, J } );

                        G[I][J]= -1;
                    }
                }
                // cout<<sz<<'\n';
                
                Mp[ clr ]+=sz;

                if( clr !=1 && flag ){
                    if( sz > MX_Local ){
                        MX_loc_Player = clr ;
                        MX_Local = sz;
                    }
                }
            }
        }
    }

    for(const auto &i:Mp){ // clr , size 
        if( i.F ==1 ){
            Area = max( Area , i.S ) ;
            continue;
        }

        if( i.S > MX_Total ){
            MX_Total_Player = i.F;
            if( MX_Total > ND_Total ){
                ND_Total = MX_Total ;
            } 
            MX_Total = i.S;
        }
    }


    if( (Area > MX_Total) || (Area + MX_Local > MX_Total) ) cout<<Area+MX_Local;
    else if( MX_loc_Player == MX_Total_Player ){
        if( ( (Area+MX_Local) > (MX_Total-MX_Local) )&&( (Area+MX_Local)>ND_Total ) ) cout<<Area+MX_Local;
        else cout<<"-1";
    }
    else cout<<"-1";
    
    return 0;
}

