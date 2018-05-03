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

    //读取文件
    if((fin=fopen(srcfile, "r"))==NULL)
    {
        printf("读取文件失败！\n");
        return;
    }
    ch = fgetc(fin);
    while(ch!=EOF)
    {   src[k++] = (char)ch;
        ch = fgetc(fin);
    }
    src[k]='\0';
    printf("%s\n", src);

    printf("请输入密钥：\n");
    scanf("%d", &key);
    printf("请选择是加密或者解密（0：加密 1：解密）：\n");
    scanf("%d", &flag);
    if(0==flag)
    {
        printf("正在加密...\n");
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
        printf("\n加密后的密文是：\n%s\n",res);
    }else if(1==flag)
    {
        printf("正在解密...\n");
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
        printf("\n解密后的明文是：\n%s\n",res);

    }else
    {
        printf("输入出错！");
    }
    //写入文件
    if((fout=fopen(resfile, "w+"))==NULL)
    {
        printf("打开文件失败！\n");
        return;
    }
    for(i=0;res[i]!='\0';i++)
    {
        fputc((int)res[i], fout);
    }
    fputc(EOF, fout);
    printf("文件保存成功！\n");

    fclose(fin);
    fclose(fout);
}

