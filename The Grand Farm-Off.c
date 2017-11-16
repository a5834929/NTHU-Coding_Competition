#include<stdio.h>
#include<stdlib.h>
typedef struct node NODE;
struct node
{
    long long int w,u;
    int i;
};
NODE ar[15000010];

long long int number, a, b, c, d, e, f, g, h, m, ans;
int is_bigger_than(long long int x);
long long int WEIGHT(int i);
long long int U_i(int i);
int cmp(const void*p, const void*q);

int main(void)
{
    int i;
    while(scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld", &number,&a,&b,&c,&d,&e,&f,&g,&h,&m)!=EOF)
    {
        for(i=0;i<3*number;i++)
        {
            ar[i].u=U_i(i);
            ar[i].i=i;
        }
        qsort(ar, 3*number, sizeof(NODE), cmp);
        ans=0;
        for(i=0;i<number;i++)
        {
            ans+=WEIGHT(ar[i].i);
            if(is_bigger_than(ans))
                ans=ans%m;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
long long int WEIGHT(int i)
{
    return (((((((((((a%d)*(i%d))%d)*(i%d))%d)*(i%d))%d)*(i%d))%d)*(i%d))%d + (((((b%d)*(i%d))%d)*(i%d))%d)+(c%d))%d;
}
long long int U_i(int i)
{
    return ((((((((((((e%h)*(i%h))%h)*(i%h))%h)*(i%h))%h)*(i%h))%h)*(i%h))%h + ((((((f%h)*(i%h))%h)*(i%h))%h)*(i%h))%h)+(g%h))%h;
}
int cmp(const void*p, const void*q)
{
    NODE a=*(NODE*)p, b=*(NODE*)q;
    if(a.u!=b.u) return (a.u<b.u)?-1:1;
    return 0;
}
int is_bigger_than(long long int x)
{
    return x>m?1:0;
}
