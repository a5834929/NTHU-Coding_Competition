#include<stdio.h>
long long int dp[12][30002]={{0}};
int main(){
    int val[11]={5, 10, 20, 50, 100, 200,
                 500, 1000, 2000, 5000, 10000};
    int i, j, v, dollar, cent, money;

    v=1;
    for(i=0;i<=30000;i++)
        if(i%5==0)
            dp[1][i]=1;
    for(i=0;i<=11;i++)
        dp[i][0]=1;
    for(i=2;i<=11;i++){
        for(j=1;j<=30000;j++){
            if(j-val[v]>=0)
                dp[i][j]=dp[i][j-val[v]]+dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
        v++;
    }
    while(scanf("%d.%d", &dollar, &cent)!=EOF && !(dollar==0 && cent==0)){
        money=dollar*100+cent;
        printf("%3d.%.2d%17lld\n", dollar, cent, dp[11][money]);
    }
    return 0;
}

/********************************************************************************

Problem Description
New Zealand currency consists of $100, $50, $20, $10, and $5 notes and
$2, $1, 50c, 20c, 10c and 5c coins. Write a program that will determine,
for any given amount, in how many ways that amount may be made up.
Changing the order of listing does not increase the count.
Thus 20c may be made up in 4 ways: 1 x 20c, 2 x 10c, 10c+2 x 5c, and 4 x 5c.

Input
Input will consist of a series of real numbers no greater than $300.00
each on a separate line. Each amount will be valid, that is will be a multiple of 5c.
The file will be terminated by a line containing zero (0.00).

Output
Output will consist of a line for each of the amounts in the input,
each line consisting of the amount of money (with two decimal places
and right justified in a field of width 6), followed by the number of
ways in which that amount may be made up, right justified in a field of width 17.

Sample Input
0.20
2.00
0.00

Sample Output
  0.20                4
  2.00              293

**********************************************************************************/
