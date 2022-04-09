
public class HW06_8110056004_1{
	public double find_median(int[][]  arr){
	    
	    
        int n=arr.length , idx=0;
<<<<<<< HEAD
        int List[] = new int[50000];
=======
        int List[] = new int[5000000];
>>>>>>> 435be5841773bc9e3135208753fa56fa285b2998

        for(int i=0;i<n;i++){
            for(int j:arr[i]){
                List[idx++]=j;
            }
        }
        
        
       sort(List,0,idx-1);
       
    //   for(int i=0;i<idx;i++){
    //       System.out.print(List[i]+" ");
    //   }
    //     System.out.print("\n");
        
        int  sz = idx;
        
        if( sz%2==1 ){
            int a=List[sz/2];
            return Double.valueOf(a);
        } 
        
        double a= Double.valueOf( List[sz/2] ), b = Double.valueOf(List[ (sz-1)/2]);
        return (a+b)/2;
    }
	private void sort(int arr[], int l, int r){
        if (l < r) {
            int m =l+ (r-l)/2;
  
            sort(arr, l, m);
            sort(arr, m + 1, r);
  
            merge(arr, l, m, r);
        }
    }
    private void merge(int arr[], int l, int m, int r)
    {
        int n1 = m - l + 1;
        int n2 = r - m;
  
        int L[] = new int[n1];
        int R[] = new int[n2];
  
        for (int i = 0; i < n1; ++i){
            L[i] = arr[l + i];
        }
           
        for (int j = 0; j < n2; ++j){
            R[j] = arr[m + 1 + j];
        }
  
        int i = 0, j = 0;
  
        int k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
  
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
  
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
}




/*
public class HW
{
	public static void main (String[] args){
		HW test= new HW();
		int[][] test_case1={ {1,3,10} , {-1,5,7} , {-2,5,12} };
		int[][] test_case2={ {3} , {-1,5} , {-2,5,12} };
		
		double ans1 = test.find_median( test_case1 );
		double ans2 = test.find_median( test_case2 );
		
		System.out.println( ans1 );
		System.out.println( ans2 );
	}

	public double find_median(int[][]  arr){
	    
	    
        int n=arr.length , idx=0;
        int List[] = new int[5000];

        for(int i=0;i<n;i++){
            for(int j:arr[i]){
                List[idx++]=j;
            }
        }
        
        // b sort
        
        for(int i=0;i<idx;i++){
            for(int j=0;j<i;j++){
                if( List[i]<List[j] ){
                    int temp =  List[i];
                    List[i] = List[j];
                    List[j] = temp;
                }
            }
        }
        
        int  sz = idx;
        
        if( sz%2==1 ){
            int a=List[sz/2];
            return Double.valueOf(a);
        } 
        
        double a= Double.valueOf( List[sz/2] ), b = Double.valueOf(List[sz/2 -1 ]);
        return (a+b)/2;
    }
	
}

*/


