#include<stdio.h>
#include<string.h>

int main(void)
{
    int str[1000]={0}, i, j, k, count;
    char ch;

    while(scanf("%d%c", &str[0], &ch)!=EOF)
    {
        count=0;
        i=1;
        while(ch!='\n')
        {
            scanf("%d%c", &str[i++], &ch);
        }

        for(j=0;j<i;j++)
        {
            for(k=j;k<i;k++)
            {
                if(str[j]>str[k]) count++;
            }
        }
        printf("%d\n", count);
    }

    return 0;
}

/***********************************************************

Problem Description
���p�b�@�ӼƦC���Aa�����Ǧbb���e���A���Oa��b�٤j�A
���ڭ̴N��(a, b)���f�Ǽƹ�(Inversion Pair)�C�u�n�ڭ̭p��
�@�ӼƦCInversion Pair���ƶq�A�N�i�H���D�o�ƦC�ֻ̤ݭn�X��
���k�����~����ƧǦn�C�{�b���A�ƦC�A�к�XInversion Pair�ƶq�C

Input
�h�մ���C
�C�մ��꦳�@��A�C�@�椤���h�Ӿ��(int�d��)��ܤ@�ӼƦC�C
�۾F��Ӿ�ƥH�@�Ӫťչj�}�A�C�@���Ƴ̦h��1000�ӡC

Output
���C�մ���п�XInversion Pair���ƶq

Sample Input
1 2 3
3 2 1
4 3 2 1
1 1 1 1

Sample Output
0
3
6
0

***********************************************************/
