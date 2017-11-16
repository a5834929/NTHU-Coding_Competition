#include<stdio.h>

int main(void)
{
    int n, arr[10000]={0};
    int i, flag, temp, count;

    while(scanf("%d", &n)!=EOF)
    {
        for(i=0;i<n;i++) scanf("%d", &arr[i]);
        flag=1;
        count=0;

        while(flag)
        {
            flag=0;
            for(i=1;i<n;i+=2)
            {
                if(arr[i-1]>arr[i])
                {
                    temp=arr[i];
                    arr[i]=arr[i-1];
                    arr[i-1]=temp;
                    flag=1;
                }
            }
            if(flag) count++;

            flag=0;

            for(i=1;i<n-1;i+=2)
            {
                if(arr[i]>arr[i+1])
                {
                    temp=arr[i];
                    arr[i]=arr[i+1];
                    arr[i+1]=temp;
                    flag=1;
                }
            }
            if(flag) count++;
        }

        printf("%d\n", count);

    }

    return 0;
}

/******************************************************

Problem Description
奇偶易位排序法(Odd-Even Transposition Sort)是一種用於平行程式的排序方法。
做法是重複以下兩個動作：
1. 奇數位置與左手邊比較(a[0]&a[1],a[2]&a[3],…)，如果左邊較大則交換
2. 奇數位置與右手邊比較(a[1]&a[2],a[3]&a[4],…)，如果左邊較大則交換
動作1 與動作2 都是平行處理，平行處理即是每⼀對要比較的數對則分配1 顆
CPU 來檢查關係。所以，這n/2個數對可以用n/2個CPU在O(1)時間內同時完成。
所以我們可以分析最差的情況是：從最左邊的數字需要換到最右邊的位置(或最
右邊換到最左邊)。因為他每次只能換相鄰的兩數，所以需要做n-1 次，綜合起
來它的時間複雜度就是 O(1)*O(n) = O(n)
現在給你⼀些數列，請算算看需要做幾次兩兩交換(動作)才可以完成排序。
◎同1次動作不論交換幾次都算1次，但是如果沒交換要算零次

Input
多組測資，每組測資有1行，第1個數字n(n<1000)是數字的數量，接下來會有
n 個整數(整數絕對值<=10000)表示這個數列。

Output
對於每組測資，輸出Odd-Even Transposition Sort 要兩兩交換的次數

Sample Input
3 1 2 3
3 3 2 1
4 2 4 1 1

Sample Output
0
3
3

Hint
交換次數的算法: 2411
1. (24)(11) -> (24)(11) 沒交換
2. 2(41)1->2(14)1 換一次
3. (21)(41) -> (12)(14) 換⼀次
4. 1(21)4->1(12)4 換一次
所以總共要換3 次

*****************************************************/
