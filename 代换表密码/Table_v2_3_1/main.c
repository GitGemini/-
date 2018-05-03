#include <stdio.h>
#include <stdlib.h>


//ͳ����ĸƵ��
void statistics();
//����
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

    //��ȡ�ļ�
    fin=fopen(file, "r");
    if(fin==NULL)
    {
        printf("��ȡ%sʧ�ܣ�\n", file);
        exit(0);
    }
    ch=fgetc(fin);

    printf("��ʼͳ���ļ�%s���ַ�\n%c", file, ch);
    while(ch!=EOF)
    {
        k=ch-'a';
        T[k]++;
        ch = fgetc(fin);
        printf("%c", ch);
    }
    fclose(fin);

    printf("\nͳ�ƽ������ַ�Ƶ��Ϊ��\n");
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
        for(k=0;ch!=T[k];k++);//��λ��
        s=T[k];
        fputc(s, fout);
        ch = fgetc(fin);
        printf("%c", ch);
    }
    fclose(fin);
    fclose(fout);
    printf("\n�ļ����ܳɹ���\n");
}




