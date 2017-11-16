#include<stdio.h>
int comb(int n, int m);

int main(void)
{
    int n, m;
    double ans;

    while(EOF!=scanf("%d %d", &n, &m))
    {
        if(n==0 && m==0) break;
        ans=comb(n, m);
        printf("%.0lf\n", ans);
    }

    return 0;
}

int comb(int n, int m)
{
    int i, j;
    double fac;

    if(m>n/2) m=n-m;
    for(fac=1,i=n,j=1;i>=n-m+1;i--,j++)
    {
        fac*=i;
        fac/=j;
    }

    return fac;
}

/************************************************

Problem Description
�qN�ӪF�褤���XM�ӪF�誺��k�ơ]���ޱƦC�����ǡ^�O�G

�ЧA�g�@�ӵ{����XC�C�A�i�H���]�A������C���|�W�X int ���d��A�]�N�O�@�w�p��2^31�C

Input
�C�մ��ո�Ƥ@�C�A��2�ӥ���� N,M�]N >= 1, 0 <= M <= N�^�C

N=0�AM=0�N���J�����C

Output
��XC

Sample Input
4 2
10 5
49 6
0 0

Sample Output
6
252
13983816

***********************************************/


