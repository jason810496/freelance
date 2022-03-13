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
const int N = 300005;
const int INF = 1e9;

struct p{
    int x , y ,idx , rk;
} point[N] , temp[N];

void Rank(int l,int r){
    if( l>=r ) return ; 

    int mid = (l+r)/2 , X_mid = point[mid].x , cnt=0;
    Rank(l,mid);
    Rank(mid+1,r);

    //  merge
    int i=l , j=mid+1 , k=l;
    while( i<=mid && j<=r){
        if( point[i].y < point[j].y){
            temp[k++] = point[i++];
            cnt++;
        }
        else{
            temp[k].rk = point[j].rk + cnt ; 
            temp[k++ ] =point[j++];
        }
    }

    while( i<= mid ){
        temp[k++] = point[i++];
        cnt++;
    }

    while( j<=r ){
        temp[k].rk = point[i].rk + cnt;
        temp[k++] = point[j++];
    }
    for(int i=l;i<=r;i++){
        point[i] = temp[i];
    }
}
signed main(){
    int n ; cin>>n;

    for(int i=0;i<n;i++){
        cin>>point[i].x >> point[i].y ;
        point[i].idx =  i;
    }
    sort(point,point+n , [](p a, p b){
        return (a.x<b.x ? 1:(a.x==b.x ? a.y<b.y: 0) );
    });

    Rank(0,n-1);

    for(int i=0 ; i<n ;i++){
        cout<<point[i].rk<<" ";
    }
    return 0;
}