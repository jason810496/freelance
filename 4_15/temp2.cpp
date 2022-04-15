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
const int MAX_N = 300005;
const int INF = 1e9;


int Median( vector<int> arr,int idx){

    int n = arr.size();
    vector< vector<int> > sub(n/5+1);
    int r=0,cnt=0;
    for(int i=0;i<n;i++,cnt++){
        if(cnt>=5){
            cnt=0;
            r++;
        }

        sub[r].push_back(arr[i]);
    }

    // for(auto i:sub){
    //     for(auto j:i){
    //         cout<<j<<' ';
    //     }
    //     cout<<'\n';
    // }

    vector<int> mid;
    for(auto &i:sub){
        if(i.empty() ) break;
        // if( i.size()==1){
        //     mid.push_back(i.back()  );
        //     continue;
        // }
        sort(range(i));
        mid.push_back( i[ (i.size()-1)/2] );

        // cout<<i[i.size()/2];
    }
    // cout<<"test2\n";

    int pivot;
    if( mid.size() <=5 ){
        sort(range(mid));
        pivot = mid[ (mid.size()-1)/2];
    }
    else pivot = Median(mid , mid.size()/2);

    cout<<"pivot : "<<pivot<<'\n';
    vector<int> Big , Small;

    for(int i : arr){
        if( i>pivot){
            Big.push_back(i);
        }
        else if(i<pivot) Small.push_back(i);
    }

    int k = Small.size();

    if( idx < k) return Median(Small,idx);
    else if(idx>k)return Median(Big,idx-k-1);

    return pivot;
}

signed main(){
    
    int n;
    cin>>n;
   
    vector<int> vec(n);

    for(int &i:vec){
        cin>>i;
    }

    int ans = Median( vec , n/2-1);
    cout<<"answer : "<<ans;
    return 0;
}
/*
10
2 3 1 4 5 8 7 6 10 9

10
8 7 3 2 4 5 9 1 10 6
*/
