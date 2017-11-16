#include<stdio.h>
int cmp(const void*p, const void*q);

int main(void)
{
    int n, q, k, i;
    int seq[100010]={0};

    while(scanf("%d %d", &n, &q)!=EOF)
    {
        for(i=0;i<n;i++) scanf("%d", &seq[i]);

        qsort(seq, n, sizeof(int), cmp);

        for(i=0;i<q;i++)
        {
            scanf("%d", &k);
            printf("%d\n", seq[k-1]);
        }
    }

    return 0;
}

int cmp(const void*p, const void*q)
{
    int a=*(int*)p, b=*(int*)q;
    if(a!=b)
        return (a<b)?-1:1;
    return 0;
}

/**************************************************

Problem Description
給一個未排序數列，請找到第k小的數字

Input

有多組測資，每組測資第一行有兩個正整數n(n<105)表示這組測資有多少個測資，
以及q(q<105)表示問題數量，接下來有n個整數(int範圍)表示這個數列(數字不會重複出現)，
以及q個正整數ki(0<ki<=n)代表一個詢問

Output
對於每個詢問，輸出該數列第k個小的數

Sample Input
5 3
9 7 5 3 1
1
2
5

Sample Output
1
3
9

**************************************************/
