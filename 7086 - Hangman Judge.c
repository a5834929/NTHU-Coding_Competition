#include<stdio.h>
#include<string.h>

int main(void)
{
    int round, i, num, wrong, correct;
    char ans[100], input[100];

    while(EOF!=scanf("%d", &round) && round!=-1)
    {
        int alpha[50]={0};
        num=0;
        wrong=0;
        correct=0;
        scanf("%100s", ans);
        scanf("%100s", input);

        for(i=0;i<strlen(ans);i++) alpha[ans[i]-'a']=1;

        for(i=0;i<26;i++)
        {
            if(alpha[i]==1) num++;
        }

        for(i=0;i<strlen(input);i++)
        {
            if(alpha[input[i]-'a']==1)
            {
                correct++;
                alpha[input[i]-'a']=-1;
            }
            else
            {
                wrong++;
                alpha[input[i]-'a']=-1;
            }
            if(correct==num || wrong==7) break;
        }

        if(correct==num && wrong<7) printf("Round %d\nYou win.\n", round);
        if(correct!=num && wrong<7) printf("Round %d\nYou chickened out.\n", round);
        if(correct!=num && wrong>=7) printf("Round %d\nYou lose.\n", round);
    }

    return 0;
}

/**************************************************

Problem Description
Hangman Judge�O�@�Ӳq�^���r���p�C���]�b�q�l�r�夤�`�|�ݨ�^�A�C���W�h�p�U�G

���׳�r�g�b�ȤW�]�C�Ӧr���@�i�ȡ^�A�åB�Q�\�_�ӡA���a�C���q�@�ӭ^��r���]letter�^�C
�p�G�o�ӭ^��r���q���]�b���ת��^���r�����X�{�^�A�Q�q�����r���N�Q½�}�C
�Ҧp�G���׬Obook�A�p�G�A�qo�Abook�������o�N�|�Q�����w�q���C
�p�G�o�ӭ^��r�����X�{�b���ת���r���A�N�|�bhangman���Ϥ��h�[�@���C
�n����hangman�Ϧ@��7���A�p�U�ϡC�`�N�G�P�@�Ӳq�����r���u��A�ϤW�e�@���A
�Ҧp�G���׬Obook�A�Ĥ@���A�qa�]���q���^�|�b�ϤW�e�@���A���ĤG���H��A�qa�ä��|�A�h�e�C
�p�G�bhangman�ϧ������e�A���a�w�q���Ҧ����פ����r���A�h���aĹ�]win�^�C
�p�G���a�|���q���Ҧ����פ����r����hangman�ϧ����F�A�A�h���a��]lose�^�C
�p�G���a�b�٨S��Ĺ�����p���U�N�����F�A���ڭ̻����a�x�p���F�]chicken out�^.

�s�w�s�w
�x ��
�x���x�@
�x  �x
�x���@
�z�r�{
�x �|�w�s
�|�w�w�w�}
�A�����ȴN�O�n�g�@�ӵ{���ھڵ��פΪ��a��J���q���ӧP�_���a�OĹ�B��B�Ω��C

Input
�|���n�X�մ��ո�ơA�C�@�զ�3�C�C�Ĥ@�C���@�ӼƦrn�A�N��ĴX�^�X�A�ĤG�C���o�@�^�X�����סA�ĤT�C���o�@�^�X���a��J���q���C�p�G n = -1�N���J�����C

Output
�п�X�C�@�^�X�ιC�����G�C�C�����G�u���T�إi��G
You win.
You lose.
You chickened out.

�аѦ�sample output�C

Sample Input
1
cheese
chese
2
cheese
abcdefg
3
cheese
abcdefgij
-1

Sample Output
Round 1
You win.
Round 2
You chickened out.
Round 3
You lose.

**************************************************/
