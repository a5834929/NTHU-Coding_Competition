#include<stdio.h>
#include<string.h>
typedef struct howmany{
    int num;
    int count;
}Hmany;

Hmany numb[100000];

int main(void)
{
    int n, q, temp;
    int i, k, b;
    int left, right, mid, flag;

    while(scanf("%d %d", &n, &q)!=EOF)
    {
        memset(&numb,0,sizeof(numb));

        k=0;
        for(i=0;i<n;i++)
        {
            if(i==0)
            {
                scanf("%d", &numb[k].num);
                numb[k].count=1;
                k++;
            }
            else if(i>0)
            {
                scanf("%d", &temp);
                if(temp!=numb[k-1].num)
                {
                    numb[k].num=temp;
                    numb[k].count=1;
                    k++;
                }
                else numb[k-1].count++;
            }
        }

        for(i=0;i<q;i++)
        {
            left=0;
            right=k-1;
            flag=0;

            scanf("%d", &b);

            while(left<=right)
            {
                mid=(left+right)/2;
                if(numb[mid].num==b)
                {
                    flag=1;
                    break;
                }
                if(numb[mid].num>b) right=mid-1;
                if(numb[mid].num<b) left=mid+1;
            }
            if(flag) printf("%d\n", numb[mid].count);
            else printf("0\n");
        }
    }

    return 0;
}

/*******************************************************

Problem Description
���@�ӱƧǦn(�q�p��j)���ƦC�A�M��|���h�Ӱ��D�A�C�Ӱ��D�|�ݤ@�ӼƦr�b�o�ӼƦC�X�{�X���C

Input
�h�մ���A�C�մ���Ĥ@�榳��ӥ���ơAn(n<100000)��ܼƦC���ƶq�A�H��q(q<100000)��ܰ��D�ƶq�C
���U��n��A��n�Ӿ��(int�d��)��ܳo�ӼƦC�C
���U��q��A�C�榳�@�Ӿ��(int�d��)�N��@�Ӱ��D

Output
���C�Ӱ��D�п�X�o�ӼƦr�X�{�b�ƦC���X��(�S�X�{�O0��)

Sample Input
5 3
1
2
5
5
5
1
5
6

Sample Output
1
3
0



********************************************************/
