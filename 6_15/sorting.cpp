#include<bits/stdc++.h>
using namespace std;

/*******************************************************************
    sorting 比較

    以下是 Radix Sort ( 基數排序 ) 跟 Merge Sort ( 合併台序 ) 的比較

                        Radix Sort  |   Merge Sort
    time complexity     O(logb(k)*(n+b))  |   O(nlog2n)
    space complexity    O(n)        |   O(n)

    其中 Radix Sort 時間複雜度的
    k : max value in array 
    b : 10 ( 因為資料是10進位 )


    因為 Radix sort 與資料範圍有關
    所以在main中分別以 3 種資料範圍做比較
    1. 32bits 整數int
    2. 資料介於 [0,1e4-1]
    3. 資料介於 [0,1e2-1]

*******************************************************************/

/*******************************************************************

    測試結果：
        可以看到 Merge Sort 不因為資料範圍的改變而有大變化，都是在0.2秒左右
        （ 雖然從數據上來看：資料範圍小時排序也比較快一些，不過這是因為資料數值小，所以計算時的常數會比較小的關係 ）

        而 Radix sort 則與資料範圍有很大的變化
        1. 32bits 整數int          約 0.39 sec
        2. 資料介於 [0,1e4-1]       約 0.12 sec
        3. 資料介於 [0,1e2-1]       約 0.06 sec

    比較結果：
        Merge Sort 還是較穩定的排序法，與資料大小有關，不受數值所影響
        是較穩定的排序法

        而 radix sort 適用於「 資料數值較小」的情況，在適合的情況會比 Merge Sort 效率更號

*******************************************************************/

// 資料數量 : 1e6 
const int MAX_N  = 1e6;

// 預先開好陣列
int data[MAX_N] , arr[MAX_N] , dump[MAX_N];

//每次取得隨機資料 ( 32bits 整數int )
void RandomData(){
    for(int i=0;i<MAX_N;i++){
        data[i] = rand();
    }
}

//每次取得隨機資料 ( [ 0 , MOD-1 ] )
void Range_RandomData(int MOD){
    for(int i=0;i<MAX_N;i++){
        data[i] = rand()%MOD;
    }
}

// 把隨機資料複製到需要sort的陣列上
void Init(){
    for(int i=0;i<MAX_N;i++){
        arr[i] = data[i];
    }
}

/***********************************
    
        合併排序的class

**********************************/
class MergeSort{
    private:
        void Merge(int l,int m,int r){
            int i=l,j=m+1,k=l;
            while( i<= m && j<= r){
                if(arr[i]<= arr[j]){
                    dump[k++]=arr[i++];
                }
                else{
                    dump[k++]=arr[j++];
                }
            }

            while( i<=m ){
                dump[k++] = arr[i++];
            }

            while( j<=r ){
                dump[k++]  = arr[j++];
            }

            for(int i=l;i<=r;i++){
                arr[i]=dump[i];
            }
        }

        void Divide(int l,int r){
            if( l>=r ) return ; 

            int m = (l+r)/2;
            Divide(l,m);
            Divide(m+1,r);
            Merge(l,m,r);
        }

    public:
        float Sort(){
            clock_t t1 , t2;

            t1 = clock();

            Divide(0,MAX_N-1);

            t2 = clock();

            float t = (float)(t2-t1)/CLOCKS_PER_SEC;

            return t;
        }
};

/***********************************
    
        基數排序的class

**********************************/
class RadixSort{
    private:
        int GetMax(){
            int mx = arr[0];
            for(int i=0;i<MAX_N;i++){
                mx = max( mx , arr[i] );
            }
            return mx;
        }
        void CountingSort(int base){
            int cnt[10]={};

            for(int i=0;i<MAX_N;i++){
                cnt[ (arr[i]/base)%10 ]++;
            }

            for(int i=1;i<10;i++){
                cnt[i]+=cnt[i-1];
            }

            for(int i=MAX_N-1 ; i>=0 ;i--){
                dump[ cnt[ (arr[i]/base)%10 ] -1 ] = arr[i];
                cnt[ (arr[i]/base)%10 ]--;
            }

            for(int i=0;i<MAX_N;i++){
                arr[i] = dump[i];
            }
        }
    public:
        float Sort(){
            clock_t t1 , t2;

            t1 = clock();

            int mx = GetMax();

            for(int base=1 ; mx/base > 0 ; base*=10 ){
                CountingSort(base);
            }

            t2 = clock();

            float t = (float)(t2-t1)/CLOCKS_PER_SEC;

            return t;
        }

};

int main(){
    srand(time(NULL));

    // variable that store sorting time 
    float avg_radix=0 , avg_merge=0 , t_radix , t_merge;

    RadixSort Radix_Sort_Class;
    MergeSort Merge_Sort_Class;

    cout<<setprecision(3);

    /***********************************
    
        資料範圍 ： 32bits 整數 int

    ***********************************/
    cout<<"===   Data in range 32bits INT  ===\n";
    cout<<"Radix Sort\t|\tMerge Sort\n";
    cout<<"-----------------------------------\n";

    for(int k=0;k<10;k++){
        // get random data every time
        RandomData();
        // reset array
        Init();
        t_radix = Radix_Sort_Class.Sort();
        // reset array
        Init();
        t_merge = Merge_Sort_Class.Sort();

        cout<<fixed<<t_radix<<" sec"<<"\t|\t"<<t_merge<<" sec\n";

        avg_radix+=t_radix;
        avg_merge+=t_merge;
    }

    cout<<"---------    avg time    ----------\n";
    cout<<(avg_radix/10.0)<<" sec\t|\t"<<(avg_merge/10.0)<<" sec\n";



    /***********************************
    
        資料範圍 ： [ 0 , 1e4-1 ]

    ***********************************/

    // reset avg counter
    avg_radix=0 , avg_merge=0;
    cout<<"\n\n";
    cout<<"===   Data in range [0,10000-1]   ===\n";
    cout<<"Radix Sort\t|\tMerge Sort\n";
    cout<<"-----------------------------------\n";

    for(int k=0;k<10;k++){
        // get random data every time
        Range_RandomData(10000);
        // reset array
        Init();
        t_radix = Radix_Sort_Class.Sort();
        // reset array
        Init();
        t_merge = Merge_Sort_Class.Sort();

        cout<<fixed<<t_radix<<" sec"<<"\t|\t"<<t_merge<<" sec\n";

        avg_radix+=t_radix;
        avg_merge+=t_merge;
    }

    cout<<"---------    avg time    ----------\n";
    cout<<(avg_radix/10.0)<<" sec\t|\t"<<(avg_merge/10.0)<<" sec\n";

    
    /***********************************
    
        資料範圍 ： [ 0 , 1e2-1 ]

    ***********************************/

    // reset avg counter
    avg_radix=0 , avg_merge=0;
    cout<<"\n\n";
    cout<<"====   Data in range [0,100]   ====\n";
    cout<<"Radix Sort\t|\tMerge Sort\n";
    cout<<"-----------------------------------\n";

    for(int k=0;k<10;k++){
        // get random data every time
        Range_RandomData(100);
        // reset array
        Init();
        t_radix = Radix_Sort_Class.Sort();
        // reset array
        Init();
        t_merge = Merge_Sort_Class.Sort();

        cout<<fixed<<t_radix<<" sec"<<"\t|\t"<<t_merge<<" sec\n";

        avg_radix+=t_radix;
        avg_merge+=t_merge;
    }

    cout<<"---------    avg time    ----------\n";
    cout<<(avg_radix/10.0)<<" sec\t|\t"<<(avg_merge/10.0)<<" sec\n";

    return 0;
}