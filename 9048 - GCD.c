#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    int n, a, b;

    while(scanf("%d", &n)!=EOF)
    {
        while(n--)
        {
            scanf("%d %d", &a, &b);
            while((a%=b) && (b%=a));
            printf("%d\n", a+b);
        }
    }
    return 0;
}

/**********************************************************

Problem Description
Given two positive integers a and b, compute the
greatest common divisor (GCD) of a and b.
The GCD of a and b is the biggest integer that can
divide a and b with no reminder.

Input
First line contains a positive integer t (t<=1000),
which indicates the number of test cases in the input.
In the next t lines, each line contains two positive
integers a, b, which are smaller than or equal to 106.

Output
For each case, output the GCD of a and b in a line.

Sample Input
3
2 4
6 9
10 15

Sample Output
2
3
5

**********************************************************/
