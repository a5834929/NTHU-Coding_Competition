#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int i, j, len, idx;
	int C[50][50]={{0}};
	char s[10];

	while(scanf("%s", s)!=EOF)
    {
        C[0][0]=1;
        for(i=1;i<50;i++)
        {
            C[i][0]=1;
            for(j=1;j<=i;j++)
                C[i][j]=C[i-1][j-1]+C[i-1][j];
        }

        len=strlen(s);
		idx=0;
		for(i=1;i<len;i++)
		{
			if(s[i]<s[i-1])
			{
				printf("0\n");
				break;
			}
			idx+=C[26][i];
		}

		if(i!=len)
            continue;

		for(i=0;i<len;i++)
		{
			for(j=(i==0)?1:s[i-1]-'a'+2;j<=s[i]-'a';j++)
				idx+=C[26-j][len-i-1];
		}

		printf("%d\n", idx+1);
	}
    return 0;
}

/****************************************************************

Problem Description
�@��ӻ��b�s�X�]Encoding�^���޳N�`�`�Φb�[�K�A
�άO�n�����`�٪��q�T�P�x�s�Ŷ����ɭԡC
�b���A�ڭ̵o�i�F�@�M²�檺�s�X����k�A
�o��k�i�H�⤣�j��5�Ӧr���]���O�p�g�r���^
���S��r�����w�@�Ӱߤ@����ơC

�b�o�̩ҿת��S��r�O���b�o�Ӧr�̭��A
�U�@�Ӧr���@�w��W�@�ӨӪ��j�C�Ҧp�Gk�Bis�Babc�Baepx�Bgwxyz
���O�X�k���C��aab�Bare�Bcat�h���O�C

��C�@�ӦX�k���r�ڭ̮ھڦr�����׻P�r�������ǵ��L�@�Ӿ�ƽs���C
�]�N�O�G

a -> 1
b -> 2
.
.
z -> 26
ab -> 27
ac -> 28
.
.
az -> 51
bc -> 52
.
.
vwxyz -> 83681�@

�A�����ȴN�O�n���o�˪��s�X�C

Input
�C�����ո�Ƥ@�C�C�C�C��1�Ӧr�]1��5�Ӥp�g�r���^�C

Output
��C�@���ո�ơA�p�G�o�Ӧr���O�X�k���A�п�X0�C�_�h�п�X�Ӧr���s���C

Sample Input
z
a
cat
vwxyz

Sample Output
26
1
0
83681

****************************************************************/
