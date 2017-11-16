#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int pri(char ch);

int main(void)
{
    char str[1010], stack[1010];
    int i, top, n;

    scanf("%d", &n);

    while(n--)
    {
        scanf("%s", str);
        top=0;

        for(i=0;i<strlen(str);i++)
        {
            if(isdigit(str[i])) printf("%c", str[i]);

            else if(str[i]=='(')
            {
                stack[top]=str[i];
                top++;
            }

            else if(str[i]==')')
            {
                while(stack[top-1]!='(')
                {
                    printf("%c", stack[top-1]);
                    top--;
                }
                top--;
            }

            else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/')
            {
                if(top==0 || stack[top-1]=='(')
                {
                    stack[top]=str[i];
                    top++;
                }

                else
                {
                    if(pri(str[i])>pri(stack[top-1]))
                    {
                        stack[top]=str[i];
                        top++;
                    }

                    else
                    {
                        while(pri(str[i])<=pri(stack[top-1]) && top>0)
                        {
                            if(stack[top-1]!='(')
                            {
                                printf("%c", stack[top-1]);
                                top--;
                            }
                            else break;
                        }
                        stack[top]=str[i];
                        top++;
                    }
                }
            }
        }
        if(i==strlen(str))
        {
            while(top>0)
            {
                printf("%c", stack[top-1]);
                top--;
            }
        }
        printf("\n");
    }

    return 0;
}

int pri(char ch)
{
    if(ch=='*' || ch=='/') return 1;
    else if(ch=='+' || ch=='-') return 0;
    return 0;
}

/********************************************************

Problem Description
�N�y���СG�Y���@�⦡a+b�A�ha��b�O�B�⤸�A+�O�B��l�C
�ƾǤW�A�̱`�����⦡�N�O�|�h�B�⦡�A�p�G(1+5)*8/2�B3*7/9*4���C
�����ڭ̭n�ǲߦp��B�z�|�h�B�⦡�C�|�h�B���ܦ��O����(infix)��ܦ��A
�n���g�L�������ഫ�A�ন���(postfix)��ܦ��A�~�n�B�z�C
�W�z�d�Ҫ���Ǫ�ܦ��� 15+8*2/�B37*9/4*
����Ǫ�ܦ���A�ڭ̥i�H�ֳt��X���סC
��k�O�G�ϥΤ@��Stack�A�J��B�⤸�NPush�i�h�A
�J��B��l�NPop�̤W������Ӥ����A�M��@�B��l�ʧ@�A�A�N���GPush�i�h�C
���ѩ��Ǫ�ܦ��⵲�G��²��A�G���D�ڭ̭n�Ҫ��O�p��F���������ഫ�C
���A�������ഫ�]�O�Τ@��Stack�ӹF�����C
�W�h�O�G
1.	���A��(�G�n�����iStack
2.	�k�A��)�G�n�NStack�s��Pop�ÿ�X�A����Pop�@�ӥ��A������(���k�A������Push)
3.	�B�⤸�G������X
4.	�B��l�GStack�}�lPop�A����(1)�̤W�褸�����u���v�p��ثe�B��l���u���v�A
    �άO(2)Stack���Ť~����C�M��A�N�ثe���B��lPush�i�h
    �u���v�G��(�� < ��+�� = ��-�� < ��*�� = ��/��

Input
�Ĥ@�ӼƦrN�A���N�մ���C���U��N��A�C���ܤ@�մ���C
�C��̦h1000�Ӧr���A�䤤�|�X�{0-9, (, ), +, -, *, /
�B�⤸���@��Ʀr�C

Output
���C�մ���A��X�@��Ӻ⦡����Ǫ�ܦ��C

Sample Input
1
(3+4)/(5-6)*(7+8)

Sample Output
34+56-/78+*

******************************************************/
