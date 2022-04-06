
public class HW06_8110056004_1{
	public double find_median(int[][]  arr){
	    
	    
        int n=arr.length , idx=0;
        int List[] = new int[50000];

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


