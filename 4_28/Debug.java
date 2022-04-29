
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.ArrayList;

public class Debug{
    public static void main(String[] args){
        int[][] test1 = {{1,1},{2,4},{2,10},{5,4},{4,8},{5,5},{8,4},{10,2},{10,1}} ;
        
        int[][] test2 = {{1,1},{2,4},{2,10},{5,4},{4,8},{5,5},{8,4},{10,2},{10,1},{100,100}} ;
        int[][] ans1 = Solution( test1 );
        int[][] ans2 = Solution( test2 );
        
        System.out.println(Arrays.deepToString( ans1 ));
        System.out.println(Arrays.deepToString( ans2 ));
    }
	public static int[][] Solution(int[][] inputArr){ 
        // sort(inputArr, 0, inputArr.length);
        
        Arrays.sort( inputArr , new Comparator<int[]>() {
            @Override
            public int compare(int[] first, int[] second) {
               if(first[1] < second[1]) return 1;
               else return -1;
            }
        });

        int n = inputArr.length , cur=0;
        
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        for(int i=0;i<n;i++){
            if( inputArr[i][0] > cur ){
                cur = inputArr[i][0];
                ans.add( Arrays.asList( inputArr[i][0] , inputArr[i][1]) );
            }
        }
        
        int[][] res = new int[ans.size()][2];
 
        int i = 0;
        for (List<Integer> l:ans) {
            res[i  ][0] = l.get(0);
            res[i++][1] = l.get(1);
        }
        
        return res;
    }
   
}

