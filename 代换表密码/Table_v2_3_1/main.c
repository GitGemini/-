#include <stdio.h>
#include <stdlib.h>


//统计字母频率
void statistics();
//解密
void decrypt();

int main()
{
    statistics();
    //decrypt();
    return 0;
}

void statistics()
{
    int T[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    const char* file= "miwen.txt";
    FILE *fin;
    char ch;
    int k,i,total=0;

    //读取文件
    fin=fopen(file, "r");
    if(fin==NULL)
    {
        printf("读取%s失败！\n", file);
        exit(0);
    }
    ch=fgetc(fin);

    printf("开始统计文件%s中字符\n%c", file, ch);
    while(ch!=EOF)
    {
        k=ch-'a';
        T[k]++;
        ch = fgetc(fin);
        printf("%c", ch);
    }
    fclose(fin);

    printf("\n统计结束，字符频率为：\n");
    for(i=0;i<26;i++)
    {
        total+=T[i];
    }
    k=0;
    for(i=0;i<26;i++)
    {
        ch='a'+i-32;
        float fre = ((float)T[i]/total)*100;
        printf("%c  %7.4f %%\t", ch, fre);
        if(++k==4)
        {
            k=0;
            printf("\n");
        }
    }
}

void decrypt()
{
    char T[26]={'q','w','e','r','t','y','u', 'i','o','p','a','s','d','f', 'g','h','j','k','l','z','x','c','v','b','n','m'};
    const char* srcfile= "miwen.txt";
    const char* resfile= "mingwen.txt";
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

    printf("开始解密文件%s中字符\n%c", srcfile, ch);
    while(ch!=EOF)
    {
        for(k=0;ch!=T[k];k++);//求位置
        s=T[k];
        fputc(s, fout);
        ch = fgetc(fin);
        printf("%c", ch);
    }
    fclose(fin);
    fclose(fout);
    printf("\n文件解密成功！\n");
}




