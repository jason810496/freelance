#include<bits/stdc++.h>
using namespace std;

int table[2][13] = {
    { 0 , 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 ,31 },
    { 0 , 31 , 29 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 ,31 }
};

inline int leap(int y){
    if( (y%400==0) || (y%4==0 && y%100!=0 ) ) return 1;

    return 0;
}

 
void Output(int y, int m, int d){

	if (m == 1 || m == 2) {
		m += 12;
		y--;
	}

	int wk = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
	switch (wk){
        case 0: cout << "Monday\n"; break;
        case 1: cout << "Tuesday\n"; break;
        case 2: cout << "Wednesday\n"; break;
        case 3: cout << "Thursday\n"; break;
        case 4: cout << "Friday\n"; break;
        case 5: cout << "Saturday\n"; break;
        case 6: cout << "Sunday\n"; break;
	}
}

void solve(int Y,int M,int D,int span){

    D +=span;
    int k=M;

    for( ; D>table[ leap(Y) ][k] ; k++ ){
        D -=table[ leap(Y)][k];
        if( k==12 ){
            k=1;
            Y++;
        }
    }
    M = k;

    cout<<Y<<"/"<<M<<"/"<<D<<" ";
    Output( Y,M,D);
    return ;
}

int main(){

    cin.tie(0);ios_base::sync_with_stdio(0);

    string str , raw;
    int span ;
    vector<int> result(3);
    while( getline( cin , str ) ){
        stringstream ss(str);
        ss>>str;
        ss>>span;

        int sum=0 , cnt=0;

        for(char c:str){
            if( isdigit(c) ){
                sum*=10;
                sum+=c-'0';
            }
            else if( c=='/'){
                result[ cnt++ ] = sum ;
                sum=0;
            }

            if( cnt==3 ) break;
        }

        solve(result[0] , result[1] , result[2] , span  );
    }

    return 0;
}