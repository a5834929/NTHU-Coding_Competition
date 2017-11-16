#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
    int num1, num2, i, j;

    scanf("%d", &num1);
    getchar();
    getchar();

    for(i=0;i<num1;i++)
    {
        int index[1000]={0};
        char data[1000][500]={{0}};
        j=0;
        num2=0;

        while(scanf("%d", &index[j++]))
        {
            num2++;
            if((getchar())=='\n') break;
        }

        for(j=0;j<num2;j++) scanf("%s", &data[index[j]-1]);

        for(j=0;j<num2;j++) printf("%s\n", data[j]);

        if(i!=num1-1) printf("\n");
    }

    return 0;
}

/*************************************************

Problem Description
�b�ܦh�q�����D���A�`�`�|��@�Ӱ}�C����ư��@�Ƿh�ʡC
�]�N�O���}�C������ƳQ���s�ƦC�C���@�ӱƦC�}�C��ƪ���k
�O�Υt�@�Ӻ٬����ް}�C�]index array�^�ӧ������C���]x�O�n
�Q���s�ƦC���}�C�A��x'�O���s�ƦC�᪺�}�C�A�������Ӧ��@��
���Y�s�b��x�Mx'�����A�ϱox'i=xpi�A�ӯ��ް}�C�N�O�O���o�����Y�Ϊ��C

���F�קK�~���D�N�A�H�Ĥ@��Sample Input, Sample Output�����G
���ް}�C��3 1 2�A�N���U�Ӫ��B�I�����Ӥ��O��X���3�C�B��1�C�B��2�C�C

Input
��J���Ĥ@�C���@�Ӿ�ơA�N��H�U���X�մ��ո�ơC�C�մ��ո��2�C�A
��1�C�����ް}�C�A�]�t�F 1~n ����ơ]�H�Y�@�رƦC�覡�X�{�^�A
�b�o��n�N�O�}�C����ƪ��ƥءC��2�C�h�]�t�Fn�ӯB�I�ơC���ո�ƶ��Ť@�C�C
�аѦ�Sample Input

Output
��C�@�մ��ո�Ʈھگ��ް}�C�����ǿ�X�B�I�ơA�C�@�ӯB�I�Ƥ@�C�A
�B�B�I�ƪ��˦������M��J���@�ˡC���ո�ƶ���ЪŤ@�C�C

Sample Input
2

3 1 2
32.0 54.7 -2

3 2 1
32.0 54.7 -2

Sample Output
54.7
-2
32.0

-2
54.7
32.0

************************************************/
