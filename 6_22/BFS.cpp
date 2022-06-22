#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define X first 
#define Y second 

vector< vector<int> > Move = { {0,1} , {1,0} , {0,-1} , {-1,0} };

void solve(){
    int n , m ;
    pii Start , End;
    cin>>n>>m;
    cin>>Start.X>>Start.Y>>End.X>>End.Y;

    vector< vector< int > > Graph(n+1 , vector<int>(m+1) );

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char ch;
            cin>>ch;
            
            Graph[i][j] = (ch=='*' ? -1:0);
        }
    }

    Graph[ Start.X ][ Start.Y ] = 1;
    queue<pii> q;
    q.push( Start );

    while( q.size() ){
        pii cur = q.front();
        q.pop();

        if( cur.X==End.X && cur.Y == End.Y ){
            cout<<"Yes "<<Graph[cur.X][cur.Y]-1<<"\n";
            return ;
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
}

int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);

    int t;
    cin>>t;

    while( t-- ){
        solve();
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