#include<bits/stdc++.h>
using namespace std;

int f(int a){
    if( a<3 ) return 1;
    else return f(a-2) + f(a-3);
}
int main(){
    cout<<f(3);

    int x=3 , y=2  , z=0;
    cout<<( !(y||z)||x )<<"\n";
    return 0;
}