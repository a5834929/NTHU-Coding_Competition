#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char matrix[1100][1100];

int main(void)
{
    int i, j, a, len, bound, row, col, flag;
    int endi, endj, done;
    char str[1100];

    while(gets(str)!=NULL)
    {
        a=strlen(str);
        if(a)
        {
            for(i=1;i<=a;i++)
            {
                if(i*i>=a)
                {
                    len=i;
                    break;
                }
            }

            for(i=0;i<len;i++)
                for(j=0;j<len;j++)
                    matrix[i][j]=' ';

            j=0;
            i=0;
            flag=0;
            bound=len;

            while(j<bound)
            {
                for(row=j, col=j;row<bound-1;row++)
                {
                    matrix[row][col]=str[i];
                    i++;

                    if(i==a)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag)
                    break;

                for(;col<bound-1;col++)
                {
                    matrix[row][col]=str[i];
                    i++;

                    if(i==a)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag)
                    break;

                for(;row>j;row--)
                {
                    matrix[row][col]=str[i];
                    i++;

                    if(i==a)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag)
                    break;

                for(;col>j;col--)
                {
                    matrix[row][col]=str[i];
                    i++;

                    if(i==a)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag)
                    break;

                if(row==(len/2) && col==(len/2))
                {
                    matrix[row][col]=str[a-1];
                    break;
                }

                bound--;
                j++;
            }

            done=0;
            for(i=len-1;i>=0;i--)
            {
                for(j=len-1;j>=0;j--)
                {
                    if(matrix[i][j]!=' ')
                    {
                        endi=i;
                        endj=j;
                        done=1;
                        break;
                    }
                }
                if(done)
                        break;
            }

            if(done)
            {
                for(i=0;i<=endi;i++)
                {
                    if(i<endi)
                    {
                        for(j=0;j<len;j++)
                        {
                            printf("%c", matrix[i][j]);
                            matrix[i][j]=' ';
                        }
                    }
                    else
                    {
                        for(j=0;j<=endj;j++)
                        {
                            printf("%c", matrix[i][j]);
                            matrix[i][j]=' ';
                        }
                    }
                }
            }
            printf("\n");
        }

        else
            printf("\n");
    }
    return 0;
}

/*********************************************

Problem Description
We can encrypt a string into other string.
One method is to put a string into an n¡Ñn array first,
where n is the smallest number such that n^2 is larger
than or equal to the length of the string.
Each character is put into a cell of the array, from
the top left cell of the array and along neighboring
cells in the counterclockwise order.  The encrypted
string is the output of the row major order.
For example, the input string "Greed is good",
whose length is 13, are put into a 4¡Ñ4 array,
as shown in the following figure.

The output string is "Googrd  e  sed i".

If the end of the encrypted string are spaces,
don't output them.
For example, the output of "Bass GG" is "B Ga Gss".


Input
The input consists of multiple lines. Each line is a test case,
a string S with length <= 1000. The number of test case is less than 100.

case1: O(N)
case2: O(N)
case3: O(N)
case4: O(N)
N means string length.

Output
For each test case, output the encrypted string of S.

Sample Input
Greed is good
Bass GG
LeiChe is a fat dog.
Oh~~~~~~~    NO!!!!!!!!!!!!!
OAQ

Sample Output
Googrd  e  sed i
B Ga Gss
L tafed   io  aCg.  he is
O!!!!!h!   O~!   N~!  ! ~!!!! ~~~~
O AQ

*********************************************/
