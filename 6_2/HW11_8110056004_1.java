import java.io.Console;

public class HW11_8110056004_1{
    int N = 10005 , INF = 100000005;
    int n , m;
    int move[][] = { {0,1} , {1,0} , {0,-1} , {-1,0 } };

	public int count_water_volume(int[][] height){ 
        n = height.length;
        m = height[0].length;

        if( n<3 || m<3 ) return 0;

        int total = n*m;
        
        boolean vis[] = new boolean[total];
        Heap pq = new Heap();

        for(int i=0;i<n;i++){
            int j1 = 0 , j2=m-1;
            int id1 = i*m+j1 , id2 = i*m+j2;
            pq.push( new pii( height[i][j1 ] , id1 ) );
            pq.push( new pii( height[i][j2 ] , id2 ) );
            vis[ id1 ]=true;
            vis[ id2 ]=true;
        }

        for(int j=1;j<m-1;j++){
            int i1=0 , i2 = n-1;
            int id1 = i1*m+j , id2=i2*m+j;
            pq.push( new pii( height[i1][j] , id1 ) );
            pq.push( new pii( height[i2][j] , id2 ) );
            vis[ id1 ]=true;
            vis[ id2 ]=true;
        }
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         System.out.print( vis[i*m+j] );
        //     }
        //     System.out.println("");
        // }

        int ans=0;

        while( pq.size() >0 ){
            pii cur = pq.top();
            pq.pop();
            int x=cur.pos/m;
            int y=cur.pos%m;
            int h=cur.ht;

            for(int k=0;k<4;k++){
                int i= x+move[k][0];
                int j= y+move[k][1];
                int id = i*m+j;
                if( i<0 || j<0 || i>=n || j>=m || vis[id] ) continue;

                vis[ id ] = true;
                ans+=( h>height[i][j] ? h-height[i][j]:0);
                pq.push( new pii( (h>height[i][j] ? h:height[i][j] ) , id ) );
                
            }
        }

        return ans;
    }

    public class pii{
        int ht,pos;
        pii(int h,int p){
            ht=h;
            pos=p;
        }
    }


    public class Heap{
        pii arr[] = new pii[N];
        int _size=0;
        int _min_idx=-1;

        pii top(){
            int ans=INF;
            for(int i=0;i<_size;i++){
                if( ans > arr[i].ht || ans==arr[i].ht ){
                    _min_idx = i;
                    ans = arr[i].ht;
                }
            }
            return arr[_min_idx] ;
        }

        void pop(){
            if( _min_idx==-1 ) top();

            for(int i=_min_idx ; i<_size-1;i++){
                arr[i] = arr[i+1];
            }
            _size--;
            _min_idx=-1;
        }

        void push(pii a){
            _size++;
            arr[_size-1]=a;
        }

        int size(){
            return _size;
        }
    }
}



