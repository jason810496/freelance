
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
const int MAX_N = 100005;
const int INF = 1e9;

int temp[MAX_N] ;
ll ans[MAX_N];
unordered_map<int,int> Mp;

void Merge(int *arr,int l,int m,int r){
    ll ret=0;
    int i=l,j=m+1,k=l;
    while( i<= m && j<= r){
        if(arr[i]<= arr[j]){
            
            ans[ Mp[ arr[i] ] ] +=ret;
            temp[k++]=arr[i++];
        }
        else{
            ret++;
            temp[k++]=arr[j++];
        }
    }

    while( i<=m ){
        ans[ Mp[ arr[i]] ] +=ret;
        temp[k++] = arr[i++];
    }

    while( j<=r ){
        temp[k++]  = arr[j++];
    }

    for(int i=l;i<=r;i++){
        arr[i]=temp[i];
    }

}

void Sort(int *arr,int l,int r){
    if( l>=r ) return ; 

    int m = (l+r)/2;
    Sort(arr,m+1,r) ; // [m+1 , r]
    Sort(arr,l,m)   ;// [l , m ]
    
    Merge(arr,l,m,r);
}


signed main(){
    OAO
    int n ; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        Mp[ arr[i] ] = i ;
    }

    Sort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
    for(int i=0;i<n;i++){
        cout<<ans[i]<<' ';
    }
    
    return 0;
}