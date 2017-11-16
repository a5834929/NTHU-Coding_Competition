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
�T���Ϊ����ߨ�T��|���Z���C�{�b���A�T���Ϊ��T�Ӯy�СA
�A�i�H��X�o�ӤT���Ϊ����߮y�ж�?

Input
���h�մ���A�C�մ���|�����Ӿ��(��Ƶ���Ȥp��10000)�A
���@�դ��O�N��T���ΤT���I��(x, y)�y�СC
���|�������I�@�I�ΤT�I�@�u�����p

Output
���C�մ����X�T���Τ��߮y��(��p���I��T��)

Sample Input
0 0 10 0 0 10
-10 -10 10 10 10 -10
123 456 789 987 654 321

Sample Output
2.929 2.929
4.142 -4.142
516.028 540.619

Hint
�p�G�y��a, b, c���O�����쪺����OA, B, C
���߮y��I = (A*a + B*b + C*c) / (A+B+C)

**************************************************/
