#include<stdio.h>

int main(void)
{
    int num1, i, j, sum;
    double stucnt, num2;

    scanf("%d", &num1);

    for(i=0;i<num1;i++)
    {
        int grade[1000]={0};
        sum=0;
        stucnt=0;

        scanf("%lf", &num2);

        for(j=0;j<num2;j++)
        {
            scanf("%d", &grade[j]);
            sum+=grade[j];
        }

        for(j=0;j<num2;j++)
        {
            if(grade[j]>(sum/num2)) stucnt++;
        }

        printf("%.3lf%%\n", stucnt*100/num2);
    }

    return 0;
}


/***************************************************

Problem Description
據說，90%的大學一年級新生期望他們自己的成績能在全班平均之上，
請你來幫忙驗證看看他們有沒有達成目標。

Input
輸入的第一列有一個整數 C 代表以下有多少組測試資料。每組資料的
第一個整數 N 代表班級總人數 ( 1 <= N <= 1000 )。接下來有N個以空白
或換行來間隔的整數，代表每個學生的期末總成績 ( 0 <= 分數 <= 100 )。

Output
對每組測試資料輸出一列，算出有多少百分比的學生成績比全班平均高，
請四捨五入到小數第三位。

Sample Input
5
5 50 50 70 80 100
7 100 95 90 80 70 60 50
3 70 90 80
3 70 90 81
9 100 99 98 97 96 95 94 93 91

Sample Output
40.000%
57.143%
33.333%
66.667%
55.556%

***************************************************/
