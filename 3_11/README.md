# Algorithm assignment


5. array inversion
count array inversion
 - Binary Index Tree
 - Merge sort
6. set permutation
submittion 1: WA ?? maybe there are multiple same elements ??

After check : no multiple elements

**find bug :**

my hash function implement as below
```c
int arr[N] , K;
bool stamp[N]; // bool array for select this element or not

int Hash(){
    int val=0;
    for(int i=0;i<K;i++){ // permutation of K element of array in size of N
        if(stap[i]){ // select this element
            val*=10;
            val+=arr[i];
        }
    }
    return val;
}
```
Hash by int : **WA**

because the sum of `Xi*10^i + X(i-1)*10^(i-1) ... +X0` might be same as `X'i*10^i + X'(i-1)*10^(i-1) ... +X'0` , which cause collision


solution:
```c
int arr[N] , K;
bool stamp[N]; // bool array for select this element or not

string Hash(){
    string val=0;
    for(int i=0;i<K;i++){ // permutation of K element of array in size of N
        if(stap[i]){ // select this element
            val+=to_string(arr[i]);
        }
    }
    return val;
}
```
hash by string : **AC**

7. 2D rank finding

Divide & Conquer (**HARD**)
8. merge sort 

9. min heap 

min heapify array & print array in level ordered 


10. Smallest Range Covering Elements from k Lists

sort + sliding window ( from leetcode HARD )