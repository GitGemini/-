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
    const char* srcfile= "mingwen.txt";
    const char* resfile= "result.txt";
    int flag,key,ch,i,j=0,k=0;
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

    printf("��������Կ��\n");
    scanf("%d", &key);
    printf("��ѡ���Ǽ��ܻ��߽��ܣ�0������ 1�����ܣ���\n");
    scanf("%d", &flag);
    if(0==flag)
    {
        printf("���ڼ���...\n");
        for(i=0;src[i]!='\0';i++)
        {
            if(src[i]>='a'&&src[i]<='z')
                res[j++]=(src[i]-'a'+key)%26+'a';
            else if(src[i]>='A'&&src[i]<='Z')
                res[j++]=(src[i]-'A'+key)%26+'A';
            else if(src[i]==' '||src[i]=='\n')
                continue;
            else
                res[j++]=src[i];
        }
        res[j]='\0';
        printf("\n���ܺ�������ǣ�\n%s\n",res);
    }else if(1==flag)
    {
        printf("���ڽ���...\n");
        for(i=0;src[i]!='\0';i++)
        {
            printf("%d",i);
            if(src[i]>='a'&&src[i]<='z')
                res[i]=(src[i]-'a'+26-key)%26+'a';
            else if(src[i]>='A'&&src[i]<='Z')
                res[i]=(src[i]-'A'+26-key)%26+'A';
            else
                res[i]=src[i];
        }
        res[i]='\0';
        printf("\n���ܺ�������ǣ�\n%s\n",res);

    }else
    {
        printf("�������");
    }
    //д���ļ�
    if((fout=fopen(resfile, "w+"))==NULL)
    {
        printf("���ļ�ʧ�ܣ�\n");
        return;
    }
    for(i=0;res[i]!='\0';i++)
    {
        fputc((int)res[i], fout);
    }
    fputc(EOF, fout);
    printf("�ļ�����ɹ���\n");

    fclose(fin);
    fclose(fout);
}

