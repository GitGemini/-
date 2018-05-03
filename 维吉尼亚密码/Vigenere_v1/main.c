#include <stdio.h>
#include <stdlib.h>

void vigenere();

int main()
{
    vigenere();
}

void vigenere()
{
    int i,j,len,k;
    char key[10];
    const int SIZE = 25000;
    char plain[SIZE];
    char cipher[SIZE];

    printf("请输入小写加密关键字：\n");
    gets(key);
    len=strlen(key);
    printf("请输入小写明文：\n");
    gets(plain);
    for(i=0;plain[i]!='\0';i++){
        j = i%len;
        k = key[j]-'a';
        cipher[i] = (plain[i]-'a'+k)%26+'a';
    }
    cipher[i]='\0';
    printf("加密后的密文是：\n%s\n",cipher);
}
