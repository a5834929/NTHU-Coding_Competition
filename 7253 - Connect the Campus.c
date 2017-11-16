#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int cmp(const void*p, const void*q);
int find(int x);
void Union(int a, int b);
double DIS(int x1, int y1, int x2, int y2);

typedef struct EDGE
{
    double dis;
    int x, y;
}EDGE;

EDGE edge[500000];

int set[1000];
int sum[1000];
int coord[1000][2];
int now, x;
int n, e, flag;
double ans;

int main(void)
{
    int i, j, a, b;

    while (scanf("%d", &n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            set[i]=i;
            sum[i]=1;
        }

        for(i=1;i<=n;i++)
            scanf("%d %d", &coord[i][0], &coord[i][1]);

        scanf("%d", &e);

        for(i=0;i<e;i++)
        {
            scanf("%d %d", &a, &b);
            Union(find(a), find(b));
        }

        x=0;
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                edge[x].dis=DIS(coord[i][0], coord[i][1], coord[j][0], coord[j][1]);
                edge[x].x=i;
                edge[x].y=j;
                x++;
            }
        }

        qsort(edge, x, sizeof(EDGE), cmp);

        flag=0;

        for(i=1;i<=n;i++)
        {
            if(find(1)!=find(i))
            {
                flag=1;
                break;
            }
        }

        now=0;
        ans=0;
        while(flag && now<x)
        {
            if(find(edge[now].x)!=find(edge[now].y))
            {
                ans+=edge[now].dis;
                Union(find(edge[now].x), find(edge[now].y));
            }

            flag=0;
            for(i=1;i<=n;i++)
            {
                if(find(1)!=find(i))
                {
                    flag=1;
                    break;
                }
            }
            now++;
        }

        printf("%.2lf\n", ans);

    }

    return 0;

}

int cmp(const void*p, const void*q)
{
    EDGE a=*(EDGE*)p, b=*(EDGE*)q;
    if(a.dis!=b.dis) return (a.dis<b.dis)?-1:1;
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
    if(a==b)
        return;

    if(sum[a]>sum[b])
        set[b]=a;

    else
    {
        set[a]=b;
        if(sum[a]==sum[b])
            sum[b]++;
    }
}

double DIS(int x1, int y1, int x2, int y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

/**********************************************************

Problem Description
�bWaterloo�j�Ǹ̦��\�h���ؿv�����b���ءC�Ǯն��ΤF�ؿv�u�H�B
���q�u�H�H�Τ@�ӵ{���]�p�v�C�{���]�p�v�H���n�h�áA���ӤH�N�O�A�C
�A�����ȴN�O�n��X�n�ظm�ն�����ݭn�Φh���l�u�C

�C�ɫؿv���i�H�����bX-Y�����W���@���I�C�s��2�ɫؿv���������u�������u�A
�B�����u�����V���C�����u�i�H�ۥѪ���V�A���O�u���b�ؿv�����a������u�~�����Y�C

�Ǯյ��A�@�i�ն骺�a�ϡA�W�����U�ؿv������m�y�СA
�H�Τ@�Ǥw�g�s�b��ؿv�����������u�C�墨�Ǥw�g�s�b�������u�A
�A���n�h�ʥ��C�A�����ȬO�n�[�]�s�������u�A�ϱo�Ҧ����ؿv�����i�H�ǥѺ����۳s�C
��M�A�Ǯդ譱�Ʊ�A�s�[�]�������u�V�u�V�n�C

Input
��J�t���h�մ��ո�ơC

�C�մ��ո�ƪ��Ĥ@�C���@�Ӿ��N�]1 <= N <= 750�^�A�N��ؿv�����ƥ�
�]�ؿv�����s���q1��N�^�C���U�Ӫ�N�C�C�C��2�Ӿ�ơ]����-10000��10000�����^�A
�N���oN�ɫؿv�����y�С]���|��2�ɤ��P���ؿv���b�P�@���I�W�^�C
�A���U�Ӫ��@�C���@�Ӿ��M�]0 <= M <= 1000�^�N��w��M�������u�s����ؿv�������C
�A���U�Ӫ�M�C�C�C��2�ӥ���ƥN��Y���w�s�b�������u�ҳs����2�ɫؿv���s���C
��2�ɫؿv�����̦h�u�|���@�������u�s���C

�аѦ�Sample Input�C

Output
�C�մ��ո�ƿ�X�@�C�C�t���@�ӯB�I�ơ]�p���I��2��^�A
�N��A�ҷs�[�]�������u�����סA�ϱo�ն鶡�U�ؿv�����i�H�����s���A
�ӥB���׭n�̤p�C

Sample Input
4
103 104
104 100
104 103
100 100
1
4 2
4
0 0
0 1
1 0
1 1
2
1 2
3 4

Sample Output
4.41
1.00

************************************************************/
