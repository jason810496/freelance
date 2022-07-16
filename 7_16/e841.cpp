#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int arr[N],K[N];
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    int n,m,l,r,L=N,R=-1,op,s,ans=1,k=0;
    long long val=-1,cur=0,sum=0;
    cin>>n>>m;
    for(int i=0;i<m;i++){
         cin>>l>>r>>op>>s;
         L=min(L,l);
         R=max(R,r);
         if(op==1){
           arr[l]+=s;
           arr[r+1]-=s;
         }
         else{
            if(s==1) continue;
            K[l]+=s;
            K[r+1]-=s;
         }
    }
    for(int i=L;i<=R;i++){
        k+=K[i];
        sum+=arr[i];
        //cout<<sum<< ' ';
        cur=sum*(k==0 ? 1:k);
        if(cur>val){
            val=cur;
            ans=i;
        }
        //cout<<cur<<' ';
    }
    cout<<ans<<' '<<val;
    return 0;
}