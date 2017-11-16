#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int bicolor[1100];
int connected[1100][1100];
void DFS(int c1, int c2, int n);
int flag;

int main(void)
{
    int n, m, a, b;

    while(scanf("%d", &n)!=EOF && n)
    {
        memset(bicolor, -1, sizeof(bicolor));
        memset(connected, 0, sizeof(connected));

        scanf("%d", &m);

        while(m--)
        {
            scanf("%d %d", &a, &b);
            connected[a][b]=1;
            connected[b][a]=1;
        }
        flag=1;
        DFS(0, 1, n);

        if(!flag)
            printf("NOT BICOLORABLE.");
        else
            printf("BICOLORABLE.");
        printf("\n");
    }

    return 0;
}

void DFS(int v1, int color, int n)
{
    int v2;

    bicolor[v1]=color;
    for(v2=0;v2<n;v2++)
    {
        if(connected[v1][v2])
        {
            if(bicolor[v1]!=-1 && bicolor[v2]==color)
            {
                flag=0;
                return;
            }

            else if(bicolor[v2]==-1)
            {
                bicolor[v2]=1-color;
                DFS(v2, 1-color, n);
            }
        }
    }
}

/****************************************************

Problem Description
1976�~�A�b�q����U���U�ҩ��F4��a�ϲz�ס]Four Color Map Theorem�^�C
�N�O�ȥH4���C��b�a�ϤW���P���ϰ���A�ϱo�۾F���ϰ��C�⧡���ۦP�C

�{�b�A�A�n�ѨM�@�������A�����²�檺���D�C
���A�@�Ӭ۳s���ϡA�ЧA�b�`�I�W���]�u��2�ؤ��P���C��^�A
�åB�^���O�_�i�H�ϱo�۾F���`�I�C�⧡���ۦP�C
���F�ϰ��D²��@�ǡA�A�i�H���]�G

�S���`�I�|���s�V�ۤv����C
��O�S����V�ʪ��A�]�N�O���p�G�`�IA�i�H�s��`�IB�A����N��`�IB�]�i�H�s��`�IA�C
�ϧάO�j�s�q���A�]�N�O����2�`�I�����Ҧ����|�۳s�C

Input
��J�t���h�մ��ո�ơC
�C�մ��ո�ƪ��Ĥ@�C���@�ӥ���� n�]1 < n < 200�^�N��`�I���ƥءC
�ĤG�C���@�ӥ����m�A�N���䪺�ƥءC
���U�Ӫ�m�C�C�C��2�Ӿ�ƥN����ҳs����2�Ӹ`�I���N���C
�on�Ӹ`�I���N�����O��0��n-1�C

n=0�N���J�����C

Output
��C�@�մ��ո�ƿ�X�O�_�i�H��2���C���`�I�ϱo�۾F���`�I�C�⧡���ۦP�C

�Y�i�H�п�X�GBICOLORABLE.�A�_�h��X�GNOT BICOLORABLE.

Sample Input
3
3
0 1
1 2
2 0
9
8
0 1
0 2
0 3
0 4
0 5
0 6
0 7
0 8
0

Sample Output
NOT BICOLORABLE.
BICOLORABLE.

****************************************************/
