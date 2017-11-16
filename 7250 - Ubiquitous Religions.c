#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int set[50001];
void Union(int a, int b);
int find(int x);

int main(void)
{
    int n ,m, i, j, x, y, sum;

    j=0;
    while(scanf("%d %d", &n, &m)!=EOF && !(m==0 && n==0))
    {
        sum=0;
        memset(set, 0, sizeof(set));
        for(i=1;i<=n;i++)
            set[i]=i;

        for(i=0;i<m;i++)
        {
            scanf("%d %d", &x, &y);
            if(set[x]!=set[y])
                Union(x, y);
        }

        for(i=1;i<=n;i++)
            if(set[i]==i)
                sum++;

        printf("Case %d: %d\n", j+1, sum);
        j++;
    }

    return 0;
}

void Union(int a, int b)
{
    set[find(b)]=find(set[a]);
    return;
}

int find(int x)
{
    if(set[x]==x)
        return x;
    else
        return set[x]=find(set[x]);
}

/**************************************************

Problem Description
�o�ӥ@�ɤW���\�h���P���v�ЫH���C
�A�Q�n���D�A�NŪ���j�Ǥ��A�ǥ̨ͭ쩳�H�F�h�ֺؤ��P���v�СC

�b�A�NŪ���j�Ǥ��@�� n �Ӿǥ� ( 0 < n <= 50000 )�C
��M�A���i���C�ӤH�ӧO�߰ݥL�̪��H���A�ӥB�Y�Ǿǥͤ]����K
�z�S�L�̩ҫH���v�СC�ӸѨM�o�ǰ��D���@�إi�઺��k�O�߰� m
( 0 <= m <= n(n-1)/2 )��ǥͥL�̬O�_�H�P�@�өv��
(�Ҧp�L�̥i��@�_�h�Y���а�A�|���D�L�̩����H�ۦP���v�� )�C
�ѳo�Ǹ�ơA�Y�ϧA�S��k���D�C�ӤH�H���ӱСA���O�A�i�H���p�X
�L�̳̦h�H�F�h�ֺؤ��P���v�СC�A�i�H���]�C�Ӿǥͳ̦h�H�@�өv�СC

Input
��J���]�t�F�\�h�����ո�ơC�C�����ո�ƥѤ@�C�]�t��Ӿ�� n
�� m �@���}�Y�C���U�Ӫ� m �C�C�C�]�t�F��Ӿ�� i �M j�A�N��
�ǥ� i �M�ǥ� j �H�P�@�өv�СC�o�Ǿǥͽs���� 1 �� n�C

�� n = m = 0 ���ɭԥN���J�����C

Output
���C�����ո�ơA�Х���X���ո�ƪ��s��(��1�}�l)�A
�M���X�ǥ̳̦ͭh�H�F�h�ֺؤ��P���v�СC

Sample Input
10 9
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
10 4
2 3
4 5
4 8
5 8
0 0

Sample Output
Case 1: 1
Case 2: 7

***************************************************/
