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
#define PB push_back
typedef pair<int,int> pii;
const int MAX_N = 1e6+5;
const int INF = 1e9;

signed main(){
    OAO
    int n ;
    string name ,str ;
    unordered_map<string,int> Map; 
    cin>>n;
    
    for(int i=0 , cnt;i<n;i++){
        cin>>name>>cnt;
        Map[ name ] = cnt;
    }

    getline( cin , str );
    getline(cin , str );
    stringstream ss( str );
    vector< string > vec;
    while( ss.good() ){
        ss>>name;
        vec.push_back( name );
    }

    int args=0;
    vector<int> funStack;
    bool flag = true ;

    for(int i=0;i<vec.size() ;i++ ){
        if( Map.find( vec[i] ) == Map.end() ){
            flag = false;
            break;
        }
        if( Map[ vec[i] ] == 0 ){
            // args.PB( vec[i] );
            args++;
        }
        else{ // function 
            funStack.push_back( Map[ vec[i] ] );
            continue;
        }

        while( funStack.size() && funStack.back()>0 && args>0 ){
            args--;
            funStack.back()--;
            if( funStack.back()==0 ){
                funStack.pop_back();
                args++;
            }
        }
    }

    // cout<<"args : "<<args<<"\n";
    // for(auto i:funStack){
    //     cout<<i<<" ";
    // }
    // cout<<"\n";

    if( args>=2 || funStack.size() || !flag ){
        
        cout<<"Compilation Error\n";
    }
    else{
        cout<<"Accepted\n";
    }

    return 0;
}
