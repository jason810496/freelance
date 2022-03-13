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
const int MAX_N = 50005;
const int INF = 1e9;

class PQ{

    private:
        vector<int> arr;

        inline int P(int i){
            return (i-1)/2;
        }

        inline int L(int i){
            return (i*2+1);
        }

        inline int R(int i){
            return (i*2+2);
        }

        void adj_down(int i){
            int l=L(i) , r=R(i) , idx=i;

            if( l<Size() && arr[l] < arr[i]){
                idx = l;
            }

            if( r<Size() && arr[r] < arr[idx]){
                idx = r;
            }

            if(idx != i ){
                swap(arr[i],arr[idx]);
                adj_down(idx);
            }
        }

        void adj_up(int i){
            if( i && arr[P(i)] > arr[i]){
                swap(arr[i] , arr[P(i)]);
                adj_up(P(i));
            }
        }

    public:
        inline int Size(){
            return arr.size();
        }
        void Push(int v){
            arr.push_back(v);
            adj_up( (arr.size()-1) );
        }
        void Pop(){
            cout<<arr[0]<<' ';
            arr[0] = arr.back();
            arr.pop_back();

            adj_down(0);
        }

        void Print(){
            
            queue<int> q;
            vector<int> ans;
            q.push(0);

            while(q.size()){
                int idx = q.front();
                q.pop();
                ans.push_back(arr[idx]);

                if( L(idx) < arr.size() ) q.push(L(idx));
                if( R(idx) < arr.size() ) q.push(R(idx));
            }

            for(auto i :ans){
                cout<<i<<' ';
            }
        }
};

signed main(){
    int n;
    cin>>n;
    
    PQ pq;

    for(int i=0,x;i<n;i++){
        cin>>x;
        pq.Push(x);
    }

    pq.Print();
    return 0;
}