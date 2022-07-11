#include<bits/stdc++.h>
using namespace std;

int lsearch(int arr[], unsigned int len, int target, unsigned& counter) {
    counter++;
    if (len == 0) return -1;
    counter++;
    if (arr[0] == target) return 0;
    if (lsearch(arr+1, len-1, target, counter) == -1) {
       counter++;
        return -1;
    } else {
       counter++;
        return 1 + lsearch(arr+1, len-1, target, counter);
    }
} // lsearch


int main() {
//   // Question 1 test
//   cout <<"Question 1:\n";
    unsigned count=0;
    // Question 6 test
    cout<<"Question 6:\n";
    count=0;
    int arr3[]={1,2,3,4,5,6,7,8,9};
    cout<<"l:"<<lsearch(arr3, 9, 9, count)<<"\n";
    cout<<"count="<<count<<endl;

    count=0;
    int arr4[]={1,2,3,4,5,6,8,9,9};
    cout<<"l:"<<lsearch(arr4, 9, 9, count)<<"\n";
    cout<<"count="<<count<<endl;

    count=0;
    int arr5[]={1,2,3,4,5,6,9,9,9};
    cout<<"l:"<<lsearch(arr5, 9, 9, count)<<"\n";
    cout<<"count="<<count<<endl;

    count=0;
    int arr6[]={1,2,3,4,5,6,9};
    cout<<"l:"<<lsearch(arr6, 7, 9, count)<<"\n";
    cout<<"count="<<count<<endl;

    count=0;
    int arr7[]={1,2,3,4,5,6,8,8,8};
    cout<<"l:"<<lsearch(arr7, 9, 9, count)<<"\n";
    cout<<"count="<<count<<endl;

    count=0;
    int arr8[]={9,9,3,4,5,6,8,8,8};
    cout<<"l:"<<lsearch(arr8, 9, 9, count)<<"\n";
    cout<<"count="<<count<<endl;

    count=0;
    int arr9[]={1,9,3,4,5,6,8,8,8};
    cout<<"l:"<<lsearch(arr9, 9, 9, count)<<"\n";
    cout<<"count="<<count<<endl;

    count=0;
    int arr10[]={1,2,9,4,5,6,8,8,8};
    cout<<"l:"<<lsearch(arr10, 9, 9, count)<<"\n";
    cout<<"count="<<count<<endl;

    

    memset(arr9,0,sizeof(arr9));
    cout<<"Loop\n";
    for(int i=0;i<9;i++){
        arr9[i]=9;
        count=0;
        for(int j=0;j<9;j++){
            cout<<arr9[j]<<' ';
        }
        cout<<"\n";
        cout<<"l:"<<lsearch(arr9, 9, 9, count)<<"\n";
        cout<<"count="<<count<<endl;
        cout<<5*pow(2,i)-3<<"\n";
        arr9[i]=-1;
    }

    return 0;
}
