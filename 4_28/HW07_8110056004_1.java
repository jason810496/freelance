


public  class HW07_8110056004_1{
	public int[][] bestPhone(int[][] inputArr){ 
        int n = inputArr.length , cur=0 , cnt=0;

        sort( inputArr , 0 ,n-1);

        boolean[] flag = new boolean [n];
        for(int i=0;i<n;i++){
            if( inputArr[i][0] > cur ){
                cur = inputArr[i][0];
                flag[i] = true;
                cnt++;
            }
        }
        
        int[][] res = new int[cnt][2];
 
        for(int i=0,j=0;i<n;i++){
            if( flag[i] ){
                res[j++] = inputArr[i];
            }
        }
        
        return res;
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
            L[i] = arr[l + i];
        }
           
        for (int j = 0; j < n2; ++j){
            R[j] = arr[m + 1 + j];
        }
  
        int i = 0, j = 0;
  
        int k = l;
        while (i < n1 && j < n2) {
            if (L[i][1] > R[j][1]) {
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



