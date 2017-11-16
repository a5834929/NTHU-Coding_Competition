#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*p, const void*q);
int dp[101][25001];
int main(){
    int T, N, i, j, sum, max;
    int val[101];

    scanf("%d", &T);
    while(T--){
        sum=0;
        max=0;
        memset(dp, 0, sizeof(dp));
        memset(val, 0, sizeof(val));
        scanf("%d", &N);
        for(i=1;i<=N;i++){
            scanf("%d", &val[i]);
            sum+=val[i];
        }
        for(i=0;i<=N;i++)
            dp[i][0]=1;
        qsort(&val[1], N, sizeof(int), cmp);
        dp[1][val[1]]=1;
        for(i=2;i<=N;i++){
            for(j=1;j<=sum/2;j++){
                if(j-val[i]>=0)
                    dp[i][j]=((dp[i-1][j-val[i]]) | (dp[i-1][j]));
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        for(i=sum/2;i>=1;i--)
            if(dp[N][i]){
                max=i;
                break;
            }
        printf("%d\n", sum-2*max);
    }
    return 0;
}

int cmp(const void*p, const void*q){
    int a=*(int*)p, b=*(int*)q;
    if(a!=b) return (a<b)?-1:1;
    return 0;
}

/***********************************************************************************

Problem Description
It's commonly known that the Dutch have invented copper-wire.
Two Dutch men were fighting over a nickel, which was made of copper.
They were both so eager to get it and the fighting was so fierce,
they stretched the coin to great length and thus created copper-wire.

Not commonly known is that the fighting started, after the two Dutch
tried to divide a bag with coins between the two of them.
The contents of the bag appeared not to be equally divisible.
The Dutch of the past couldn't stand the fact that a division should
favour one of them and they always wanted a fair share to the very last cent.
Nowadays fighting over a single cent will not be seen anymore,
but being capable of making an equal division as fair as possible is something
that will remain important forever...

That's what this whole problem is about. Not everyone is capable of seeing
instantly what's the most fair division of a bag of coins between two persons.
Your help is asked to solve this problem.

Given a bag with a maximum of 100 coins, determine the most fair division
between two persons.
This means that the difference between the amount each person obtains
should be minimised. The value of a coin varies from 1 cent to 500 cents.
It's not allowed to split a single coin.

Input
A line with the number of problems n, followed by n times:

a line with a non negative integer m (m<=100) indicating the number of coins in the bag
a line with m numbers separated by one space, each number indicates the value of a coin.

Output
The output consists of n lines.
Each line contains the minimal positive difference between the amount
the two persons obtain when they divide the coins from the corresponding bag.

Sample Input
2
3
2 3 5
4
1 2 4 6

Sample Output
0
1

*************************************************************************************/
