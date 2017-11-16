#include<stdio.h>
#include<stdlib.h>
int cmp(const void*p, const void*q);
int str[1000000]={0};

int main(void)
{
    int N, i;
    double med;

    while(scanf("%d", &N)!=EOF && N!=0)
    {
        for(i=0;i<N;i++) scanf("%d", &str[i]);

        qsort(str, N, sizeof(int), cmp);

        if(N%2) med=str[N/2];
        else med=(double)(str[N/2]+str[N/2-1])/2;

        printf("%.1lf\n", med);

        for(i=0;i<N;i++) str[i]=0;
    }

    return 0;
}

int cmp(const void*p, const void*q)
{
    int a=*(int*)p, b=*(int*)q;
    if(a!=b) return (a<b)?-1:1;
    return 0;
}

/*****************************************

Problem Description
The median of an integer sequence can be found by
arranging all the integers from the smallest to the
largest and picking the middle one. If the number of
integers is even, the median is defined to be the mean
of the two middle integers.  Given an integer sequence,
output the median of the sequence.

Input
There are multiple test cases.  Each case begins with an
integer N (1 <= N <= 106) in a line.  The next line has N
integers are in the next line, separated by spaces.
The input is terminated if N = 0.

Output
For each test case, print a number represent the median of the sequence.

Sample Input
5
1 2 3 4 5
4
1 2 3 4
0

Sample Output
3.0
2.5

*****************************************/
