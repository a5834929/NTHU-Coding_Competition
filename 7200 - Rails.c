#include<stdio.h>

int main(void)
{
    int n, i, j, flag;

    while(scanf("%d", &n)!=EOF && n!=0)
    {
        int input[1001]={0};

        while(scanf("%d", &input[0]) && input[0])
        {
            int train[1001]={0};

            for(i=1;i<n;i++) scanf("%d", &input[i]);

            flag=1;

            while(1)
            {
                for(i=0;i<n;i++)
                {
                    train[input[i]]=1;
                    j=input[i];
                    if(input[i]<input[i-1])
                    {
                        for(;j<=input[i-1];j++)
                        {
                            if(train[j]==0)
                            {
                                flag=0;
                                break;
                            }
                        }
                        if(!flag) break;
                    }
                }
                break;
            }
            if(!flag) printf("No\n");
            else printf("Yes\n");
        }
        printf("\n");
    }

    return 0;
}

/***************************************************

Problem Description
�b�@�ӥs�u���|���v�����������@�Ӧ��W���������C�ѩ�a�έ���H�θg�O�����Y�C

�{�b�����qA��V�ӡA�w�w�qB��V���}�C�����@��N�`���[�]N <=1000�^�A
�åB�U���[�̦��H1��N�ӽs���C�A�i�H���]�U���[�b�i�����e�i�H��W�P��L���[�����A
�]�i�H��W���}�����쩹B��V���K�y�W�C�A�]�i�H���]�b����ɶ����������i�H�e�ǩҦ������[�C
���O�@���@�`���[�i����A�N����A�^��A��V���K�y�W�F�A�åB�@�����}������B��V��A�]����A�^�쨮���C

�{�b�A�����ȬO�g�@�ӵ{���A�P�_������_�H�@�S�w���ƦC�覡�bB��V���K�y�W�C

Input
��J�t���h�մ��ո�ơC�C�մ��ո�ƪ��Ĥ@�C�A��1�Ӿ��N�A��N�q�p�W�ҭz�C
��󦹲մ��ո�Ʊ��U�Ӧ�0��h�Ӥ��������աA�C�Ӵ��դ@�C�A�C�C��N�Ӿ�ơA
���e��1,2,......,N�����N�ƦC�C��J��ȧt���@��0���@�C�A�N��Ӳմ��ո�Ƶ����C

N=0�N���J�����A�аѦ�Sample Input�C

Output
��C�@�մ��ո�ƪ��C�Ӵ��աA��X��1,2,......,N�����N�ƦC�O�_�i��C
�p�G�i��A�п�Xyes�A�Y���i��h��XNo�C

�C�մ��ո�ƫ��ЪŤ@�C�C�аѦ�Sample Output�C

Sample Input
5
1 2 3 4 5
5 4 3 2 1
5 4 1 2 3
0
7
4 5 3 7 6 2 1
0
0

Sample Output
Yes
Yes
No

Yes

****************************************************/
