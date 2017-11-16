#include<stdio.h>

int main(void)
{
    int num, lowLim, uppLim, count=0;

    scanf("%d", &num);

    while(count<num)
    {
        scanf("%d %d", &lowLim, &uppLim);
        if(lowLim%2==0) lowLim=lowLim+1;
        if(uppLim%2==0) uppLim=uppLim-1;
        printf("Case %d: %d\n", count+1, ((lowLim+uppLim)*((uppLim-lowLim)/2+1))/2);
        count++;
    }

    return 0;
}

/***************************************

Problem Description
給你一個範圍 a 到 b ，請你找出 a 與 b 之間所有奇數的和。

例如：範圍 [3, 9] 中所有奇數的和就是 3 + 5 + 7 + 9 = 24 。

Input
輸入的第一列有一個整數 T （1≦T≦100），代表以下有多少組測試資料。
每組測試資料為兩列，包含兩個數 a 與 b （0≦a≦b≦100）。

Output
每組測試資料輸出一列，內容為 a 及 b 間所有奇數的和。

Sample Input
2
1
5
3
5

Sample Output
Case 1: 9
Case 2: 8

**************************************/
