#include<stdio.h>

int main(void)
{
    int num, rela, i, j, k, temp;

    scanf("%d", &num);

    for(i=0;i<num;i++)
    {
        int door[1000]={0}, door_max=0;
        int dist_sum=0, dist;

        scanf("%d", &rela);

        for(j=0;j<rela;j++)
        {
            scanf("%d", &door[j]);
            door_max=(door[j]>door_max)?door[j]:door_max;
        }

        for(j=rela-1;j>0;j--)
        {
            for(k=0;k<j;k++)
            {
                if(door[k]>door[k+1])
                {
                    temp=door[k];
                    door[k]=door[k+1];
                    door[k+1]=temp;
                }
            }
        }

        if(rela%2==1)
        {
            if(rela==1) printf("1\n");

            else
            {
                for(j=0;j<rela;j++)
                {
                    if(door[j]>door[rela/2]) dist=door[j]-door[rela/2];
                    else dist=door[rela/2]-door[j];
                    dist_sum+=dist;
                }
                printf("%d\n", dist_sum);
            }
        }

        else
        {
            for(j=0;j<rela;j++)
            {
                if(door[j]>door[(rela/2)-1]) dist=door[j]-door[(rela/2)-1];
                else dist=door[(rela/2)-1]-door[j];
                dist_sum+=dist;
            }
            printf("%d\n", dist_sum);
        }
    }

    return 0;
}

/***************************************************

Problem Description
�@�ɻD�W���ª��|�ѤjVito Deadstone�n�h��ì��ӤF�C
�b���̥L���@�Ӥj�a�ڡA�åB�L�̳���bLamafia�j�D�W�C
�]��Vito�ɱ`�n���X�Ҧ����˱��A�L�Q�n��@�����L�̳̪񪺩Фl�A
�]�N�O���L�Ʊ�q�L���a��Ҧ����˱����a���Z�����M���̤p�C

�L���~�A�g�@�ӵ{�������U���U�L�ѨM�o�Ӱ��D�C

Input
��J���Ĥ@�C���@�Ӿ�ƥN��H�U���h�ֲմ��ո�ơC

�C�մ��ո�Ƥ@�C�A�Ĥ@�Ӿ�� r�]0 < r < 500�^�A�N��L�˱����ƥءC
���U�Ӫ�r�Ӿ��s1,s2,......sr���o�ǿ˱��Фl�����P���X�]0 < si <30000�^�C
�`�N�G���ǿ˱������P���X�|�ۦP�C

Output
��C�@�մ��ո�ơA��X�q�L���s�a��Ҧ����˱����a���Z�����M���̤p���h�֡C
2�Ӫ��P���Xsi�Bsj���Z����si-sj������ȡC

Sample Input
3
2 2 4
3 2 4 6
4 2 1 999 5

Sample Output
2
4
1001

****************************************************/
