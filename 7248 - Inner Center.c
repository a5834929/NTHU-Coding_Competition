#include<stdio.h>
#include<math.h>

int main(void)
{
    double x1, y1, x2, y2, x3, y3;
    double A, B, C, Ix, Iy;

    while(scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3)!=EOF)
    {
        C=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        A=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
        B=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));

        printf("%.3lf %.3lf\n", (A*x1+B*x2+C*x3)/(A+B+C), (A*y1+B*y2+C*y3)/(A+B+C));
    }

    return 0;
}

/*************************************************

Problem Description
三角形的內心到三邊會等距離。現在給你三角形的三個座標，
你可以算出這個三角形的內心座標嗎?

Input
有多組測資，每組測資會有六個整數(整數絕對值小於10000)，
兩兩一組分別代表三角形三個點的(x, y)座標。
不會有任兩點共點或三點共線的情況

Output
對於每組測資輸出三角形內心座標(到小數點後三位)

Sample Input
0 0 10 0 0 10
-10 -10 10 10 10 -10
123 456 789 987 654 321

Sample Output
2.929 2.929
4.142 -4.142
516.028 540.619

Hint
如果座標a, b, c分別對應到的邊長是A, B, C
內心座標I = (A*a + B*b + C*c) / (A+B+C)

**************************************************/
