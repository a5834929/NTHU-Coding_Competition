#include<stdio.h>
#include<stdlib.h>
typedef struct _m
{
    int start, end;
    int cost;
}M;
M edge[250];

int map[250][250];
int vis[250];
int sum, D;

int main(void)
{
    int P, C, F, S, a, b, c;

    while(scanf("%d%d%d%d%d", &D, &P, &C, &F, &S)!=EOF)
    {
        sum=0;
        memset(vis, 0, sizeof(vis));
        memset(map, 0, sizeof(map));
        memset(cost, 0, sizeof(cost));

        while(D--)
        {
            scanf("%d %d", &a, &b);
            edge[n].start=a;
            edge[n].end=b;
            edge[n].cost=100;
        }
        while(C--)
        {
            scanf("%d %d %d", &a, &b, &c);
            edge[n].start=a;
            edge[n].end=b;
            edge[n].cost=-c;
        }



    }

    return 0;
}

