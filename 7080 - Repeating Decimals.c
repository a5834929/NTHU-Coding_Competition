#include<stdio.h>

int main(void)
{
    int numer, denom, remain, quot, record1, record2;
    int i, j, count, cycle, cyclen, nondec;

    while(EOF!=scanf("%d %d", &numer, &denom))
    {
        int dec[10000]={0}, repeat[10000]={0}, countRemain[10000]={0};
        i=0;
        cycle=0;
        quot=numer/denom;
        remain=numer%denom;
        record1=quot;
        record2=numer;

        while(!cycle)
        {
            if(repeat[remain])
            {
                count=countRemain[remain];
                cyclen=i-count;
                cycle=1;
            }

            else
            {
                repeat[remain]=1;
                countRemain[remain]=i;
            }

            numer=remain*10;
            quot=numer/denom;
            remain=numer%denom;
            dec[i]=quot;
            i++;
        }

        printf("%d/%d = %d.", record2, denom, record1);

        nondec=(count>50)?50:count;
        for(j=0;j<nondec;j++) printf("%d", dec[j]);

        if(cyclen<50)
        {
            printf("(");
            for(j=count;j<(((i-1)<50)?(i-1):50);j++) printf("%d", dec[j]);
            printf(")");
        }

        else
        {
            printf("(");
            for(j=0;j<50;j++) printf("%d", dec[j]);
            printf("...)");
        }

        printf("\n");
        printf("   %d = number of digits in repeating cycle\n", cyclen);
        printf("\n");
    }

    return 0;
}

/**********************************************

Problem Description
1/33=0.030303030303�K���@�Ӵ`���p�ơA�b�o��03�o2�ӼƦr�|�û��`���U�h(cycle length=2)�C

�g�@�ӵ{����J���ƪ����l�M�����M���X��Q�i��p�ƪ�ܪk���`���`�C
�b���ڭ̩w�q�`���`���̥��X�{���̤p���ת����_�� �ƼƦr��C�ҥH�A
1/250=0.04000000�K���`���`���]0�^�A��cycle length=1�C655/990=0.6616161616161616161�K���`���`���]61�^�A
��cycle length=2�C

Input
�C�մ��ո�Ƥ@�C�A�]�t��2�Ӽ�x,y�A���O�N����l�M�����Cx���D�t��ơAy������ơA�Bx,y<=3000

Output
��C�@�մ��ո�ơA��X��Q�i�쪺��ܪk�δ`���`�����סC�H���N�`���`��ܥX�ӡC
�p�G�`���`���פj��50�A�h�u�n��X�e50�ӡA�᭱��...��ܧY�i�C�C�մ��ո�ƫ�п�X�@�ťզC�C
�ԲӮ榡�аѦ�Sample Output�C

Sample Input
76 25
5 43
1 397
1 1
0 558

Sample Output
76/25 = 3.04(0)
   1 = number of digits in repeating cycle

5/43 = 0.(116279069767441860465)
   21 = number of digits in repeating cycle

1/397 = 0.(00251889168765743073047858942065491183879093198992...)
   99 = number of digits in repeating cycle

1/1 = 1.(0)
   1 = number of digits in repeating cycle

0/558 = 0.(0)
   1 = number of digits in repeating cycle

**********************************************/
