#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int find(int x);
void Union(int a, int b);

int set[1010];
int sum[1010];

int main(void)
{
    int N, K, i;
    int a, b, max, ans;

    while(scanf("%d", &N)!=EOF && N)
    {
        scanf("%d", &K);
        for(i=1;i<=N;i++)
        {
            set[i]=i;
            sum[i]=1;
        }

        for(i=1;i<=K;i++)
        {
            scanf("%d %d", &a, &b);

            if(set[a]!=set[b])
                Union(a, b);
        }

        max=0;
        for(i=1;i<=N;i++)
            if(sum[i]>max)
                max=sum[i];

        ans=0;
        for(i=1;i<=N;i++)
            if(sum[i]==max)
                ans++;

        printf("%d\n", ans);
    }

    return 0;
}

int find(int x)
{
    if(set[x]=x)
        return x;
    else
        return set[x]=find(set[x]);
}

void Union(int a, int b)
{
    int x, y;
    x=find(set[a]);
    y=find(b);

    if(x!=y)
    {
        set[y]=x;
        sum[x]+=sum[y];
        sum[y]=0;
    }
}

/*******************************************

Problem Description
在班上，有些人因為個性上比較接近，會常常聚在一起。
此時，我們會將這幾個人歸為”同一掛”。若A跟B是同一掛、B跟C是同一掛，則A跟C也會是同一掛的。
現在，給你目前班上有多少人，及這些”誰跟誰是同一掛”的關係。有了這些關係，
你就知道班上有幾個小團體了（獨行俠自成一伙）。
但其實有時候小團體的數量並不是那麼重要。
我們只在意這些小團體中的最大勢力，也就是人最多的小團體。
因為他們在表決公共事務時，會佔優勢。現在，給你這些關係圖，請找出人最多的小團體有幾個。

Input
有多組測資。
每組測資第一行，有兩個整數：N, K，表示班上有N個人、K個關係(1<=N<=1000)
接下來K行，每行有兩個整數X,Y，表示X跟Y是同一掛的。(1<=X,Y<=N)
當N=0時，測資結束。

Output
對於每組測資，輸出一個整數表示有幾個最大勢力的小團體。

Sample Input
10 5
1 2
3 4
1 5
4 8
6 7
0

Sample Output
2

******************************************/
