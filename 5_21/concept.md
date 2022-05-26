# 線段樹Segment Tree


## 運用
主要解決**RMQ**問題

**RMQ** :  Range Maximum/Minimum Query

題目多次查詢區間 `[ L , R ]`的資訊

可以運用的場合

**區間和**

**區間最大**

**區間最小**

**區間XOR**

**區間GCD**

## 概念

### 架構

### 空間複雜度

### 時間複雜度

因為每次都切 2 塊 ， 直到區塊大小為 1 ， 所以會有 logN 層

而因為最多遞迴 logN 層查詢 ， 每次查詢或修改的時間複雜度都是 logN
## 實做

### 細節
有很多版本的線段樹，寫法因人而異

像是除了陣列版本還有指標版本的線段樹（ 應該說最早的線段樹是用指標來實做，但是因為方便可以使用陣列的方式去代 new &
delete 的操作，但是因為線段樹是既有的資料結構，所以以偽線段樹稱之。雖然大家已將兩個東西混為一談了，只會說「指標版本」或「陣列版本」的線段樹）

還有 0-based index 或 1-based index 

兩個者個差別是：

0-based index 的 left-child-index 會是： i*2+1

0-based index 的 right-child-index 會是： i*2+2

1-based index 的 left-child-index 會是： i*2

1-based index 的 right-child-index 會是： i*2+1

查詢範圍也分成：

左閉右閉： [L,R]

左閉右開： [L,R)

都跟二分搜一樣，大家寫法不盡相同，細節有注意到就好

### 建構 Build


### 查詢 Query 


### 單點修改 Update

### 區間查詢？

因為區間查詢又牽扯到 Lazy Tag ， 難度會指數上升，所以先暫且不提

## 其他

這邊實做的是單點修改的陣列版本

另外可以使用指標實做還有區間修改、動態開點、高維線段樹等版本（ 但因為較複雜，這邊不進行介紹

## 例題

[ZJ d539 RMQ 練習]()

[區間 XOR + 單點修改]()



### Referece

（ Baltic OI 2001: Mars Maps  ）
https://www.oi.edu.pl/static/attachment/20110713/boi-2001.pdf

https://web.ntnu.edu.tw/~algo/Sequence2.html#3

https://cp.wiwiho.me/segment-tree/

https://yuihuang.com/segment-tree/

https://oi-wiki.org/topic/rmq/

https://oi-wiki.org/ds/seg/