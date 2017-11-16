#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*p, const void*q);
int find(int x);
void Union(int a, int b);
typedef struct R{
    int from, to, dis;
}ROAD;
ROAD road[10002];
int set[102];

int main(){
    int farm, i, j, r_num, sum;

    while(scanf("%d", &farm)!=EOF){
        r_num=sum=0;
        for(i=0;i<farm;i++){
            set[i]=i;
            for(j=0;j<farm;j++){
                scanf("%d", &road[r_num].dis);
                if(road[r_num].dis){
                    road[r_num].from=i;
                    road[r_num].to=j;
                    r_num++;
                }
            }
        }
        qsort(road, r_num, sizeof(ROAD), cmp);
        for(i=0;i<r_num;i++){
            if(find(road[i].from)!=find(road[i].to)){
                sum+=road[i].dis;
                Union(road[i].from, road[i].to);
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}

int cmp(const void*p, const void*q){
    ROAD a=*(ROAD*)p, b=*(ROAD*)q;
	if(a.dis!=b.dis) return (a.dis<b.dis)?-1:1;
	else if(a.from!=b.from) return (a.from<b.from)?-1:1;
	else if(a.to!=b.to) return (a.to<b.to)?-1:1;
	return 0;
}

int find(int x){
    if(set[x]==x) return x;
    return set[x]=find(set[x]);
}

void Union(int a, int b){
    int x, y;
    x=find(set[a]);
    y=find(set[b]);
    if(x!=y)
        set[y]=set[x];
    return;
}
