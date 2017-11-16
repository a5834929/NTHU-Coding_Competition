#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int board[26][26];
int big(int a, int b);

int main(void)
{
    int R, i, j;

    while(scanf("%d", &R)!=EOF)
    {
        for(i=1;i<=R;i++)
            for(j=1;j<=i;j++)
                scanf("%d", &board[i][j]);

        for(i=R;i>0;i--)
            for(j=2;j<=i;j++)
                board[i-1][j-1]+=big(board[i][j-1], board[i][j]);

        printf("%d\n", board[1][1]);
    }
    return 0;
}

int big(int a, int b)
{
    return (a>=b)?a:b;
}
