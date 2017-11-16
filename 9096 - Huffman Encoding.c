#include<stdio.h>
int heap[20000], n_node;
void push(int node);
int pop(void);

int main(){
    int T, t, n, i, x;
    int f, fd, min1, min2;

    scanf("%d", &T);
    for(t=1;t<=T;t++){
        n_node=f=fd=0;
        scanf("%d", &n);
        for(i=1;i<=n;i++){
            scanf("%d", &x);
            f+=x;
            push(x);
        }
        while(n_node>1){
            min1=pop();
            min2=pop();
            fd+=min1+min2;
            push(min1+min2);
        }
        printf("Case %d: %.2lf\n", t, (double)fd/f);
    }
    return 0;
}

void push(int node){
    int i, tmp;
    n_node++;
    heap[n_node]=node;
    for(i=n_node;i>1;i/=2){
        if(heap[i]<heap[i/2]){
            tmp=heap[i];
            heap[i]=heap[i/2];
            heap[i/2]=tmp;
        }
    }
}

int pop(void){
    int i, tmp, min, x;
    x=heap[1];
    heap[1]=heap[n_node];
    n_node--;
    i=1;
    while(i*2<=n_node){
        min=2*i;
        if((i*2+1)<=n_node)
            min=(heap[2*i]<heap[2*i+1])?2*i:2*i+1;
        if(heap[min]<=heap[i]){
                tmp=heap[i];
                heap[i]=heap[min];
                heap[min]=tmp;
                i=min;
        }
        else
            break;
    }
    return x;
}

/**************************************************************************************

Problem Description
Given f1, f2… fn denoting the frequencies of n different symbols to be encoded into
variable length binary representation using Huffman encoding.
Let d1, d2… dn denote the encoded length of the symbols.
Please find the optimal encoding, which means that the average length of the encoded
message is minimized.

Input
The first line of the input consists of an integer T (T ≤ 1000) denoting the number of test cases.
Each test case starts with an integer N (N ≤ 10000) representing the number of symbols to be encoded,
and the following are N integers corresponding to the frequencies of the symbols.

Output
For each test case, output “Case i:”, where i is the sequence number starting from 1,
and then the minimized average length of the encoded message, rounded to two decimal places.

Sample Input
2
5 5 10 20 25 40
5 4 2 2 1 1

Sample Output
Case 1: 2.10
Case 2: 2.20

**************************************************************************************/
