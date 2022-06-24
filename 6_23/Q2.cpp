#include<bits/stdc++.h>
using namespace std;

int arr[105];

void solve(int idx){
    int n=idx-2,target=arr[idx-1];

    sort( arr , arr+n);

    cout<<"sort array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }

    cout<<"\ntarget: "<<target<<"\n";

    int L=0 ,R=n-1;

    while( L<=R ){
        int mid  = (L+R)/2;
        cout<<"middle is "<<mid<<",";
        if( arr[mid]==target ){
            cout<<"get answer in "<<mid<<"\n";
            break;
        }
        else{
            cout<<"because ";

            if( arr[mid]>target ){
                R = mid-1;
                cout<<arr[mid]<<" > "<<target<<", right is "<<mid+1<<"\n";
            }
            else{
                L = mid+1; 
                cout<<arr[mid]<<" < "<<target<<", left is "<<mid-1<<"\n";
            }
        }
    }

    cout<<"\n";
    return ;
}

int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);

    // int t;
    // cin>>t;

    // while( t-- ){
    //     solve();
    // }

    string str;
    while( getline( cin , str ) ){
        stringstream ss(str);
        int idx = 0 , num ;

        while( ss>>num ){
            arr[idx++] = num ;
        }
        
        if( !idx) return 0;
        solve( idx );
    }

    return 0;
}