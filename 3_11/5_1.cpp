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
const int MAX_N = 1e8;
const int INF = 1e9;

int MOD = 524287;

int Merge(int *arr,int *temp,int L,int R,int mid){
    int inv=0,idx=0;
    int l=L,r=R,m=mid;

    while( l<mid && m<=R ){
        if(arr[l]<=arr[m]){
            temp[idx++]=arr[l++];
        }
        else{
            temp[idx++]=arr[m++];
            inv+=(mid-l);
        }
    }

    while(l<mid){
        temp[idx++]=arr[l++];
    }

    while(m<=R){
        temp[idx++]=arr[m++];
    }

    for(int i=L;i<R;i++){
        arr[i]=temp[i];
    }

    return inv%MOD;
}
int Sort(int *arr,int *temp,int l,int r){
    int inv=0;
    
    if(l<r){
        int mid=(l+r)/2;
        inv=(inv+Sort(arr,temp,l,mid))%MOD;
        inv=(inv+Sort(arr,temp,mid+1,r))%MOD;
        inv=(inv+Merge(arr,temp,l,r,mid))%MOD;
    }

    return inv;
}

signed main(){
    int n;
    cin>>n;
    int arr[n],temp[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<Sort(arr,temp,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}