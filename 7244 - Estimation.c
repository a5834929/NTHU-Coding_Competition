#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
long long int cal(int n);

int have[100500]={0};
long long int num[100500]={0};

int main(void)
{
    long long int n;
    have[1]=1;
    num[1]=1;

    while(scanf("%lld", &n)!=EOF)
    {
        printf("%lld\n", cal(n));
    }

    return 0;
}

long long int cal(int n)
{
    long long int min;
    int i;

    if(have[n]==1)
        return num[n];

    else if(n>=2 && n<=13)
    {
        num[n]=cal(n-1)*(4*n-2)/(n+1);
        have[n]=1;
        return num[n];
    }

    else if(n>13)
    {
        for(i=1;i<=10;i++)
        {
            if(i==1)
                min=((i*cal(n-i)%1573921)*(cal(n+i-11)%1573921))%1573921;
            else
                if(((i*cal(n-i)%1573921)*(cal(n+i-11)%1573921))%1573921<min)
                    min=((i*cal(n-i)%1573921)*(cal(n+i-11)%1573921))%1573921;
        }
        num[n]=min;
        have[n]=1;
        return num[n];
    }

    else
        return 0;
}

/**************************************************

Problem Description
f(n) = min{ k*f(n-k)*f(n-(10-k+1))%1573921 }, if n>13
f(n) = f(n-1)*(4n-2)/(n+1), if 2<=n<=13
f(n) = 1, if n=1
f(n) = 0, otherwise

Input
輸入有多組測資。
每組測資為一個非負整數N（N<=50000）

Output
輸出f(n)

Sample Input
1
2
3
4
5

Sample Output
1
2
5
14
42

**************************************************/
