#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct s
{
    int from ,to;
}SIDE;

SIDE side[50000];
int check[1001][1001];

int main(void)
{
    int i, j, point, edge;
    int a, b;

    while(scanf("%d %d", &point, &edge)!=EOF)
    {
        memset(side, 0, sizeof(SIDE));
        memset(check, 0, sizeof(check));
        j=0;
        for(i=0;i<edge;i++)
        {
            scanf("%d %d", &a, &b);
            if(a!=b)
            {
                if(!check[a][b])
                {
                    side[j].from=a;
                    side[j].to=b;
                    check[a][b]=1;
                    check[b][a]=1;
                    j++;
                }
            }
        }
        printf("%d %d\n", point, j);
        for(i=0;i<j;i++)
            printf("%d %d\n", side[i].from, side[i].to);
        printf("\n");
    }

    return 0;
}


/*********************************************

Problem Description
Alan �X�D�خɷ|�H�����ͤ@�Ǵ��ո�ơC�{�b�L�n�X�@��BFS �D�ءA�ҥH�L�ιq���H��
���ͤ@����A���O���ո�Ƥ������ӥX�{���ƪ���A�]�����ӥX�{�ۤv�s�ۤv�����p�A��
�H�L�o��o�Ǳ��p���B�z���C���L�L�̪񬰤F�T���P�t�ΦҸյJ�Y���B���A�A�i�H���L�B
�z�����?

Input
���h�մ���C
�C�մ���A�Ĥ@�榳��ӥ���ơC
n(n<=500)��ܳo�մ��꦳�h�֭��I�Am(m<=50000)��ܭ쥻�䪺�ƶq�C
���U��m ��A�C��|����ӥ���ƥN��@����C�I���s���O��1~n�A��O���V��C

Output
���C�մ���A��X�S��������P�ۤv�s�ۤv���p������C
�Ĥ@��O�I���ƶqn���P�䪺�ƶqm���C
���U��m�����X�Ҧ���A��зӭ쥻��J���ǱƦC�C�C�մ��ꤧ��Цh�@�Ӵ���

Sample Input
4 5
3 4
1 2
2 1
1 1
3 4

Sample Output
4 2
3 4
1 2

*********************************************/
