#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void seg(int left, int right, int ind);
void insert(int bound, int grade, int ind);
int findmax(int left, int right, int ind);
typedef struct T{
	int lb, rb, grade, who;
}TREE;
TREE node[400001];
int ans[100001];
int max(int a, int b){
	return (ans[a]>=ans[b])?a:b;
}

int main(){

	int N, Q, i, x, y, c;
	while(scanf("%d%d", &N, &Q)!=EOF){
		seg(1, N, 1);
		for(i=1;i<=N;i++){
			scanf("%d", &x);
			ans[i]=x;
			insert(i, x, 1);
		}
		while(Q--){
			scanf("%d%d%d", &x, &y, &c);
			insert(findmax(x, y, 1), c, 1);
		}
		for(i=1;i<=N;i++)
			printf("%d%c", ans[i], (i<N)?' ':'\n');	
	}
	return 0;
}

void seg(int left, int right, int ind){
	node[ind].lb=left;
	node[ind].rb=right;
	node[ind].grade=0;
	node[ind].who=0;
	if(left!=right){
		seg(left, (left+right)/2, ind*2);
		seg((left+right)/2+1, right, ind*2+1);
	}
	return;
}

void insert(int bound, int grade, int ind){
	int mid, i;
	mid=(node[ind].lb+node[ind].rb)/2;
	if(node[ind].lb==bound && node[ind].rb==bound){
		node[ind].grade=grade;
		node[ind].who=bound;
		ans[bound]=grade;
		return;
	}
	else if(bound<=mid)
		insert(bound, grade, ind*2);
	else
		insert(bound, grade, ind*2+1);
	ans[bound]=grade;
	i=(node[ind*2].grade>=node[ind*2+1].grade)?ind*2:ind*2+1;
	node[ind].grade=node[i].grade;
	node[ind].who=node[i].who;
	return;
}

int findmax(int left, int right, int ind){
	int mid=(node[ind].lb+node[ind].rb)/2;
	if(node[ind].lb==left && node[ind].rb==right)
		return node[ind].who;
	else if(right<=mid)
		return findmax(left, right, ind*2);
	else if(left>mid)
		return findmax(left, right, ind*2+1);
	else
		return max(findmax(left, mid, ind*2), findmax(mid+1, right, ind*2+1));
}


