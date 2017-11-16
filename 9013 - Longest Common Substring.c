#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    int n, i, j, k, sum, cnt;
    int len1, len2;
    char str1[1001], str2[1001], temp[1001];

    while(scanf("%d", &n)!=EOF)
    {
        while(n--)
        {
            scanf("%s %s", str1, str2);

            if(strlen(str1)>strlen(str2))
            {
                strcpy(temp, str1);
                strcpy(str1, str2);
                strcpy(str2, temp);
            }
            len1=strlen(str1);
            len2=strlen(str2);
            k=0;
            sum=0;

            for(k=0;k<len1;k++)
            {
                cnt=0;
                for(i=k, j=0;i<len1;i++, j++)
                {
                    if(str1[i]==str2[j])
                    {
                        cnt++;
                        if(cnt>sum)
                            sum=cnt;
                    }
                    else
                        cnt=0;
                }
            }

            for(k=1;k<len2;k++)
            {
                cnt=0;
                for(i=0, j=k;j<len2;i++, j++)
                {
                    if(str1[i]==str2[j])
                    {
                        cnt++;
                        if(cnt>sum)
                            sum=cnt;
                    }
                    else
                        cnt=0;
                }
            }
            printf("%d\n", sum);
        }
    }
    return 0;
}

/**************************************

Problem Description
Given two strings, find the length of the longest common substring.

Input
The first line of input contains a positive integer t ,
which indicates the number of test cases. For each case, there are
two strings in a line (length of the string <= 1000).

Case1: O(n^3) T <= 10 , length of string <= 100
Case2: O(n^2) T <= 100 , length of string <= 1000
Case3: O(n^2) T <= 100 , length of string <= 1000
Case4: O(n^2) T <= 500 , length of string <= 1000

Output
Output the length of the longest common substring.

Sample Input
3
aabbaab aabbbbbb
ABCDEDCBA ABCDCBA
qazwsxedcrfv azwsxedcq

Sample Output
4
4
8

***************************************/
