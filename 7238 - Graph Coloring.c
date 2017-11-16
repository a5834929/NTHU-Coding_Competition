#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void DFS(int node, int choose, int notchoose);
int map[101][101], mt[101];
int tmp[101], Ans[101], maxL;
int cant[101];
int T, n, m;

int main(void)
{
	int i, x, y;
	while(scanf("%d", &T)!=EOF)
	{
	    while(T--)
        {
            scanf("%d %d", &n, &m);
            memset(mt, 0, sizeof(mt));
            memset(cant, 0, sizeof(mt));

            for(i=0;i<m;i++)
            {
                scanf("%d %d", &x, &y);
                map[x][mt[x]]=y;
                map[y][mt[y]]=x;
                mt[x]++;
                mt[y]++;
            }

            maxL=0;
            DFS(1, 0, 0);
            printf("%d\n", maxL);

            for(i=0;i<maxL-1;i++)
                printf("%d ", Ans[i]);

            printf("%d\n", Ans[i]);
        }
	}

    return 0;
}

void DFS(int node, int choose, int notchoose)
{
    int i, newNot, reduce[101]={0}, idx;

	if((choose+notchoose)==n || node==(n+1))
	{
		if(choose>maxL)
		{
			maxL=choose;

			for(i=0;i<maxL;i++)
				Ans[i]=tmp[i];
		}
		return;
	}

	if(cant[node]==0)
	{
		idx=0;
		newNot=notchoose;

		for(i=0;i<mt[node];i++)
		{
			if(cant[map[node][i]]==0)
			{
				cant[map[node][i]]=1;
				reduce[idx++]=map[node][i];
				newNot++;
			}
		}

		tmp[choose]=node;
		DFS(node+1, choose+1, newNot);

		for(i=0;i<idx;i++)
			cant[reduce[i]]=0;
	}
	DFS(node+1, choose, notchoose+(!cant[node]));
}


/********************************************

Problem Description
���A�@�ӹϧΡA�A�����ȬO���@�س̨ζ�⪺��k�C
�ϧΤ����I�n�Q���C��]�u���¦�Υզ�^�A�ӥB
����2�Ӭ۳s���I���i�H����¦�C�ҿ׳̨Ϊ�����k
�O�����o�ӹϧζ¦⪺�I�̦h�C

Input
��J���Ĥ@�C���@�Ӿ�ơA�N��H�U���h�ֲմ��ո�ơC

�C�մ��ո�ƪ��Ĥ@�C�t��2�Ӿ�� n ( 1 <= n <= 100 )�Ak�C
n �N��ϧΤ��I���ƥء]�s���q1�� n�^�Ak �N��ϧΤ��䪺�ƥءC
���U�Ӫ� k �C�C�C�t�� 2 ���I���s���A�N��@����C�аѦ�Sample Input�C

Output
��C�@�մ��ո�ƿ�X 2 �C�C�Ĥ@�C��X�̦h�i�H���h�֭��I�i�H�Q��¦�C
�ĤG�C��X�@�إi�઺��k�A�H��¦��I���s���Ӫ�ܡC�аѦ� Sample Output�C

Sample Input
3
6 8
1 2
1 3
2 4
2 5
3 4
3 6
4 6
5 6
2 0
6 5
1 2
1 3
2 3
4 5
4 6

Sample Output
3
1 4 5
2
1 2
3
1 5 6

**********************************************/
