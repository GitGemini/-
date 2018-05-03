#include <stdio.h>
#include <stdlib.h>

void decrypt();

int main()
{
    //解密
    decrypt();
    return 0;
}

void decrypt()
{
    char mingwen[100];
    char miwen[100];
    int k,i;
    printf("请输入小写字母的密文M（不可输入空白串）\n");
    gets(miwen);
    for(k=1;k<=25;k++)
    {
        for(i=0;miwen[i]!='\0';i++)
        mingwen[i]=(miwen[i]-'a'-k+26)%26+'a';

        mingwen[i]='\0';
        printf("第%d种可能的明文是：\n%s\n",k,mingwen);
    }
}
