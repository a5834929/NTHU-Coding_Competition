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

/***************************************************************
Problem Description
在西洋棋裡，皇后的移動方式是選擇米字的其中一個方向移動，且移動步數可為任意長度。
有一個經典問題名為N 皇后問題，在一個N*N 的西洋棋盤上找一個解法，放置N 個皇后，
使得這些皇后兩兩不會攻擊到彼此。
現在將棋盤上的每一格賦予一個數字。並定義⼀一個解法的分數為，這N 個皇后所在位置的
數字相加。給予一個N*N 棋盤，詢問所有解法內，分數最高的解法為多少？

Input
有多組測資。
每組測資第一行，有一個整數N(1<=N<=8)。
接下來有N 行，每行有N 個數字，且每兩個數字間用一個空白隔開。
每個數字Qij 為整數。(-100 <= Qij <= 100)

Output
輸出所有N 皇后解法中，分數最高為多少。
若無任何可行的N 皇后解法，則輸出”No Solution”。

Sample Input
8
1 2 3 4 5 6 7 8
9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
48 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64

Sample Output
260
****************************************************************/
