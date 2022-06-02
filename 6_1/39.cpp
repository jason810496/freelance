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
vector< vector<int> > G(N);
vector<int> In(N);

signed main(){
    OAO 
    
    while( cin>>n>>m){
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<=n;i++) In[i]=0;

        while(m--){
            int a,b;
            cin>>a>>b;
            G[a].push_back( b );
            In[b]++;
        }

        for(int i=1;i<=n;i++) sort(all(G[i]));

        // for(int i=1;i<=n;i++){
        //     for(auto j:G[i]){
        //         cout<<j<<' ';
        //     }
        //     cout<<'\n';
        // }

        priority_queue<int , vector<int> , greater<int> > q;
        vector<int> ans;
        for(int i=1;i<=n;i++){
            if( !In[i] ){
                q.push( i );
            }
        }

        while( q.size() ){
            int cur = q.top();
            q.pop();

            ans.push_back( cur );
            for(int nxt : G[cur] ){
                if( !--In[nxt] ){
                    q.push( nxt );
                    // ans.push_back( nxt );
                }
            }
        }

        for(int &i:ans){
            cout<<i<<' ';
        }
        cout<<'\n';
    }
    return 0;
}