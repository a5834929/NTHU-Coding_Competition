#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int group[1100], queue[1100], visited[1100];
int matrix[1100][1100];

int main(void)
{
    int n, m, a, b, flag;
    int j, front, rear;

    while(scanf("%d", &n)!=EOF && n)
    {
        memset(group, -1, sizeof(group));
        memset(matrix, 0, sizeof(matrix));
        memset(visited, 0, sizeof(visited));

        scanf("%d", &m);
        flag=1;

        while(m--)
        {
            scanf("%d %d", &a, &b);
            matrix[a][b]=1;
            matrix[b][a]=1;
        }
        front=0;
        rear=0;
        queue[0]=1;
        visited[1]=1;

        while(front<=rear)
        {
            for(j=1;j<=n;j++)
            {
                if(matrix[queue[front]][j])
                {
                    if(!visited[j])
                    {
                        rear++;
                        visited[j]=1;
                        queue[rear]=j;
                    }

                    if(group[queue[front]]==-1 && group[j]==-1)
                    {
                        group[queue[front]]=1;
                        group[j]=0;
                    }

                    else if(group[queue[front]]==-1 && group[j]!=-1)
                        group[queue[front]]=1-group[j];

                    else if(group[queue[front]]!=-1 && group[j]==-1)
                        group[j]=1-group[queue[front]];

                    else if(group[queue[front]]!=-1 && group[j]!=-1)
                        if(group[queue[front]]==group[j])
                        {
                            flag=0;
                            break;
                        }
                }
            }
            front++;
            if(!flag)
                break;
            if(front>rear)
            {
                for(j=1;j<=n;j++)
                {
                    if(visited[j]==0)
                    {
                        visited[j]=1;
                        front=0;
                        queue[front]=j;
                        rear=0;
                        break;
                    }
                }
            }
        }

        if(!flag)
            printf("You discover a BIG Secret!!");
        else
            printf("Successful");
        printf("\n");
    }

    return 0;
}

/*************************************************************
Problem Description
�ܻ��o�J�O�@�ӥ]��ť�A�L���ֽ�N�O�[��Y�ǤH������
�άO�q�B�ͨ���ť�����A�H�T�w�Y��ӤH�O�_�������n�P�C
�]���M�o�q�����@�w���T�A�����ٷ|�Q�R�ѡy�o�~�|�i�j�F�I�z�A���L�֦����h��^
���@�ѡA�L����@�ʥ[�K�L���W��C�W���C���@�s�ꪺ��ơA
�C����ƥN��Q�h�ê���H�C���ѩ�o���W��Q���h�W�r�u���N���A
�L�i��u���DA<=>B�BA<=>C�BB<=>D�B�B���C���F�ѱK�A
�L�M�w���N�o�ǥN�������k�ͤ@�s�B�k�ͤ@�s�A�A�ӱ����H�W�C
�аݬO�_���@�Ӥ��k�A�i�H�N�o�ǥN��������s�H
�]���������s���ɭԡA��ܥi��o�{�F�@�Ӥj���K�K�^

Input
���h�մ���C
�C�մ���Ĥ@�欰���N�A��ܦ�N�ӤH(�N����1...N�AN<=1000)
���U�Ӭ����K�A��ܦ�K�ӳQ�h�ê����Y�C
���U��K��A�C�榳��Ӿ�ơA��ܳo��ӥN���i��O�����n�P���C
��N=0�ɡA���굲���C

Output
�w��C�մ���A
�p�G����k�N�N�������k�k��s�A�п�X��Successful���F
�_�h�A�п�X��You discover a BIG Secret!!��

Sample Input
3
2
1 2
2 3
4
5
1 2
1 3
2 4
3 4
2 3
7
7
1 2
2 3
3 1
4 5
4 6
5 7
6 7
0

Sample Output
Successful
You discover a BIG Secret!!
You discover a BIG Secret!!
***************************************************************/
