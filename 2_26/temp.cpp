#include<bits/stdc++.h>
#define arr vector<int>
using namespace std;

stack<arr> stk;

void Push(){
	stk.push(arr(0));
	cout<<stk.top().size()<<"\n";
}

void Dup(){
	auto t = stk.top();
	stk.push(t);
	cout<<t.size()<<"\n";
}

void Union(){
	arr Top_1 = stk.top() ; stk.pop();
	arr Top_2 = stk.top() ; stk.pop();
	
	for(auto i:Top_1){
		Top_2.push_back(i);
	}
	
	stk.push(Top_2);
	cout<<Top_2.size()<<"\n";
}

void Intersect(){

	arr Top_1 = stk.top() ; stk.pop();
	arr Top_2 = stk.top() ; stk.pop();
	
	arr U(0);
	sort(Top_1.begin(),Top_1.end());
	
	for(auto i:Top_2){
		if( *lower_bound(Top_1.begin(),Top_1.end(),i)==i ){
			U.push_back(i);
			}
	}
	
	stk.push(U);
	cout<<U.size()<<"\n";
	
	/*
	cout<<"T1\n";
	for(auto i:Top_1) cout<<i<<" ";
	cout<<"\n";
	cout<<"T2\n";
	for(auto i:Top_2) cout<<i<<" ";
	cout<<"\n U : ";
	for(auto i:U) cout<<i<<" ";
	cout<<"\n";
	*/
}

void Add(){
	arr First = stk.top() ; stk.pop();
	arr Second = stk.top() ; stk.pop();
	
	Second.push_back(First.size()+1);
	stk.push(Second);
	cout<<Second.size()<<"\n";
}

int main(){
	cin.tie(0);ios_base::sync_with_stdio(0);
	
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
	}
	
	
	return 0;
}
