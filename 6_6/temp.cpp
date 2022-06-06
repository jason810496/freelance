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
    bool flag = true;
    int MID=INF;

    for(auto &i:Mp){
        if( !flag ) break;

        int n = i.S.size() , mid ;
        int half=n/2 ;

        if( n&1 ){
            mid=i.S[ half ];
            for(int j=0;j<half;j++){
                if( i.S[j]+i.S[n-j-1] != mid*2 ){
                    flag = false;
                    break;
                }
            }
        }
        else{
            mid=i.S.front()+i.S.back();
            for(int j=0;j<half;j++){
                if( i.S[j]+i.S[n-j-1] != mid ){
                    flag = false;
                    break;
                }
            }
        }
        if( MID==INF){
            MID=mid;
        }
        else if( MID!=INF && MID !=mid ){
            flag = false;
            break;
        }
    }

    cout<<(flag ? "success":"failure");

    return 0;
}