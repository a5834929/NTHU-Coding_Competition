#include<stdio.h>
int heap[200000], n_node;
void push(int node);
int pop(void);

int main(){
    int N, Q, s;
    char com[10];

    while(scanf("%d%d", &N, &Q)!=EOF){
        n_node=0;
        while(Q--){
            scanf("%s%d", com, &s);
            if(com[0]=='P'){
                push(s);
                while(n_node>N)
                    pop();
            }
            else if(com[0]=='U')
                while(s--)
                    printf("%d%c", pop(), s?' ':'\n');
        }
    }
    return 0;
}

void push(int node){
    int i, tmp;
    n_node++;
    heap[n_node]=node;
    for(i=n_node;i>1;i/=2){
        if(heap[i]>heap[i/2]){
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
            min=(heap[2*i]>heap[2*i+1])?2*i:2*i+1;
        if(heap[min]>=heap[i]){
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
