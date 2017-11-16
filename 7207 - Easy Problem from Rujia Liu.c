#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*p, const void*q);
typedef struct rujia
{
    int num;
    int index;
}RUJIA;

RUJIA numb[1000100];
int firstp[1000100];

int main(void)
{
    int n, m, i, k, v;

    while(scanf("%d %d", &n, &m)!=EOF)
    {
        memset(numb, 0, sizeof(RUJIA));
        memset(firstp, 0, sizeof(int));

        for(i=1;i<=n;i++)
        {
            scanf("%d", &numb[i].num);
            numb[i].index=i;
        }
        numb[0].num=-1;
        numb[0].index=-1;
        qsort(numb, n+1, sizeof(RUJIA), cmp);

        for(i=1;i<=n;i++)
            if(firstp[numb[i].num]==0)
                firstp[numb[i].num]=i;

        for(i=0;i<m;i++)
        {
            scanf("%d %d", &k, &v);
            if(numb[firstp[v]+k-1].num==v)
                printf("%d\n", numb[firstp[v]+k-1].index);
            else
                printf("0\n");
        }
    }

    return 0;
}

int cmp(const void*p, const void*q)
{
    RUJIA a=*(RUJIA*)p, b=*(RUJIA*)q;
    if(a.num!=b.num) return (a.num<b.num)?-1:1;
    else if(a.index!=b.index) return (a.index<b.index)?-1:1;
    return 0;
}

/***********************************************

Problem Description
雖然 Rujia Liu 通常出很難的題目，他偶而也會出一些簡單的題目來鼓勵大家解題。
給你一個陣列，你必需回答在此陣列中某一特定的數值 v 重複出現第 k 次時的位置
(在此陣列中的位置，以1開始)。為了讓問題難一些（並且有趣一些），你必須回答m個這樣的詢問。

Input
輸入會有許多組測試資料，每組資料的第一列有兩個整數n, m (1 <= n, m <= 100,000)，
n 表示陣列的長度，接下會有 n 個小於1,000,000的正整數。再接下來有 m 列，
每列為一組 k v 值(1 <= k <= n, 1<= v <= 1,000,000)，請回答每一組數值 v 出現第 k 次在陣列中的位置。

Output
請依要求輸出序號(以1為第一個)，如果不存在請輸出 0。

Sample Input
8 4
1 3 2 2 4 3 2 1
1 3
2 4
3 2
4 2

Sample Output
2
0
7
0

***********************************************/
