
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

int arr[105];
int n ; 

bool check(int idx){
    int x= arr[idx--];

    while( idx >=0 && x){
        x-=(x/arr[idx])*arr[idx];
        idx--;
    }

    return x==0;
}
signed main(){
    OAO
    
    int t; cin>>t;
    

    while(t--){
        cin>>n;

        for(int i=0;i<n;i++) cin>>arr[i];

        bool flag = true;
        for(int i=n-1;i>0 ;i--){
            if( !check(i) ){
                flag = false;
                break;
            }
        }

        cout<<( flag ? "YES\n":"NO\n");

    }
    return 0;
}

