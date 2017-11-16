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
�ڻ��A90%���j�Ǥ@�~�ŷs�ʹ���L�̦ۤv�����Z��b���Z�������W�A
�ЧA���������ҬݬݥL�̦��S���F���ؼСC

Input
��J���Ĥ@�C���@�Ӿ�� C �N��H�U���h�ֲմ��ո�ơC�C�ո�ƪ�
�Ĥ@�Ӿ�� N �N��Z���`�H�� ( 1 <= N <= 1000 )�C���U�Ӧ�N�ӥH�ť�
�δ���Ӷ��j����ơA�N��C�Ӿǥͪ������`���Z ( 0 <= ���� <= 100 )�C

Output
��C�մ��ո�ƿ�X�@�C�A��X���h�֦ʤ��񪺾ǥͦ��Z����Z�������A
�Х|�ˤ��J��p�ƲĤT��C

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
