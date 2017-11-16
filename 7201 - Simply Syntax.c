#include<stdio.h>
#include<string.h>

int main(void)
{
    char str[300];
    int i, count;

    while(scanf("%s", str)!=EOF)
    {
        count=0;
        for(i=strlen(str)-1;i>=0;i--)
        {
            if(str[i]>='p' && str[i]<='z') count++;

            else if(str[i]=='C' || str[i]=='D' || str[i]=='E' || str[i]=='I')
            {
                if(count>=2) --count;
                else
                {
                    count=0;
                    break;
                }
            }
            else if(str[i]=='N')
            {
                if(count==0) break;
            }
            else
            {
                count=0;
                break;
            }
        }

        if(count==1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

/********************************************************************

Problem Description
�b Hedonia �q�W���x��y���O Hedonian �y�C���� Hedonian �y���Ǳб�
�o�{�o���\�h�ǥͨå��˩��� Hedonian �y���y�k�W�h�C�o��b�O���ФF
�q���ǥͪ��y�k���~�A�ҥH�o�M�w�n�o���ǥ̼ͭg�ӵ{���A����ˬd�X
�L�̼g���y�l�����y�k���~�C�N�� Hedonian �H���ѩʤ@�ˡAHedonian �y
����k�W�h�]�۷��¡A�W�h�p�U�G

0.�o�ӻy�����Ȧ� p �� z�A�٦� N�AC�AD�AE�AI �o�X�Ӧr���C
1.�q p �� z ���A����@�Ӧr�����O�@�ӥ��T���y�l�C
2.�p�G s �O�@�ӥ��T���y�l�A���� Ns �]�O�C
3.�p�G s �� t ���O���T���y�l�A���� Cst, Dst, Est �٦� Ist �]���O���T���y�l�C
4.0. �� 3. �O�ˬd�@�ӥy�l�O�_�X�G�y�k�Ȧ����W�h�C

�A�Q�n�D�g�{���ˬd�@�ӥy�l�O�_�����W�z���W�h 0. �� 4.�C

Input
��J���t���\�h�y�l�A�C�ӥy�l�@�C�A���u�t�� p �� z �٦� N, C, D, E, I�o�X�Ӧr���C
�A�i�H���]�C�ӥy�l�ܦh�� 256 �Ӧr���A�ܤ� 1 �Ӧr���C

Output
���@�Ӯ榡���T���y�l��X YES�A���@�ӿ��~���y�l�h��X NO�C

Sample Input
Cp
Isz
NIsz
Cqpq
IzIst
IIszz
IIszIsz
IIszIIIszzIsz
NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNCst
zN
zzI
st
z

Sample Output
NO
YES
YES
NO
YES
YES
YES
YES
YES
NO
NO
NO
YES

*********************************************************************/
