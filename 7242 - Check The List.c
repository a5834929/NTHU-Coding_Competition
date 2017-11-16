#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*p, const void*q);

int main(void)
{
    int n, q, i, j;
    int left, right, mid, flag;
    int ID[100010]={0}, id;

    while(scanf("%d %d", &n, &q)!=EOF)
    {
        for(i=0;i<n;i++) scanf("%d", &ID[i]);

        qsort(ID, n, sizeof(int), cmp);

        for(i=0;i<q;i++)
        {
            scanf("%d", &id);
            left=0;
            right=n-1;
            flag=0;

            while(left<=right)
            {
                mid=(left+right)/2;
                if(ID[mid]==id)
                {
                    flag=1;
                    break;
                }
                else if(ID[mid]<id) left=mid+1;
                else if(ID[mid]>id) right=mid-1;
            }
            if(flag) printf("Yes\n");
            else printf("No\n");
        }
    }

    return 0;
}


int cmp(const void*p, const void*q)
{
    int a=*(int*)p, b=*(int*)q;
    if(a!=b) return (a<b)?-1:1;
    return 0;
}


/*********************************************************

Problem Description
最近大學推薦申請放榜，搗蛋想要查查看他的學弟有沒有上清大，
所以他就去找了清大榜單來查。不過要慢慢找准考證實在太麻煩了，
你能幫他找到他學弟的准考證號碼嗎?

Input
有多組測資，每組測資第一行有兩個正整數n(n<105)代表榜單上准考證號碼數量，
以及q(q<105)代表詢問次數；接下來會有n個准考證號碼(int範圍正整數，
且不會有0開頭)表示榜單，再接下q行每行有個准考證號碼(int範圍正整數)代表一個詢問。
榜單准考證號碼不會照准考證順序排，且因為一個人同時可以申請多個系所，所以榜單的准考證號碼可能會重複。

Output
對於每個詢問，如果准考證號碼有出現在榜單上輸出"Yes"，反之輸出"No"

Sample Input
7 3
10020307 10144708 10264514
10020307 10264514 10309513 10118108
10118108
99999999
12345678

Sample Output
Yes
No
No

********************************************************/
