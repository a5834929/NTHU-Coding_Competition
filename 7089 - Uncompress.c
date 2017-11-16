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
對於不含數字的文章有一種簡單的壓縮法，方法是用一個串列（list）
來記錄曾經出現過的字（word）。壓縮的過程如下：如果遇到非英文字母
的字元，該字元直接複製到壓縮後的檔案。當遇到一個字時，如果這一個字
是第一次出現，除了把這個字複製到壓縮後的檔案之外，並把他加到串列的開頭。
如果這一個 字不是第一次出現，則這個字不會複製到壓縮後的檔案，而是把這個字
在串列中的位置複製到壓縮後的檔案，並且在串列中把這個字移到串列的開頭。
串列的開頭位 置為1。

現在你的任務是給你一篇用上述方法壓縮後的文章，請你把他還原回來。
你可以假設所有的字都不會超過50個字元，並且未壓縮的文章不含有數字。
另外，字的定義為：最長的連續的英文字母（A~Z, a~z）。例如：

x-ray 包含了2個字：x 和 ray
Mary's 包含了2個字：Mary 和 s
It's a winner包含了4個字：It、s、a 和 winner
並且字有分大小寫，因此abc 和Abc是不同的2個字。在本問題中，不同的字的數目並無上限。

Input
只有一組測試資料。內容為多列壓縮後的文章。最後一列僅含有一個0，代表輸入結束（此列無輸出）。
請參考Sample Input。

Output
對於輸入的每一列，輸出解壓縮後的文章。請參考Sample Output。

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
