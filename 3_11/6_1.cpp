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

int n ,arr[15],st,ed ;
bool vis[15]={};
set<string> Same;

inline string HASH(){
    string str;
    for(int i=0;i<n;i++){
        if(vis[i]){
            str+=to_string(arr[i]);
        }
    }
    return str;
}
void rec(int step,int cnt){
    if( step >= N){
        if( cnt == N ){
            string h = HASH();
            if( Same.find(h)!=Same.end()){
                return;
            }
            Same.insert(h);
            for(int i=0;i<n;i++){
                if(vis[i]){
                    cout<<arr[i]<<' ';
                }
            }
            cout<<'\n';
        }
        return;
    }
    for(int i=step;i<n;i++){
        if(!vis[i]){
            vis[i]=1;
            rec(step+1,cnt+1);
            vis[i]=0;
            rec(step+1,cnt);
        }
    }
}
signed main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    rec(0,0);
    return 0;
}