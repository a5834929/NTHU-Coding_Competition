#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
    int map[9][9], queue[1000][2];
    char sr, er;
    int sc, ec;
    int i, j, flag, front, rear;

    while(scanf("%c%d", &sr, &sc)!=EOF)
    {
        getchar();
        flag=0;
        scanf("%c%d", &er, &ec);
        getchar();
        memset(map, 0, sizeof(map));
        memset(queue, 0, sizeof(queue));

        front=0;
        rear=1;
        i=sr-'a'+1;
        j=sc;
        queue[0][0]=i;
        queue[0][1]=j;
        while(!flag)
        {
            if((i==er-'a'+1) && (j==ec))
            {
                printf("To get from %c%d to %c%d takes %d knight moves.\n", sr, sc, er, ec, map[i][j]);
                flag=1;
            }
            else
            {
                if(i+1<=8 && j+2<=8 && map[i+1][j+2]==0)
                {
                    map[i+1][j+2]=map[i][j]+1;
                    queue[rear][0]=i+1;
                    queue[rear][1]=j+2;
                    rear++;
                }
                if(i+1<=8 && j-2>0 && map[i+1][j-2]==0)
                {
                    map[i+1][j-2]=map[i][j]+1;
                    queue[rear][0]=i+1;
                    queue[rear][1]=j-2;
                    rear++;
                }
                if(i-1>0 && j+2<=8 && map[i-1][j+2]==0)
                {
                    map[i-1][j+2]=map[i][j]+1;
                    queue[rear][0]=i-1;
                    queue[rear][1]=j+2;
                    rear++;
                }
                if(i-1>0 && j-2>0 && map[i-1][j-2]==0)
                {
                    map[i-1][j-2]=map[i][j]+1;
                    queue[rear][0]=i-1;
                    queue[rear][1]=j-2;
                    rear++;
                }
                if(i+2<=8 && j+1<=8 && map[i+2][j+1]==0)
                {
                    map[i+2][j+1]=map[i][j]+1;
                    queue[rear][0]=i+2;
                    queue[rear][1]=j+1;
                    rear++;
                }
                if(i+2<=8 && j-1>0 && map[i+2][j-1]==0)
                {
                    map[i+2][j-1]=map[i][j]+1;
                    queue[rear][0]=i+2;
                    queue[rear][1]=j-1;
                    rear++;
                }
                if(i-2>0 && j+1<=8 && map[i-2][j+1]==0)
                {
                    map[i-2][j+1]=map[i][j]+1;
                    queue[rear][0]=i-2;
                    queue[rear][1]=j+1;
                    rear++;
                }
                if(i-2>0 && j-1>0 && map[i-2][j-1]==0)
                {
                    map[i-2][j-1]=map[i][j]+1;
                    queue[rear][0]=i-2;
                    queue[rear][1]=j-1;
                    rear++;
                }
                front++;
                i=queue[front][0];
                j=queue[front][1];
            }
        }
    }
    return 0;
}

/*************************************

Problem Description
你的一個朋友正在做一個關於西洋棋中騎士旅行問題（Traveling Knight Problem）的研究，
他希望你幫他解決一個問題：就是給你2個格子的位置X及Y，請你找出騎士從X走到Y最少需要走幾步。

Input
每筆測試資料一列。每列有2個西洋棋的座標位置。每個位置座標是由一個英文字母
（a-h，代表棋盤的第幾欄）及一個數字（1-8，代表棋盤的第幾列）組成。

Output
對每一列輸入，請輸出 "To get from xx to yy takes n knight moves.".

Sample Input
e2 e4
a1 b2
b2 c3
a1 h8
a1 h7
h8 a1
b1 c3
f6 f6

Sample Output
To get from e2 to e4 takes 2 knight moves.
To get from a1 to b2 takes 4 knight moves.
To get from b2 to c3 takes 2 knight moves.
To get from a1 to h8 takes 6 knight moves.
To get from a1 to h7 takes 5 knight moves.
To get from h8 to a1 takes 6 knight moves.
To get from b1 to c3 takes 1 knight moves.
To get from f6 to f6 takes 0 knight moves.

*************************************/
