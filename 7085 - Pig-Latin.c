#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(void)
{
    char arr[1000], c;
    int i, wordlen=0, isword=0;

    while((c=getchar())!=EOF)
    {
        if(isalpha(c))
        {
            arr[wordlen++]=c;
            isword=1;
        }

        else if(c!='\n' && isword==1)
        {
            if(arr[0]=='A' || arr[0]=='E' || arr[0]=='I' || arr[0]=='O' || arr[0]=='U' ||
                arr[0]=='a' || arr[0]=='e' || arr[0]=='i' || arr[0]=='o' || arr[0]=='u')
            {
                for(i=0;i<wordlen;i++) printf("%c", arr[i]);
                printf("ay");
            }

            else
            {
                for(i=1;i<wordlen;i++) printf("%c", arr[i]);
                printf("%cay", arr[0]);
            }
            putchar(c);
            wordlen=0;
            isword=0;
        }

        else if(!isword) putchar(c);
        else printf("\n");

    }

    return 0;
}

/***********************************************************

Problem Description
�A�{��email��PGP�[�K�k�����w���A�ҥH�A�M�w�b�A���H��HPGP�[�K�e��������ରPig Latin�H�[�j�w���ʡC

Input
�A�����g��i�HŪ�J���N�檺��r�åHPig Latin����k��X���{���C��r���C�@��]�t�@�Χ�h�ӳ�r�C
�@�ӳ�r���w�q�O�@�t�C�s��``�r��"�]�j�g ��/�M �p�g�^�C��r�����H�U�C�W�h�ഫ��Pig Latin
�]�S�������r�|�H���̦binput�����ˤl��X�^�G

1.�H�����]�j�p�g��a,e,i,o,u�^��������r�����b���̫᭱�[�W�r��"ay"�]���t�޸��^�C
�Ҧp�G"apple"�ܦ�"appleay"�C
2.�H�l���]���F�j�p�g��a,e,i,o,u�~���Ҧ��r���^��������r��������Ĥ@�Ӧr������̫᭱�A
�M��b��r���Y�]�[�W�r��"ay"�C�Ҧp�G"hello"�ܦ�"ellohay"�C
3.���i�H���ܦr�����j�p�g�C

Sample Input
This is the input.
I love my country.

Sample Output
hisTay isay hetay inputay.
Iay ovelay ymay ountrycay.

***********************************************************/
