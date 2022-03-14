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
const int MAX_N = 50005;
const int INF = 1e9;

int temp[MAX_N];
void Merge(int *arr,int l,int m,int r){
    int i=l,j=m+1,k=l;
    while( i<= m && j<= r){
        if(arr[i]<= arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
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
}
void Sort(int *arr,int l,int r){
    if( l>=r ) return ; 

    int m = (l+r)/2;
    Sort(arr,l,m);
    Sort(arr,m+1,r);
    Merge(arr,l,m,r);
}

void demo(){
    srand(time(0));
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=rand() % 100;
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
    Sort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
}
signed main(){
    OAO
    int n ; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    Sort(arr,0,n-1);
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    return 0;
}