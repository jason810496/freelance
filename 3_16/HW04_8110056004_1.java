public class HW04_8110056004_1 {
	// public abstract boolean[]  one0k(String[] str);

    public boolean[]  one0k(String[] str){
        int n = str.length ;
        boolean[] ans_list =  new boolean [n];

        for(int i=0;i<n;i++){
            int cnt_0=0;
            int cnt_1=0;
            boolean flag = false;
            char[] num = str[i].toCharArray();
            for(int j=0;j<num.length; j++){
                if(num[j]=='0'){
                    cnt_0++;
                }
                else {
                    break;
                }
            }

            cnt_1 = n-cnt_1;

            ans_list[i] = ( (cnt_0==0 || cnt_0!=cnt_1) ? false:true);
        }

        return ans_list;
    }
}