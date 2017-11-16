#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void f(int N);
int have[1010]={0};

typedef struct n
{
    int num[1010];
    int len;
}Num;
Num fibo[1010];

int main(void)
{
    int N, i;
    memset(fibo, 0, sizeof(Num));

    while(scanf("%d", &N)!=EOF && N)
    {
        fibo[1].num[0]=fibo[1].len=fibo[2].num[0]=fibo[2].len=1;
        have[1]=have[2]=1;

        f(N);

        for(i=fibo[N].len-1;i>=0;i--)
            printf("%d", fibo[N].num[i]);
        printf("\n");
    }
    return 0;
}

void f(int N)
{
    int i, carry, len;

    if(have[N]==1)
        return;

    else
    {
        f(N-1);
        f(N-2);
        len=fibo[N-1].len;
        for(i=0;i<len;i++)
            fibo[N].num[i]=fibo[N-1].num[i]+fibo[N-2].num[i];
        for(i=0;i<=len;i++)
        {
            carry=fibo[N].num[i]/10;
            fibo[N].num[i]%=10;
            fibo[N].num[i+1]+=carry;
        }
        if(fibo[N].num[len])
            fibo[N].len=len+1;
        else
            fibo[N].len=len;
        have[N]=1;
    }
}


/*************************************************************

Problem Description
Given a positive integer N, calculate the N'th Fibonacci number.

Input
For each case a line, there is a positive integer N.
( 1 <= N <= 1000 ) When N equals 0, it is the end of file.

Output
For each case a line, print the N'th Fibonacci number.

Sample Input
1
2
3
4
50
0

Sample Output
1
1
2
3
12586269025

***************************************************************/
