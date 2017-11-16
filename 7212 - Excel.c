#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*p, const void*q);

typedef struct people{
    char team[50];
    double id;
    int prob;
}student;

student s[100000];

int main(void)
{
    int n, i;

    while(scanf("%d", &n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s", s[i].team);
            scanf("%d", &s[i].prob);
            scanf("%lf", &s[i].id);
        }

        qsort(s, n, sizeof(s[0]), cmp);

        for(i=0;i<n;i++)
        {
            printf("%.0lf ", s[i].id);
            printf("%s ", s[i].team);
            printf("%d\n", s[i].prob);
        }
        printf("\n");
    }

    return 0;
}

int cmp(const void*p, const void*q)
{
    student a=*(student*)p, b=*(student*)q;
    if(a.id!=b.id)
        return a.id<b.id ? -1:1;
    return 0;
}

/*************************************************

Problem Description
競技程式期中考考完了，Alan想要把score board整理成同學的成績表。
不過他筆電的excel壞了，讓他沒辦法將成績依照學號排好，你可以幫他排一下嗎?

Input
多組測資，每組測資第一行有個整數n(n<100000)表示參加考試的人數，
接下來n行有一個字串表示同學的Team(字串長度<15),以及非負整數表示
解題數(解題數<20)，以及數字表示學號(學號最多9位，不會有0開頭的學號,
學號不會重複且皆為正整數)

Output
對於每組資料請按照學號由小到大輸出 學號,隊伍名,解題數，中間請以一個空白隔開，每組資料後請多一個換行

Sample Input
5
Team1 2 9862987
Team2 3 9762456
Team3 3 9960321
Team4 5 100062999
Team5 4 100062777

Sample Output
9762456 Team2 3
9862987 Team1 2
9960321 Team3 3
100062777 Team5 4
100062999 Team4 5

*************************************************/
