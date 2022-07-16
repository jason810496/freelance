#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long


int JumpBinarySearch( vector<int> &arr,int target){
	int pos=0 , n= arr.size() ;
	if( arr[ pos ] >= target ) return pos ;

	for(int jump = n/2 ; jump ; jump>>=1 ){
		while( pos+jump < n && arr[ pos + jump ] < target ){
			pos+=jump;
		}
	}

	return pos+1;
}

int Inclusive( vector<int> &arr , int target ){
	int L=0 , R = arr.size()-1;

	while( L<=R ){
		int mid = (L+R)/2;
		if( arr[mid]>target ) R = mid-1;
		else L = mid+1;
	}

	return L;
}

int Exclusive(  vector<int> &arr,int target ){
	int L=0 , R=arr.size();

	while( L<R ){
		int mid = (L+R)/2;
		if( arr[mid] > target ){
			R = mid;
		}
		else L = mid+1;
	}

	return L;
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
	Inclusive( vec , 100 );

	// [ L ,R ) inclusive L , exclusive R
	Exclusive( vec , 100 );

	// jump Binary Search 
	JumpBinarySearch( vec , 100 );

	return 0;
}