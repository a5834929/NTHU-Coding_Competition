#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*p, const void*q);

typedef struct L
{
    int start, end;
    int len, order;
}l;

l Palin[11100];

int main(void)
{
    char str[1010];
    int i, j, k, n, len;

    while(scanf("%s", str)!=EOF)
    {
        memset(Palin, 0, sizeof(l));
        len=strlen(str);

        n=0;
        for(i=0;i<len;i++)
        {
            for(j=i, k=i;j<len && k>=0;j++, k--)
            {
                if(str[j]==str[k])
                {
                    Palin[n].start=k;
                    Palin[n].end=j;
                    Palin[n].len=j-k+1;
                    Palin[n].order=n;
                }
                else
                    break;
            }
            n++;
        }

        for(i=0;i<len;i++)
        {
            for(j=i+1, k=i;j<len && k>=0;j++, k--)
            {
                if(str[j]==str[k])
                {
                    Palin[n].start=k;
                    Palin[n].end=j;
                    Palin[n].len=j-k+1;
                    Palin[n].order=n;
                }
                else
                    break;
            }
            n++;
        }

        qsort(Palin, n, sizeof(l), cmp);

        for(i=Palin[0].start;i<=Palin[0].end;i++)
            printf("%c", str[i]);

        for(i=0;i<n;i++)
        {
            Palin[i].start=0;
            Palin[i].end=0;
            Palin[i].len=0;
        }

        printf("\n");
    }

    return 0;
}

int cmp(const void*p, const void*q)
{
    l a=*(l*)p, b=*(l*)q;
    if(a.len!=b.len) return (a.len>b.len)?-1:1;
    else if(a.order!=b.order) return (a.order<b.order)?-1:1;
    return 0;
}

/********************************************************

Problem Description
Palindrome is a string that is identical to its reverse,
like "level" or "aba". Given a string, find the longest
palindrome in the string.

Input
The input consists of multiple lines.
Each line contains a string.
The length of each string is less than 1000.

Output
In each test case, output the longest palindrome in the string.
If there are many palindromes of the same length,
output the first one in the string.

Sample Input
level
abacdc
OAQ
182838485868574737271

Sample Output
level
aba
O
58685

*********************************************************/
