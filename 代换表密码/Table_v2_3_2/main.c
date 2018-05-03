#include <stdio.h>
#include <stdlib.h>

//统计字母频率
void statistics();
struct Letter
{
    char letter;
    int weight;
} T[26];


int main()
{
    statistics();
    return 0;
}

void statistics()
{
    //int T[26]={0};
    const char* file= "miwen.txt";
    const char* res= "result.txt";
    FILE *fin,*fout;
    char ch,buffer[20];
    int k,i,total=0;

    //读取文件
    fin=fopen(file, "r");
    if(fin==NULL)
    {
        printf("读取%s失败！\n", file);
        exit(0);
    }

    fout=fopen(res, "w");
    if(fout==NULL)
    {
        printf("读取%s失败！\n", res);
        exit(0);
    }

    printf("开始统计文件%s中字符\n", file);
    ch=fgetc(fin);
    while(ch!=EOF)
    {
        k=ch-'a';
        T[k].weight++;
        ch = fgetc(fin);
    }

    for(i=0;i<26;i++)
    {
        T[i].letter = 'a'+i-32;
        total+=T[i].weight;
    }
    //排序
    struct Letter temp;
    for(i=0;i<26;i++)
    {
        for(k=i+1;k<26;k++)
        {
            if(T[i].weight<T[k].weight)
            {
                temp=T[i];
                T[i]=T[k];
                T[k]=temp;
            }
        }
    }
    printf("\n统计结束!\n总字符个数为：%d\n字符频率表为：\n", total);

    k=0;
    for(i=0;i<26;i++)
    {
        float fre = ((float)T[i].weight/total)*100;
        sprintf(buffer, "%c  %7.4f %%\t", T[i].letter, fre);
        printf("%s", buffer);
        fprintf(fout, buffer);
        if(++k==4)
        {
            k=0;
            printf("\n");
            fprintf(fout, "\n");
        }
    }

    fclose(fin);
    fclose(fout);
}
