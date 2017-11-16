#include<stdio.h>
double comb(int n, int m);

int main(void)
{
    int n, m;
    double ans;

    while(EOF!=scanf("%d %d", &n, &m) && n!=0 && m!=0)
    {
        ans=comb(n, m);
        printf("%d things taken %d at a time is %.0lf exactly.\n", n, m, ans);
    }

    return 0;
}

double comb(int n, int m)
{
    int i, j;
    double fac=1;

    if(m>n/2) m=n-m;
    for(fac=1,i=n,j=1;i>=n-m+1;i--,j++)
    {
        fac*=i;
        fac/=j;
    }

    return fac;
}

/**********************************************

Problem Description
���F�I���x�W�q���m�骺�o��A�ڭ̯S�O���X��զX�������D�ءC
�H�x�W���m��ӻ��A�q46�Ӳy�����X6�ӡA�@��C(46,6)=9366819�زզX�C
�]���S�������v�G1/936681989�A���C�F�a�I�^���A�G

5 <= N <=100, and 5 <= M <=100, and M <= N

�ڭ̥i�H�ھڤU�������ܺ�X�qN�ӪF�褤���XM�ӪF�誺�զX�ơG

�A�i�H���]�A������C���|�W�X long int ���d��C

Input
�C�����ո�Ƥ@��A��2�ӥ���� N,M�C N=0�AM=0�N���J�����C

Output
�H�U�C���榡��X�G

N things taken M at a time is C exactly.

�аѦ�Sample Output�C

Sample Input
100 6
20 5
18 6
0 0

Sample Output
100 things taken 6 at a time is 1192052400 exactly.
20 things taken 5 at a time is 15504 exactly.
18 things taken 6 at a time is 18564 exactly.

***********************************************/
