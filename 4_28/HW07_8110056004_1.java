
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.ArrayList;

public  class HW07_8110056004_1{
	public int[][] bestPhone(int[][] inputArr){ 
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



