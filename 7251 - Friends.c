#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int find(int x);
void Union(int a, int b);

int set[30010];
int sum[30010];

int main(void)
{
    int n, N, M;
    int i, a, b, ans;

    scanf("%d", &n);

    while(n--)
    {
        scanf("%d %d", &N, &M);
        for(i=1;i<=N;i++)
        {
            set[i]=i;
            sum[i]=1;
        }

        for(i=1;i<=M;i++)
        {
            scanf("%d %d", &a, &b);

            if(set[a]!=set[b])
                Union(a, b);
        }

        ans=0;
        for(i=1;i<=N;i++)
            if(sum[i]>ans)
                ans=sum[i];

        printf("%d\n", ans);

    }
    return 0;
}

int find(int x)
{
    if(set[x]==x)
        return x;
    else
        return set[x]=find(set[x]);
}

void Union(int a, int b)
{
    int x, y;
    x=find(set[a]);
    y=find(b);

    if(x!=y)
    {
        set[y]=x;
        sum[x]+=sum[y];
        sum[y]=0;
    }
    return;
}

/**********************************************************

Problem Description
���@����N�ө~���C��M�䤤���\�h�H�O�B�ͪ����Y�C
�ھڦ��W���λy�G�u�ڪB�ͪ��B�ͤ]�O�ڪ��B�͡v�A
�ҥH�p�GA�MB�O�B�͡AB�MC�O�B�͡A����A�MC�]�O�B�͡C

�A�����ȬO��X�b�o�����̤j���B�Ͷ��ά��h�֤H�C

Input
��J���Ĥ@�C���@�ӥ���ơA�N��H�U���h�ֲմ��ո�ơC

�C�մ��ո�ƪ��Ĥ@�C��2�ӥ���� N �M M �C
N�N����W�~�����ƥء]1 <= N <= 30000 �^�A
M �N��o�ǩ~�����B�����Y���ƥء] 0 <= M <= 500000�^�C
���U�Ӫ�M�C�C�C��2�Ӿ��A�AB�] 1 <= A,B <= N , A������B�^�A
�N��A�AB���B�����Y�C�oM�C���i�঳���|���ƥX�{�C

�аѦ� Sample Input�C

Output
��C�մ��ո�ƿ�X�@�C�A�b�o�����̤j���B�Ͷ��ά��h�֤H�C

Sample Input
2
3 2
1 2
2 3
10 12
1 2
3 1
3 4
5 4
3 5
4 6
5 2
2 1
7 10
1 2
9 10
8 9

Sample Output
3
6
***********************************************************/
