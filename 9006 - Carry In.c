#include<stdio.h>
#include<string.h>
char A[100000]={0}, B[100000]={0};
int a[100000]={0}, b[100000]={0}, c[100000]={0};

int main(void)
{
    int i, j, carry, count, len, lena, lenb;

    while(scanf("%s%s", A, B)!=EOF)
    {
        lena=strlen(A);
        lenb=strlen(B);
        len=(lena>=lenb)?lena:lenb;

        for(i=0;i<lena;i++) a[i]=A[lena-i-1]-'0';
        for(i=0;i<lenb;i++) b[i]=B[lenb-i-1]-'0';
        for(i=0;i<len;i++) c[i]=a[i]+b[i];
        for(i=0;i<lena;i++) a[i]=0;
        for(i=0;i<lenb;i++) b[i]=0;

        carry=0;
        count=0;

        for(i=0;i<len;i++)
        {
            c[i]+=carry;
            carry=c[i]/10;
            c[i]=0;

            if(carry) count++;
        }
        printf("%d\n", count);
    }

    return 0;
}

/***********************************************

Problem Description
Compute how many carries occur when calculating A+B.

Input
For each case a line, there will be two positive integers A and B < 10^100.

Output
For each case a line, output how many times carries occur.

Sample Input
2 3
5 6
123 567
123 777

Sample Output
0
1
1
2

***********************************************/
