#include<stdio.h>
#include<string.h>
#define MAX(a, b) ((a)>(b)?(a):(b))
int dp[1001][1001];
int main(){
    int i, j, len1, len2;
    char str1[1001], str2[1001];

    while(gets(&str1[1])!=NULL){
        gets(&str2[1]);
        len1=strlen(&str1[1]);
        len2=strlen(&str2[1]);
        memset(dp, 0, sizeof(dp));
        for(i=1;i<=len1;i++){
            for(j=1;j<=len2;j++){
                if(str1[i]==str2[j])
                    dp[i][j]=MAX(dp[i-1][j], MAX(dp[i][j-1], dp[i-1][j-1]+1));
                else
                    dp[i][j]=MAX(dp[i-1][j], dp[i][j-1]);
            }
        }
        printf("%d\n", dp[len1][len2]);
    }
    return 0;
}

/**********************************************************************************

Problem Description
Given two sequences of characters, print the length of the longest common subsequence
of both sequences.
For example, the longest common subsequence of the following two sequences:

abcdgh aedfhr
is adh of length 3.

Input consists of pairs of lines.
The first line of a pair contains the first string and the second line contains
the second string. Each string is on a separate line and consists of at most 1,000 characters

For each subsequent pair of input lines, output a line containing one integer number
which satisfies the criteria stated above.

Sample Input
a1b2c3d4e
zz1yy2xx3ww4vv
abcdgh
aedfhr
abcdefghijklmnopqrstuvwxyz
a0b0c0d0e0f0g0h0i0j0k0l0m0n0o0p0q0r0s0t0u0v0w0x0y0z0
abcdefghijklmnzyxwvutsrqpo
opqrstuvwxyzabcdefghijklmn

Sample Output
4
3
26
14

*************************************************************************************/
