#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int min(int a, int b){
    return (a<b)?a:b;
}
int max(int a, int b){
    return (a>b)?a:b;
}

typedef struct P{
    int x, y;
}POLYGON;
POLYGON poly[10002], q, inf;

typedef struct R{
    int lx, ly, ux, uy;
}RECTANGLE;
RECTANGLE rec1, rec2;

int EXCLUDE(RECTANGLE r1, RECTANGLE r2){
    if(r1.lx>r2.ux) return 0;
    if(r1.ly>r2.uy) return 0;
    if(r1.ux<r2.lx) return 0;
    if(r1.uy<r2.ly) return 0;
    return 1;
}

int CROSS(POLYGON p1, POLYGON p2, POLYGON q, POLYGON inf){
    long long int X1, X2, X3, X4;
    X1=(long long int)(p1.x-q.x)*(p2.y-q.y)-(long long int)(p1.y-q.y)*(p2.x-q.x);
    X2=(long long int)(p1.x-inf.x)*(p2.y-inf.y)-(long long int)(p1.y-inf.y)*(p2.x-inf.x);
    X3=(long long int)(q.x-p1.x)*(inf.y-p1.y)-(long long int)(q.y-p1.y)*(inf.x-p1.x);
    X4=(long long int)(q.x-p2.x)*(inf.y-p2.y)-(long long int)(q.y-p2.y)*(inf.x-p2.x);
    if((X1*X2<0) && (X3*X4<0)) return 1;
    else return 0;
}

int On_E_or_V(POLYGON p1, POLYGON p2, POLYGON q){
    long long int X=1;
    if((p1.x-q.x)*(p2.x-q.x)<=0 && (p1.y-q.y)*(p2.y-q.y)<=0)
        X=(long long int)(p1.x-q.x)*(p2.y-q.y)-(long long int)(p1.y-q.y)*(p2.x-q.x);
    if(X==0) return 1;
    return 0;
}

RECTANGLE MAKEREC(POLYGON p1, POLYGON p2){
    RECTANGLE rec;
    rec.lx=min(p1.x, p2.x);
    rec.ly=min(p1.y, p2.y);
    rec.ux=max(p1.x, p2.x);
    rec.uy=max(p1.y, p2.y);
    return rec;
}

int main(){
    int T, N, Q, i, flag;

    scanf("%d", &T);
    while(T--){
        inf.x=-20001;
        scanf("%d", &N);
        for(i=0;i<N;i++){
            scanf("%d%d", &poly[i].x, &poly[i].y);
            inf.x=(inf.x>poly[i].x)?inf.x:poly[i].x;
        }
        scanf("%d", &Q);
        while(Q--){
            flag=0;
            scanf("%d%d", &q.x, &q.y);
            inf.y=q.y+1;
            inf.x=inf.x+1;
            rec1=MAKEREC(q, inf);
            for(i=0;i<N;i++){
                if(On_E_or_V(poly[i%N], poly[(i+1)%N], q)){
                    flag=0;
                    break;
                }
                rec2=MAKEREC(poly[i%N], poly[(i+1)%N]);
                if(EXCLUDE(rec1, rec2))
                    flag+=CROSS(poly[i%N], poly[(i+1)%N], q, inf);
            }
            if(flag%2)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
