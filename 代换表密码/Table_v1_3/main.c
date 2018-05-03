#include <stdio.h>

void getTable();
void decrypt();
void encrypt();

char T[26]={'q','w','e','r','t','y','u', 'i','o','p','a','s','d','f', 'g','h','j','k','l','z','x','c','v','b','n','m'};

int main()
{
    getTable();
    //加密
    encrypt();

    //解密
    decrypt();
    return 0;
}

void getTable()
{
    printf("请输入26代换表:\n");
    gets(T);
}

void encrypt()
{
    char mingwen[100];
    int k,j,i=0,n=0;
    printf("请输入小写字母的明文M（不可输入空白串）\n");
    gets(mingwen);
    printf("请输入加密次数：\n");
    scanf("%d", &n);
    getchar();
    for(j=0;j<n;j++)
    {
        i=0;
        while(mingwen[i]!='\0')
        {
            char S=mingwen[i];
            if('A'<=S && S<='Z')
                S+=32;

            k=S-'a';
            mingwen[i]=T[k];
            i++;
        }
        printf("第%d次加密后的密文是:\n%s\n",j+1,mingwen);
    }

    //printf("加密后的密文是:\n%s\n",mingwen);
}

void decrypt()
{
    char miwen[100];
    int k,j,i=0,n;
    printf("请输入小写字母的密文M（不可输入空白串）\n");
    gets(miwen);
    printf("请输入解密次数：\n");
    scanf("%d", &n);
    for(j=0;j<n;j++)
    {
        i=0;
        while(miwen[i]!='\0')
        {
            char S=miwen[i];
            if('A'<=S && S<='Z')
                S+=32;

            k=0;
            while(S!=T[k])
                k++;

            miwen[i]='a'+k;
            i++;
        }
        printf("第%d次解密后的明文是:\n%s\n",j+1,miwen);
    }
}


