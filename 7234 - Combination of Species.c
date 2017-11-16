#include<stdio.h>
void DFS(int i);
int n, m, num;
int comb[12]={0};

int main(void)
{
    int i;

    scanf("%d %d", &n, &m);
    while(n && m)
    {
        num=0;
        for(i=1;i<=n;i++) DFS(i);

        scanf("%d %d", &n, &m);
        if(n&&m) printf("\n");
    }

    return 0;
}

void DFS(int i)
{
    int j;
    comb[num++]=i;

    if(num==m)
    {
        for(j=0;j<num;j++) printf("%d%c", comb[j], (j<num-1)?' ':'\n');
        num--;
        return;
    }

    for(j=i+1;j<=n;j++) DFS(j);
    num--;
}


/***************************************************

Problem Description
��n�ӪF��A�s����1��n�A�п�Xn�ӪF���m�ӪF�誺�Ҧ��զX

Input
���h�մ���A�C�մ��꦳��ӥ����n(0<n<=10)�Pm(0<m<=n)�A��n=0�Bm=0���ɭԵ�������C



Output
��C�@�����ո�ơA��X��Ҧ��i�઺�զX�A�C�ӲզX�@��C
�Ъ`�N��X�զX�����ǻݥѤp��j�ƦC�C���ո�Ƥ����ЪŤ@��C�аѦ�Sample Output�C

Sample Input
3 2
5 5
2 1
0 0

Sample Output
1 2
1 3
2 3

1 2 3 4 5

1
2

******************************************************/
