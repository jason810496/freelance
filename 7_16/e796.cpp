#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int arr[1005],n,q;
    memset(arr,0,sizeof(arr));
    cin>>n>>q;
    for(int i=0,l,r;i<q;i++){
        cin>>l>>r;
        if(l>r) swap(l,r);
        arr[l]++;
        arr[r+1]--;
    }
    int MAX=INT_MIN,MIN=INT_MAX,MAX_num=0,MIN_num;
    for(int i=1,cur=0;i<=n;i++){
        cur+=arr[i];
        if(cur>MAX){
            MAX=cur;
            MAX_num=i;
        }
        if(cur<MIN){
            MIN=cur;
            MIN_num=i;
        }
        if(cur==MAX){
            MAX_num=max(MAX_num,i);
        }
    }
    cout<<MIN_num<<' '<<MAX_num;
    return 0;
}