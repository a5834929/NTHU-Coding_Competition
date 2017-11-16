#include<stdio.h>

int main(){
    long long int way[6][30001]={{0}};
    int W, i, j, v=0, val[4]={5, 10, 25, 50};

    for(i=0;i<=30000;i++)
        way[1][i]=1;
    for(i=0;i<=5;i++)
        way[i][0]=1;
    for(i=2;i<=5;i++){
        for(j=1;j<=30000;j++){
            if(j-val[v]>=0)
                way[i][j]=way[i-1][j]+way[i][j-val[v]];
            else
                way[i][j]=way[i-1][j];
        }
        v++;
    }
    while(scanf("%d", &W)!=EOF){
        if(way[5][W]==1)
            printf("There is only %lld way to produce %d cents change.\n", way[5][W], W);
        else
            printf("There are %lld ways to produce %d cents change.\n", way[5][W], W);
    }
    return 0;
}

/************************************************************************************

Problem Description
After making a purchase at a large department store, Mel's change was 17 cents.
He received 1 dime, 1 nickel, and 2 pennies.
Later that day, he was shopping at a convenience store.
Again his change was 17 cents. This time he received 2 nickels and 7 pennies.
He began to wonder "How many stores can I shop in and receive 17 cents change
in a different configuration of coins?
After a suitable mental struggle, he decided the answer was 6.
He then challenged you to consider the general problem.

Write a program which will determine the number of different combinations of US coins
(penny: 1c, nickel: 5c, dime: 10c, quarter: 25c, half-dollar: 50c)
which may be used to produce a given amount of money.

Input
The input will consist of a set of numbers between 0 and 30000 inclusive,
one per line in the input file.

Output
The output will consist of the appropriate statement from the selection
below on a single line in the output file for each input value.
The number m is the number your program computes, n is the input value.

There are m ways to produce n cents change.
There is only 1 way to produce n cents change.

Sample Input
17
11
4

Sample Output
There are 6 ways to produce 17 cents change.
There are 4 ways to produce 11 cents change.
There is only 1 way to produce 4 cents change.

**************************************************************************************/
