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
算一算每行有幾個字（word）。
Word的定義是連續的字元（letter: A~Z a~z）所組成的字。

Input
測試資料每筆一行，每行至少有一個字。

Output
輸出每一行的word數。

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
