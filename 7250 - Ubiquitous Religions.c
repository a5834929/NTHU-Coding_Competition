#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int set[50001];
void Union(int a, int b);
int find(int x);

int main(void)
{
    int n ,m, i, j, x, y, sum;

    j=0;
    while(scanf("%d %d", &n, &m)!=EOF && !(m==0 && n==0))
    {
        sum=0;
        memset(set, 0, sizeof(set));
        for(i=1;i<=n;i++)
            set[i]=i;

        for(i=0;i<m;i++)
        {
            scanf("%d %d", &x, &y);
            if(set[x]!=set[y])
                Union(x, y);
        }

        for(i=1;i<=n;i++)
            if(set[i]==i)
                sum++;

        printf("Case %d: %d\n", j+1, sum);
        j++;
    }

    return 0;
}

void Union(int a, int b)
{
    set[find(b)]=find(set[a]);
    return;
}

int find(int x)
{
    if(set[x]==x)
        return x;
    else
        return set[x]=find(set[x]);
}

/**************************************************

Problem Description
這個世界上有許多不同的宗教信仰。
你想要知道你就讀的大學中，學生們到底信了多少種不同的宗教。

在你就讀的大學中共有 n 個學生 ( 0 < n <= 50000 )。
顯然你不可能對每個人個別詢問他們的信仰，而且某些學生也不方便
透露他們所信的宗教。而解決這些問題的一種可能的方法是詢問 m
( 0 <= m <= n(n-1)/2 )對學生他們是否信同一個宗教
(例如他們可能一起去某間教堂，會知道他們彼此信相同的宗教 )。
由這些資料，即使你沒辦法知道每個人信哪個教，但是你可以估計出
他們最多信了多少種不同的宗教。你可以假設每個學生最多信一個宗教。

Input
輸入中包含了許多的測試資料。每筆測試資料由一列包含兩個整數 n
及 m 作為開頭。接下來的 m 列每列包含了兩個整數 i 和 j，代表
學生 i 和學生 j 信同一個宗教。這些學生編號為 1 到 n。

當 n = m = 0 的時候代表輸入結束。

Output
對於每筆測試資料，請先輸出測試資料的編號(由1開始)，
然後輸出學生們最多信了多少種不同的宗教。

Sample Input
10 9
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
10 4
2 3
4 5
4 8
5 8
0 0

Sample Output
Case 1: 1
Case 2: 7

***************************************************/
