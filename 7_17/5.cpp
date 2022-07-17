#include<iostream>
#include<queue>
using namespace std;

int main (){
    int n , second;
    cin>>n;

    queue<int> q;

    for(int i=1;i<=n;i++){
        q.push(i);
    }

    while( q.size()>=2 ){
        cout<<q.front()<<" ";
        q.pop();
        second = q.front();
        q.pop();
        q.push( second );
    }
    cout<<q.front();


    return 0;
}