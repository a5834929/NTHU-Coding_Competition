#include<stdio.h>
#include<string.h>

int main(void)
{
    int round, i, num, wrong, correct;
    char ans[100], input[100];

    while(EOF!=scanf("%d", &round) && round!=-1)
    {
        int alpha[50]={0};
        num=0;
        wrong=0;
        correct=0;
        scanf("%100s", ans);
        scanf("%100s", input);

        for(i=0;i<strlen(ans);i++) alpha[ans[i]-'a']=1;

        for(i=0;i<26;i++)
        {
            if(alpha[i]==1) num++;
        }

        for(i=0;i<strlen(input);i++)
        {
            if(alpha[input[i]-'a']==1)
            {
                correct++;
                alpha[input[i]-'a']=-1;
            }
            else
            {
                wrong++;
                alpha[input[i]-'a']=-1;
            }
            if(correct==num || wrong==7) break;
        }

        if(correct==num && wrong<7) printf("Round %d\nYou win.\n", round);
        if(correct!=num && wrong<7) printf("Round %d\nYou chickened out.\n", round);
        if(correct!=num && wrong>=7) printf("Round %d\nYou lose.\n", round);
    }

    return 0;
}

/**************************************************

Problem Description
Hangman Judge是一個猜英文單字的小遊戲（在電子字典中常會看到），遊戲規則如下：

答案單字寫在紙上（每個字元一張紙），並且被蓋起來，玩家每次猜一個英文字元（letter）。
如果這個英文字元猜中（在答案的英文單字中有出現），被猜中的字元就被翻開。
例如：答案是book，如果你猜o，book中的兩個o就會被視為已猜中。
如果這個英文字元未出現在答案的單字中，就會在hangman的圖中多加一劃。
要完成hangman圖共需7劃，如下圖。注意：同一個猜錯的字元只能再圖上畫一劃，
例如：答案是book，第一次你猜a（未猜中）會在圖上畫一劃，但第二次以後再猜a並不會再多畫。
如果在hangman圖完成之前，玩家已猜中所有答案中的字元，則玩家贏（win）。
如果玩家尚未猜中所有答案中的字元而hangman圖完成了，，則玩家輸（lose）。
如果玩家在還沒輸贏的情況之下就不玩了，那我們說玩家膽小放棄了（chicken out）.

┬─┬─
│ Ｏ
│／│＼
│  │
│／＼
┌┴┐
│ └─┬
└───┘
你的任務就是要寫一個程式根據答案及玩家輸入的猜測來判斷玩家是贏、輸、或放棄。

Input
會有好幾組測試資料，每一組有3列。第一列為一個數字n，代表第幾回合，第二列為這一回合的答案，第三列為這一回合玩家輸入的猜測。如果 n = -1代表輸入結束。

Output
請輸出每一回合及遊戲結果。遊戲結果只有三種可能：
You win.
You lose.
You chickened out.

請參考sample output。

Sample Input
1
cheese
chese
2
cheese
abcdefg
3
cheese
abcdefgij
-1

Sample Output
Round 1
You win.
Round 2
You chickened out.
Round 3
You lose.

**************************************************/
