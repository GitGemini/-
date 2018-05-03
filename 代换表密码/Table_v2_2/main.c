#include <stdio.h>
#include <stdlib.h>

//加密
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

    //读取文件
    fin=fopen(srcfile, "r");
    if(fin==NULL)
    {
        printf("读取%s失败！\n", srcfile);
        exit(0);
    }

    //写入文件
    fout=fopen(resfile, "w");
    if(fout==NULL)
    {
        printf("打开%s失败！\n", resfile);
        exit(0);
    }
    ch=fgetc(fin);

    printf("开始加密文件%s中字符\n%c", srcfile, ch);
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
    printf("\n文件加密成功！\n");
}



