#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*p, const void*q);

typedef struct people{
    char team[50];
    double id;
    int prob;
}student;

student s[100000];

int main(void)
{
    int n, i;

    while(scanf("%d", &n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s", s[i].team);
            scanf("%d", &s[i].prob);
            scanf("%lf", &s[i].id);
        }

        qsort(s, n, sizeof(s[0]), cmp);

        for(i=0;i<n;i++)
        {
            printf("%.0lf ", s[i].id);
            printf("%s ", s[i].team);
            printf("%d\n", s[i].prob);
        }
        printf("\n");
    }

    return 0;
}

int cmp(const void*p, const void*q)
{
    student a=*(student*)p, b=*(student*)q;
    if(a.id!=b.id)
        return a.id<b.id ? -1:1;
    return 0;
}

/*************************************************

Problem Description
�v�޵{�������Ҧҧ��F�AAlan�Q�n��score board��z���P�Ǫ����Z��C
���L�L���q��excel�a�F�A���L�S��k�N���Z�̷ӾǸ��Ʀn�A�A�i�H���L�Ƥ@�U��?

Input
�h�մ���A�C�մ���Ĥ@�榳�Ӿ��n(n<100000)��ܰѥ[�Ҹժ��H�ơA
���U��n�榳�@�Ӧr���ܦP�Ǫ�Team(�r�����<15),�H�ΫD�t��ƪ��
���D��(���D��<20)�A�H�μƦr��ܾǸ�(�Ǹ��̦h9��A���|��0�}�Y���Ǹ�,
�Ǹ����|���ƥB�Ҭ������)

Output
���C�ո�ƽЫ��ӾǸ��Ѥp��j��X �Ǹ�,����W,���D�ơA�����ХH�@�Ӫťչj�}�A�C�ո�ƫ�Цh�@�Ӵ���

Sample Input
5
Team1 2 9862987
Team2 3 9762456
Team3 3 9960321
Team4 5 100062999
Team5 4 100062777

Sample Output
9762456 Team2 3
9862987 Team1 2
9960321 Team3 3
100062777 Team5 4
100062999 Team4 5

*************************************************/
