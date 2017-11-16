#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct T{
    int id;
	long long int x, y;
}SHAPE;
SHAPE p[100003];
int cmp(const void*p, const void*q){
	SHAPE a=*(SHAPE*)p, b=*(SHAPE*)q;
	if(a.x!=b.x)return(a.x<b.x)?-1:1;
	else if(a.y!=b.y)return(a.y<b.y)?-1:1;
	return 0;
}

SHAPE upper[100003], lower[100003], ans[100003];
int u_top, l_top, n_ans, done[100003];

int CROSS(SHAPE p1, SHAPE p2, SHAPE p3){
	long long int cross;
	SHAPE v1, v2;
	v1.x=p2.x-p1.x;
	v1.y=p2.y-p1.y;
	v2.x=p3.x-p1.x;
	v2.y=p3.y-p1.y;
	cross=v1.x*v2.y-v1.y*v2.x;
	if(cross<=0)
		return 1;
	else
		return 0;
}
int main(void)
{
	int N, i;
	scanf("%d", &N);
	while(1){
	    memset(done, 0, sizeof(done));
		u_top=l_top=n_ans=0;
		for(i=0;i<N;i++){
            scanf("%lld%lld", &p[i].x, &p[i].y);
            p[i].id=i;
		}
		qsort(p, N, sizeof(SHAPE), cmp);
		upper[u_top++]=p[0];
		upper[u_top++]=p[1];
		for(i=2;i<N;i++){
			while(!CROSS(upper[u_top-2], upper[u_top-1], p[i]) && u_top>=2)
				u_top--;
            upper[u_top++]=p[i];
		}
		lower[l_top++]=p[N-1];
		lower[l_top++]=p[N-2];
		for(i=N-3;i>=0;i--){
			while(!CROSS(lower[l_top-2], lower[l_top-1], p[i]) && l_top>=2)
				l_top--;
            lower[l_top++]=p[i];
		}
        for(i=l_top-1;i>=0;i--){
            if(!done[lower[i].id]){
                ans[n_ans]=lower[i];
                done[lower[i].id]=1;
                n_ans++;
            }
        }
        for(i=u_top-1;i>=0;i--){
            if(!done[upper[i].id]){
                ans[n_ans]=upper[i];
                done[upper[i].id]=1;
                n_ans++;
            }
        }
        printf("%d\n", n_ans);
        for(i=0;i<n_ans;i++)
            printf("%lld %lld\n", ans[i].x, ans[i].y);
        if(scanf("%d", &N)==EOF)
            break;
        else
            printf("\n");
    }
	return 0;
}
