#include<stdio.h>
long long int comb(int n, int m);

int main(void)
{
    int n, m;
    long long int ans;

    while(EOF!=scanf("%d %d", &n, &m))
    {
        ans=comb(n, m);
        printf("%lld\n", ans);
    }

    return 0;
}

long long int comb(int n, int m)
{
    int i, j;
    long long int fac;

    if(m>n/2) m=n-m;
    for(fac=1,i=n,j=1;i>=n-m+1;i--,j++)
    {
        fac*=i;
        fac/=j;
    }

    return fac;
}

/*************************************************

Problem Description
我們可以把(x + 1)^n展開，像是(x + 1)^2可以展開成x^2+ 2x + 1
然後從最前面(次方項最大的)到後面我們把他們從第0 項到第n 項去編號
現在的問題是，給你正整數n 與k，請你把(x + 1)^n展開，求出第k 項的係數
例如: n=2,k=0，答案就是x2的係數1

Input
輸入有多組，每組一行，每行有兩個數字n ,k (1 ≤ n ≤ 50, 0 ≤ k ≤ n)

Output
對於每組問題請輸出他的答案

Sample Input
3 3
4 0
4 1
5 4

Sample Output
1
1
4
5

*************************************************/
