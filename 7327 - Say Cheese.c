#include<stdio.h>
#include<math.h>
#include<string.h>
void SPFA(void);
double DIS(double x1, double x2, double y1, double y2, double z1, double z2);
typedef struct _B{
    double x, y, z, r;
}BUBBLE;
BUBBLE bubble[101];
int B;
double edge[105][105], dis[105];
int main(){
    int I, i, j;

    I=1;
    scanf("%d", &B);
    while(B!=-1){
        for(i=0;i<=B+1;i++){
            dis[i]=-1;
            for(j=0;j<=B+1;j++)
                edge[i][j]=-1;
        }

        for(i=1;i<=B;i++)
            scanf("%lf%lf%lf%lf", &bubble[i].x, &bubble[i].y, &bubble[i].z, &bubble[i].r);
        scanf("%lf%lf%lf", &bubble[0].x, &bubble[0].y, &bubble[0].z);
        bubble[0].r=0;
        scanf("%lf%lf%lf", &bubble[i].x, &bubble[i].y, &bubble[i].z);
        bubble[i].r=0;
        for(i=0;i<=B+1;i++){
            for(j=0;j<=B+1;j++){
                edge[i][j]=DIS(bubble[i].x, bubble[j].x, bubble[i].y, bubble[j].y, bubble[i].z, bubble[j].z);
                if(edge[i][j]-(bubble[i].r+bubble[j].r)>=0)
                    edge[i][j]-=(bubble[i].r+bubble[j].r);
                else
                    edge[i][j]=0;
            }
        }

        SPFA();

        printf("Cheese %d: Travel time = %.0lf sec\n", I, dis[B+1]*10);
        I++;
        scanf("%d", &B);
    }
    return 0;
}

double DIS(double x1, double x2, double y1, double y2, double z1, double z2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
}

void SPFA(void){
    int i, head, tail, now;
    int q[101], inq[101];
    memset(inq, 0, sizeof(inq));
    head=tail=0;
    q[0]=0;
    inq[0]=1;
    tail++;
    dis[0]=0;
    while(head<tail){
        now=q[head%(B+2)];
        head++;
        inq[now]=0;
        for(i=0;i<=B+1;i++){
            if(dis[now]+edge[now][i]<dis[i] || dis[i]==-1){
                dis[i]=dis[now]+edge[now][i];
                if(inq[i]==0){
                    q[tail%(B+2)]=i;
                    inq[i]=1;
                    tail++;
                }
            }
        }
    }
}
