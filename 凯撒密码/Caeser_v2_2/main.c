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
    //写入文件
    if((fout=fopen(resfile, "w+"))==NULL)
    {
        printf("打开文件失败！\n");
        return;
    }
    printf("正在解密...\n");

    for(j=1;j<=25;j++)
    {
        for(i=0;src[i]!='\0';i++)
            res[i]=(src[i]-'a'-j+26)%26+'a';

        res[i]='\0';
        printf("第%d种可能的明文是：\n%s\n",j,res);



        for(i=0;res[i]!='\0';i++)
        {
            fputc((int)res[i], fout);
        }
        fputc('\n', fout);
        printf("文件保存成功！\n");

    }
    fputc(EOF, fout);
    fclose(fin);
    fclose(fout);
}
