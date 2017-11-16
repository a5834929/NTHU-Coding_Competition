#include<stdio.h>

int main(void)
{
    int numer, denom, temp;
    int i, count;
    int table[10000]={0};

    while(EOF!=scanf("%d %d", &numer, &denom))
    {
        count=0;

        for(i=0;denom>0;i++)
        {
            table[i]=numer/denom;
            temp=denom;
            denom=numer-table[i]*temp;
            numer=temp;
            count++;
        }

        printf("[%d;", table[0]);

        for(i=1;i<count;i++)
        {
            printf("%d", table[i]);

            if(i!=count-1) printf(",");
        }

        printf("]");
        printf("\n");
    }

    return 0;
}

/****************************************************

Problem Description
�Ob0, b1, b2, ......, bn���@��ƧǦC�A�䤤b0�j�󵥩�0�A��L�ƬҤj��0�C�ڭ̩w�qn���h���s����Ƭ��G

�H²�g [b0; b1, b2, ......, bn]�Ӫ�ܡC�|�һ����G��n=3���s����ƪ�²�g [2;3,1,4] ��ܥH�U�����l�G

�g�@�ӵ{��Ū�J�̫᪺���ƪ����l�Τ����A��X���s����ƪ�²�g�C���F�T�O�ߤ@�ʡAbn > 1�C

Input
�C�մ��ո�Ƥ@�C�A��2�Ӿ��a,b�A���O�N����ƪ����l�Τ����]a,b > 0�^�C

Output
��C�մ��ո�ơA�п�X�������s����ƪ�²�g�C

Sample Input
43 19
1 2

Sample Output
[2;3,1,4]
[0;2]

****************************************************/

