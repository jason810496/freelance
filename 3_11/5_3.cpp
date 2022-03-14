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
#define PB emplace_back
typedef pair<int,int> pii;
const int MAX_N = 1000005;
const int INF = 1e9;

int temp[MAX_N] ;
ll MOD=524287;
ll Merge(int *arr,int l,int m,int r){
    ll ret=0;
    int i=l,j=m+1,k=l;
    while( i<= m && j<= r){
        if(arr[i]<= arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
            ret=(ret+(m-i+1) )%MOD;
        }
    }

    while( i<=m ){
        temp[k++] = arr[i++];
    }

    while( j<=r ){
        temp[k++]  = arr[j++];
    }

    for(int i=l;i<=r;i++){
        arr[i]=temp[i];
    }

    return ret;
}
int Sort(int *arr,int l,int r){
    if( l>=r ) return 0; 

    ll ret=0;
    int m = (l+r)/2;
    ret= (ret+Sort(arr,l,m)   )%MOD;
    ret= (ret+Sort(arr,m+1,r) )%MOD;
    ret= (ret+Merge(arr,l,m,r))%MOD;

    return ret;
}


signed main(){
    OAO
    int n ; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<Sort(arr,0,n-1);
    
    return 0;
}