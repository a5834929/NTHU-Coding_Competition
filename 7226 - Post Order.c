#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
    char ch, Ch, digi[1001];
    int n, stack[1010]={0}, top, y, len;

    scanf("%d", &n);

    while(n--)
    {
        scanf("%d", &y);
        top=0;
        getchar();
        scanf("%c", &ch);
        while(ch!='\n')
        {
            len=0;
            if(isdigit(ch))
            {
                while(isdigit(ch))
                {
                    digi[len]=ch;
                    len++;
                    scanf("%c", &ch);
                }

                if(len==1)
                    stack[top]=digi[0]-'0';

                else if(len==2)
                    stack[top]=(digi[0]-'0')*10+(digi[1]-'0');

                else if(len==3)
                    stack[top]=(digi[0]-'0')*100+(digi[1]-'0')*10+(digi[2]-'0');

                else if(len==4)
                    stack[top]=((digi[0]-'0')*1000+(digi[1]-'0')*100+(digi[2]-'0')*10+(digi[3]-'0'));

                top++;
            }

            else if(ch=='+')
            {
                stack[top-2]=stack[top-2]+stack[top-1];
                top=top-2;
                top++;
                scanf("%c", &ch);
            }

            else if(ch=='-')
            {
                scanf("%c", &ch);

                len=0;
                if(isdigit(ch))
                {
                    while(isdigit(ch))
                    {
                        digi[len]=ch;
                        len++;
                        scanf("%c", &ch);
                    }

                    if(len==1)
                        stack[top]=-(digi[0]-'0');

                    else if(len==2)
                        stack[top]=-((digi[0]-'0')*10+(digi[1]-'0'));

                    else if(len==3)
                        stack[top]=-((digi[0]-'0')*100+(digi[1]-'0')*10+(digi[2]-'0'));

                    else if(len==4)
                        stack[top]=-((digi[0]-'0')*1000+(digi[1]-'0')*100+(digi[2]-'0')*10+(digi[3]-'0'));

                    top++;
                }

                else
                {
                    stack[top-2]=stack[top-2]-stack[top-1];
                    top=top-2;
                    top++;
                }
            }
            else
                scanf("%c", &ch);
        }
        printf("%d\n", stack[top-1]);
    }

    return 0;
}

/**************************************************************

Problem Description
術語介紹：若有一算式a+b，則a 跟b 是運算元，+是運算子
我們將算式從中序轉後序之後，就可以利用stack 把答案算出來！計算的方法是
1. 如果是運算元，那就直接Push 到stack 中
2. 如果是運算子，那就Pop 出stack 最上面兩個數字，算完再Push 回去
舉個例子：假如後序是 1 2 + 4 –
那我們會先把1,2 丟進stack；然後碰到“+”時把1,2 拿出來計算，再把答案3 丟
回stack；然後把4 丟到stack，碰到”-“時再把stack 的3,4 拿出來處理，再把答
案-1 丟回stack；算式結束後，stack 中剩下的值(唯一存在的)就會是答案。

Input
第1個數字N，表示N 組測資。
接下來N 行，每行表示N組測資。
每行有1個開頭數字M，代表運算元加運算子總共有多少符號。
然後，後面接著有M 個符號，且任兩個運算元或運算子中間會以空白隔開。
每行運算元以及運算子加起來最多1000 個。
每個運算元為絕對值小於等於1000 的整數，運算子有”+”,”-“

Output
對於每組測資，輸出該算式的答案。

Sample Input
3
11 3 4 5 6 - + 7 8 + - -
19 1 2 3 4 5 6 7 8 9 10 + + + + + + + + +
5 1 -2 + -3 -

Sample Output
15
55
2

***************************************************************/
