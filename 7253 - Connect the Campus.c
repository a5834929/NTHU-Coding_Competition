#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int cmp(const void*p, const void*q);
int find(int x);
void Union(int a, int b);
double DIS(int x1, int y1, int x2, int y2);

typedef struct EDGE
{
    double dis;
    int x, y;
}EDGE;

EDGE edge[500000];

int set[1000];
int sum[1000];
int coord[1000][2];
int now, x;
int n, e, flag;
double ans;

int main(void)
{
    int i, j, a, b;

    while (scanf("%d", &n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            set[i]=i;
            sum[i]=1;
        }

        for(i=1;i<=n;i++)
            scanf("%d %d", &coord[i][0], &coord[i][1]);

        scanf("%d", &e);

        for(i=0;i<e;i++)
        {
            scanf("%d %d", &a, &b);
            Union(find(a), find(b));
        }

        x=0;
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                edge[x].dis=DIS(coord[i][0], coord[i][1], coord[j][0], coord[j][1]);
                edge[x].x=i;
                edge[x].y=j;
                x++;
            }
        }

        qsort(edge, x, sizeof(EDGE), cmp);

        flag=0;

        for(i=1;i<=n;i++)
        {
            if(find(1)!=find(i))
            {
                flag=1;
                break;
            }
        }

        now=0;
        ans=0;
        while(flag && now<x)
        {
            if(find(edge[now].x)!=find(edge[now].y))
            {
                ans+=edge[now].dis;
                Union(find(edge[now].x), find(edge[now].y));
            }

            flag=0;
            for(i=1;i<=n;i++)
            {
                if(find(1)!=find(i))
                {
                    flag=1;
                    break;
                }
            }
            now++;
        }

        printf("%.2lf\n", ans);

    }

    return 0;

}

int cmp(const void*p, const void*q)
{
    EDGE a=*(EDGE*)p, b=*(EDGE*)q;
    if(a.dis!=b.dis) return (a.dis<b.dis)?-1:1;
    return 0;
}

int find(int x)
{
    if(set[x]==x)
        return x;
    else
        return set[x]=find(set[x]);
}

void Union(int a, int b)
{
    if(a==b)
        return;

    if(sum[a]>sum[b])
        set[b]=a;

    else
    {
        set[a]=b;
        if(sum[a]==sum[b])
            sum[b]++;
    }
}

double DIS(int x1, int y1, int x2, int y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

/**********************************************************

Problem Description
在Waterloo大學裡有許多的建築物正在興建。學校雇用了建築工人、
水電工人以及一個程式設計師。程式設計師？不要懷疑，那個人就是你。
你的任務就是要算出要建置校園網路需要用多少纜線。

每棟建築物可以視為在X-Y平面上的一個點。連接2棟建築物的網路線均為直線，
且網路線為雙向的。網路線可以自由的跨越，但是只有在建築物的地方網路線才有接頭。

學校給你一張校園的地圖，上面有各建築物的位置座標，
以及一些已經存在於建築物間的網路線。對那些已經存在的網路線，
你不要去動它。你的任務是要架設新的網路線，使得所有的建築物都可以藉由網路相連。
當然，學校方面希望你新架設的網路線越短越好。

Input
輸入含有多組測試資料。

每組測試資料的第一列有一個整數N（1 <= N <= 750），代表建築物的數目
（建築物的編號從1到N）。接下來的N列每列有2個整數（介於-10000到10000之間），
代表為這N棟建築物的座標（不會有2棟不同的建築物在同一個點上）。
再接下來的一列有一個整數M（0 <= M <= 1000）代表已有M條網路線連接於建築物之間。
再接下來的M列每列有2個正整數代表某條已存在的網路線所連接的2棟建築物編號。
任2棟建築物間最多只會有一條網路線連接。

請參考Sample Input。

Output
每組測試資料輸出一列。含有一個浮點數（小數點後2位），
代表你所新架設的網路線的長度，使得校園間各建築物都可以網路連接，
而且長度要最小。

Sample Input
4
103 104
104 100
104 103
100 100
1
4 2
4
0 0
0 1
1 0
1 1
2
1 2
3 4

Sample Output
4.41
1.00

************************************************************/
