#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int seq[1000001];

int main(void)
{
    int n, q, i, tar, flag;
    int left, right, mid;

    scanf("%d", &n);
    while(1)
    {
        memset(seq, 0, sizeof(seq));

        for(i=0;i<n;i++)
            scanf("%d", &seq[i]);

        scanf("%d", &q);

        while(q--)
        {
            scanf("%d", &tar);
            left=0;
            right=n-1;
            flag=0;
            while(left<=right)
            {
                mid=(left+right)/2;
                if(seq[mid]==tar)
                {
                    flag=1;
                    break;
                }
                else if(seq[mid]>tar)
                    right=mid-1;
                else if(seq[mid]<tar)
                    left=mid+1;
            }
            if(flag)
                printf("Yes\n");
            else
                printf("No\n");
        }
        if(scanf("%d", &n)!=EOF && n)
            printf("\n");
        else
            break;
    }
    return 0;
}

/***********************************************

Problem Description
Given a sorted integer sequence in the ascending order
and some queries, determine whether each queried number
is in the sequence or not.

Input
There are multiple test cases.  Each case begins with
an integer N (1 <= N <= 10^6) in a line.
The second line contains N integers, separated by a space.
The third line contains an integer Q (1 <= Q <= 10^6)
representing the number of the queries.
In the next Q lines, each line contains an integer,
representing a query.
The input is terminated if N = 0.

Output
For each query, print ¡§Yes¡¨ (without quotes) if the
queried integer is in the given sequence and print ¡§No¡¨
(without quotes) otherwise.  Print a blank line after each test case.

Sample Input
3
11 23 43
2
11
22
4
100 200 300 400
1
300
0

Sample Output
Yes
No

Yes

***********************************************/
