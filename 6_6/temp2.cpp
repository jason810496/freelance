#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first 
#define S second 
#define all(x) x.begin(),x.end()
typedef pair<int,int> pii;
const int INF = 1e9;
const int N = 1005;

signed main(){
    OAO
    
    int t,x,y;
    cin>>t;

    unordered_map<int, vector<int> > Mp;

    while( t--){
        cin>>x>>y;
        Mp[x].push_back( y );
    }

    for(auto &i:Mp){
        sort(all(i.S));
    }

    set<int> flag;
    for(auto &i:Mp){
        if( flag.size()>1 ) break;

        int n = i.S.size();
        for(int j=0;j<=n/2;j++){
            int cur = i.S[j]+i.S[n-j-1];
            flag.insert( cur );
        }
        
    }

    cout<<( flag.size()==1 ? "success":"failure");

    return 0;
}