#include<stdio.h>
#include<stdlib.h>
int matrix[8][8];
int ans[100], ansn;
int cmp(const void*p, const void*q);
void dfs(int done[][8], int row, int sum);

int main(void)
{
    int n, i, j;
    int done[8][8]={{0}};

    scanf("%d", &n);

    while(n--)
    {
        for(i=0;i<8;i++)
            for(j=0;j<8;j++)
                scanf("%d", &matrix[i][j]);
        ansn=0;
        dfs(done, 0, 0);
        qsort(ans, ansn, sizeof(ans[0]), cmp);
        printf("%5d\n", ans[0]);
    }
    return 0;
}

void dfs(int done[][8], int row, int sum)
{
    int col, i, flag;

    if(row==8)
    {
        ans[ansn]=sum;
        ansn++;
        return;
    }

    for(col=0;col<8;col++)
    {
        flag=1;
        for(i=0;i<row;i++)
        {
            if(done[i][col])
            {
                flag=0;
                break;
            }
            else if(row+col-i<8 && done[i][row+col-i])
            {
                flag=0;
                break;
            }
            else if(i-row+col>=0 && done[i][i-row+col])
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            done[row][col]=1;
            dfs(done, row+1, sum+matrix[row][col]);
            done[row][col]=0;
        }
    }
    return;
}

int cmp(const void*p, const void*q)
{
    int a=*(int*)p, b=*(int*)q;
    if(a!=b) return a>b?-1:1;
    return 0;
}

/*****************************************************************

Problem Description
Each chessboard has numbers in the range 1 to 99 written on each square
and is supplied with 8 chess queens. The task is to place the 8 queens
on the chess board in such a way that no queen threatens another one,
and so that the sum of the numbers on the squares selected is the maximum .
(For those unfamiliar with the rules of chess, this implies that each row
 and column of the board contains exactly one queen, and each diagonal
 contains no more than one queen.)

Write a program that will read in the number and details of the chessboards
and determine the highest scores possible for each board under these conditions.

Input
Input will consist of K (the number of boards), on a line by itself,
followed by K sets of 64 numbers, each set consisting of eight lines
of eight numbers. Each number will be a non-negative integer less than 100.
Each case is separated by a blank line. There will never be more than 20 boards.

Output
The outputs of all test cases should be printed in order.
For each test case a line, print the highest score right justified
in field 5 characters wide.

Sample Input
3
1 2 3 4 5 6 7 8
9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
48 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64

1 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 1
0 0 0 0 0 1 0 0
0 0 1 0 0 0 0 0
0 0 0 0 0 0 1 0
0 1 0 0 0 0 0 0
0 0 0 1 0 0 0 0

0 0 1 0 0 0 0 0
0 0 0 0 2 0 0 0
0 3 0 0 0 0 0 0
0 0 0 0 0 0 0 4
5 0 0 0 0 0 0 0
0 0 0 0 0 0 6 0
0 0 0 7 0 0 0 0
0 0 0 0 0 8 0 0

Sample Output
  260
    8
   36
****************************************************************/
