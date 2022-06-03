#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;

#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long 
#define D long double
#define range(x) x.begin(),x.end()
#define MEM(x,i) memset(x,i,sizeof(x))
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,st,n) for(int i=st;i<=n;++i)
#define PB emplace_back
typedef pair<int,int> pii;
const int MAX_N = 500005;
const int INF = 1e9;

/*
    array version segment tree
    ( 1-based index )
    ( [Q_L , Q_R ] )
    ( single position update)

*/

// left child idx 
inline int L_idx(int i){
    return i<<1;
}

// right child idx
inline int R_idx(int i){
    return i<<1|1;
}

int T[MAX_N<<2];

void Build(int idx,int L,int R){
    if(L==R){
        cin>>T[ idx ];
        // T[idx] = arr[L];
        return ;
    }

    int mid = (L+R)>>1;

    Build( L_idx(idx) , L , mid );
    Build( R_idx(idx) , mid+1,R );

    // pull
    T[ idx ] = max( T[ L_idx(idx) ] , T[ R_idx(idx) ] );
}

void Update(int idx,int L,int R ,int pos ,int val){
    if( L==R ){
        T[ idx ] = val;
        return ;
    }

    int mid = (L+R)>>1;

    // in left part
    if( pos<= mid ){
        Update( L_idx(idx) , L ,mid , pos ,val );
    }
    else{ // right part 
        Update( R_idx(idx) , mid+1 , R , pos ,val );
    }

    // pull
    T[ idx ] = max( T[ L_idx(idx) ] , T[ R_idx(idx) ] );
}

int Query(int idx,int L,int R,int Q_L ,int Q_R ){
    // in current range
    if( Q_L<=L && R<=Q_R ) return T[ idx ];
    // out of range 
    if( L>Q_R || R<Q_L ) return -INF;

    // recursion down 
    int mid = (L+R)>>1;

    return max( Query(L_idx(idx) , L ,mid  ,Q_L , Q_R ) ,
                Query(R_idx(idx) , mid+1 ,R ,Q_L ,Q_R )  );
}

signed main(){
    OAO

    int n ,q ; 
    cin>>n;

    // for(int i=1;i<n;i++){
    //     cin>>arr[i];
    // }

    Build(1,1,n);

    // for(int i=1,x;i<=n;i++){
    //     cin>>x;
    //     Update(1,1,n,i,x);
    // }

    cin>>q;

    int L,R;

    while(q--){
        cin>>L>>R;
        if( L>R) swap(L,R);
        cout<<Query(1,1,n,L,R)<<'\n';
    }
    return 0;
}