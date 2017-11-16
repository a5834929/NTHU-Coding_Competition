#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int group[1100], queue[1100], visited[1100];
int matrix[1100][1100];

int main(void)
{
    int n, m, a, b, flag;
    int j, front, rear;

    while(scanf("%d", &n)!=EOF && n)
    {
        memset(group, -1, sizeof(group));
        memset(matrix, 0, sizeof(matrix));
        memset(visited, 0, sizeof(visited));

        scanf("%d", &m);
        flag=1;

        while(m--)
        {
            scanf("%d %d", &a, &b);
            matrix[a][b]=1;
            matrix[b][a]=1;
        }
        front=0;
        rear=0;
        queue[0]=1;
        visited[1]=1;

        while(front<=rear)
        {
            for(j=1;j<=n;j++)
            {
                if(matrix[queue[front]][j])
                {
                    if(!visited[j])
                    {
                        rear++;
                        visited[j]=1;
                        queue[rear]=j;
                    }

                    if(group[queue[front]]==-1 && group[j]==-1)
                    {
                        group[queue[front]]=1;
                        group[j]=0;
                    }

                    else if(group[queue[front]]==-1 && group[j]!=-1)
                        group[queue[front]]=1-group[j];

                    else if(group[queue[front]]!=-1 && group[j]==-1)
                        group[j]=1-group[queue[front]];

                    else if(group[queue[front]]!=-1 && group[j]!=-1)
                        if(group[queue[front]]==group[j])
                        {
                            flag=0;
                            break;
                        }
                }
            }
            front++;
            if(!flag)
                break;
            if(front>rear)
            {
                for(j=1;j<=n;j++)
                {
                    if(visited[j]==0)
                    {
                        visited[j]=1;
                        front=0;
                        queue[front]=j;
                        rear=0;
                        break;
                    }
                }
            }
        }

        if(!flag)
            printf("You discover a BIG Secret!!");
        else
            printf("Successful");
        printf("\n");
    }

    return 0;
}

/*************************************************************
Problem Description
話說搗蛋是一個包打聽，他的樂趣就是觀察某些人的互動
或是從朋友那打聽消息，以確定某兩個人是否有姦情好感。
（雖然這猜測不一定正確，有時還會被吐槽『這誤會可大了！』，但他樂此不疲～）
有一天，他收到一封加密過的名單。上面列有一連串的資料，
每筆資料代表被懷疑的兩人。但由於這份名單被隱去名字只有代號，
他可能只知道A<=>B、A<=>C、B<=>D、、等。為了解密，
他決定先將這些代號分成男生一群、女生一群，再來推測人名。
請問是否有一個分法，可以將這些代號分成兩群？
（當不能分成兩群的時候，表示可能發現了一個大秘密…）

Input
有多組測資。
每組測資第一行為整數N，表示有N個人(代號為1...N，N<=1000)
接下來為整數K，表示有K個被懷疑的關係。
接下來K行，每行有兩個整數，表示這兩個代號可能是互有好感的。
當N=0時，測資結束。

Output
針對每組測資，
如果有辦法將代號分成男女兩群，請輸出”Successful”；
否則，請輸出”You discover a BIG Secret!!”

Sample Input
3
2
1 2
2 3
4
5
1 2
1 3
2 4
3 4
2 3
7
7
1 2
2 3
3 1
4 5
4 6
5 7
6 7
0

Sample Output
Successful
You discover a BIG Secret!!
You discover a BIG Secret!!
***************************************************************/
