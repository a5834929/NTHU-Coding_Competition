#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*p, const void*q);

typedef struct ppl
{
    int num;
    int order;
    char ID[100];
}STU;

STU list[100100];

int main(void)
{
    int N, i;

    while(scanf("%d", &N)!=EOF)
    {
        memset(list, 0, sizeof(STU));
        for(i=0;i<N;i++)
        {
            scanf("%s", list[i].ID);
            scanf("%d", &list[i].num);
            list[i].order=i;
        }

        qsort(list, N, sizeof(STU), cmp);

        for(i=0;i<N;i++)
        {
            printf("%s %d\n", list[i].ID, list[i].num);
        }
    }

    return 0;
}

int cmp(const void*p, const void*q)
{
    STU a=*(STU*)p, b=*(STU*)q;
    if(a.num!=b.num) return (a.num<b.num)?-1:1;
    else if(a.order!=b.order) return (a.order<b.order)?-1:1;
    return 0;
}

/*************************************************

Problem Description
Given the grades of N people.
Please output the sorted result. (Increasing order)
Input
The input includes multiple test cases. In each test case,
the first line contains one integer N. The following N lines
specify the name Si and the grade Gi.

1 <= N <= 105

1 <= |Si| <= 10

0 <= Gi <= 100 (Gi is an integer.)

Output
Output the result in N lines. Every line contains
the name and the grade. If more people¡¦s grades are same,
output by input order. (That means it uses stable sort.)

Sample Input
4

John 99

Steven 100

Stan 75

Howard 99

Sample Output
Stan 75

John 99

Howard 99

Steven 100

**************************************************/
