#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    int adj[120][120], indeg[120], queue[120];
    int i, front, rear;
    int n, m, first, next;

	while(scanf("%d %d", &n, &m)!=EOF && !(n==0 && m==0))
	{
	    memset(adj, 0, sizeof(adj));
	    memset(indeg, 0, sizeof(indeg));
	    memset(queue, 0, sizeof(queue));
	    front=0;
	    rear=0;
	    for(i=0;i<m;i++)
	    {
	        scanf("%d %d", &first, &next);
	        indeg[next]++;
	        adj[first][next]=1;
	    }

	    for(i=1;i<=n;i++)
        {
            if(!indeg[i])
            {
                queue[rear]=i;
                rear++;
            }
        }

        while(front<rear)
        {
            for(i=1;i<=n;i++)
            {
                if(adj[queue[front]][i])
                {
                    indeg[i]--;
                    if(!indeg[i])
                    {
                        queue[rear]=i;
                        rear++;
                    }
                }
            }
            front++;
        }

        for(i=0;i<rear-1;i++)
            printf("%d ", queue[i]);
        printf("%d\n", queue[i]);
	}
    return 0;
}

/**************************************************

Problem Description
John�� n ��Ʊ��n���A�������O�o�ǨƱ��ä��O�U�ۿW�ߪ��A�ӬO���̩ۨʪ��C
���y�ܻ��i�঳�Y��Ʊ��@�w�n�b�t�@��Ʊ���������~�వ�C

Input
�C�մ��ո�ƥi�঳�n�X�C�C�Ĥ@�C��2�Ӿ�� n,m�C�]1 <= n <= 100�^
n�N��@���X��Ʊ��n���]�s���q 1 �� n�^�Am �N��Ʊ��������X�Ӭۨ����Y�s�b�C
���U�Ӫ�m�C�C�C��2�Ӿ�� i �M j�C�N�� i �o��Ʊ��@�w�n�b j �o��ƫe�Q����C

n=m=0�ɥN���J�����C

Output
��C�մ��ո�ơA�п�Xn�Ӿ�ơA�N��Ʊ��Q���檺���ǡC

���G���ץi�ण�O�ߤ@��

Sample Input
5 4
1 2
2 3
1 3
1 5
0 0

Sample Output
1 4 2 5 3

*************************************************/
