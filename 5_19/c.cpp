// c f g h k  l

#include<bits/stdc++.h>
using namespace std;

int pos[4][2] = { {0,1} ,{1,0},{0,-1} , { -1 ,0 } };

int n  , m; 
vector< vector<int> > G;

void DFS(int x,int y ){
    for(int k=0;k<4;k++){
        int i = x + pos[k][0] , j = y +pos[k][1];
        if( i<1 || j<1 || i==n-1 || j==m-1) continue;
        if( G[i][j] ) continue;

        
    }
}
int main (){
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin>>n>>m;
    G.resize( n , vector<int>(m) );

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>G[i][j];
        }
    }

    DFS(1,1);


    return 0;
}