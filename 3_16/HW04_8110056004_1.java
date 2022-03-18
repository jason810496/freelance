public class HW04_8110056004_1 {
	// public abstract boolean[]  one0k(String[] str);

    public boolean[]  one0k(String[] str)
	{
		boolean[] ans = new boolean[str.length];
		for (int i=0; i< str.length; ++i){
			 int n=str[i].length();
			 if(n%2==1) continue;
			 
			 boolean flag = true;
			 for(int j=0 , N=n/2 ; j<N;j++){
			     if( str[i].charAt(j)!='0' || str[i].charAt(n-j-1)!='1' ){
			         flag = false;
			         break;
			     }
			 }
			 
			 ans[i] = flag ;
		}
		return ans;
	}
}

/*
public class HW04_4108056007_4
{
	public static void main (String[] args){
		HW04_4108056007_4 test= new HW04_4108056007_4();
		String[] test_case={"00001111", "000101", "1", "11001", "01", "10", "011", "100", "00000000001111111111"};
		boolean[] ans= test.one0k( test_case );
		for (boolean i : ans) {
			System.out.println(i);
		}
	}

	public boolean[]  one0k(String[] str)
	{
		boolean[] ans = new boolean[str.length];
		for (int i=0; i< str.length; ++i){
			 int n=str[i].length();
			 if(n%2==1) continue;
			 
			 boolean flag = true;
			 for(int j=0 , N=n/2 ; j<N;j++){
			     if( str[i].charAt(j)!='0' || str[i].charAt(n-j-1)!='1' ){
			         flag = false;
			         break;
			     }
			 }
			 
			 ans[i] = flag ;
		}
		return ans;
	}
	
}

*/