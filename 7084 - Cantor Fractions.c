#include<stdio.h>
#include<math.h>

int main(void)
{
    long long int num, group, count;

    while(EOF!=scanf("%lld", &num))
    {
        group=ceil((sqrt(1+8*num)-1)/2);

        count=num-(group)*(group-1)/2;

        printf("%lld/%lld\n", group+1-count, count);
    }

    return 0;
}

/*********************************************

Problem Description
在19世紀末,德國數學家 George Cantor 爭論說正分數Q+的集合和正整數N的集合相等,
指他們都是無限,而且一樣大. 為了證明這事實,他找出存在於N到 Q+間的對映關係.
這對映是要利用一個 N x N 平面的遊走去證實:

Cantor 對映如下(PS: 1對映1/1,2對映2/1,3對映1/2.....如圖):

寫出一個程式找出第 i 個Cantor fraction如上面的對映關係.

Input
這輸入由許多行正整數所組成.

Output
輸出由每一行輸入所產生,它表示第 i 個分數,以著分子和分母由(/)做分割.這分數不用被化簡到最簡形式.

Sample Input
6
100
999
123456
654321

Sample Output
1/3
6/9
37/9
298/200
620/525

******************************************/
