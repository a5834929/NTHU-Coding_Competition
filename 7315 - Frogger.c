#include<stdio.h>
#include<string.h>
#include<math.h>
int map[250][250];
double max(double a, double b);
double min(double a, double b);
double X[250], Y[250];
double dis[250][250];
void Floyd(int n);
int main(){
    int I=1, N, i, j;
    double x, y;
    while(scanf("%d", &N)!=EOF && N){
        memset(dis, 0, sizeof(dis));
        for(i=0;i<N;i++)
            scanf("%lf%lf", &X[i], &Y[i]);
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                x=X[i]-X[j];
                y=Y[i]-Y[j];
                dis[i][j]=sqrt(x*x+y*y);
            }
        }
        Floyd(N);
        printf("Scenario #%d\n", I);
        printf("Frog Distance = %.3lf\n\n", dis[0][1]);
        I++;
    }
    return 0;
}

double max(double a, double b){
    return (a>b)?a:b;
}
double min(double a, double b){
    return (a<b)?a:b;
}
void Floyd(int n){
    int i, j, k;
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                dis[i][j]=min(dis[i][j], max(dis[i][k], dis[k][j]));
}
