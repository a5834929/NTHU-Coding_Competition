#include<stdio.h>
double comb(int n, int m);

int main(void)
{
    int n, m;
    double ans;

    while(EOF!=scanf("%d %d", &n, &m) && n!=0 && m!=0)
    {
        ans=comb(n, m);
        printf("%d things taken %d at a time is %.0lf exactly.\n", n, m, ans);
    }

    return 0;
}

double comb(int n, int m)
{
    int i, j;
    double fac=1;

    if(m>n/2) m=n-m;
    for(fac=1,i=n,j=1;i>=n-m+1;i--,j++)
    {
        fac*=i;
        fac/=j;
    }

    return fac;
}

/**********************************************

Problem Description
為了呼應台灣電腦彩券的發行，我們特別推出跟組合有關的題目。
以台灣的彩券來說，從46個球中取出6個，共有C(46,6)=9366819種組合。
（中特獎的機率：1/936681989，夠低了吧！）給你：

5 <= N <=100, and 5 <= M <=100, and M <= N

我們可以根據下面的公示算出從N個東西中取出M個東西的組合數：

你可以假設你的答案C不會超出 long int 的範圍。

Input
每筆測試資料一行，有2個正整數 N,M。 N=0，M=0代表輸入結束。

Output
以下列的格式輸出：

N things taken M at a time is C exactly.

請參考Sample Output。

Sample Input
100 6
20 5
18 6
0 0

Sample Output
100 things taken 6 at a time is 1192052400 exactly.
20 things taken 5 at a time is 15504 exactly.
18 things taken 6 at a time is 18564 exactly.

***********************************************/
