
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
	int x ,y , idx;
} Points[N] , temp[N];

int rk[N];
void Merge(int l,int m,int r){
	int i=l , j=m+1 , k=l ,  cnt=0;

	while( i<=m && j<=r ){
		if( Points[i].y < Points[j].y ){
			temp[k] = Points[i];
			cnt++;
			k++,i++;
		}
		else{
			temp[k] = Points[j];
			rk[ Points[j].idx ] += cnt;
			k++,j++;
		}
	}

	while( i<=m ){
		temp[k++] = Points[i++];
		cnt++;
	}

	while( j<=r ){
		temp[k] = Points[j];
		rk[ Points[j].idx ] += cnt;
		k++,j++;
	}

	for(int i=l;i<=r;i++){
		Points[i] = temp[i] ;
	}
}
void Sort_Y(int l,int r){
	if( l<=r ) return ;
	int m = (l+r)/2 ;

	Sort_Y(l,m);
	Sort_Y(m+1,r);
	Merge(l,m,r);
}

signed main() {

	int n ;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>Points[i].x >> Points[i].y;
		Points[i].idx = i;
	}

	sort(Points,Points+n,[&](P &a,P &b){
		return (a.x<b.x ? 1:(a.x==b.x ? a.y<b.y: 0) );
	});

	cout<<"---\n";
	for(int i=0;i<n;i++){
		cout<<Points[i].x<<' '<<Points[i].y<<'\n';
	}
	Sort_Y(0,n-1);

	cout<<"---\n";
	for(int i=0;i<n;i++){
		cout<<Points[i].x<<' '<<Points[i].y<<'\n';
	}
	

	for(int i=0;i<n;i++){
		cout<<rk[i]<<' ';
	}
	return 0;
}

/*
7
3 1
4 1
5 9
2 6
5 3
5 8
9 7


*/