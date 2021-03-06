#include<stdio.h>
#include<math.h>
#define PI 3.141592653589793

int main(void)
{
    double x1, x2, x3, y1, y2, y3;
    double a, b, c, s;

    while(EOF!=scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3))
    {
        a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
        c=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
        s=(a+b+c)/2;

        printf("%.2lf\n", 2*(a*b*c)*PI/(4*sqrt(s*(s-a)*(s-b)*(s-c))));
    }

    return 0;
}

/*********************************************

Problem Description
要計算一個圓的圓週長似乎是相當簡單的事，如果你知道直徑的話。但是如果你不知道直徑呢？

給你不共線的三個點的座標，你的任務是算出通過這三個點的唯一圓的週長是多少。

Input
每組測試資料一列，含有6個實數x1,y1,x2,y2,x3,y3，分別代表三個點的座標（此三個點不共線）。
通過這三個點的唯一圓的直徑不會超過1百萬。

Output
對每一組測試資料，輸出通過這三個點的唯一圓的週長是多少，請輸出到小數點後2位。

圓週率PI的值大約是 3.141592653589793

Sample Input
0.0 -0.5 0.5 0.0 0.0 0.5
0.0 0.0 0.0 1.0 1.0 1.0
5.0 5.0 5.0 7.0 4.0 6.0
0.0 0.0 -1.0 7.0 7.0 7.0
50.0 50.0 50.0 70.0 40.0 60.0
0.0 0.0 10.0 0.0 20.0 1.0
0.0 -500000.0 500000.0 0.0 0.0 500000.0

Sample Output
3.14
4.44
6.28
31.42
62.83
632.24
3141592.65

*********************************************/
