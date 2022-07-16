#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long

inline bool cmp(const int &a,const int &b){
	return a>b;
}

int main(){
	
	vector<int> vec;
	sort( vec.begin() , vec.end() ) ;

	int arr[100];
	sort( arr , arr+100);

	// decreasing : 

	sort( vec.begin() , vec.end() , greater<int>() );

	// compare function : 

	sort( vec.begin() , vec.end() , cmp );

	// compare lambda : 

	sort( vec.begin()  , vec.end() , [&](const int &a ,  const int &b){
		return a>b ;
	});


	return 0;
}