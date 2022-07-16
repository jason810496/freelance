#include<bits/stdc++.h>
using namespace std;
#define OAO cin.tie(0);ios_base::sync_with_stdio(0);
#define F first
#define S second
#define ll long long



int arr[100];

// bool cmp(const int &a,const int &b){
// 	return a>b;
// }

bool cmp(int a, int b){
	return a>b;
}

struct point{
	int x, y;
};

bool cmp_point(point a ,point b){
	return a.x < b.x;
}


void demo(){
	// compare function : 
	sort( arr, arr+100, cmp );
}

int main(){
	
	vector<int> vec;
	sort( vec.begin() , vec.end() ) ;

	int arr[100];
	sort( arr , arr+100);

	// decreasing : 

	sort( vec.begin() , vec.end() , greater<int>() );

	// compare lambda : 

	sort( vec.begin()  , vec.end() , [&](const int &a ,  const int &b){
		return a>b ;
	});


	return 0;
}