#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void DFS(int node, int choose, int notchoose);
int map[101][101], mt[101];
int tmp[101], Ans[101], maxL;
int cant[101];
int T, n, m;

int main(void)
{
	int i, x, y;
	while(scanf("%d", &T)!=EOF)
	{
	    while(T--)
        {
            scanf("%d %d", &n, &m);
            memset(mt, 0, sizeof(mt));
            memset(cant, 0, sizeof(mt));

            for(i=0;i<m;i++)
            {
                scanf("%d %d", &x, &y);
                map[x][mt[x]]=y;
                map[y][mt[y]]=x;
                mt[x]++;
                mt[y]++;
            }

            maxL=0;
            DFS(1, 0, 0);
            printf("%d\n", maxL);

            for(i=0;i<maxL-1;i++)
                printf("%d ", Ans[i]);

            printf("%d\n", Ans[i]);
        }
	}

    return 0;
}

void DFS(int node, int choose, int notchoose)
{
    int i, newNot, reduce[101]={0}, idx;

	if((choose+notchoose)==n || node==(n+1))
	{
		if(choose>maxL)
		{
			maxL=choose;

			for(i=0;i<maxL;i++)
				Ans[i]=tmp[i];
		}
		return;
	}

	if(cant[node]==0)
	{
		idx=0;
		newNot=notchoose;

		for(i=0;i<mt[node];i++)
		{
			if(cant[map[node][i]]==0)
			{
				cant[map[node][i]]=1;
				reduce[idx++]=map[node][i];
				newNot++;
			}
		}

		tmp[choose]=node;
		DFS(node+1, choose+1, newNot);

		for(i=0;i<idx;i++)
			cant[reduce[i]]=0;
	}
	DFS(node+1, choose, notchoose+(!cant[node]));
}


/********************************************

Problem Description
給你一個圖形，你的任務是找到一種最佳塗色的方法。
圖形中的點要被塗顏色（只能塗黑色或白色），而且
任何2個相連的點不可以都塗黑色。所謂最佳的塗色方法
是指讓這個圖形黑色的點最多。

Input
輸入的第一列有一個整數，代表以下有多少組測試資料。

每組測試資料的第一列含有2個整數 n ( 1 <= n <= 100 )，k。
n 代表圖形中點的數目（編號從1到 n），k 代表圖形中邊的數目。
接下來的 k 列每列含有 2 個點的編號，代表一個邊。請參考Sample Input。

Output
對每一組測試資料輸出 2 列。第一列輸出最多可以有多少個點可以被塗黑色。
第二列輸出一種可能的塗法，以塗黑色點的編號來表示。請參考 Sample Output。

Sample Input
3
6 8
1 2
1 3
2 4
2 5
3 4
3 6
4 6
5 6
2 0
6 5
1 2
1 3
2 3
4 5
4 6

Sample Output
3
1 4 5
2
1 2
3
1 5 6

**********************************************/
