# 編譯器原理

## 建構流程

1. 詞法分析器

2. 語法分析器
將詞法分析得到的token 生成一棵語法樹

3. 目標代碼生成
將語法樹轉化為目標代碼

## 編譯器框架
1. `next()` 用於語法分析

2. `program()` 語法分析的入口，分析整個 C 語言程式

3. `expression( level )` 用於解析一個表達式

4. `eval()` 虛擬機的入口，用於解釋代碼

## main 讀取命令參數
```c
#include <stdio.h>
int main(int argc, char *argv[]) {
  printf("We have %d arguments:\n", argc);
  for (int i = 0; i < argc; ++i) {
    printf("[%d] %s\n", i, argv[i]);
  }
  return 0;
}
```
`argc`

`argv`
