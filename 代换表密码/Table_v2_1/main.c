#include <stdio.h>
#include <stdlib.h>

void edit1();
void edit2();
void edit3();

int main()
{
    edit1();
    //edit2();
    //edit3();
    return 0;
}

//1 使用fgetc()
void edit1()
{
    const char* srcfile= "source.txt";
    const char* resfile= "mingwen.txt";
    FILE *fin,*fout;
    char ch;

    //读取文件
    fin=fopen(srcfile, "r");
    if(fin==NULL)
    {
        printf("读取%s失败！\n", srcfile);
        exit(0);
    }

    //写入文件
    fout=fopen(resfile, "w+");
    if(fout==NULL)
    {
        printf("打开%s失败！\n", resfile);
        exit(0);
    }
    ch=fgetc(fin);
    printf("开始整理文件\n%c", ch);
    while(ch!=EOF)
    {
        if(ch>='A'&&ch<='Z')
        {
            ch=ch+32;
        }
        if(ch>='a'&&ch<='z')
        {
            fputc(ch, fout);
        }
        ch = fgetc(fin);
        printf("%c", ch);
    }
    fclose(fin);
    fclose(fout);
    printf("文件保存成功！\n");
}

//2 使用fscanf()
void edit2()
{
    const char* srcfile= "source.txt";
    const char* resfile= "mingwen.txt";
    FILE *fin,*fout;
    char word[30];

    //读取文件
    fin=fopen(srcfile, "r");
    if(fin==NULL)
    {
        printf("读取%s失败！\n", srcfile);
        exit(0);
    }

    //写入文件
    fout=fopen(resfile, "w+");
    if(fout==NULL)
    {
        printf("打开%s失败！\n", resfile);
        exit(0);
    }

    printf("开始整理文件\n");
    while(!feof(fin))
    {
        fscanf(fin, "%s", word);
        printf("%s\t", word);
        fprintf(fout, "%s", word);
    }
    fclose(fin);
    fclose(fout);
    printf("文件保存成功！\n");
}

#define SIZE 1024

//3 使用fread()
void edit3()
{
    const char* srcfile= "source.txt";
    const char* resfile= "mingwen.txt";
    FILE *fin,*fout;
    char buffer[SIZE];
    int count;

    //读取文件
    fin=fopen(srcfile, "r");
    if(fin==NULL)
    {
        printf("读取%s失败！\n", srcfile);
        exit(0);
    }

    //写入文件
    fout=fopen(resfile, "w+");
    if(fout==NULL)
    {
        printf("打开%s失败！\n", resfile);
        exit(0);
    }

    printf("开始整理文件\n");

    while(!feof(fin))
    {
        count = fread (buffer, sizeof (char), SIZE, fin);
        printf ("%d,%s\n", count, buffer);
        fwrite(buffer, sizeof(char), count, fout);
    }
    fclose(fin);
    fclose(fout);
    printf("文件保存成功！\n");
}

