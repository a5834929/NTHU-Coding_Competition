#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

typedef struct word
    {
        char word[100];
        struct word *next;
    }list;

int main(void)
{
    int i, index;
    char ch;
    list *lead, *search, *temp, *recent=NULL;
    ch=getchar();
    while(ch!='0')
    {
        i=0;
        lead=malloc(sizeof(list));

        if(isalpha(ch))
        {
            do
            {
                lead->word[i++]=ch;
                putchar(ch);
            }while(isalpha(ch=getchar()));

            lead->word[i]='\0';
            lead->next=recent;
            recent=lead;
        }

        else if(isdigit(ch))
        {
            index=0;

            do
            {
                index=index*10+ch-'0';
            }while(isdigit(ch=getchar()));

            search=recent;

            if(index!=1)
            {
                for(i=0;i<index-2;i++) search=search->next;

                temp=search->next;
                search->next=temp->next;
                temp->next=recent;
                recent=temp;
            }
            printf("%s", recent->word);
        }

        else
        {
            putchar(ch);
            ch=getchar();
        }
    }

    while(recent!=NULL)
    {
        temp=recent;
        recent=recent->next;
        free(temp);
    }

    return 0;
}

/**********************************************

Problem Description
��󤣧t�Ʀr���峹���@��²�檺���Y�k�A��k�O�Τ@�Ӧ�C�]list�^
�ӰO�����g�X�{�L���r�]word�^�C���Y���L�{�p�U�G�p�G�J��D�^��r��
���r���A�Ӧr�������ƻs�����Y�᪺�ɮסC��J��@�Ӧr�ɡA�p�G�o�@�Ӧr
�O�Ĥ@���X�{�A���F��o�Ӧr�ƻs�����Y�᪺�ɮפ��~�A�ç�L�[���C���}�Y�C
�p�G�o�@�� �r���O�Ĥ@���X�{�A�h�o�Ӧr���|�ƻs�����Y�᪺�ɮסA�ӬO��o�Ӧr
�b��C������m�ƻs�����Y�᪺�ɮסA�åB�b��C����o�Ӧr�����C���}�Y�C
��C���}�Y�� �m��1�C

�{�b�A�����ȬO���A�@�g�ΤW�z��k���Y�᪺�峹�A�ЧA��L�٭�^�ӡC
�A�i�H���]�Ҧ����r�����|�W�L50�Ӧr���A�åB�����Y���峹���t���Ʀr�C
�t�~�A�r���w�q���G�̪����s�򪺭^��r���]A~Z, a~z�^�C�Ҧp�G

x-ray �]�t�F2�Ӧr�Gx �M ray
Mary's �]�t�F2�Ӧr�GMary �M s
It's a winner�]�t�F4�Ӧr�GIt�Bs�Ba �M winner
�åB�r�����j�p�g�A�]��abc �MAbc�O���P��2�Ӧr�C�b�����D���A���P���r���ƥبõL�W���C

Input
�u���@�մ��ո�ơC���e���h�C���Y�᪺�峹�C�̫�@�C�ȧt���@��0�A�N���J�����]���C�L��X�^�C
�аѦ�Sample Input�C

Output
����J���C�@�C�A��X�����Y�᪺�峹�C�аѦ�Sample Output�C

Sample Input
Dear Sally,

Please, please do it--1 would 4
Mary very, 1 much. And 4 6
8 everything in 5's power to make
14 pay off for you.

-- Thank 2 18 18--
0

Sample Output
Dear Sally,

Please, please do it--it would please
Mary very, very much. And Mary would
do everything in Mary's power to make
it pay off for you.

-- Thank you very much--

*************************************************/
