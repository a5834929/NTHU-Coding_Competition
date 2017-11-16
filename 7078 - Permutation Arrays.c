#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
    int num1, num2, i, j;

    scanf("%d", &num1);
    getchar();
    getchar();

    for(i=0;i<num1;i++)
    {
        int index[1000]={0};
        char data[1000][500]={{0}};
        j=0;
        num2=0;

        while(scanf("%d", &index[j++]))
        {
            num2++;
            if((getchar())=='\n') break;
        }

        for(j=0;j<num2;j++) scanf("%s", &data[index[j]-1]);

        for(j=0;j<num2;j++) printf("%s\n", data[j]);

        if(i!=num1-1) printf("\n");
    }

    return 0;
}

/*************************************************

Problem Description
在很多電腦問題中，常常會把一個陣列的資料做一些搬動。
也就是說陣列中的資料被重新排列。有一個排列陣列資料的方法
是用另一個稱為索引陣列（index array）來完成的。假設x是要
被重新排列的陣列，而x'是重新排列後的陣列，那麼應該有一個
關係存在於x和x'之間，使得x'i=xpi，而索引陣列就是記載這個關係用的。

為了避免誤解題意，以第一組Sample Input, Sample Output說明：
索引陣列為3 1 2，代表接下來的浮點數應該分別輸出於第3列、第1列、第2列。

Input
輸入的第一列有一個整數，代表以下有幾組測試資料。每組測試資料2列，
第1列為索引陣列，包含了 1~n 的整數（以某一種排列方式出現），
在這裡n就是陣列中資料的數目。第2列則包含了n個浮點數。測試資料間空一列。
請參考Sample Input

Output
對每一組測試資料根據索引陣列的順序輸出浮點數，每一個浮點數一列，
且浮點數的樣式必須和輸入的一樣。測試資料間亦請空一列。

Sample Input
2

3 1 2
32.0 54.7 -2

3 2 1
32.0 54.7 -2

Sample Output
54.7
-2
32.0

-2
54.7
32.0

************************************************/
