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

int arr[MAX_N] , n;

void Heap(int m){
    int j , temp ;
    temp = arr[m];
    j = m*2 ; 

    while( j<= n){
        if( j<n && arr[j+1] < arr[j]) j+=1;
        if( temp < arr[j] ) break;
        else if( temp >= arr[j] ) {
            arr[j/2] = arr[j];
            j*=2 ;
        }
    }
    arr[j/2] = temp;
}

void Build(){
    for(int i=n/2 ; i>0 ;i--){
        Heap(i);
    }
}

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    Build();

    for(int i=1;i<=n;i++){
        cout<<arr[i]<<' ';
    }
    return 0;
}