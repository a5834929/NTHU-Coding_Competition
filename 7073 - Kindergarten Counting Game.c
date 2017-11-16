#include<stdio.h>
#include<ctype.h>

int main(void)
{
    char c;
    int n_word=0;
    int isword=0;

    while((c=getchar()) != EOF)
    {
        if(!isalpha(c) && !isword)
        {
            isword=1;
            n_word++;
        }

        if(isalpha(c) && isword) isword=0;

        if(c=='\n')
        {
            printf("%d\n", n_word);
            n_word=0;
        }
    }
    return 0;
}

/***************************************************

Problem Description
��@��C�榳�X�Ӧr�]word�^�C
Word���w�q�O�s�򪺦r���]letter: A~Z a~z�^�Ҳզ����r�C

Input
���ո�ƨC���@��A�C��ܤ֦��@�Ӧr�C

Output
��X�C�@�檺word�ơC

Sample Input
Meep Meep!
I tot I taw a putty tat.
I did! I did! I did taw a putty tat.
Shsssssssssh ... I am hunting wabbits. Heh Heh Heh Heh ...

Sample Output
2
7
10
9

***************************************************/
