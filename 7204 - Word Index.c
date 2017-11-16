#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int i, j, len, idx;
	int C[50][50]={{0}};
	char s[10];

	while(scanf("%s", s)!=EOF)
    {
        C[0][0]=1;
        for(i=1;i<50;i++)
        {
            C[i][0]=1;
            for(j=1;j<=i;j++)
                C[i][j]=C[i-1][j-1]+C[i-1][j];
        }

        len=strlen(s);
		idx=0;
		for(i=1;i<len;i++)
		{
			if(s[i]<s[i-1])
			{
				printf("0\n");
				break;
			}
			idx+=C[26][i];
		}

		if(i!=len)
            continue;

		for(i=0;i<len;i++)
		{
			for(j=(i==0)?1:s[i-1]-'a'+2;j<=s[i]-'a';j++)
				idx+=C[26-j][len-i-1];
		}

		printf("%d\n", idx+1);
	}
    return 0;
}

/****************************************************************

Problem Description
一般來說在編碼（Encoding）的技術常常用在加密，
或是要有較節省的通訊與儲存空間的時候。
在此，我們發展了一套簡單的編碼的方法，
這方法可以把不大於5個字元（都是小寫字母）
的特殊字都指定一個唯一的整數。

在這裡所謂的特殊字是指在這個字裡面，
下一個字元一定比上一個來的大。例如：k、is、abc、aepx、gwxyz
都是合法的。而aab、are、cat則不是。

對每一個合法的字我們根據字的長度與字元的順序給他一個整數編號。
也就是：

a -> 1
b -> 2
.
.
z -> 26
ab -> 27
ac -> 28
.
.
az -> 51
bc -> 52
.
.
vwxyz -> 83681　

你的任務就是要做這樣的編碼。

Input
每筆測試資料一列。每列有1個字（1到5個小寫字母）。

Output
對每一測試資料，如果這個字不是合法的，請輸出0。否則請輸出該字的編號。

Sample Input
z
a
cat
vwxyz

Sample Output
26
1
0
83681

****************************************************************/
