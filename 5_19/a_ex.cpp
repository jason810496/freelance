#include<bits/stdc++.h>
using namespace std ;

// # define mys (c , n ) (((( c ) << (( n ) % 7) ) | (( c ) >> (7 - (( n ) % 7) ) ) ) & 127)


inline int mys(int c,int n ){
    return (((( c ) << (( n ) % 7) ) | (( c ) >> (7 - (( n ) % 7) ) ) ) & 127) ;
}
int main () {
    string plaintext ;
    getline ( cin , plaintext ) ;
    assert ( plaintext . substr (0 , 6) == "Ahoy!!" && plaintext . back () == '!') ;
    assert ( plaintext . size () >= 10 && plaintext . size () <= 280) ;

    int magic [4];

    for ( int i = 0; i < 4; i ++) {
        cin >> magic [ i ];
        assert ( magic [ i ] >= 0 && magic [ i ] <= 127) ;
    }

    string ciphertext ;

    char p , c , x = 0 , y = 0;
    for ( int i = 0; i < plaintext . size () ; i ++) {
        p = plaintext [ i ];
        assert ( p >= 32 && p <= 126) ;
        c = mys ( mys ( p ^ x , i ) , mys ( p ^ y , i )) ^ mys ( mys ( magic [( p ^ x ) &3] , i ) , mys ( magic [( p ^ y ) & 3] , i ) ) ;
        assert ( c >= 32 && c <= 126) ;
        x = p ;
        y = c ;
        ciphertext += c ;
    }

    cout << ciphertext << "\n";
    return 0;
}