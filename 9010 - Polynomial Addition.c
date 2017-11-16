#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long int poly1[1010], poly2[1010];

int main(void)
{
    int t, n, m, i, len;

    scanf("%d", &t);
    while(t--)
    {
        memset(poly1, 0, sizeof(poly1));
        memset(poly2, 0, sizeof(poly2));

        scanf("%d %d", &n, &m);
        len=(m>n)?m:n;
        for(i=n;i>=0;i--)
            scanf("%lld", &poly1[i]);
        for(i=m;i>=0;i--)
            scanf("%lld", &poly2[i]);
        for(i=len;i>=0;i--)
        {
            printf("%lld", poly1[i]+poly2[i]);
            if(i)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}

/**********************************************************************

Problem Description
Given two polynomials
please calculate the result of adding these two polynomials.

Input
The first line contains an integer t (1 <= t <= 20),
which indicates the number of test cases in the input.
For each case, the first line contains two integers n, m(n, m <= 1000).
Integer n means the highest power of the first polynomial.
Integer m means the highest power of the second polynomial.
In the next 2 lines, the first line contains n+1 integers,
which means the coefficients of the polynomial A from high to low.
The second line contains m+1 integers, which means the coefficients
of the polynomial B from high to low. All coefficients are less or equal than 105.

Output
For each case, output a line with the coefficients of the polynomial A+B.
There is a space between two consecutive numbers.

Sample Input
2
2 3
3 2 1
4 3 2 1
2 2
3 2 1
1 2 3

Sample Output
4 6 4 2
4 4 4

***********************************************************************/
