#include <stdio.h>
#include <stdlib.h>

void caeser();

int main()
{
    caeser();
    return 0;
}

void caeser()
{
    char src[255];
    char res[255];
    const char* srcfile= "miwen.txt";
    const char* resfile= "mingwen.txt";
    int ch,i,j,k=0;
    FILE *fin,*fout;

    //��ȡ�ļ�
    if((fin=fopen(srcfile, "r"))==NULL)
    {
        printf("��ȡ�ļ�ʧ�ܣ�\n");
        return;
    }
    ch = fgetc(fin);
    while(ch!=EOF)
    {   src[k++] = (char)ch;
        ch = fgetc(fin);
    }
    src[k]='\0';
    printf("%s\n", src);
    //д���ļ�
    if((fout=fopen(resfile, "w+"))==NULL)
    {
        printf("���ļ�ʧ�ܣ�\n");
        return;
    }
    printf("���ڽ���...\n");

    for(j=1;j<=25;j++)
    {
        for(i=0;src[i]!='\0';i++)
            res[i]=(src[i]-'a'-j+26)%26+'a';

        res[i]='\0';
        printf("��%d�ֿ��ܵ������ǣ�\n%s\n",j,res);



        for(i=0;res[i]!='\0';i++)
        {
            fputc((int)res[i], fout);
        }
        fputc('\n', fout);
        printf("�ļ�����ɹ���\n");

    }
    fputc(EOF, fout);
    fclose(fin);
    fclose(fout);
}
