#include<bits/stdc++.h>
using namespace std;
#define LL bitset<5000>
#define arr vector<unsigned long long>
#define all(x) x.begin(),x.end()

stack<LL> stk;

void Push(){
	stk.push(0);
	cout<<"0\n";
}

void Dup(){
	auto t = stk.top();
	stk.push(t);
	cout<<t.count()<<"\n";
}

void Union(){
	auto A= stk.top() ; stk.pop();
	auto B = stk.top() ; stk.pop();
	
	A|=B;
	
	stk.push(A);
	cout<<A.count()<<"\n";
}

void Intersect(){

	auto A= stk.top() ; stk.pop();
	auto B= stk.top() ; stk.pop();
	
	A&=B;

	stk.push(A);
	cout<<A.count()<<"\n";
}

void Add(){
	auto A= stk.top() ; stk.pop();
	auto B= stk.top() ; stk.pop();
	
	LL C=0,A2=A;

	if( A.none() ){ // A = null
		B[1]=1;
	}
	else{
		
		int cnt=0;
		for(int i=1 ;A2.any();A2>>=1,i++){
			if(A[i]){
				cnt+=i;
				cnt*=2;
			}
		}
		
		B[ cnt%3079+1800 ]=1;
	}
	
	stk.push(B);
	cout<<B.count()<<"\n";
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
		
	}
	
	return 0;
}
