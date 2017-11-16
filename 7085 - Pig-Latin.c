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
你認為email的PGP加密法不夠安全，所以你決定在你的信件以PGP加密前先把明文轉為Pig Latin以加強安全性。

Input
你必須寫支可以讀入任意行的文字並以Pig Latin的文法輸出的程式。文字的每一行包含一或更多個單字。
一個單字的定義是一系列連續的``字母"（大寫 或/和 小寫）。單字必須以下列規則轉換為Pig Latin
（沒有任何單字會以它們在input中的樣子輸出）：

1.以母音（大小寫的a,e,i,o,u）為首的單字必須在它們後面加上字串"ay"（不含引號）。
例如："apple"變成"appleay"。
2.以子音（除了大小寫的a,e,i,o,u外的所有字母）為首的單字必須先把第一個字母移到最後面，
然後在單字後頭也加上字串"ay"。例如："hello"變成"ellohay"。
3.不可以改變字母的大小寫。

Sample Input
This is the input.
I love my country.

Sample Output
hisTay isay hetay inputay.
Iay ovelay ymay ountrycay.

***********************************************************/
