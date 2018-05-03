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
    char src[100];
    char res[100];
    int flag,key,i,j=0;
    printf("请输入一个字符串M（不可输入空白串）\n");
    gets(src);
    printf("请输入密钥：\n");
    scanf("%d", &key);
    printf("请选择是加密或者解密（0：加密 1：解密）：\n");
    scanf("%d", &flag);
    if(0==flag)
    {
        for(i=0;src[i]!='\0';i++)
        {
            if(src[i]>='a'&&src[i]<='z')
                res[j++]=(src[i]-'a'+key)%26+'a';
            else if(src[i]>='A'&&src[i]<='Z')
                res[j++]=(src[i]-'A'+key)%26+'A';
            else if(src[i]==' ')
                continue;
            else
                res[j++]=src[i];
        }

        res[j]='\0';
        printf("加密后的密文是：\n%s\n",res);
    }else if(1==flag)
    {
        for(i=0;src[i]!='\0';i++)
        {
            if(src[i]>='a'&&src[i]<='z')
                res[i]=(src[i]-'a'+26-key)%26+'a';
            else if(src[i]>='A'&&src[i]<='Z')
                res[i]=(src[i]-'A'+26-key)%26+'A';
            else
                res[i]=src[i];
        }

        res[j]='\0';
        printf("解密后的明文是：\n%s\n",res);
    }else
    {
        printf("输入出错！");
    }
}

