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
const int MAX_N = 300005;
const int INF = 1e9;

#define lowbit(x) x&(-x)
int MX=-1;
vector<vector<int> > BIT;

void upd(int x,int y){
    for(int i=x;i<=MX;i+=lowbit(i)){
        for(int j=y;j<=MX;j+=lowbit(j)){
            BIT[i][j]++;
        }
    }
}

int query(int x,int y){
    int ret=0;
    for(int i=x;i;i-=lowbit(i)){
        for(int j=y;j;j-=lowbit(j)){
            ret+=BIT[i][j];
            
        }
    }
    return ret;
}
signed main(){
    OAO

    int n ;
    cin>>n;
    vector<pii> P(n);
    vector<int> X(n),Y(n);

    for(int i=0;i<n;i++){
        cin>>P[i].F>>P[i].S;
        X[i]=P[i].F;
        Y[i]=P[i].S;
    }

    sort(range(X));
    sort(range(Y));

    int X_mx=-1 , Y_mx=-1;
    for(pii &i:P){
        i.F = (lower_bound(range(X),i.F)-X.begin())+1;
        X_mx=max(X_mx,i.F);
        i.S = (lower_bound(range(Y),i.S)-Y.begin())+1;
        Y_mx=max(Y_mx,i.S);
    }
    
    MX=max(X_mx,Y_mx);
    BIT.resize(MX+2,vector<int>(MX+2,0));

    for(const pii &i:P){
        upd(i.F,i.S);
    }

    for(const pii &i:P){
        cout<<query(i.F-1,i.S-1)<<' ';
    }
}

/*
in :
7
3 1
4 1
5 9
2 6
5 3
5 8
9 7

out:
0 1 5 0 2 4 4
*/