#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
double dist[502][502]={{0}};
double DIST(double x1, double x2, double y1, double y2);
int cmp(const void*p, const void*q);

typedef struct _c
{
    double x, y;
    double l_dist;
    int order;
    int l_order;
}COW;
COW cow[502];

int main(void)
{
    int N, i, j;
    double d;

    while(scanf("%d", &N)!=EOF)
    {
        memset(dist, 0, sizeof(dist));
        memset(cow, 0, sizeof(COW));
        for(i=0;i<N;i++)
        {
            cow[i].l_dist=0;
            scanf("%lf %lf", &cow[i].x, &cow[i].y);
            cow[i].order=i;
        }

        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                if(!dist[i][j] && i!=j)
                {
                    dist[i][j]=1;
                    d=DIST(cow[i].x, cow[j].x, cow[i].y, cow[j].y);
                    if(d>cow[i].l_dist)
                    {
                        cow[i].l_order=cow[j].order;
                        cow[i].l_dist=d;
                    }
                }
            }
        }
        qsort(cow, N, sizeof(COW), cmp);

        if(cow[0].order<cow[0].l_order)
            printf("%d %d\n", cow[0].order+1, cow[0].l_order+1);
        else
            printf("%d %d\n", cow[0].l_order+1, cow[0].order+1);
    }
    return 0;
}

double DIST(double x1, double x2, double y1, double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int cmp(const void*p, const void*q)
{
    COW a=*(COW*)p, b=*(COW*)q;
    if(a.l_dist!=b.l_dist)  return (a.l_dist>b.l_dist)?-1:1;
    return 0;
}
