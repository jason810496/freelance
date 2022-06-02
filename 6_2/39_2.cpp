#include<bits/stdc++.h>
using namespace std;

#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first 
#define S second 
#define ll long long 
#define all(x) x.begin(),x.end()
#define PB push_back
const int INF = 1e9;
const int N = 505;

typedef pair<int,int> pii;

int n ,m; 

bool G[N][N];
int indeg[N];

signed main(){
    OAO 
    
    while(cin>>n>>m){
        for(int i=1;i<=n;i++) indeg[i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                G[i][j]=G[j][i]=0;
            }
        }

        while( m-- ){
            int a,b;
            cin>>a>>b;
            G[a][b]=1;
            indeg[b]++;
        }

        // vector<int> ans;
        set<pii> ans;
        vector<int> dis(n+1);
        queue<int> q;

        for(int i=1;i<=n;i++){
            if( !indeg[i] ){
                q.push( i );
                // ans.PB( i );
                ans.insert( {0 , i} );
                dis[i]=0;
            }
        }

        while( q.size() ){
            int cur = q.front();
            q.pop();

            for(int nxt=1; nxt<=n ; nxt++){
                if( nxt == cur || !G[cur][nxt] ) continue;

                dis[ nxt ] = max(dis[ nxt ] , dis[cur]+1 );
                if( !--indeg[nxt] ){
                    q.push( nxt );
                    ans.insert( { dis[ nxt ] , nxt } );
                    // ans.PB( nxt );
                }
            }
        }

        for(auto &i:ans){
            cout<<i.S<<' '; 
        }
        cout<<'\n';
    }
    return 0;
}