
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
    OAO
    
    // for(int i=32;i<=128;i++){
    //     cout<<char(i)<<'\n';
    // }
    string encrypt;
    getline(cin,encrypt);
    string Ahoy = "Ahoy!!";

    // cin>>encrypt;

    int magic[4] ;
    // int arr[7] = {49, 98, 69, 11, 22, 44, 88};

    vector< vector<int > > arr(4); 
    // int xy[4][2] = { {0,4} , {1,0} , {2,3} , {3, 2 } };

    for(int i=0;i<7;i++){
        arr[0].push_back( mys( encrypt[4] ^ mys(mys('!'^'y',4),  mys('!'^encrypt[3],4)), i) );
        arr[1].push_back( mys( encrypt[0] ^ mys(mys('A'^'\0',0), mys('A'^'\0',0)),  i) );
        arr[2].push_back( mys( encrypt[3] ^ mys(mys('y'^'o',3),  mys('y'^encrypt[2],3)),i) );
        arr[3].push_back( mys( encrypt[2] ^ mys(mys('o'^'h',2),  mys('o'^encrypt[1],2)),  i) );
    }

    for(auto i:arr){
        for(auto j:i){
            cout<<j<<' ';
        }
        cout<<'\n';
    }
    char p ,c ,x=0,y=0;

    int ans =0 ;
    bool flag = false;
    for(int a=0;a<7;a++){
        for(int b=0;b<7;b++){
            for(int c=0;c<7;c++){
                for(int d=0;d<7;d++){
                    magic[0] = arr[0][a];
                    magic[1] = arr[1][b];
                    magic[2] = arr[2][c];
                    magic[3] = arr[3][d];

                    char p , c , x = 0 , y = 0;
                    string temp ;
                    int i = 0;
                    for ( ; i < 6 ; i ++) {
                        p = Ahoy[ i ];
                        // assert ( p >= 32 && p <= 126) ;
                        c = mys ( mys ( p ^ x , i ) , mys ( p ^ y , i )) ^ mys ( mys ( magic [( p ^ x ) &3] , i ) , mys ( magic [( p ^ y ) & 3] , i ) ) ;
                        // assert ( c >= 32 && c <= 126) ;
                        // if( !( c >= 32 && c <= 126) ) break;
                        x = p ;
                        y = c ;

                        // 3 -> 000011 
                        temp += c ;
                    }

                    if( temp == encrypt.substr(0,6) ){
                        
                        cout<<temp<<'\n';

                        for(int i=0;i<4;i++){
                            cout<<magic[i]<<' ';
                        }
                        cout<<'\n';

                        for( ; i< encrypt.size() ; i++) {
                            p = Ahoy[ i ];
                            // assert ( p >= 32 && p <= 126) ;
                            c = mys ( mys ( p ^ x , i ) , mys ( p ^ y , i )) ^ mys ( mys ( magic [( p ^ x ) &3] , i ) , mys ( magic [( p ^ y ) & 3] , i ) ) ;
                            // assert ( c >= 32 && c <= 126) ;
                            // if( !( c >= 32 && c <= 126) ) break;
                            x = p ;
                            y = c ;
                            temp += c ;
                        }

                        cout<<temp<<'\n';
                    }

                    
                }
            }
        }
    }
    
    if( flag ) cout<<ans;
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