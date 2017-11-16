#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*p, const void*q);

int main(void)
{
    int level[10010];
    int n, m, i, j;
    int A, C, G, T;
    char dna[1000];

    scanf("%d %d", &n, &m);
    while(1)
    {
        memset(level, 0, sizeof(level));
        A=C=G=T=0;
        for(i=0;i<m;i++)
        {
            scanf("%s", dna);
            for(j=0;j<n;j++)
            {
                if(dna[j]=='A') A++;
                else if(dna[j]=='C') C++;
                else if(dna[j]=='G') G++;
                else if(dna[j]=='T') T++;
            }

            for(j=0;j<n;j++)
            {
                if(dna[j]=='A') A--;
                else if(dna[j]=='C')
                {
                    C--;
                    level[i]+=A;
                }
                else if(dna[j]=='G')
                {
                    G--;
                    level[i]=level[i]+A+C;
                }
                else if(dna[j]=='T')
                {
                    T--;
                    level[i]=level[i]+A+C+G;
                }
            }
        }

        qsort(level, m, sizeof(int), cmp);

        for(i=0;i<m;i++)
            printf("%d\n", level[i]);

        if(scanf("%d %d", &n, &m)!=EOF)
            printf("\n");
        else
            break;
    }

    return 0;
}

int cmp(const void*p, const void*q)
{
    int a=*(int*)p, b=*(int*)q;
    if(a!=b) return (a<b)?-1:1;
    return 0;
}

/************************************************

Problem Description
�b�@�Ӧr�ꤤ�A�u���Ƨǡv���{�׬O�H�U�r�����������j�p���Y�ӭp�⪺�C
�Ҧp�b�r�� DAABEC���A�u���Ƨǡv���{�׬� 5�A�]��D�񥦥k�䪺4�Ӧr���j�A
E�񥦥k�䪺1�Ӧr���j�C�Ӧr��AACEDGG�u���Ƨǡv���{�׬� 1�]�X�G�O�ֱƧǦn���A
�ߤ@�����Ƨǵo�ͦbE�MD�����^�A�r��ZYXW�u���Ƨǡv���{�׬� 6�]��n�O�����ƧǪ��ۤϡ^�C
�{�b�A�����ȬO���\�h��DNA�r��Ӱ��ƧǡC�C�Ӧr�ꤤ�ȧt��A,C,G�MT�o4�ئr���C
�ƧǪ���h�O�ھڦU�r��u���Ƨǡv���{�סA�Ѥp��j��X�C�b�o�̨C�Ӧr�ꪺ���ק��ۦP�C

Input
�h�մ���C�C�մ��ո�ƪ��Ĥ@�C�t��2�ӥ���� n�]0 < n <= 600�^�M m�]0 < m <= 10000�^�A
n �N��r�ꪺ���סAm �N��r�ꪺ�ƥءC���U�Ӫ� m �C�A�C�C���@�Ӫ��׬� n ���r��C

Output
��C�մ��ո�ƫ��ӡu���Ƨǡv���{�סA�Ѥp��j��X�C�U�մ��ո�Ƥ����п�X�@�ťզC�C

Sample Input
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
9
10
11
17
36
37

0
1
1

**************************************************/
