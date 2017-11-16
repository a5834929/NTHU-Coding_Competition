#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long int comb(int n);

int main(void)
{
    int N;
    while(scanf("%d", &N)!=EOF && N)
    {
        printf("%lld\n", comb(N)%10000);
    }

    return 0;
}

long long int comb(int n)
{
    int i, j;
    long long int fac;

    if(n==1)
        return 0;
    else
    {
        for(fac=1,i=n,j=1;i>=n-2+1;i--,j++)
        {
            fac*=i;
            fac/=j;
        }

        return fac;
    }
}

/****************************************************************

Problem Description
There are N straight lines in a 3D coordinate.
Your job is to find the maximum number of intersections for N straight lines.

Input
The input contains multiple cases.
In each test case, there is an integer N which indicates the number of straight lines.
( 0 < N < 1000000 ) When N is equal to 0, it is the end of the input file.

Output
Print the result mod 10000 in a newline.

Sample Input
1
2
3
0

Sample Output
0
1
3

*****************************************************************/
