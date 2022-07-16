#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long


int JumpBinarySearch( vector<int> &arr, int n,int target){
	int pos=0;
	if( arr[ pos ] >= target ) return pos ;

	for(int jump = n/2 ; jump ; jump>>=1 ){
		while( pos+jump < n && arr[ pos + jump ] < target ){
			pos+=jump;
		}
	}

	return pos+1;
}

inline bool cmp(const int &a , const int &b){
	return a>b; 
}


int main(){
	
	// remember to sort the array first 
	vector<int> vec;
	sort( vec.begin() , vec.end() ) ;

	// upper_bound : 

	upper_bound( vec.begin() , vec.end() , 10 );

	// lower_bound : 

	lower_bound( vec.begin() , vec.end() , 10 );

	// compare funciton in B-search 

	lower_bound( vec.begin() , vec.end() , 10 , cmp );

	// our Binary search 

	// [ L ,R ] inclusive L , inclusive R 
	int L=1 , R=10 , target = 100 ;

	while( L<=R ){
		int mid  = (L+R)/2;

		if( vec[mid]> target ){
			R = mid-1;
		}
		else L = mid+1 ;
	}


	// jump Binary Search 

	JumpBinarySearch( vec , vec.size() , 100 );

	return 0;
}