#include<stdio.h>
#include<stdlib.h>
int cmp(const void*p, const void*q);

typedef struct a
{
    char ID[20];
    double time;
}stu;

stu rank[100000];

int main(void)
{
    int n, i;

    while(scanf("%d", &n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s", rank[i].ID);
            scanf("%lf", &rank[i].time);
        }

        qsort(rank, n, sizeof(rank[0]), cmp);

        for(i=0;i<n;i++) printf("%d %s %.3lf\n", i+1, rank[i].ID, rank[i].time);

    }

    return 0;

}

int cmp(const void*p, const void*q)
{
    stu a=*(stu*)p, b=*(stu*)q;
    if(a.time!=b.time)
        return (a.time<b.time)?-1:1;
    return 0;
}


/*****************************************************

Problem Description
NTHU OJ 第1000 題的題目是 A+B，題目是請大家輸出A+B 的值，這題因為很
簡單，所以有很多人去做。不過Alan 最近在改judge 網頁，不小心把Rank List
的網頁改爛了，所以現在網頁的Rank List 沒有依照程式執行速度排序，你可以
幫Alan 寫個排序，把Rank List 重新改好嗎?

Input
多組測資，每組測資第⼀行有個整數n(n<100000)表示解題人數，接下來n 行每
行代表1個解題者的資訊，第一個字串是User ID(長度<20 的大小寫英文字母與
數字)，第二個字串是CPU Time(正浮點數，到小數後第三位)。

Output
對於每組測資請依照CPU Time 排序，輸出名次(從1 開始排)、User ID、CPU
Time(輸出到小數點後三位)，中間以空白隔開；如果CPU Time 相同，先出現的要排前面

Sample Input
5
BlackMouth 0.008
Team1 0.000
LeiCha 0.004
orz 0.016
kerker 0.004

Sample Output
1 Team1 0.000
2 LeiCha 0.004
3 kerker 0.004
4 BlackMouth 0.008
5 orz 0.016

****************************************************/
