#include<stdio.h>
#include<string.h>
#define Min(a, b) ((a)<(b)?(a):(b))
int dis[4005][4005];
int main(){
    char str1[4005], str2[4005];
    int i, j, a, n, m;

    while(scanf("%s%s", &str1[1], &str2[1])!=EOF){
        n=strlen(&str1[1]);
        m=strlen(&str2[1]);
        for(i=0;i<=n;i++){
            for(j=0;j<=m;j++){
                if(i==0 && j!=0)
                    dis[0][j]=j;
                else if(i!=0 && j==0)
                    dis[i][0]=i;
                else if(i!=0 && j!=0){
                    if(str1[i]!=str2[j])
                        a=1;
                    else
                        a=0;
                    dis[i][j]=Min(dis[i-1][j]+1, Min(dis[i][j-1]+1, dis[i-1][j-1]+a));
                }
            }
        }
        printf("%d\n", dis[n][m]);
    }
    return 0;
}

/*********************************************************************

Problem Description
Edit distance is to measure the difference between two strings.
There are three types of edit operations that can be used to change a given string S:
(1) Substitution: replace a character of S by a different character.
For example, ¡§cut¡¨ can be changed to ¡§cat¡¨ by replacing ¡§u¡¨ with ¡§a¡¨.
(2) Insertion: insert a single character into S.
For example, ¡§cat¡¨ can be changed to ¡§cats¡¨ by inserting ¡§s¡¨ at the end of ¡§cat¡¨.
(3) Deletion: delete a single character from S.
For example, ¡§cats¡¨ can be changed to ¡§cat¡¨ again by deleting ¡§s¡¨ from ¡§cats¡¨.
Given two strings S1 and S2, the edit distance between S1 and S2 is defined as
the minimum number of edit operations required to transform S1 to S2.

Input
Each case consists of two lines. Each line contains a string of lowercase characters,
with the first line representing S1 and the second representing S2.
The length of each string is no more than 4000.

Output
Print the edit distance between S1 and S2.

Hint
Suppose that S1 and S2 are strings with n and m characters, respectively.
Let S1[1..n] and S2[1..m] denote these two strings.
Now, we can define a function Dist(x, y) to give the edit distance between
the strings S1[1..x] and S2[1..y].
It is easy to check that Dist(x, y) satisfies the following rules:

¡´Dist(x, 0) = x for all x = 0, 1, 2, ¡K, n;
¡´Dist(0, y) = y for all y = 0, 1, 2, ¡K, m;
¡´Dist(x, y) = min { Dist(x ¡V 1, y)+1, Dist(x, y ¡V 1)+1, Dist(x ¡V 1, y ¡V 1)+a }
if x > 0 and y > 0, where a = 1 if S1[x] is not the same as S2[y]; otherwise, a = 0.

The required answer will be the value of Dist(n, m).
You should store the value of each entry Dist(i, j) or you may not pass all of the test case

Sample Input
ywcqpgk
lawyqqkpgka
sunday
saturday
kitchennofood
kittenseekhost
accggtcgagtgcgc
gcgttcggttgctct
dynamicprogrammingstrategy
programmingstrategydynamic

Sample Output
6
3
9
7
14

**********************************************************************/
