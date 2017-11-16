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
�x�s�@�i�Ϫ��覡���\�h�ءA����`�������O�Gadjacency matrix�Badjacency lists�C
adjacency matrix�O�Τ@�ӤG�����}�C�h�����@��node���S���s��t�@��node�C
���O���ǮɭԤ@��node �s�쪺 node�ƶq�i��|�L�h�A
�ɭPadjacency matrix���G���}�C�L�k�s�_�ӡC
�Ҧp�A��node�Ƥj��100000�ɡAadjacency matrix�|�F��10^10�A�O����|�L�j�C
�o�ɭԡA�ڭ̴N�|���adjacency lists�h�����C
adjacency lists��������k�O�G���C��node�}�@��link list�A
�M��⦳�s�u��node��b�o��link list�W�C

Input

���h������A����Ĥ@�榳��ӼƦrn,m

n (1<n<=100000)���node�ơA�䤤node�s���q0��n-1

m (1<m<=100000)��ܫ��O���ƶq�C

���U�Ӫ�m��A�C�榳�@�ӫ��O�G

1.Connect a b : �Na�i�H�s�� b�A�O�Ҥ��|���Ƴs�u�A�B�ۤv���|�M�ۤv�s�u

2.Ask a b : �߰�a�O�_�i�H�s��b�A�i�H���ܿ�X��Yes���A�Ϥ���X��No��

3.Cut a b : �Na��b���s�u���_�A�p�Ga��b���ӨS���s�u�п�X��Error��

�s�u���O��V���Aa�s��b�����b�i�H�s��a

Output
���Ask, Cut���O�Ы��ӳW�h��X

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
