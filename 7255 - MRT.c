#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int queue[600], visited[600];
int matrix[600][600];

int main(void)
{
    int n, m, s, a, b;
    int i, cost[600];
    int front, rear;

    while(scanf("%d %d %d", &n, &m, &s)!=EOF)
    {
        memset(visited, 0, sizeof(visited));
        memset(matrix, 0, sizeof(matrix));
        memset(cost, 0, sizeof(cost));

        while(m--)
        {
            scanf("%d %d", &a, &b);
            matrix[a][b]=1;
            matrix[b][a]=1;
        }

        queue[0]=s;
        visited[s]=1;
        front=0;
        rear=1;

        while(front<rear)
        {
            for(i=1;i<=n;i++)
            {
                if(matrix[queue[front]][i])
                {
                    if(!visited[i])
                    {
                        visited[i]=1;
                        queue[rear]=i;
                        rear++;
                        cost[i]=cost[queue[front]]+1;
                    }
                }
            }
            front++;
        }

        if(s!=1)
            printf("%d", (cost[1]/5)*5+20);
        else
            printf("0");
        for(i=2;i<=rear;i++)
        {
            if((i)!=s)
                printf(" %d", (cost[i]/5)*5+20);
            else
                printf(" 0");
        }
        printf("\n");
    }

    return 0;
}

/********************************************************

Problem Description
���B�|�̷ӧA���F�h�֯��Ӧ��O�A�p��O�Ϊ���k�O�G(�_�I����I���̵u�Z��/5)*5+20�C
�Ҧp�ìK���n��x�_�����A�̵u���u�O�ìK->���F��->��������]->��������->�����_��
->�����s��->���ɦx->�x�_�����A�@�ݸg�L�C���A�ҥH�����N�O (7/5)*5+20 = 25 ���C�{�b
���A���B�a�ϡA�H�ΰ_�I���A�A�����X�_�I����Ҧ����һݭn��������?

Input
���h�մ���A�C�մ���Ĥ@�榳�T�ӥ����n(n<=500)�N���B���ơAm �N��s�u�A�H��
s �N��_�I���C���U��m ��C�榳��ӥ����a,b(1<=a,b<=n)�N���B�����s�u(���V)�A��
�B���������w�O�s�q��

Output
���C�մ���A�Ш̷�index���ǿ�X�_�I����Ҧ����һݪ������A���P�����������Ť@�ӪŮ�A
�_�I����_�I�����ο��C

Sample Input
6 5 1
1 2
2 3
3 4
4 5
5 6

Sample Output
0 20 20 20 20 25

********************************************************/
