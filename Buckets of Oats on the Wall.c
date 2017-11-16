#include<stdio.h>
#include<stdlib.h>
typedef struct n{
	int value;
	struct n* next;
	struct n* pre;
}Node;

int num;
Node* now;
Node* root;

void kill(int M){
	for(int i = 0;i<M-1;i++){
		now = now->next;
	}
	now->pre->next = now->next;
	now->next->pre = now->pre;
	num--;
	now = now->next;
}

int main(void){
	int N,M;
	
	
	while(scanf("%d%d", &N,&M) != EOF && !(N == 0 && M == 0) ){
	num = N;
	root = malloc(sizeof(Node)*N);
	now = root;
	for(int i = 0;i<N;i++){
		now->next = root+((i+1)%N);
		now->pre = root+(i-1);
		now->value = i+1;
		now = now->next;
	}
	root->pre = root+N-1;
	
	now = root;
	while(num > 1){
		kill(M);
	}
	printf("%d\n",now->value);
	free(root);
	
	}
}
