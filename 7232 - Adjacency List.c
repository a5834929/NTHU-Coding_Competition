#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node* node_pointer;
typedef struct node
{
    int data;
    node_pointer next;
}node;
node_pointer AdjList[100100]={0};

int main(void)
{
    int n, m, start, x, flag;
    char com[10];
    node_pointer temp, node, target;

    while(scanf("%d %d", &n, &m)!=EOF)
    {
        while(m--)
        {
            scanf("%s", com);
            if(strcmp(com, "Connect")==0)
            {
                scanf("%d %d", &start, &x);
                if(AdjList[start]==NULL)
                {
                    temp=(node_pointer)malloc(sizeof(node));
                    temp->data=x;
                    temp->next=NULL;
                    AdjList[start]=temp;
                }

                else
                {
                    flag=0;
                    target=AdjList[start];
                    while(target->next!=NULL)
                    {
                        if(target->data==-1)
                        {
                            flag=-1;
                            break;
                        }
                        target=target->next;
                    }
                    if(flag)
                        target->data=x;
                    else
                    {
                        temp=(node_pointer)malloc(sizeof(node));
                        temp->data=x;
                        temp->next=NULL;
                        target->next=temp;
                    }
                }
            }

            else if(strcmp(com, "Ask")==0)
            {
                flag=0;
                scanf("%d %d", &start, &x);

                node=AdjList[start];
                while(node!=NULL)
                {
                    if(node->data==x)
                    {
                        flag=1;
                        break;
                    }
                    else
                        node=node->next;
                }
                if(flag)
                    printf("Yes\n");
                else
                    printf("No\n");
            }

            else if(strcmp(com, "Cut")==0)
            {
                flag=0;
                scanf("%d %d", &start, &x);

                node=AdjList[start];
                while(node->next!=NULL)
                {
                    if(node->data==x)
                    {
                        flag=1;
                        break;
                    }
                    else
                        node=node->next;
                }
                if(flag)
                    node->data=-1;
                else
                    printf("Error\n");
            }
        }
    }

    return 0;
}

/**************************************************************

Problem Description
儲存一張圖的方式有許多種，比較常見的像是：adjacency matrix、adjacency lists。
adjacency matrix是用一個二維的陣列去紀錄一個node有沒有連到另一個node。
但是有些時候一個node 連到的 node數量可能會過多，
導致adjacency matrix的二維陣列無法存起來。
例如，當node數大於100000時，adjacency matrix會達到10^10，記憶體會過大。
這時候，我們就會改用adjacency lists去紀錄。
adjacency lists的紀錄方法是：對於每個node開一個link list，
然後把有連線的node串在這條link list上。

Input

有多筆測資，測資第一行有兩個數字n,m

n (1<n<=100000)表示node數，其中node編號從0到n-1

m (1<m<=100000)表示指令的數量。

接下來的m行，每行有一個指令：

1.Connect a b : 將a可以連到 b，保證不會重複連線，且自己不會和自己連線

2.Ask a b : 詢問a是否可以連到b，可以的話輸出”Yes”，反之輸出”No”

3.Cut a b : 將a到b的連線剪斷，如果a到b本來沒有連線請輸出”Error”

連線都是單向的，a連到b不表示b可以連到a

Output
對於Ask, Cut指令請按照規則輸出

Sample Input
100000 9
Connect 0 1
Connect 0 2
Ask 0 1
Cut 0 1
Ask 0 1
Cut 0 1
Connect 0 1
Ask 0 1
Ask 0 99999
10 2
Connect 0 1
Ask 1 0

Sample Output
Yes
No
Error
Yes
No
No
***************************************************************/
