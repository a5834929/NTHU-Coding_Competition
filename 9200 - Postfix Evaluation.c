#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
    int n, m, i, top, len;
    long long int stack[10010]={0};
    char ch, digi[10];

    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        scanf("%d\n", &m);
        top=0;

        while(scanf("%c", &ch)!=EOF && ch!='\n')
        {
            len=0;
            if(isdigit(ch))
            {
                while(isdigit(ch))
                {
                    digi[len]=ch;
                    len++;
                    scanf("%c", &ch);
                }

                if(len==1)
                    stack[top]=digi[0]-'0';

                else if(len==2)
                    stack[top]=(digi[0]-'0')*10+(digi[1]-'0');

                else if(len==3)
                    stack[top]=(digi[0]-'0')*100+(digi[1]-'0')*10+(digi[2]-'0');

                top++;
            }

            else if(ch=='+')
            {
                stack[top-2]=stack[top-2]+stack[top-1];
                top=top-2;
                top++;
            }

            else if(ch=='-')
            {
                stack[top-2]=stack[top-2]-stack[top-1];
                top=top-2;
                top++;
            }

            else if(ch=='*')
            {
                stack[top-2]=stack[top-2]*stack[top-1];
                top=top-2;
                top++;
            }

            else if(ch=='/')
            {
                stack[top-2]=stack[top-2]/stack[top-1];
                top=top-2;
                top++;
            }
        }
        printf("Case %d: %lld\n", i+1, stack[top-1]);
    }

    return 0;
}

/********************************************

Problem Description
Evaluate the result of a given numerical expression written in postfix notation.

Input
The first line of the input contains an integer N (N ≤ 100) which denotes the number of test cases.
Each test case begins with an integer M (M ≤ 10000) representing the number of tokens in the
expression,followed by M tokens in the next line. Tokens are separated by spaces and the operators
contain only “+”,“-”, “*” and “/”; the operands are integers in the range [0, 100].
The division operator “/” here is considered as integral division. You may assume that all of
the expressionsare valid (divide-by-zero would never occur) and the answer will fit in 32-bit
signed integers. Evaluated results(in each stage of the evaluation ) will fit in 100-digit
signed integers and divide-by-bignumber would never occur.

Output
The output of each test case occupies a line. Each line begins with the test case number “Case i:”,
and then a space character followed by the evaluated answer.

Sample Input
2
5
2 3 4 * +
5
1 2 + 7 *

Sample Output
Case 1: 14
Case 2: 21

********************************************/
