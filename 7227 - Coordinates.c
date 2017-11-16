#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct p
{
    int X, Y;
}NUM;

NUM cor[100001];

int main(void)
{
    int n, q, x, y, i, flag;
    int left, right, mid;

    while(scanf("%d %d", &n, &q)!=EOF)
    {
        memset(cor, 0, sizeof(NUM));
        for(i=0;i<n;i++)
        {
            scanf("%d %d", &x, &y);
            cor[i].X=x;
            cor[i].Y=y;
        }

        while(q--)
        {
            flag=0;
            scanf("%d %d", &x, &y);

            left=0;
            right=n-1;
            while(left<=right)
            {
                mid=(left+right)/2;
                if(cor[mid].X==x)
                {
                    if(cor[mid].Y==y)
                    {
                        flag=1;
                        break;
                    }
                    else if(cor[mid].Y>y)
                        right=mid-1;
                    else if(cor[mid].Y<y)
                        left=mid+1;
                }
                else if(cor[mid].X>x)
                    right=mid-1;
                else if(cor[mid].X<x)
                    left=mid+1;
            }

            if(flag)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}

/************************************************

Problem Description
��n�ӥ�2D �I�y�ЩҲզ����ƦCS�A�I���y�з|���̷�x �y��(�p��j)�A�A��
��y �y��(�p��j)�ƧǡC�w��C�ӼƦCS�A�|���h�Ӹ߰ݡC�C�Ӹ߰ݷ|����q��
�y�СA�Ц^���o�y�Ц��S���X�{�bS ���C

Input
�h�մ���A�C�մ���Ĥ@�榳��ӥ���ơAn(n<100000)��ܮy���I���ƶq�A
�H��q(q<100000)��ܰ��D�ƶq�C���U��n��A�C�榳��Ʀrx,y(int�d��)
�N��C���I���y�СA�����H�ťչj�}�C���U��q��A�C�榳��Ʀrx,y(int�d��)
�N��@�Ӹ߰�

Output
���C�Ӹ߰ݡA�п�X�o�y�Ц��S���X�{�bS���C
���п�X"Yes"�A�S���п�X"No"�C

Sample Input
5 3
1 1
2 1
5 1
5 1
5 2
1 1
5 1
6 1

Sample Output
Yes
Yes
No

**************************************************/
