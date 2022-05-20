
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

signed main(){
    OAO
    string str; cin>>str;

    bool Court[8] = {} ;
    int ans = 0 ;
    vector<int> vec ; 
    for(char &c : str ){
        if( c=='H' ){
            ans++; // itself
            for(int k=1;k<=3;k++){
                if( Court[k] ) ans++;
                Court[k]=0;
            }
        }
        else if( c=='O' ){
            vec.push_back(ans);
            ans = 0 ;
        }
        else if ( c=='1'){
            Court[0] = 1;
            for(int k=3;k>=0;k--){
                if( Court[k] ){

                    if( k>=3){
                        ans++;
                    }
                    else{
                        Court[k+1]=1;
                    }
                    Court[k]=0;
                }
            }
        }
        else if ( c=='2'){

            Court[0] = 1;
            for(int k=3;k>=0;k--){
                if( Court[k] ){

                    if( k>=2){
                        ans++;
                    }
                    else{
                        Court[k+2]=1;
                    }
                    Court[k]=0;
                }
            }
        }
        else if ( c=='3'){
            Court[0] = 1;
            for(int k=3;k>=0;k--){
                if( Court[k] ){

                    if( k>=1){
                        ans++;
                    }
                    else{
                        Court[k+3]=1;
                    }
                    Court[k]=0;
                }
            }
        }

        // cout<<c<<"  :  ";
        // for(int i=1;i<4;i++) cout<<Court[i]<<' ';
        // cout<<" ans : "<<ans;
        // cout<<'\n';
    }

    if( str.back() !='O' )vec.push_back( ans );

    int n = vec.size() , sum =0 , MX=0;

    for(int i=0;i<3 && i<n ;i++){
        sum += vec[i];
    }
    MX=max(MX,sum);

    for(int i=3;i<n;i++){
        sum-=vec[i-3];
        sum+=vec[i];
        MX=max(MX,sum);
    }
    cout<<MX;
    return 0;
}

