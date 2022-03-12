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
const int N = 6;
const int INF = 1e9;

int n ,arr[15],st,ed;
bool vis[15]={};
vector<int> ans;

void rec(int st,int cnt , int step){
    if(step>6){
        if(cnt=6{
            for(auto i:ans){
                cout<<i<<' ';
            }
            cout<<'\n';
        }
        return ;
    }

    if(vis[st]) ans.push_back()

    for(int i=0;i<n;i++){
        rec()
    }
}
signed main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    MEM(vis,1);

    for(int x=n-6,i=0;i<x;i++){
        vis[i]=1;
        rec(i,0,0);
        vis[i]=0;
        rec(i,0,0);
    }
    return 0;
}