#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int cmp(const void*p, const void*q);
double DIS(double x1, double x2, double y1, double y2);
typedef struct _c
{
    double x, y;
    double dis;
    int order, l_order;
}COW;
COW cow[2010];

int main(void)
{
    int N, i, j;
    double d;

    while(scanf("%d", &N)!=EOF)
    {
        memset(cow, 0, sizeof(COW));
        for(i=0;i<N;i++)
        {
            cow[i].dis=150000;
            scanf("%lf %lf", &cow[i].x, &cow[i].y);
            cow[i].order=i;
        }

        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                if(i!=j)
                {
                    d=DIS(cow[i].x, cow[j].x, cow[i].y, cow[j].y);
                    if(d<cow[i].dis)
                    {
                        cow[i].dis=d;
                        cow[i].l_order=j;
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

double DIS(double x1, double x2, double y1, double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int cmp(const void*p, const void*q)
{
    COW a=*(COW*)p, b=*(COW*)q;
    if(a.dis!=b.dis) return (a.dis<b.dis)?-1:1;
    return 0;
}
