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

//1 ʹ��fgetc()
void edit1()
{
    const char* srcfile= "source.txt";
    const char* resfile= "mingwen.txt";
    FILE *fin,*fout;
    char ch;

    //��ȡ�ļ�
    fin=fopen(srcfile, "r");
    if(fin==NULL)
    {
        printf("��ȡ%sʧ�ܣ�\n", srcfile);
        exit(0);
    }

    //д���ļ�
    fout=fopen(resfile, "w+");
    if(fout==NULL)
    {
        printf("��%sʧ�ܣ�\n", resfile);
        exit(0);
    }
    ch=fgetc(fin);
    printf("��ʼ�����ļ�\n%c", ch);
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
    printf("�ļ�����ɹ���\n");
}

//2 ʹ��fscanf()
void edit2()
{
    const char* srcfile= "source.txt";
    const char* resfile= "mingwen.txt";
    FILE *fin,*fout;
    char word[30];

    //��ȡ�ļ�
    fin=fopen(srcfile, "r");
    if(fin==NULL)
    {
        printf("��ȡ%sʧ�ܣ�\n", srcfile);
        exit(0);
    }

    //д���ļ�
    fout=fopen(resfile, "w+");
    if(fout==NULL)
    {
        printf("��%sʧ�ܣ�\n", resfile);
        exit(0);
    }

    printf("��ʼ�����ļ�\n");
    while(!feof(fin))
    {
        fscanf(fin, "%s", word);
        printf("%s\t", word);
        fprintf(fout, "%s", word);
    }
    fclose(fin);
    fclose(fout);
    printf("�ļ�����ɹ���\n");
}

#define SIZE 1024

//3 ʹ��fread()
void edit3()
{
    const char* srcfile= "source.txt";
    const char* resfile= "mingwen.txt";
    FILE *fin,*fout;
    char buffer[SIZE];
    int count;

    //��ȡ�ļ�
    fin=fopen(srcfile, "r");
    if(fin==NULL)
    {
        printf("��ȡ%sʧ�ܣ�\n", srcfile);
        exit(0);
    }

    //д���ļ�
    fout=fopen(resfile, "w+");
    if(fout==NULL)
    {
        printf("��%sʧ�ܣ�\n", resfile);
        exit(0);
    }

    printf("��ʼ�����ļ�\n");

    while(!feof(fin))
    {
        count = fread (buffer, sizeof (char), SIZE, fin);
        printf ("%d,%s\n", count, buffer);
        fwrite(buffer, sizeof(char), count, fout);
    }
    fclose(fin);
    fclose(fout);
    printf("�ļ�����ɹ���\n");
}

