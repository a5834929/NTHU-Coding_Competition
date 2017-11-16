#include<stdio.h>
#include<string.h>

int main(void)
{
    char str[100010];
    int i, j, len, pal;

    while(gets(str)!=NULL)
    {
        pal=0;
        len=strlen(str);
        for(i=0, j=len-1;i<j;i++, j--)
        {
            if(str[i]!=str[j])
            {
                pal=1;
                break;
            }
        }

        if(!pal)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}

/**********************************************************

Problem Description
Palindrome is a string that is identical to its reverse,
like "level" or "aba".  Check whether a given string is a palindrome or not.

Input
The input consists of multiple lines. Each line contains a
string. The length of each string is less than 100000.
The number of test case is less than 1000.

Output
For each test case, output "Yes" if it's a palindrome or "No"
if it's not a palindrome in a line.

Sample Input
level
aba
Level

Sample Output
Yes
Yes
No

**********************************************************/
