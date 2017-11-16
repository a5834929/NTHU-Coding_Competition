#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void DFS(int s);
void DFS2(int s);
int sch[105][105], vis[105], done[105], scc[105];
int in[105], out[105];
int n, m, n_scc;

int main(void){

    int i, j, x, ans1, ans2;
    while(scanf("%d", &n)!=EOF){

        memset(sch, 0, sizeof(sch));
        memset(vis, 0, sizeof(vis));
        memset(done, 0, sizeof(done));
        memset(scc, 0, sizeof(scc));
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));

        for(i=1;i<=n;i++){
            scanf("%d", &x);
            while(x){
                sch[i][x]=1;
                scanf("%d", &x);
            }
        }

        m=0;
        for(i=1;i<=n;i++){
            if(!vis[i]){
                vis[i]=1;
                DFS(i);
            }
        }

        n_scc=1;
        for(i=m-1;i>=0;i--){
            if(!scc[done[i]]){
                scc[done[i]]=n_scc;
                DFS2(done[i]);
                n_scc++;
            }
        }

        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(sch[i][j] && scc[i]!=scc[j]){
                    in[scc[j]]++;
                    out[scc[i]]++;
                }
            }
        }

        ans1=0;
        ans2=0;
        for(i=1;i<n_scc;i++){
            if(!in[i])
                ans1++;
            if(!out[i])
                ans2++;
        }

        if(n_scc>2)
            printf("%d\n%d\n", ans1, (ans1>=ans2)?ans1:ans2);
        else
            printf("1\n0\n");
    }

    return 0;
}

void DFS(int s){
    int i;
    for(i=1;i<=n;i++){
        if(sch[s][i] && !vis[i]){
            vis[i]=1;
            DFS(i);
        }
    }
    done[m]=s;
    m++;
    return;
}
void DFS2(int s){
    int i;
    for(i=1;i<=n;i++){
        if(sch[i][s] && !scc[i]){
            scc[i]=scc[s];
            DFS2(i);
        }
    }
    return;
}

/************************************************************************

Problem Description
A number of schools are connected to a computer network.
Agreements have been developed among those schools:
each school maintains a list of schools to which it distributes software
(the ¡§receiving schools¡¨).
Note that if B is in the distribution list of school A,
then A does not necessarily appear in the list of school B
You are to write a program that computes the minimal number of schools
that must receive a copy of the new software in order for the software
to reach all schools in the network according to the agreement (Subtask A).
As a further task, we want to ensure that by sending the copy of new software
to an arbitrary school, this software will reach all schools in the network.
To achieve this goal we may have to extend the lists of receivers by new members.
Compute the minimal number of extensions that have to be made
so that whatever school we send the new software to,
it will reach all other schools (Subtask B).
One extension means introducing one new member into the list of receivers of one school.

Input
The first line contains an integer N: the number of schools in the network (2 <= N <= 100).
The schools are identified by the first N positive integers.
Each of the next N lines describes a list of receivers.
The line i+1 contains the identifiers of the receivers of school i.
Each list ends with a 0. An empty list contains a 0 alone in the line.

Output
Your program should write two lines to the standard output.
The first line should contain one positive integer: the solution of subtask A.
The second line should contain the solution of subtask B.

Sample Input
5
2 4 3 0
4 5 0
0
0
1 0

Sample Output
1
2

******************************************************************************/
