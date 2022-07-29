( line N ) -> 拉到可以看到第 N 行的位子

（ line 5 )
第一個函式 FindMax() 是 for 迴圈的版本 
並且有 2 個參數 ， 第一個是 data 陣列 ， 第二個是 data 陣列的大小

而 index 變數代表最大值的索引值，一開始初始為 0 
而 value 則存當前的最大值，初始為 data[0] 

接著從 i=1 開始遍歷陣列 ， 遇到比 value 大的 data 就更新 value 和 index 


（ line 19 )
FindRecursionMax() 是遞迴版本，有 5 個參數 
第 1 個是 data 陣列
第 2 個是 N 代表陣列大小 
第 3 個是 current 代表當前的索引值
第 4 個是 index變數的 pointer
第 5 個是 value變數的 pointer 

每次的遞迴 current 都加一代表遍歷到下一個  index 
如果 current 的數字大於 value 所存的數字就更新 value 和 index ， 又因為 value 和 index 是 pointer 型態所以 main 函式的 idx 變數和 val 變數也會一同更動到
( line 44 ) 



