#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int find(int x);
void Union(int a, int b);

int set[30010];
int sum[30010];

int main(void)
{
    int n, N, M;
    int i, a, b, ans;

    scanf("%d", &n);

    while(n--)
    {
        scanf("%d %d", &N, &M);
        for(i=1;i<=N;i++)
        {
            set[i]=i;
            sum[i]=1;
        }

        for(i=1;i<=M;i++)
        {
            scanf("%d %d", &a, &b);

            if(set[a]!=set[b])
                Union(a, b);
        }

        ans=0;
        for(i=1;i<=N;i++)
            if(sum[i]>ans)
                ans=sum[i];

        printf("%d\n", ans);

    }
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
    int x, y;
    x=find(set[a]);
    y=find(b);

    if(x!=y)
    {
        set[y]=x;
        sum[x]+=sum[y];
        sum[y]=0;
    }
    return;
}

/**********************************************************

Problem Description
有一個鎮有N個居民。當然其中有許多人是朋友的關係。
根據有名的諺語：「我朋友的朋友也是我的朋友」，
所以如果A和B是朋友，B和C是朋友，那麼A和C也是朋友。

你的任務是算出在這個鎮中最大的朋友集團為多少人。

Input
輸入的第一列有一個正整數，代表以下有多少組測試資料。

每組測試資料的第一列有2個正整數 N 和 M 。
N代表鎮上居民的數目（1 <= N <= 30000 ），
M 代表這些居民中朋友關係的數目（ 0 <= M <= 500000）。
接下來的M列每列有2個整數A，B（ 1 <= A,B <= N , A不等於B），
代表A，B為朋友關係。這M列中可能有的會重複出現。

請參考 Sample Input。

Output
對每組測試資料輸出一列，在這個鎮中最大的朋友集團為多少人。

Sample Input
2
3 2
1 2
2 3
10 12
1 2
3 1
3 4
5 4
3 5
4 6
5 2
2 1
7 10
1 2
9 10
8 9

Sample Output
3
6
***********************************************************/
