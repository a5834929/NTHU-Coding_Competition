#include<stdio.h>
#include<string.h>

typedef struct gene{
    char order[60];
    int count;
}DNA;

int main(void)
{
    int n, len, num;
    int i, j, k;

    scanf("%d\n\n", &n);

    while(n--)
    {
        int temp;
        DNA dna[110];
        char Temp[60];
        scanf("%d %d", &len, &num);

        for(i=0;i<num;i++) dna[i].count=0;

        for(i=0;i<num;i++) scanf("%s", dna[i].order);

        for(k=0;k<num;k++)
        {
            for(i=0;i<len;i++)
            {
                for(j=i;j<len;j++)
                {
                    if(dna[k].order[i]>dna[k].order[j]) dna[k].count++;
                }
            }
        }

        for(i=0;i<num-1;i++)
        {
            for(j=0;j<num-1-i;j++)
            {
                if(dna[j].count>dna[j+1].count)
                {
                    temp=dna[j+1].count;
                    dna[j+1].count=dna[j].count;
                    dna[j].count=temp;

                    strcpy(Temp, dna[j+1].order);
                    strcpy(dna[j+1].order, dna[j].order);
                    strcpy(dna[j].order, Temp);
                }
            }
        }

        for(i=0;i<num;i++) printf("%s\n", dna[i].order);

        if(n) printf("\n");
    }

    return 0;
}

/**********************************************************

Problem Description
�b�@�Ӧr�ꤤ�A�u���Ƨǡv���{�׬O�H�U�r�����������j�p���Y�ӭp�⪺�C
�Ҧp�b�r�� DAABEC���A�u���Ƨǡv���{�׬� 5�A�]��D�񥦥k�䪺4�Ӧr���j�A
E�񥦥k�䪺1�Ӧr���j�C�Ӧr��AACEDGG�u���Ƨǡv���{�׬� 1�]�X�G�O�ֱƧǦn���A
�ߤ@�����Ƨǵo�ͦbE�MD�����^�A�r��ZYXW�u���Ƨǡv���{�׬� 6�]��n�O�����ƧǪ��ۤϡ^�C

�{�b�A�����ȬO���\�h��DNA�r��Ӱ��ƧǡC�C�Ӧr�ꤤ�ȧt��A,C,G�MT�o4�ئr���C
�ƧǪ���h�O�ھڦU�r��u���Ƨǡv���{�סA�Ѥp��j��X�C�b�o�̨C�Ӧr�ꪺ���ק��ۦP�C

Input
��J���Ĥ@�C���@�Ӿ�ƥN��H�U���X�մ��ո�ơC�C�մ��ո�ƪ��Ĥ@�C�t��2�ӥ����
n�]0 < n <= 50�^�M m�]0 < m <= 100�^�An �N��r�ꪺ���סAm �N��r�ꪺ�ƥءC
���U�Ӫ� m �C�A�C�C���@�Ӫ��׬� n ���r��C

�Ĥ@�C�βĤ@�մ��ո�ơA�H�ΦU�մ��ո�ƶ������@�ťզC�C�аѦ�Sample Input�C

Output
��C�մ��ո�ƫ��ӡu���Ƨǡv���{�סA�Ѥp��j��X�U�r��C���p�����u2�Ӧr��u���Ƨǡv
���{�׬ۦP�A�h���ӥ��̦b��J�������ǿ�X�C

�U�մ��ո�Ƥ����п�X�@�ťզC�A��X�榡�аѦ�Sample Output�C

Sample Input
2

10 6
AACATGAAGG
TTTTGGCCAA
TTTGGCCAAA
GATCAGATTT
CCCGGGGGGA
ATCGATGCAT

2 3
TC
TT
TA

Sample Output
CCCGGGGGGA
AACATGAAGG
GATCAGATTT
ATCGATGCAT
TTTTGGCCAA
TTTGGCCAAA

TT
TC
TA

**********************************************************/
