
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
const int MAX_N = 500005;
const int INF = 1e9;

// 7 bit rotation 
inline int mys(int c,int n ){
    return (((( c ) << (( n ) % 7) ) | (( c ) >> (7 - (( n ) % 7) ) ) ) & 127) ;
}

signed main(){
    // OAO
    
    for(int i=32;i<=126;i++){
        cout<<char(i)<<'\n';
    }
    cout<<char(32);
    return 0;
}


/*

char p ,c ,x,y;
    for(int a=0;a<7;a++){
        for(int b=0;b<7;b++){
            for(int c=0;c<7;c++){
                for(int d=0;d<7;d++){
                    
                    magic[0]= arr[ a ] ;
                    magic[1]= arr[ b ] ;
                    magic[2]= arr[ c ] ;
                    magic[3]= arr[ d ] ;

                    bool flag = true;

                    for ( int i = 0; i < 6; i ++) {
                        p = Ahoy [ i ];
                        c = mys ( mys ( p ^ x , i ) , mys ( p ^ y , i )) ^ mys ( mys ( magic [( p ^ x ) &3] , i ) , mys ( magic [( p ^ y ) & 3] , i ) ) ;
                        // assert ( c >= 32 && c <= 126) ;

                        if( !( c >= 32 && c <= 126) ){
                            flag=false;
                            break;
                        }
                        x = p ;
                        y = c ;

                        // 3 -> 000011 
                        if( c!= encrypt[i] ){
                            flag = false;
                            break;
                        }
                    }

                    if( flag ){
                        cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
                        return 0;
                    }
                }
            }
        }
    }

*/