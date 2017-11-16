#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void SPFA(int X);
int cmp(const void*p, const void*q);
typedef struct _P{
	int from, to, time;
}PATH;
PATH path[3000];
int time[1000], q[1000], inq[1000], q2[1000];
int se[1000][2], sum[1000];
int N, P, C;
int main(){
	int i, x, min;

	while(scanf("%d%d%d", &N, &P, &C)!=EOF){
		memset(se, -1, sizeof(se));
		memset(sum, 0, sizeof(sum));
		for(i=0;i<N;i++){
			scanf("%d", &x);
			q[i]=x;
		}
		for(i=0;i<2*C;i+=2){
			scanf("%d%d%d", &path[i].from, &path[i].to, &path[i].time);
			path[i+1].to=path[i].from;
			path[i+1].from=path[i].to;
			path[i+1].time=path[i].time;
		}

		qsort(path, 2*C, sizeof(PATH), cmp);
		for(i=0;i<2*C;i++){
			if(se[path[i].from][0]==-1)
				se[path[i].from][0]=i;
			se[path[i].from][1]=i;
		}
		for(i=0;i<N;i++){
			memset(inq, 0, sizeof(inq));
			memset(time, -1, sizeof(time));
			SPFA(q[i]);
		}
		min=sum[1];
		for(i=1;i<=P;i++)
			if(sum[i]<min)
				min=sum[i];
		printf("%d\n", min);
	}
	return 0;
}

int cmp(const void*p, const void*q){
	PATH a=*(PATH*)p, b=*(PATH*)q;
	if(a.from!=b.from) return (a.from <b.from)?-1:1;
	else if(a.to!=b.to) return (a.to <b.to)?-1:1;
	return 0;
}

void SPFA(int X){
	int i, head, tail, now, next;
	time[X]=0;
	head=tail=0;
	q2[tail]=X;
	inq[X]=1;
	tail++;
	while(head<tail){
		now=q2[head%P];
		head++;
		inq[now]=0;
		for(i=se[now][0];i<=se[now][1] && se[now][0]!=-1;i++){
			next=path[i].to;
			if(time[now]+path[i].time<time[next] || time[next]==-1){
				time[next]=time[now]+path[i].time;
				if(inq[next]==0){
					q2[tail%P]=next;
					inq[next]=1;
					tail++;
				}
			}
		}
	}

	for(i=1;i<=P;i++){
		if(time[i]!=-1)
			sum[i]+=time[i];
	}
}
