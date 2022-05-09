
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
typedef pair<int,long long> pil;
const int MAX_N = 500005;
const int INF = 1e9;

// AC
signed main(){
    OAO
    int n ; cin>>n;
    int ans = n;
    vector<int > vec(n);
    for(int &i:vec) cin>>i;

    vector<int> LIS;

    vector<int> Right(n),Left(n);

    for(int i=0;i<n;i++){
        if( LIS.empty() || LIS.back() < vec[i] ){
            LIS.PB( vec[i] );
        }
        else{
            auto it = lower_bound( range(LIS) , vec[i] );
            // if( it!=LIS.end() ) it++;
            if( it!=LIS.end() ){
                *it = vec[i];
            }
        }
        Left[i] = LIS.size();
    }

    LIS.clear();

    for(int i=n-1 ; i>=0 ;i--){
        if( LIS.empty() || LIS.back() < vec[i] ){
            LIS.PB( vec[i] );
        }
        else{
            auto it = lower_bound( range(LIS) , vec[i] );
            // if( it!=LIS.end() ) it++;
            if( it!=LIS.end() ){
                *it = vec[i];
            }
        }

        // Right[i] = LIS.size();

        ans = min( ans ,n- int(LIS.size() + Left[i] -1 ));
    }
    cout<<ans;
    // ans = min(ans , int(n-LIS.size()) );


    // cout<< abs( int(LIS.size()) - int(LIS.size()) );

    // for(int i=0;i<n;i++){
    //     cout<<Left[i]<<' ';
    // }
    // cout<<'\n';
    // for(int i=0;i<n;i++){
    //     cout<<Right[i]<<' ';
    // }
    // cout<<'\n';
    return 0;

}

/*
8
7 21 16 19 16 7 12 5


*/