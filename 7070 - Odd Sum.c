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
���A�@�ӽd�� a �� b �A�ЧA��X a �P b �����Ҧ��_�ƪ��M�C

�Ҧp�G�d�� [3, 9] ���Ҧ��_�ƪ��M�N�O 3 + 5 + 7 + 9 = 24 �C

Input
��J���Ĥ@�C���@�Ӿ�� T �]1��T��100�^�A�N��H�U���h�ֲմ��ո�ơC
�C�մ��ո�Ƭ���C�A�]�t��Ӽ� a �P b �]0��a��b��100�^�C

Output
�C�մ��ո�ƿ�X�@�C�A���e�� a �� b ���Ҧ��_�ƪ��M�C

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
