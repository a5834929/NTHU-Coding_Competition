#include<stdio.h>

int main(void)
{
    int num, height, freq;
    int cnt1,cnt2,cnt3,cnt4;

    scanf("%d", &num);

    for(cnt1=0;cnt1<num;cnt1++)
    {
        scanf("%d %d", &height, &freq);

        for(cnt2=0;cnt2<freq;cnt2++)
        {
            for(cnt3=0;cnt3<height;cnt3++)
            {
                for(cnt4=0;cnt4<cnt3+1;cnt4++)
                {
                    printf("%d", cnt3+1);
                }
                printf("\n");
            }

            for(cnt3=height;cnt3>1;cnt3--)
            {
                for(cnt4=0;cnt4<cnt3-1;cnt4++)
                {
                    printf("%d", cnt3-1);
                }
                printf("\n");
            }
            if(cnt2<freq-1) printf("\n");
        }
        if(cnt1<num-1) printf("\n");
    }
    return 0;
}

/************************************************

Problem Description
�b�o�Ӱ��D���A�ھکҵ������T(Amplitude)���W�v(Frequency)�A
�A���{���n���ͳo�˪��i�C

Input
��J���Ĥ@�C���@�Ӿ��n�A�N���X�մ��ո�ơC���U�ӨC�մ��ո�Ʀ�2�C�A
�U��1�ӥ���ơ]A�BF�^�AA�N���T�]A<=9�^�AF�N���W�v�C

�Ĥ@�C�H�ΦU�մ��ո�ƶ��Ҧ��@�ťզ�C�аѦ�Sample input�C

Output
�C�մ��ո�ƽп�XF�Ӫi�A�C�Ӫi���T���������׬�A�C�i�����O�H��"����"��
���e�Ҳզ��C�C�Ӫi�����H�@�ťզ���j�}�ӡC

���ո�ƶ��]�H�@�ťզ���}�C

�аѦ�sample output�C

Sample Input
2

3
2

5
3

Sample Output
1
22
333
22
1

1
22
333
22
1

1
22
333
4444
55555
4444
333
22
1

1
22
333
4444
55555
4444
333
22
1

1
22
333
4444
55555
4444
333
22
1
*************************************************/
