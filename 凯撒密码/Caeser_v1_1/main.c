#include <stdio.h>
#include <stdlib.h>

void decrypt();
void encrypt();

int main()
{
    //加密
    encrypt();

    //解密
    decrypt();
    return 0;
}

void encrypt()
{
    char mingwen[100];
    char miwen[100];
    int k=3,i;
    printf("请输入小写字母的明文M（不可输入空白串）\n");
    gets(mingwen);
    for(i=0;mingwen[i]!='\0';i++)
        miwen[i]=(mingwen[i]-'a'+k)%26+'a';

    miwen[i]='\0';
    printf("加密后的密文是：\n%s\n",miwen);
}

void decrypt()
{
    char mingwen[100];
    char miwen[100];
    int k=3,i;
    printf("请输入小写字母的密文M（不可输入空白串）\n");
    gets(miwen);
    for(i=0;miwen[i]!='\0';i++)
        mingwen[i]=(miwen[i]-'a'-k+26)%26+'a';

    mingwen[i]='\0';
    printf("解密后的明文是：\n%s\n",mingwen);
}


