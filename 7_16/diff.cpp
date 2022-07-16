#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long


int main(){
	vector<int> arr(10) , diff(10);

	diff[0] = arr[0];
	for(int i=1;i<arr.size() ; i++){
		diff[i] = arr[i] -arr[i-1];
	}


	return 0;
}