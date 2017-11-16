#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    int adj[120][120], indeg[120], queue[120];
    int i, front, rear;
    int n, m, first, next;

	while(scanf("%d %d", &n, &m)!=EOF && !(n==0 && m==0))
	{
	    memset(adj, 0, sizeof(adj));
	    memset(indeg, 0, sizeof(indeg));
	    memset(queue, 0, sizeof(queue));
	    front=0;
	    rear=0;
	    for(i=0;i<m;i++)
	    {
	        scanf("%d %d", &first, &next);
	        indeg[next]++;
	        adj[first][next]=1;
	    }

	    for(i=1;i<=n;i++)
        {
            if(!indeg[i])
            {
                queue[rear]=i;
                rear++;
            }
        }

        while(front<rear)
        {
            for(i=1;i<=n;i++)
            {
                if(adj[queue[front]][i])
                {
                    indeg[i]--;
                    if(!indeg[i])
                    {
                        queue[rear]=i;
                        rear++;
                    }
                }
            }
            front++;
        }

        for(i=0;i<rear-1;i++)
            printf("%d ", queue[i]);
        printf("%d\n", queue[i]);
	}
    return 0;
}

/**************************************************

Problem Description
John有 n 件事情要做，不幸的是這些事情並不是各自獨立的，而是有相依性的。
換句話說可能有某件事情一定要在另一件事情做完之後才能做。

Input
每組測試資料可能有好幾列。第一列有2個整數 n,m。（1 <= n <= 100）
n代表共有幾件事情要做（編號從 1 到 n），m 代表事情之間有幾個相依關係存在。
接下來的m列每列有2個整數 i 和 j。代表 i 這件事情一定要在 j 這件事前被執行。

n=m=0時代表輸入結束。

Output
對每組測試資料，請輸出n個整數，代表事情被執行的順序。

註：答案可能不是唯一解

Sample Input
5 4
1 2
2 3
1 3
1 5
0 0

Sample Output
1 4 2 5 3

*************************************************/
