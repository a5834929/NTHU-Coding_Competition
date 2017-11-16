#include<stdio.h>
#include<string.h>

int main(void)
{
    char str[200], stack[200], ch;
    int n, i, j, flag;

    scanf("%d%c", &n, &ch);

    while(n--)
    {
        gets(str);
        flag=1;

        for(j=0,i=0;i<strlen(str);i++)
        {
            if(str[i]=='(' || str[i]=='[') stack[++j]=str[i];

            else if(str[i]==')')
            {
                if(j==0 || stack[j]!='(') flag=0;
                j--;
            }

            else if(str[i]==']')
            {
                if(j==0 || stack[j]!='[') flag=0;
                j--;
            }

            if(j<0) break;
        }
        if(j!=0) flag=0;

        if(flag==0) printf("No\n");
        else printf("Yes\n");
    }

    return 0;
}

/*************************************************************

Problem Description
�b���D���A�D�ط|�����A�@�ӥ]�t�p�A���]�^�Τ��A���e�f���r��C
��r��ŦX�U�C����ɧڭ̺٥L�����T���B�⦡�G

1.�Ӧr�ꬰ�@�ӪŦr��
2.�p�G�ϩM�г������T���B�⦡�A�h�ϢФ]�����T���B�⦡�A
3.�p�G�Ϭ����T���B�⦡�A�h�]�ϡ^�Ρe�ϡf�������T���B�⦡�C

�{�b�A�ЧA�g�@��{���i�HŪ�J�o���r����ˬd���̬O�_�����T���B�⦡�C
�r�ꪺ�̤j���׬�128�Ӧr���C

Input
��J���Ĥ@�C�������n�A�N���U�Ӧ�n�C�ݴ���ơC

Output
�ˬd�C�C�ݴ���ơA�p�G���T��XYes�A�_�h��XNo�C

Sample Input
3
([])
(([()])))
([()[]()])()

Sample Output
Yes
No
Yes

************************************************************/
