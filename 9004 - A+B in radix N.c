#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
    int N, i, j;
    char c1[101], c2[101];
    int n1[101], n2[101], n3[101];
    int len1, len2, len, carry;

    while(scanf("%d", &N)!=EOF)
    {
        memset(n1, 0, sizeof(n1));
        memset(n2, 0, sizeof(n2));
        memset(n3, 0, sizeof(n3));
        scanf("%s %s", c1, c2);
        len1=strlen(c1);
        len2=strlen(c2);
        len=(len1>len2)?len1:len2;
        for(i=0;i<len1;i++)
        {
            if(isdigit(c1[len1-i-1]))
                n1[i]=c1[len1-i-1]-'0';
            else if(isalpha(c1[len1-i-1]))
                n1[i]=c1[len1-i-1]-'A'+10;
        }

        for(i=0;i<len2;i++)
        {
            if(isdigit(c2[len2-i-1]))
                n2[i]=c2[len2-i-1]-'0';
            else if(isalpha(c2[len2-i-1]))
                n2[i]=c2[len2-i-1]-'A'+10;
        }

        for(i=0;i<len;i++)
            n3[i]=n1[i]+n2[i];

        for(i=0;i<=len;i++)
        {
            carry=n3[i]/N;
            n3[i]%=N;
            n3[i+1]+=carry;
        }

        if(n3[len])
            len=len+1;

        for(i=len-1;i>=0;i--)
        {
            if(n3[i]<10)
                printf("%d", n3[i]);
            else if(n3[i]==10)
                printf("A");
            else if(n3[i]==11)
                printf("B");
            else if(n3[i]==12)
                printf("C");
            else if(n3[i]==13)
                printf("D");
            else if(n3[i]==14)
                printf("E");
            else if(n3[i]==15)
                printf("F");
        }
        printf("\n");
    }
    return 0;
}

/********************************************************
Problem Description
Output the sum of A+B in radix N.

Input
For each line, there are three positive integers, N, A and B.
(2 <= N <= 16, A, B is at most 100-digits) A and B are represented in radix N.

Output
For each line a case, output the sum of A+B in radix N.

Sample Input
10 5 7
5 3 4
2 101 1
16 9A B

Sample Output
12
12
110
A5
********************************************************/
