#include<stdio.h>
int cmp(const void*p, const void*q);

int main(void)
{
    int n, q, k, i;
    int seq[100010]={0};

    while(scanf("%d %d", &n, &q)!=EOF)
    {
        for(i=0;i<n;i++) scanf("%d", &seq[i]);

        qsort(seq, n, sizeof(int), cmp);

        for(i=0;i<q;i++)
        {
            scanf("%d", &k);
            printf("%d\n", seq[k-1]);
        }
    }

    return 0;
}

int cmp(const void*p, const void*q)
{
    int a=*(int*)p, b=*(int*)q;
    if(a!=b)
        return (a<b)?-1:1;
    return 0;
}

/**************************************************

Problem Description
���@�ӥ��ƧǼƦC�A�Ч���k�p���Ʀr

Input

���h�մ���A�C�մ���Ĥ@�榳��ӥ����n(n<105)��ܳo�մ��꦳�h�֭Ӵ���A
�H��q(q<105)��ܰ��D�ƶq�A���U�Ӧ�n�Ӿ��(int�d��)��ܳo�ӼƦC(�Ʀr���|���ƥX�{)�A
�H��q�ӥ����ki(0<ki<=n)�N��@�Ӹ߰�

Output
���C�Ӹ߰ݡA��X�ӼƦC��k�Ӥp����

Sample Input
5 3
9 7 5 3 1
1
2
5

Sample Output
1
3
9

**************************************************/
