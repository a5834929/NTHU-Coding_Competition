#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct p
{
    int X, Y;
}NUM;

NUM cor[100001];

int main(void)
{
    int n, q, x, y, i, flag;
    int left, right, mid;

    while(scanf("%d %d", &n, &q)!=EOF)
    {
        memset(cor, 0, sizeof(NUM));
        for(i=0;i<n;i++)
        {
            scanf("%d %d", &x, &y);
            cor[i].X=x;
            cor[i].Y=y;
        }

        while(q--)
        {
            flag=0;
            scanf("%d %d", &x, &y);

            left=0;
            right=n-1;
            while(left<=right)
            {
                mid=(left+right)/2;
                if(cor[mid].X==x)
                {
                    if(cor[mid].Y==y)
                    {
                        flag=1;
                        break;
                    }
                    else if(cor[mid].Y>y)
                        right=mid-1;
                    else if(cor[mid].Y<y)
                        left=mid+1;
                }
                else if(cor[mid].X>x)
                    right=mid-1;
                else if(cor[mid].X<x)
                    left=mid+1;
            }

            if(flag)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}

/************************************************

Problem Description
給n個由2D 點座標所組成的數列S，點的座標會先依照x 座標(小到大)，再依
照y 座標(小到大)排序。針對每個數列S，會有多個詢問。每個詢問會給予q個
座標，請回答這座標有沒有出現在S 中。

Input
多組測資，每組測資第一行有兩個正整數，n(n<100000)表示座標點的數量，
以及q(q<100000)表示問題數量。接下來n行，每行有兩數字x,y(int範圍)
代表每個點的座標，中間以空白隔開。接下來q行，每行有兩數字x,y(int範圍)
代表一個詢問

Output
對於每個詢問，請輸出這座標有沒有出現在S中。
有請輸出"Yes"，沒有請輸出"No"。

Sample Input
5 3
1 1
2 1
5 1
5 1
5 2
1 1
5 1
6 1

Sample Output
Yes
Yes
No

**************************************************/
