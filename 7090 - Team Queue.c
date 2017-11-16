#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int team[1000000];
int tail[1001], head[1001];
int que[1001][1001];
int tque[200001], istque[1001];

int main(){
    int T, I=1 ,isprint;
    int i, j, n, x, qhead, qtail;
    char com[10];
    while(scanf("%d", &T)!=EOF && T){
        memset(team, -1, sizeof(team));
        memset(tail, -1, sizeof(tail));
        memset(head, -1, sizeof(head));
        memset(que, -1, sizeof(que));
        memset(tque, 0, sizeof(tque));
        memset(istque, 0, sizeof(istque));
        printf("Scenario #%d\n", I);
        I++;
        for(i=1;i<=T;i++){
            scanf("%d", &n);
            for(j=0;j<n;j++){
                scanf("%d", &x);
                team[x]=i;
            }
        }
        qtail=qhead=0;
        scanf("%s", com);
        while(com[0]!='S'){
            if(com[0]=='E'){
                scanf("%d", &x);
                if(!istque[team[x]]){
                    tque[qtail++]=team[x];
                    istque[team[x]]=1;
                }
                que[team[x]][tail[team[x]]++]=x;
            }
            else if(com[0]=='D'){
                isprint=0;
                for(i=qhead;i<qtail;i++){
                    if(istque[tque[i]] && que[tque[i]][head[tque[i]]]!=-1){
                        isprint=1;
                        printf("%d\n", que[tque[i]][head[tque[i]]]);
                        que[tque[i]][head[tque[i]]]=-1;
                        head[tque[i]]++;
                    }
                    if(head[tque[i]]==tail[tque[i]]){
                        istque[tque[i]]=0;
                        qhead++;
                    }
                    if(isprint) break;
                }
            }
            scanf("%s", com);
        }
        printf("\n");
    }
    return 0;
}
