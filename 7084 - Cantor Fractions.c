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
�b19�@����,�w��ƾǮa George Cantor ���׻�������Q+�����X�M�����N�����X�۵�,
���L�̳��O�L��,�ӥB�@�ˤj. ���F�ҩ��o�ƹ�,�L��X�s�b��N�� Q+������M���Y.
�o��M�O�n�Q�Τ@�� N x N �������C���h�ҹ�:

Cantor ��M�p�U(PS: 1��M1/1,2��M2/1,3��M1/2.....�p��):

�g�X�@�ӵ{����X�� i ��Cantor fraction�p�W������M���Y.

Input
�o��J�ѳ\�h�楿��ƩҲզ�.

Output
��X�ѨC�@���J�Ҳ���,����ܲ� i �Ӥ���,�H�ۤ��l�M������(/)������.�o���Ƥ��γQ��²���²�Φ�.

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
