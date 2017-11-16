#include<stdio.h>
long long int seq[100010]={0};

int main(void)
{
    int t, n, q, i, a, b, x;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d", &n);
        seq[0]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d", &x);
            seq[i]=seq[i-1]+x;
        }

        scanf("%d", &q);
        while(q--)
        {
            scanf("%d %d", &a, &b);
            printf("%lld\n", seq[b]-seq[a-1]);
        }
    }

    return 0;
}

/*****************************************

Problem Description
Given n integers and q queries, in which each query defines a range,
find the sum of the n given integers within the range.

Input
The first line contains an integer t (1 <= t <= 20), which indicates
the number of test cases. In each test case, the first line contains
an integer n (n <= 105), specifying how many integers will be given.
The next line contains n integers, in which the ith integer represents
as (-231 <= ai <= 231-1). The followed line contains a positive integer
q (q <= 105), denoting the number of queries. Next q lines define q queries,
one per line. Each query is specified by two integers a and b (1 <= a <= b <= n),
meaning a range, in which the partial sum of the given integers are queried.

Output
For each query, output a line with the partial sum of the given integers within the queried range.

Sample Input
2
5
3 2 1 4 5
3
1 3
2 4
1 4
2
-1 1
2
1 2
1 1

Sample Output
6
7
10
0
-1

*****************************************/
