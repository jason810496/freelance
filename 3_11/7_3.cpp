
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

struct P{
    int x,y,rk;
}point[N] , temp[N];


void Merge(int left,int mid,int right) {//sort by y-axis
    int i = left, j = mid+1;
    int k = 0 , cnt=0;
    while(i <= mid && j <= right) {
        if(point[i].y < point[j].y){
            temp[k++] = point[i++];
            cnt++;
        }   
        else{
            temp[k].rk = point[j].rk + cnt;
            temp[k++] = point[j++];
        }
    }
    while(i <= mid){
        // point[i].idx =  i;
        temp[k++] = point[i++];
        cnt++;
    }   
    while(j <= right){
        temp[k].rk = point[i].rk + cnt;
        temp[k++] = point[j++];
    }
        
    for(int i=left;i<=right;i++){
        point[i] = temp[i-left];
    }
}

void rk2D(int left,int right) {// array index
    if(left >= right)    return;
    int mid = (left+right)/2;
    rk2D(left, mid);//切 x = point[mid].x 垂直線
    rk2D(mid+1, right);
    Merge(left, mid, right);
}

signed main(){
    int n ; cin>>n;

    for(int i=0;i<n;i++){
        cin>>point[i].x >> point[i].y ;
    }
    sort(point,point+n , [](P a, P b){
        return (a.x<b.x ? 1:(a.x==b.x ? a.y<b.y: 0) );
    });

    rk2D(0,n-1);

    for(int i=0 ; i<n ;i++){
        cout<<point[i].rk<<" ";
    }
    return 0;
}