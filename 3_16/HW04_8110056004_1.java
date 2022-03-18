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