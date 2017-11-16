#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int bicolor[1100];
int connected[1100][1100];
void DFS(int c1, int c2, int n);
int flag;

int main(void)
{
    int n, m, a, b;

    while(scanf("%d", &n)!=EOF && n)
    {
        memset(bicolor, -1, sizeof(bicolor));
        memset(connected, 0, sizeof(connected));

        scanf("%d", &m);

        while(m--)
        {
            scanf("%d %d", &a, &b);
            connected[a][b]=1;
            connected[b][a]=1;
        }
        flag=1;
        DFS(0, 1, n);

        if(!flag)
            printf("NOT BICOLORABLE.");
        else
            printf("BICOLORABLE.");
        printf("\n");
    }

    return 0;
}

void DFS(int v1, int color, int n)
{
    int v2;

    bicolor[v1]=color;
    for(v2=0;v2<n;v2++)
    {
        if(connected[v1][v2])
        {
            if(bicolor[v1]!=-1 && bicolor[v2]==color)
            {
                flag=0;
                return;
            }

            else if(bicolor[v2]==-1)
            {
                bicolor[v2]=1-color;
                DFS(v2, 1-color, n);
            }
        }
    }
}

/****************************************************

Problem Description
1976年，在電腦協助之下證明了4色地圖理論（Four Color Map Theorem）。
就是僅以4種顏色在地圖上不同的區域塗色，使得相鄰的區域顏色均不相同。

現在，你要解決一個類似，但比較簡單的問題。
給你一個相連的圖，請你在節點上塗色（只有2種不同的顏色），
並且回答是否可以使得相鄰的節點顏色均不相同。
為了使問題簡單一些，你可以假設：

沒有節點會有連向自己的邊。
邊是沒有方向性的，也就是說如果節點A可以連到節點B，那麼代表節點B也可以連到節點A。
圖形是強連通的，也就是說任2節點之間皆有路徑相連。

Input
輸入含有多組測試資料。
每組測試資料的第一列有一個正整數 n（1 < n < 200）代表節點的數目。
第二列有一個正整數m，代表邊的數目。
接下來的m列每列有2個整數代表邊所連接的2個節點的代號。
這n個節點的代號分別為0到n-1。

n=0代表輸入結束。

Output
對每一組測試資料輸出是否可以用2種顏色塗節點使得相鄰的節點顏色均不相同。

若可以請輸出：BICOLORABLE.，否則輸出：NOT BICOLORABLE.

Sample Input
3
3
0 1
1 2
2 0
9
8
0 1
0 2
0 3
0 4
0 5
0 6
0 7
0 8
0

Sample Output
NOT BICOLORABLE.
BICOLORABLE.

****************************************************/
