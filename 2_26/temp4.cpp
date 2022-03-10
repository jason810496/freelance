#include<bits/stdc++.h>
using namespace std;
#define LL unsigned long long
#define arr vector<unsigned long long>
#define all(x) x.begin(),x.end()

stack<arr> stk;

/*
inline int Size(LL num){
	int cnt=0;
	while(num){ num/=10;cnt++;}
	return cnt;
} 

*/
void Push(){
	stk.push(arr(0));
	cout<<"0\n";
}

void Dup(){
	auto t = stk.top();
	stk.push(t);
	cout<<t.size()<<"\n";
}

void Union(){
	auto A= stk.top() ; stk.pop();
	auto B = stk.top() ; stk.pop();
	
	A.insert(A.end() , all(B) );
	sort(all(A));
	A.erase( unique(all(A)),A.end() );
	
	stk.push(A);
	cout<<A.size()<<"\n";
}

void Intersect(){

	auto A= stk.top() ; stk.pop();
	auto B = stk.top() ; stk.pop();
	arr temp(0);
	
	sort(all(A));
	sort(all(A));
	
	A.erase( unique(all(A)),A.end() );
	B.erase( unique(all(B)),B.end() );
	
	for(auto i:B){
		if( *lower_bound(all(A),i)==i ){
				temp.push_back(i);
			}
	}
	
	stk.push(temp);
	cout<<temp.size()<<"\n";
}

void Add(){
	auto A= stk.top() ; stk.pop();
	auto B= stk.top() ; stk.pop();
	
	sort(all(A));
	
	LL num=0;
	for(auto i:A){
		num+=i;
		num*=10;
	}
	
	B.push_back( ( num ? num:1) );
	
	sort(all(B));
	B.erase( unique(all(B)),B.end() );
	
	stk.push(B);
	
	cout<<B.size()<<"\n";
}

signed main(){
	//cin.tie(0);ios_base::sync_with_stdio(0);
	
	int n ; 
	
	cin>>n;
	string oper;
	
	while(n--){
		cin>>oper;
		if(oper=="PUSH"){
			Push();
		}
		else if(oper=="DUP"){
			Dup();
		}
		else if(oper=="UNION"){
			Union();
		
		}
		else if(oper=="INTERSECT"){
			Intersect();
		}
		else if(oper=="ADD"){
			Add();
		}
		
		//cout<<" top : "<<stk.top()<<"\n stk: "<<stk.size()<<"\n";
	}
	
	
	return 0;
}
