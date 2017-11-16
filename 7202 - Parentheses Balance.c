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
在本題中，題目會先給你一個包含小括號（）及中括號〔〕的字串。
當字串符合下列條件時我們稱他為正確的運算式：

1.該字串為一個空字串
2.如果Ａ和Ｂ都為正確的運算式，則ＡＢ也為正確的運算式，
3.如果Ａ為正確的運算式，則（Ａ）及〔Ａ〕都為正確的運算式。

現在，請你寫一支程式可以讀入這類字串並檢查它們是否為正確的運算式。
字串的最大長度為128個字元。

Input
輸入的第一列為正整數n，代表接下來有n列待測資料。

Output
檢查每列待測資料，如果正確輸出Yes，否則輸出No。

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
