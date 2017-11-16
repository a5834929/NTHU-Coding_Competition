#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*p, const void*q);

int main(void)
{
    int n, q, i, j;
    int left, right, mid, flag;
    int ID[100010]={0}, id;

    while(scanf("%d %d", &n, &q)!=EOF)
    {
        for(i=0;i<n;i++) scanf("%d", &ID[i]);

        qsort(ID, n, sizeof(int), cmp);

        for(i=0;i<q;i++)
        {
            scanf("%d", &id);
            left=0;
            right=n-1;
            flag=0;

            while(left<=right)
            {
                mid=(left+right)/2;
                if(ID[mid]==id)
                {
                    flag=1;
                    break;
                }
                else if(ID[mid]<id) left=mid+1;
                else if(ID[mid]>id) right=mid-1;
            }
            if(flag) printf("Yes\n");
            else printf("No\n");
        }
    }

    return 0;
}


int cmp(const void*p, const void*q)
{
    int a=*(int*)p, b=*(int*)q;
    if(a!=b) return (a<b)?-1:1;
    return 0;
}


/*********************************************************

Problem Description
�̪�j�Ǳ��˥ӽЩ�]�A�o�J�Q�n�d�d�ݥL���ǧ̦��S���W�M�j�A
�ҥH�L�N�h��F�M�j�]��Ӭd�C���L�n�C�C�����ҹ�b�ӳ·ФF�A
�A�����L���L�ǧ̪�����Ҹ��X��?

Input
���h�մ���A�C�մ���Ĥ@�榳��ӥ����n(n<105)�N��]��W����Ҹ��X�ƶq�A
�H��q(q<105)�N��߰ݦ��ơF���U�ӷ|��n�ӭ���Ҹ��X(int�d�򥿾�ơA
�B���|��0�}�Y)��ܺ]��A�A���Uq��C�榳�ӭ���Ҹ��X(int�d�򥿾��)�N��@�Ӹ߰ݡC
�]�����Ҹ��X���|�ӭ���Ҷ��ǱơA�B�]���@�ӤH�P�ɥi�H�ӽЦh�Өt�ҡA�ҥH�]�檺����Ҹ��X�i��|���ơC

Output
���C�Ӹ߰ݡA�p�G����Ҹ��X���X�{�b�]��W��X"Yes"�A�Ϥ���X"No"

Sample Input
7 3
10020307 10144708 10264514
10020307 10264514 10309513 10118108
10118108
99999999
12345678

Sample Output
Yes
No
No

********************************************************/
