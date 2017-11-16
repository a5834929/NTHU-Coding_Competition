#include<stdio.h>
void DFS(int);

int map[6][6]={{0,0,0,0,0,0},
               {0,0,1,1,0,1},
               {0,1,0,1,0,1},
               {0,1,1,0,1,1},
               {0,0,0,1,0,1},
               {0,1,1,1,1,0}};
int path[10]={0}, len=0;

int main(void)
{
    DFS(1);
    return 0;
}

void DFS(int start)
{
    int i;
    path[len++]=start;

    if(len==9)
    {
        for(i=0;i<len;i++) printf("%d", path[i]);
        printf("\n");
        len--;
        return;
    }

    for(i=1;i<=5;i++)
    {
        if(map[start][i]==1)
        {
            map[start][i]=map[i][start]=0;
            DFS(i);
            map[start][i]=map[i][start]=1;
        }
    }
    len--;
}


/***************************************************

Problem Description
不知道你們小時候有沒有玩過一筆畫，畫聖誕老人的房子的遊戲。
畫出來的圖就像下面這樣：

經過這麼多年了，現在我們想要寫一個程式來知道如果我們從左下角
開始畫起，共有多少種一筆畫聖誕老人房子的方法。下面的圖中的5個點
用1到5來編號（從編號1開始畫起），箭頭代表一筆畫時筆的路徑。
這個例子中的路徑為：153125432

Input
No input

Output
把所有可能的畫法按照數字大小由小到大排列好。

Sample Output
123153452
123154352
...
...
...
154352312

****************************************************/
