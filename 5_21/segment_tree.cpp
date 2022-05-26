#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;
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

int T[MAX_N<<2] , arr[MAX_N];

void Build(int idx,int L,int R){
    if(L==R){
        T[L] =arr[L];
    }

    int mid = (L+R)>>1;

    Build( L_idx(idx) , L , mid );
    Build( R_idx(idx) , mid+1,R );

    // pull
    T[ idx ] = max( T[L] , T[R] );
}

void Update(int idx,int L,int R ,int pos ,int val){
    if( L==R ){
        T[L] = val;
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
}

int Query(int idx,int L,int R,int Q_L ,int Q_R ){
    // in current range
    if( L<= Q_L && Q_R <= R ) return T[ idx ];
    // out of range 
    if( L>Q_R || R<Q_L ) return -INF;

    // recursion down 
    int mid = (L+R)>>1;

    return max( Query(L_idx(idx) , L ,mid  ,Q_L , Q_R ) ,
                Query(R_idx(idx) , mid+1 ,R ,Q_L ,Q_R )  );
}