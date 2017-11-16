#include<stdio.h>
void DFS(int);

int map[6][6]={{0,0,0,0,0,0},
               {0,0,1,1,0,1},
               {0,1,0,1,0,1},
               {0,1,1,0,1,1},
               {0,0,0,1,0,1},
               {0,1,1,1,1,0}};
int path[10]={0}, len=0;

int main(void)
{
    DFS(1);
    return 0;
}

void DFS(int start)
{
    int i;
    path[len++]=start;

    if(len==9)
    {
        for(i=0;i<len;i++) printf("%d", path[i]);
        printf("\n");
        len--;
        return;
    }

    for(i=1;i<=5;i++)
    {
        if(map[start][i]==1)
        {
            map[start][i]=map[i][start]=0;
            DFS(i);
            map[start][i]=map[i][start]=1;
        }
    }
    len--;
}


/***************************************************

Problem Description
�����D�A�̤p�ɭԦ��S�����L�@���e�A�e�t�ϦѤH���Фl���C���C
�e�X�Ӫ��ϴN���U���o�ˡG

�g�L�o��h�~�F�A�{�b�ڭ̷Q�n�g�@�ӵ{���Ӫ��D�p�G�ڭ̱q���U��
�}�l�e�_�A�@���h�ֺؤ@���e�t�ϦѤH�Фl����k�C�U�����Ϥ���5���I
��1��5�ӽs���]�q�s��1�}�l�e�_�^�A�b�Y�N��@���e�ɵ������|�C
�o�ӨҤl�������|���G153125432

Input
No input

Output
��Ҧ��i�઺�e�k���ӼƦr�j�p�Ѥp��j�ƦC�n�C

Sample Output
123153452
123154352
...
...
...
154352312

****************************************************/
