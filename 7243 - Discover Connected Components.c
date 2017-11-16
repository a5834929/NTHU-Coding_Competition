#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int find(int x);
void Union(int a, int b);

int set[1010];
int sum[1010];

int main(void)
{
    int N, K, i;
    int a, b, max, ans;

    while(scanf("%d", &N)!=EOF && N)
    {
        scanf("%d", &K);
        for(i=1;i<=N;i++)
        {
            set[i]=i;
            sum[i]=1;
        }

        for(i=1;i<=K;i++)
        {
            scanf("%d %d", &a, &b);

            if(set[a]!=set[b])
                Union(a, b);
        }

        max=0;
        for(i=1;i<=N;i++)
            if(sum[i]>max)
                max=sum[i];

        ans=0;
        for(i=1;i<=N;i++)
            if(sum[i]==max)
                ans++;

        printf("%d\n", ans);
    }

    return 0;
}

int find(int x)
{
    if(set[x]=x)
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
}

/*******************************************

Problem Description
�b�Z�W�A���ǤH�]���өʤW�������A�|�`�`�E�b�@�_�C
���ɡA�ڭ̷|�N�o�X�ӤH�k�����P�@�����C�YA��B�O�P�@���BB��C�O�P�@���A�hA��C�]�|�O�P�@�����C
�{�b�A���A�ثe�Z�W���h�֤H�A�γo�ǡ��ָ�֬O�P�@���������Y�C���F�o�����Y�A
�A�N���D�Z�W���X�Ӥp����F�]�W��L�ۦ��@��^�C
����꦳�ɭԤp���骺�ƶq�ä��O���򭫭n�C
�ڭ̥u�b�N�o�Ǥp���餤���̤j�դO�A�]�N�O�H�̦h���p����C
�]���L�̦b��M���@�ưȮɡA�|���u�աC�{�b�A���A�o�����Y�ϡA�Ч�X�H�̦h���p���馳�X�ӡC

Input
���h�մ���C
�C�մ���Ĥ@��A����Ӿ�ơGN, K�A��ܯZ�W��N�ӤH�BK�����Y(1<=N<=1000)
���U��K��A�C�榳��Ӿ��X,Y�A���X��Y�O�P�@�����C(1<=X,Y<=N)
��N=0�ɡA���굲���C

Output
���C�մ���A��X�@�Ӿ�ƪ�ܦ��X�ӳ̤j�դO���p����C

Sample Input
10 5
1 2
3 4
1 5
4 8
6 7
0

Sample Output
2

******************************************/
