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

unsigned int arr[100100]={};

signed main(){
    int n;
    cin>>n;
    for(int i=0,x;i<n;i++){
        cin>>x;
        int y= x+50005;
        arr[y]++;
    }

    for(int i=0;i<100005;i++){
        if(arr[i]>0){
            for(int j=0,x=arr[i];j<x;j++){
                cout<<i-50005<<' ';
            }
        }
    }
    
    return 0;
}