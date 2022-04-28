
public abstract class Buy_Phone{
	public abstract int[][] bestPhone(int[][] inputArr);
}

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
/*
Assignment Requirement:
 
Your program will take a two-dimensional integer array as input.
Each element represents a smartphone model which contains two features (e.g., screen size and performance ranking).
Please return an array containing a list of unbeatable smartphone models (In other words, filter out the phone models that can be beat by some model).
Given two items A =(Xa, Ya) and B =(Xb, Yb), Item A beats Item B iff xa≥xb and ya≥yb
 
 
[[1,1],[2,4],[2,10],[5,4],[4,8],[5,5],[8,4],[10,2],[10,1]]
Input:
 
Output: [[2,10],[4,8],[5,5],[8,4],[10,2]]

[[1,1],[2,4],[2,10],[5,4],[4,8],[5,5],[8,4],[10,2],[10,1],[100,100]]
Input:
 
Output: [[100,100]]
*/