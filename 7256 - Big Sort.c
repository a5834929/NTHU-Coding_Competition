#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int cmp(const void*p, const void*q);

typedef struct _p
{
    char num[105];
    int len;
}P;
P pnum[100010];
P nnum[100010];

int main(void)
{
    char str[10000];
    int N, p, n, i;

    scanf("%d", &N);
    while(1)
    {
        n=0;
        p=0;
        memset(pnum, 0, sizeof(P));
        memset(nnum, 0, sizeof(P));
        while(N--)
        {
            scanf("%s", str);

            if(isdigit(str[0]))
            {
                strcpy(pnum[p].num, str);
                pnum[p].len=strlen(str);
                p++;
            }
            else
            {
                strcpy(nnum[n].num, str);
                nnum[n].len=strlen(str);
                n++;
            }
        }
        qsort(pnum, p, sizeof(P), cmp);
        qsort(nnum, n, sizeof(P), cmp);

        if(n)
            for(i=n-1;i>=0;i--)
                printf("%s\n", nnum[i].num);
        if(p)
            for(i=0;i<p;i++)
                printf("%s\n", pnum[i].num);
        if(scanf("%d", &N)!=EOF)
            printf("\n");
        else
            break;
    }
    return 0;
}
int cmp(const void*p, const void*q)
{
    P a=*(P*)p, b=*(P*)q;
    if(a.len!=b.len) return (a.len<b.len)?-1:1;
    else if(strcmp(a.num, b.num)!=0) return (strcmp(a.num, b.num)<0)?-1:1;
    return 0;
}

/**********************************************************************

Problem Description
�бN��J����ƨ̷Ӥj�p�ƦC�C

Input
���h�մ���C�C�մ���Ĥ@��A���@�Ӿ��N (1<=N <=10^5)�N���X�ӼƦr�A���U�Ӧ�
N ��A�C�榳�@�Ӿ��Ai(-10^100<=Ai<=10^100)�N��n�ƧǪ��Ʀr(���|���L��0 �}�Y��-0)

Output
���C�մ���ХѤp��j��X�Ҧ��Ʀr�A���궡�ЪŤ@��

Sample Input
5
9999999999999999999999999999999999999999999999999999999999999999
1
2
3
4
3
9
-99
-9

Sample Output
1
2
3
4
9999999999999999999999999999999999999999999999999999999999999999

-99
-9
9

*********************************************************************/
