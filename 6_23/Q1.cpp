#include<bits/stdc++.h>
using namespace std;


void solve(int n){
    vector< pair<vector<int> , string> > arr(n);

    for(auto &i:arr){
        cin>>i.second;

        i.first.resize(5);
        for(int &j:i.first){
            cin>>j;
        }
    }

    sort(arr.begin() ,arr.end() ,greater<pair<vector<int> ,string > >() );

    int rk=1;

    for(auto &i:arr){
        cout<<rk++<<" "<<i.second<<" ";
        for(int &j:i.first) cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n";
}

int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);

    int n;
    while( cin>>n ){
        solve( n );
    }

    return 0;
}