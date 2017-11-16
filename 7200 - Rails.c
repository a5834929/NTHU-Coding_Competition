#include<stdio.h>

int main(void)
{
    int n, i, j, flag;

    while(scanf("%d", &n)!=EOF && n!=0)
    {
        int input[1001]={0};

        while(scanf("%d", &input[0]) && input[0])
        {
            int train[1001]={0};

            for(i=1;i<n;i++) scanf("%d", &input[i]);

            flag=1;

            while(1)
            {
                for(i=0;i<n;i++)
                {
                    train[input[i]]=1;
                    j=input[i];
                    if(input[i]<input[i-1])
                    {
                        for(;j<=input[i-1];j++)
                        {
                            if(train[j]==0)
                            {
                                flag=0;
                                break;
                            }
                        }
                        if(!flag) break;
                    }
                }
                break;
            }
            if(!flag) printf("No\n");
            else printf("Yes\n");
        }
        printf("\n");
    }

    return 0;
}

/***************************************************

Problem Description
在一個叫「堆疊市」的城市中有一個有名的火車站。由於地形限制以及經費的關係。

現在火車從A方向來，預定從B方向離開。火車共有N節車廂（N <=1000），
並且各車廂依次以1到N來編號。你可以假設各車廂在進站之前可以單獨與其他車廂分離，
也可以單獨離開車站到往B方向的鐵軌上。你也可以假設在任何時間火車站都可以容納所有的車廂。
但是一旦一節車廂進站後，就不能再回到A方向的鐵軌上了，並且一旦離開車站往B方向後，也不能再回到車站。

現在你的任務是寫一個程式，判斷火車能否以一特定的排列方式在B方向的鐵軌上。

Input
輸入含有多組測試資料。每組測試資料的第一列，有1個整數N，其意義如上所述。
對於此組測試資料接下來有0到多個不等的測試，每個測試一列，每列有N個整數，
內容為1,2,......,N的任意排列。當遇到僅含有一個0的一列，代表該組測試資料結束。

N=0代表輸入結束，請參考Sample Input。

Output
對每一組測試資料的每個測試，輸出該1,2,......,N的任意排列是否可能。
如果可能，請輸出yes，若不可能則輸出No。

每組測試資料後亦請空一列。請參考Sample Output。

Sample Input
5
1 2 3 4 5
5 4 3 2 1
5 4 1 2 3
0
7
4 5 3 7 6 2 1
0
0

Sample Output
Yes
Yes
No

Yes

****************************************************/
