#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int move[4][2] = { {-1,0} , {1,0} , {0,-1} , {0,1} };

int **MineArray  ,**Map;
//  amount of mines;
int Mine;

void UserInterface(){
    printf("input next position :\n(1) up \n(2) down \n(3) left \n(4) right\n");
}

bool check(int curX,int curY ){
    if( Map[ curX ][ curY ]==-1 ) return false;
    return true;
}

int main(){
    // map size 
    int Row , Column ; 
    printf("Input row size of map: ");
    scanf("%d" , &Row);
    printf("Input row column of map: ");
    scanf("%d" , &Column);

    printf("Input the amount of mines: ");
    scanf("%d" , &Mine );

    MineArray = (int**)malloc(Mine * sizeof(int*));
    for(int i=0;i<Mine;i++){
        MineArray[i]=(int*)malloc(2 * sizeof(int));
    }

    Map = (int**)malloc(Row * sizeof(int*));
    for(int i=0;i<Row;i++){
        Map[i]=(int*)malloc(Column * sizeof(int));
    }

    for(int i=0;i<Mine;i++){
        printf("Input coordinate (x,y) of Mine %d :\n" ,i+1);
        scanf("%d%d",&MineArray[i][0],&MineArray[i][1]);
        Map[ MineArray[i][0] ][ MineArray[i][1] ] = -1;
    }

    int curX=Row/2 , curY=Column/2 , option ;

    while( check(curX,curY) ){
        printf(" current condition: \n");
        for(int i=-1;i<=Row;i++){
            for(int j=-1;j<=Column;j++){
                if( curX==i && curY==j ){
                    printf("X");
                }
                else if(i==-1 || j==-1 || i==Row || j==Column){
                    if( (i==-1&&j==-1) || (i==-1&&j==Column) || (i==Row&&j==-1) || (i==Row&&j==Column) ){
                        printf("+");
                    }
                    else printf(".");
                }
                else{
                    if( check(i,j) ){
                        printf(" ");
                    }
                    else {
                        // mine
                        printf("*");
                    }
                }
            }
            printf("\n");
        }
        UserInterface();
        scanf("%d" , &option );
        curX+=move[option-1][0];
        curY+=move[option-1][1];

        if( curX==-1 ) curX=0;
        if( curX==Row) curX=Row-1;
        if( curY==-1 ) curY=0;
        if( curY==Column) curY=Column-1;
    }

    printf("Game over !");

    return 0;
}