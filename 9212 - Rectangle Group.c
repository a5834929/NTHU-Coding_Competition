#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int find(int x);
void Union(int a, int b);

typedef struct s
{
    int lx, ly;
    int rx, ry;
}S;

S rec[1100];
int set[1100], sum[1100];

int main(void)
{
    int i, j, n, flag, ans;

    while(scanf("%d", &n)!=EOF && n!=0)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d %d %d %d", &rec[i].lx, &rec[i].ly, &rec[i].rx, &rec[i].ry);
            set[i]=i;
            sum[i]=1;
        }

        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                flag=1;
                if(rec[i].lx>rec[j].rx)
                    flag=0;
                else if(rec[i].rx<rec[j].lx)
                    flag=0;
                else if(rec[i].ly>rec[j].ry)
                    flag=0;
                else if(rec[i].ry<rec[j].ly)
                    flag=0;

                if(flag)
                    Union(i, j);
            }
        }

        ans=0;
        for(i=1;i<=n;i++)
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


/******************************************************

Problem Description
There are some rectangles in 2 dimensional space. We define some relations:

(1) Intersect: Choose any 2 rectangles A and B.
They intersect each other if and only if there exists at least one point
that can cover by the 2 rectangles. If A and B intersect, they are in the same group.

(2) Transitivity: Choose any 3 rectangles A, B, C.
If A intersect B and B intersect C, we denote that A, B, C are in the same group.

Given the rectangles in the 2D space, please find the size of the maximum rectangle group.

Input
There are more than one cases in the input.
Each case contains N rectangles in the first line of the case.
In the next n lines, each line contains 4 integers: lx, ly, rx, ry.
(0 <= lx, ly, rx, ry <= 1000)

lx, ly denote the left-bottom coordinate of the rectangle.

rx, ry denote the right-top coordinate of the rectangle.

Input ends with N = 0.

9212 O(N!*N) can pass this input, N <= 10
9213 O(N3) can pass this input, N <= 100
9214 O(N2) can pass this input, N <= 1000
9215 O(N2) can pass this input, N <= 1000

Output
For each test case, output the number of maximum group in one line.

Sample Input
2
1 1 3 3
2 2 4 4
4
0 0 1 2
1 2 3 3
2 0 3 1
2 2 4 4
0

Sample Output
2
3

********************************************************/
