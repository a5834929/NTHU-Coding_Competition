#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int queue[600], visited[600];
int matrix[600][600];

int main(void)
{
    int n, m, s, a, b;
    int i, cost[600];
    int front, rear;

    while(scanf("%d %d %d", &n, &m, &s)!=EOF)
    {
        memset(visited, 0, sizeof(visited));
        memset(matrix, 0, sizeof(matrix));
        memset(cost, 0, sizeof(cost));

        while(m--)
        {
            scanf("%d %d", &a, &b);
            matrix[a][b]=1;
            matrix[b][a]=1;
        }

        queue[0]=s;
        visited[s]=1;
        front=0;
        rear=1;

        while(front<rear)
        {
            for(i=1;i<=n;i++)
            {
                if(matrix[queue[front]][i])
                {
                    if(!visited[i])
                    {
                        visited[i]=1;
                        queue[rear]=i;
                        rear++;
                        cost[i]=cost[queue[front]]+1;
                    }
                }
            }
            front++;
        }

        if(s!=1)
            printf("%d", (cost[1]/5)*5+20);
        else
            printf("0");
        for(i=2;i<=rear;i++)
        {
            if((i)!=s)
                printf(" %d", (cost[i]/5)*5+20);
            else
                printf(" 0");
        }
        printf("\n");
    }

    return 0;
}

/********************************************************

Problem Description
捷運會依照你坐了多少站來收費，計算費用的方法是：(起點到終點的最短距離/5)*5+20。
例如永春站要到台北車站，最短路線是永春->市政府->國父紀念館->忠孝敦化->忠孝復興
->忠孝新生->善導寺->台北車站，共需經過七站，所以票價就是 (7/5)*5+20 = 25 元。現在
給你捷運地圖，以及起點站，你能夠算出起點站到所有站所需要的票價嗎?

Input
有多組測資，每組測資第一行有三個正整數n(n<=500)代表捷運站數，m 代表連線，以及
s 代表起點站。接下來m 行每行有兩個正整數a,b(1<=a,b<=n)代表捷運站的連線(雙向)，捷
運站之間必定是連通的

Output
對於每組測資，請依照index順序輸出起點站到所有站所需的票價，不同站票價中間空一個空格，
起點站到起點站不用錢。

Sample Input
6 5 1
1 2
2 3
3 4
4 5
5 6

Sample Output
0 20 20 20 20 25

********************************************************/
