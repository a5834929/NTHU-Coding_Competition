#include<stdio.h>

int main(void)
{
    int num, count=0;
    double initTemp, diff;

    scanf("%d", &num);

    while(count<num)
    {
        scanf("%lf %lf", &initTemp, &diff);
        printf("Case %d: %.2lf\n", count+1, initTemp+diff*5/9);
        count++;
    }
    return 0;
}

/******************************************

Problem Description
�b��ǹ��窺�L�{���A�q���ū׻P�Ůt�O�ܱ`�����u�@�A
���L�]�����ؤ�(��F)�P���(��C)��ر`�����ūת�ܪk�A
�ҥH���ɭԷ|���I�·СC��̪��ഫ�����p�U�G

F=(5/9)*C+32

���D�|���w�H����ܪ���l�ū�C�A�P�H�ؤ��ܪ��ŮtF�A
�ЧA�H���ūת�ܷs���ū׬���C

Input
��J�Ĥ@�C���@�Ӿ�� T (<= 100)��ܴ�����ƪ��ռơC
�C�ո�Ʀ���Ӿ�� C �P d ( 0 <= C, d <= 100)�AC��ܪ�l�ū�
(�H���ūת��)�Ad��ܷŮt(�H�ؤ�ūת��)�C

Output
�ХH���ū׬�����X�s���ū׬���A�п�X��p���I����C

Sample Input
2
100 0
0 100

Sample Output
Case 1: 100.00
Case 2: 55.56

******************************************/
