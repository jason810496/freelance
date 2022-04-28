
public abstract class Buy_Phone{
	public abstract int[][] bestPhone(int[][] inputArr);
}

public  class HW07_8110056004_1 extends Buy_Phone{
	public int[][] bestPhone(int[][] inputArr){ 
   	
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