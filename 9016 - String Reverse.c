#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    int i, j, len;
    char str[1000001], swap;

    while(gets(str)!=NULL)
    {
        len=strlen(str);
        for(i=0, j=len-1;i<=j;i++, j--)
        {
            swap=str[i];
            str[i]=str[j];
            str[j]=swap;
        }
        printf("%s\n", str);
    }
    return 0;
}

/**********************************************************

Problem Description
Given a string S, output the reverse of S.

Input
The input consists of multiple lines.
Each line is a string S with length <= 1000000.
The number of test case is less than 100.

Output
Output the reverse of S.

Sample Input
level
abbbbaaabbaba
12345612345

Sample Output
level
ababbaaabbbba
54321654321

**********************************************************/
