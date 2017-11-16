#include<stdio.h>
#include<stdlib.h>
#define little 1e-7
struct seat{
	int x,y;
	int order;
	int dis;
};
struct seat theater[10010];
int distance[100][100];
int cmp(const void *a,const void *b);
int cmp2(const void *a,const void *b);
int main(void)
{
	int i,j,k;
	int w,r;
	int mid[2];
	for(i=0;i<60;i++){
		for(j=0;j<60;j++){
			distance[i][j]=i*i+j*j;
		}
	}
	
	while(EOF!=scanf("%d%d",&w,&r)){
		mid[0]=1;
		mid[1]=(w+1)/2;
		for(k=0,i=1;i<=r;i++){
			for(j=1;j<=w;j++,k++){
				theater[k].x=j;
				theater[k].y=i;
				theater[k].dis=distance[i-mid[0]][(j-mid[1]>0)?j-mid[1]:mid[1]-j];
			}
		}
		qsort(theater,k,sizeof(theater[0]),cmp);
		for(k=0,i=1;i<=r;i++){
			for(j=1;j<=w;j++,k++){
				theater[k].order=k+1;
			}
		}
		qsort(theater,k,sizeof(theater[0]),cmp2);
		
		for(k=0,i=1;i<=r;i++){
			for(j=1;j<=w;j++,k++){
				if(j>1) printf(" ");
				printf("%d",theater[k].order);
			}
			printf("\n");
		}
	}
    return 0;
}
int cmp(const void *a,const void *b)
{
	struct seat *x=(struct seat*)a,*y=(struct seat*)b;
	if((x->dis)>(y->dis)) return 1;
	else if((y->dis)>(x->dis)) return -1;
	else{
		if(x->y > y->y) return 1;
		else if(x->y < y->y) return -1;
		else {return x->x - y->x;}
	}
}
int cmp2(const void *a,const void *b)
{
	struct seat *x=(struct seat*)a,*y=(struct seat*)b;
	if(x->y > y->y) return -1;
	else if(x->y < y->y)return 1;
	else return x->x - y->x;
}
