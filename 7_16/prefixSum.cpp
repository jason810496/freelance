#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long

/*

	array:		1 4 8  2  9  10 3 

prefix sum : 	1 5 13 15 24 34 37

difference : 	1 3 4 -6  7  1  -7 

*/

int main(){
	
	vector<int> arr(10) , prefix(10);

	prefix[0] = arr[0];

	for(int i=1 ; i<arr.size();i++){
		prefix[i] = prefix[i-1] + arr[i];
	}


	return 0;
}