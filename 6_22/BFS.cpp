#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define X first 
#define Y second 

vector< vector<int> > Move = { {0,1} , {1,0} , {0,-1} , {-1,0} };


struct data{
    int n , m ;
    pii Start , End;
    vector< vector< int > > Graph;
};

vector< data > Data;

void Input(int idx){
    cin>>Data[idx].n>>Data[idx].m;
    cin>>Data[idx].Start.X>>Data[idx].Start.Y>>Data[idx].End.X>>Data[idx].End.Y;

    Data[idx].Graph.resize(Data[idx].n+1 , vector<int>(Data[idx].m+1 , 0) );

    for(int i=1;i<=Data[idx].n;i++){
        for(int j=1;j<=Data[idx].m;j++){
            char ch;
            cin>>ch;
            if( ch=='*') Data[idx].Graph[i][j] = -1;
            else{
                Data[idx].Graph[i][j] = 0;
                if( ch=='s'){
                    Data[idx].Start = {i,j};
                }
                else if( ch=='e'){
                    Data[idx].End = {i,j};
                }
            }
        }
    }
}

void solve(int idx){
    int n=Data[idx].n , m=Data[idx].m ;
    pii Start=Data[idx].Start , End=Data[idx].End;

    vector< vector< int > > Graph = Data[idx].Graph;

    Graph[ Start.X ][ Start.Y ] = 1;
    queue<pii> q;
    q.push( Start );

    while( q.size() ){
        pii cur = q.front();
        q.pop();

        if( cur == End ){
            cout<<"Yes "<<Graph[End.first][End.second]-1<<"\n";
            return;
        }

        for(auto &v : Move){
            int next_x = cur.X+v[0] , next_y = cur.Y+v[1];

            if( next_x<=0 || next_y<=0 || next_x >n || next_y>m ) continue;

            if( Graph[ next_x ][next_y ]==0 ){
                Graph[next_x][next_y] = Graph[ cur.X ][ cur.Y ]+1;
                q.push( { next_x , next_y } );
            }
        }
    }

    cout<<"No\n";
    return ;
}

int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);

    int t;
    cin>>t;

    Data.resize(t);

    for(int i=0;i<t;i++){
        Input(i);
    }

    for(int i=0;i<t;i++){
        solve(i);
    }

    return 0;
}

/*****************************************

Sample Input：
2
17 20 4 3 17 1
********************
********************
********************
**s++++*************
**+***+*************
**+***+*************
**+***+*************
**+***+*************
**+***+*************
**+***+*************
**+***+*************
**+***+*************
**+++++*************
**+++++*************
+++++++*************
+*******************
e*******************
17 20 4 3 17 1
********************
********************
********************
**s++++*************
**+***+*************
**+***+*************
**+***+*************
**+***+*************
**+***+*************
**+***+*************
**+***+*************
**+***+*************
**+++++*************
**+++++*************
+++++++*************
********************
e*******************
Sample Output：
Yes 15
No



*****************************************/