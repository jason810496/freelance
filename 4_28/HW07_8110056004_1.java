/*
public class HelloWorld{

     public static void main(String []args){
        System.out.println("Hello World");
     }
}
*/
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.ArrayList;

public class HelloWorld{
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

/*
public  class HW07_8110056004_1 extends Buy_Phone{
	public int[][] bestPhone(int[][] inputArr){ 
        sort(inputArr, 0, inputArr.length);

        for(int i=0;i<inputArr.length;i++){
            System.out( inputArr[i][0]);
        }
        return new int[1][1];
    }

    private void sort(int arr[][], int l, int r){
        if (l < r) {
            int m =l+ (r-l)/2;
  
            sort(arr, l, m);
            sort(arr, m + 1, r);
  
            merge(arr, l, m, r);
        }
    }
    private void merge(int arr[][], int l, int m, int r)
    {
        int n1 = m - l + 1;
        int n2 = r - m;
  
        int L[][] = new int[n1][2];
        int R[][] = new int[n2][2];
  
        for (int i = 0; i < n1; ++i){
            L[i][0] = arr[l + i][0];
            L[i][1] = arr[l + i][1];
        }
           
        for (int j = 0; j < n2; ++j){
            R[j][0] = arr[m + 1 + j][0];
            R[j][1] = arr[m + 1 + j][1];
        }
  
        int i = 0, j = 0;
  
        int k = l;
        while (i < n1 && j < n2) {
            if (L[i][0] <= R[j][0]) {
                arr[k][0] = L[i][0];
                arr[k][1] = L[i][1];
                i++;
            }
            else {
                arr[k][0] = R[j][0];
                arr[k][1] = R[j][1];
                j++;
            }
            k++;
        }
  
        while (i < n1) {
            arr[k][0] = L[i][0];
            arr[k][1] = L[i][1];
            i++;
            k++;
        }
  
        while (j < n2) {
            arr[k][0] = R[j][0];
            arr[k][1] = R[j][1];
            j++;
            k++;
        }
    }
}
*/
