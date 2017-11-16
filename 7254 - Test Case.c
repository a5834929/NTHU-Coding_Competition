#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct s
{
    int from ,to;
}SIDE;

SIDE side[50000];
int check[1001][1001];

int main(void)
{
    int i, j, point, edge;
    int a, b;

    while(scanf("%d %d", &point, &edge)!=EOF)
    {
        memset(side, 0, sizeof(SIDE));
        memset(check, 0, sizeof(check));
        j=0;
        for(i=0;i<edge;i++)
        {
            scanf("%d %d", &a, &b);
            if(a!=b)
            {
                if(!check[a][b])
                {
                    side[j].from=a;
                    side[j].to=b;
                    check[a][b]=1;
                    check[b][a]=1;
                    j++;
                }
            }
        }
        printf("%d %d\n", point, j);
        for(i=0;i<j;i++)
            printf("%d %d\n", side[i].from, side[i].to);
        printf("\n");
    }

    return 0;
}


/*********************************************

Problem Description
Alan 出題目時會隨機產生一些測試資料。現在他要出一個BFS 題目，所以他用電腦隨機
產生一些邊，但是測試資料中不應該出現重複的邊，也不應該出現自己連自己的情況，所
以他得把這些情況都處理掉。不過他最近為了訊號與系統考試焦頭爛額中，你可以幫他處
理測資嗎?

Input
有多組測資。
每組測資，第一行有兩個正整數。
n(n<=500)表示這組測資有多少個點，m(m<=50000)表示原本邊的數量。
接下來m 行，每行會有兩個正整數代表一個邊。點的編號是由1~n，邊是雙向邊。

Output
對於每組測資，輸出沒有重複邊與自己連自己情況的測資。
第一行是點的數量n’與邊的數量m’。
接下來m’行輸出所有邊，邊請照原本輸入順序排列。每組測資之後請多一個換行

Sample Input
4 5
3 4
1 2
2 1
1 1
3 4

Sample Output
4 2
3 4
1 2

*********************************************/
