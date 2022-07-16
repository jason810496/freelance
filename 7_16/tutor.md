# 7/16 C++ 


### Topic 

**前綴合**

**差分數列**

**排序 ( Review )**

**APCS 2021/11/3 生產線**

**二分搜 ( Review + Advance )**


### 前綴合

- **Naive**


有一個長度為 `N` 的序列 ， 接著有 `Q` 筆詢問 ， 每一筆詢問都有 `L` , `R` 兩個數值 。
對於每個詢問輸出序列 `[L,R]` 的和

```
1<= N <= 10^6
1<= Q <= 10^6
```

**Input** :

第 1 行輸入 `N` `Q`

第 2 行有 `N` 筆輸入代表序列

接著有 `Q` 行，每行輸入 `L` , `R` 

```
5 3
1 2 3 4 5
1 2
1 5
3 4
```

**Output**:

```
3
15
7
```

**What is prefix sum ？** 

- **Definition**

`prefix[i]` = sum of `arr[0]` to `arr[i]` 


Eg : 

```
	array:		1 4 8  2  9  10 3 

prefix sum : 	1 5 13 15 24 34 37
```

( i > 0 )

`prefix[i]` = `prefix[ i-1 ]` + `arr[i]`


- **Feature**

( i < j )

prefix[i] = sum of [start , i ] 

prefix[j] = sum of [start , j ]


sum of [ i ,j ] = prefix[j] - prefix[i-1]


visualization : 

```c
array:          --------i---------j-------------

prefix[i]:      --------i

prefix[j]:      --------i---------j

prefix[i-1]:    --------

prefix[j]-prefix[i-1]:  i---------j
```

- **Rule**

`sum of [L,R] = prefix[R] - prefix[L-1]`

- **Exercise**

[區間和](https://zerojudge.tw/ShowProblem?problemid=e346)


### 差分數列 

[2019 TOI新手同好會 站牌廣告](https://zerojudge.tw/ShowProblem?problemid=e796) : e796

[2019 TOI新手同好會 幽靈寶藏](https://zerojudge.tw/ShowProblem?problemid=e841) : e841

**What is difference ？**

- **Definition:**

( i>0 )

`diff[i]` = `arr[i]` - `arr[i-1]` 



Eg : 

```
	array:		1 4 8  2  9  10 3 

difference : 	1 3 4 -6  7  1  -7 

array2:		    1 7 11 5  12  13 6

difference2 : 	1 6 4 -6  7  1  -7 
                            -span  
line : [ L , R ]                
span = 3                       
idx :             L       R (R+1)
```


- **prefix sum + diference :**


### 排序

- review

- greater

- compare function 

- marco trick 
( define ... )

### APCS 歷屆 

**2021/11/3 生產線**

[https://zerojudge.tw/ShowProblem?problemid=g597]

### 二分搜


[Review Binary Search](https://zerojudge.tw/ShowProblem?problemid=f679)


- algorithm header file

    - upper_bound

    - lower_bound 

    - binary_search 

- our own binary search



### 練習題 

[2019 TOI新手同好會 幽靈寶藏](https://zerojudge.tw/ShowProblem?problemid=e841)

[2021/04 TOI練習賽 遊戲升等 ](https://zerojudge.tw/ShowProblem?problemid=f815)

[2021/04 TOI練習賽 Youtube頻道 ](https://zerojudge.tw/ShowProblem?problemid=f816)


2022	6	3	雷射測試	Link	二分搜、模擬
2022	6	4	內積	Link	DP
2021	11	2	動線安排	Link	模擬、陣列
2021	11	3	生產線	Link	陣列、排序、差分
2021	11	4	真假子圖	Link	DFS、二分搜


