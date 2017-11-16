#include<stdio.h>
int heap[20000], n_node;
void push(int node);
int pop(void);

int main(){
    int T, i, x;
    int fd, min1, min2;

    while(scanf("%d", &T)!=EOF && T){
        fd=n_node=0;
        for(i=0;i<T;i++){
            scanf("%d", &x);
            push(x);
        }
        while(n_node>1){
            min1=pop();
            min2=pop();
            fd+=min1+min2;
            push(min1+min2);
        }
        printf("%d\n", fd);
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
