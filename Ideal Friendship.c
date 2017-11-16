#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct F{
    long long int x, y;
    int id;
}FENCE;
FENCE fence[100001];
FENCE upper[100001], lower[100001], ans[100001];
int up, low, done[100001];

int cmp(const void*p, const void*q){
    FENCE a=*(FENCE*)p, b=*(FENCE*)q;
    if(a.x!=b.x)return(a.x<b.x)?-1:1;
    else if(a.y!=b.y)return(a.y<b.y)?-1:1;
    return 0;
}

double Dis(FENCE f1, FENCE f2){
    return sqrt((double)(f1.x-f2.x)*(f1.x-f2.x)+(double)(f1.y-f2.y)*(f1.y-f2.y));
}

int CROSS(FENCE f1, FENCE f2, FENCE f3){
    long long int cross;
	FENCE v1, v2;
	v1.x=f2.x-f1.x;
	v1.y=f2.y-f1.y;
	v2.x=f3.x-f1.x;
	v2.y=f3.y-f1.y;
	cross=v1.x*v2.y-v1.y*v2.x;
	if(cross<=0)
		return 1;
	else
		return 0;
}

int main(){
    int N, i, n_ans;
    double dis;

    while(scanf("%d", &N)!=EOF){
        memset(done, 0, sizeof(done));
        for(i=0;i<N;i++){
            scanf("%lld%lld", &fence[i].x, &fence[i].y);
            fence[i].id=i;
        }
        qsort(fence, N, sizeof(FENCE), cmp);
        up=low=n_ans=0;
        dis=0;
        upper[up++]=fence[0];
        upper[up++]=fence[1];
        for(i=2;i<N;i++){
            while(!CROSS(upper[up-2], upper[up-1], fence[i]) && up>=2)
                up--;
            upper[up++]=fence[i];
        }
        lower[low++]=fence[N-1];
        lower[low++]=fence[N-2];
        for(i=N-3;i>=0;i--){
            while(!CROSS(lower[low-2], lower[low-1], fence[i]) && low>=2)
                low--;
            lower[low++]=fence[i];
        }
        for(i=low-1;i>=0;i--){
            if(!done[lower[i].id]){
                ans[n_ans]=lower[i];
                done[lower[i].id]=1;
                n_ans++;
            }
        }
        for(i=up-1;i>=0;i--){
            if(!done[upper[i].id]){
                ans[n_ans]=upper[i];
                done[upper[i].id]=1;
                n_ans++;
            }
        }
        for(i=0;i<n_ans;i++)
            dis+=Dis(ans[i%n_ans], ans[(i+1)%n_ans]);
        printf("%.2lf\n", dis*50);
    }
    return 0;
}
