#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first 
#define S second 
#define all(x) x.begin(),x.end()
#define PB push_back 
typedef pair<int,int> pii;
const int INF = 1e9;
const int N = 1005;

int n , m , k , st , ed;

signed main(){
    OAO
    cin>>n>>m>>k;
    cin>>st>>ed;
    
    vector< pii > edge(m);
    for(auto &i:edge){
        cin>>i.F>>i.S;
    }

    unordered_set<int> Bound;

    for(int i=0,x;i<k;i++){
        cin>>x;
        Bound.insert(x);
    }

    vector<int> dis(n+1,INF );

    dis[st]=0;

    for(int k=1;k<n;k++){
        for(auto &e:edge){
            if( Bound.find(e.F)==Bound.end() || Bound.find(e.S)==Bound.end() ){
                if( dis[e.F]!=INF ){
                    dis[e.S]=0;
                }
            }
        }
    }

    cout<<( dis[ed]==0 ? "SAFE":"UNSAFE" );

    return 0;
}   
/* case 1 :
5 7 1
1 3
3 1
2 1
5 4
5 3
3 5
5 2
4 1
4

*/

/* case 2:
5 7 1
4 1
4 1
1 2
5 3
1 5
4 3
2 1
4 5
2

*/