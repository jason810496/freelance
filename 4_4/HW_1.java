
public class HW_1{
	public double find_median(int[][]  arr){
	    
	    
		int n=arr.length;
		ArrayList<Integer> List = new ArrayList<Integer>();
	
		for(int i=0;i<n;i++){
			for(int j:arr[i]){
				List.add(j);
			}
		}
		
		Collections.sort(List);  
		
		int  sz = List.size();
		
		if( sz%2==1 ){
			int a=List.get(sz/2);
			return Double.valueOf(a);
		} 
		
		double a= Double.valueOf( List.get(sz/2) ), b = Double.valueOf(List.get(sz/2 -1 ) );
		return (a+b)/2;
	}
}


/*
import java.util.ArrayList;
import java.util.Collections;

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
	    
	    
        int n=arr.length;
        ArrayList<Integer> List = new ArrayList<Integer>();

        for(int i=0;i<n;i++){
            for(int j:arr[i]){
                List.add(j);
            }
        }
        
        Collections.sort(List);  
        
        int  sz = List.size();
        
        if( sz%2==1 ){
            int a=List.get(sz/2);
            return Double.valueOf(a);
        } 
        
        double a= Double.valueOf( List.get(sz/2) ), b = Double.valueOf(List.get(sz/2 -1 ) );
        return (a+b)/2;
    }
	
}

*/

