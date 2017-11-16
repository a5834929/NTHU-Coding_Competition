#include<stdio.h>
#include<string.h>

int main(void)
{
    char str1[12], str2[12];
    char num1[12]={0}, num2[12]={0}, num3[12]={0};
    int i, len1, len2, len_max;

    while(EOF!=scanf("%20s %20s", str1, str2))
    {
        int carry=0, crycnt=0;

        if(str1[0]=='0' && str2[0]=='0') break;
        else
        {
            len1=strlen(str1);
            len2=strlen(str2);
            len_max=(len1>=len2)?len1:len2;

            for(i=0;i<len1;i++) num1[len1-i-1]=str1[i]-'0';

            for(i=0;i<len2;i++) num2[len2-i-1]=str2[i]-'0';

            for(i=0;i<len_max;i++) num3[i]=num1[i]+num2[i];

            for(i=0;i<len_max;i++)
            {
                num3[i]+=carry;
                carry=num3[i]/10;
                num3[i]=num3[i]%10;
                num1[i]=0;
                num2[i]=0;

                if(carry!=0) crycnt++;
            }

            if(crycnt==0) printf("No carry operation.\n");
            else if(crycnt==1) printf("1 carry operation.\n");
            else printf("%d carry operations.\n", crycnt);
        }
    }

    return 0;
}

/*****************************************************

Problem Description
�b�p�Ǯɧڭ̳����L�[�k���B��A�N�O��2�Ӿ�ƾa�k����M��A
�ѥk�ܥ��@��@��ۥ[�C�p�G�ۥ[�����G�j�󵥩�10�N���i��
�]carry�^�����p�X�{�C�A�����ȴN�O�n�P�_2�Ӿ�Ƭۥ[�ɲ��ͤF
�X���i�쪺���p�C�o�N���U�p�ǦѮv���R�[�k�D�ت����סC

Input
�C�@�C���ո�Ʀ�2�ӥ���ơA���ק��p��10��C�̫�@�C��2��0�N���J�����C

Output
�C�C���ո�ƿ�X��2�Ƭۥ[�ɲ��ͦh�֦��i��A�аѦ�Sample Output�C
�`�N�i��W�L1����operation���[s

Sample Input
123 456
555 555
123 594
0 0

Sample Output
No carry operation.
3 carry operations.
1 carry operation.

****************************************************/
