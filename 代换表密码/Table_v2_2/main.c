#include <stdio.h>
#include <stdlib.h>

//����
void encrypt();

int main()
{
    encrypt();
    return 0;
}



void encrypt()
{
    char T[27]={'q','w','e','r','t','y','u', 'i','o','p','a','s','d','f', 'g','h','j','k','l','z','x','c','v','b','n','m','\0'};
    const char* srcfile= "mingwen.txt";
    const char* resfile= "miwen.txt";
    FILE *fin,*fout;
    char ch,s;
    int k;

    //��ȡ�ļ�
    fin=fopen(srcfile, "r");
    if(fin==NULL)
    {
        printf("��ȡ%sʧ�ܣ�\n", srcfile);
        exit(0);
    }

    //д���ļ�
    fout=fopen(resfile, "w");
    if(fout==NULL)
    {
        printf("��%sʧ�ܣ�\n", resfile);
        exit(0);
    }
    ch=fgetc(fin);

    printf("��ʼ�����ļ�%s���ַ�\n%c", srcfile, ch);
    while(ch!=EOF)
    {
        k=ch-'a';
        s=T[k];
        fputc(s, fout);
        ch = fgetc(fin);
        printf("%c", ch);
    }
    fclose(fin);
    fclose(fout);
    printf("\n�ļ����ܳɹ���\n");
}



