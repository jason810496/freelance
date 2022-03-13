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

vector<int> BIT;

int MX=-1;
void upd(int i){
    for(;i<=MX;i+=lowbit(i)){
        BIT[i]++;
    }
}

int query(int i){
    int ret=0;
    for(;i;i-=lowbit(i)){
        ret+=BIT[i];
    }
    return ret;
}
signed main(){
    OAO

    int n ;
    cin>>n;
    vector<int> vec(n),temp(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
        temp[i]=vec[i];
    }

    sort(range(temp));
    temp.erase(unique(temp.begin(),temp.end()),temp.end());

    for(int &i:vec){
        int rk = lower_bound(range(temp),i) - temp.begin() +1;
        i=rk;
        MX=max(MX,i);
    }

    BIT.resize(MX+5,0);

    int MOD=524287 , ans=0;
    
    
    for(int i=0;i<n;i++){
        ans = ( ans + i - query(vec[i]) )%MOD;
        upd(vec[i]);
    }

    cout<<ans;
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