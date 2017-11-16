#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*p, const void*q);
typedef struct rujia
{
    int num;
    int index;
}RUJIA;

RUJIA numb[1000100];
int firstp[1000100];

int main(void)
{
    int n, m, i, k, v;

    while(scanf("%d %d", &n, &m)!=EOF)
    {
        memset(numb, 0, sizeof(RUJIA));
        memset(firstp, 0, sizeof(int));

        for(i=1;i<=n;i++)
        {
            scanf("%d", &numb[i].num);
            numb[i].index=i;
        }
        numb[0].num=-1;
        numb[0].index=-1;
        qsort(numb, n+1, sizeof(RUJIA), cmp);

        for(i=1;i<=n;i++)
            if(firstp[numb[i].num]==0)
                firstp[numb[i].num]=i;

        for(i=0;i<m;i++)
        {
            scanf("%d %d", &k, &v);
            if(numb[firstp[v]+k-1].num==v)
                printf("%d\n", numb[firstp[v]+k-1].index);
            else
                printf("0\n");
        }
    }

    return 0;
}

int cmp(const void*p, const void*q)
{
    RUJIA a=*(RUJIA*)p, b=*(RUJIA*)q;
    if(a.num!=b.num) return (a.num<b.num)?-1:1;
    else if(a.index!=b.index) return (a.index<b.index)?-1:1;
    return 0;
}

/***********************************************

Problem Description
���M Rujia Liu �q�`�X�������D�ءA�L���Ӥ]�|�X�@��²�檺�D�بӹ��y�j�a���D�C
���A�@�Ӱ}�C�A�A���ݦ^���b���}�C���Y�@�S�w���ƭ� v ���ƥX�{�� k ���ɪ���m
(�b���}�C������m�A�H1�}�l)�C���F�����D���@�ǡ]�åB����@�ǡ^�A�A�����^��m�ӳo�˪��߰ݡC

Input
��J�|���\�h�մ��ո�ơA�C�ո�ƪ��Ĥ@�C����Ӿ��n, m (1 <= n, m <= 100,000)�A
n ��ܰ}�C�����סA���U�|�� n �Ӥp��1,000,000������ơC�A���U�Ӧ� m �C�A
�C�C���@�� k v ��(1 <= k <= n, 1<= v <= 1,000,000)�A�Ц^���C�@�ռƭ� v �X�{�� k ���b�}�C������m�C

Output
�Ш̭n�D��X�Ǹ�(�H1���Ĥ@��)�A�p�G���s�b�п�X 0�C

Sample Input
8 4
1 3 2 2 4 3 2 1
1 3
2 4
3 2
4 2

Sample Output
2
0
7
0

***********************************************/
