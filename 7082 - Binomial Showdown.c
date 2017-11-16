#include<stdio.h>
int comb(int n, int m);

int main(void)
{
    int n, m;
    double ans;

    while(EOF!=scanf("%d %d", &n, &m))
    {
        if(n==0 && m==0) break;
        ans=comb(n, m);
        printf("%.0lf\n", ans);
    }

    return 0;
}

int comb(int n, int m)
{
    int i, j;
    double fac;

    if(m>n/2) m=n-m;
    for(fac=1,i=n,j=1;i>=n-m+1;i--,j++)
    {
        fac*=i;
        fac/=j;
    }

    return fac;
}

/************************************************

Problem Description
從N個東西中取出M個東西的方法數（不管排列的順序）是：

請你寫一個程式算出C。你可以假設你的答案C不會超出 int 的範圍，也就是一定小於2^31。

Input
每組測試資料一列，有2個正整數 N,M（N >= 1, 0 <= M <= N）。

N=0，M=0代表輸入結束。

Output
輸出C

Sample Input
4 2
10 5
49 6
0 0

Sample Output
6
252
13983816

***********************************************/


