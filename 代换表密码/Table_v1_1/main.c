#include <stdio.h>

void decrypt();
void encrypt();

char T[26]={'q','w','e','r','t','y','u', 'i','o','p','a','s','d','f', 'g','h','j','k','l','z','x','c','v','b','n','m'};

int main()
{
    //����
    encrypt();

    //����
    decrypt();
    return 0;
}

void encrypt()
{
    char mingwen[100];
    char miwen[100];
    int k,i;
    printf("������Сд��ĸ������M����������հ״���\n");
    gets(mingwen);
    for(i=0;mingwen[i]!='\0';i++)
    {
        k=mingwen[i]-'a';
        miwen[i]=T[k];
    }
    miwen[i]='\0';
    printf("���ܺ��������:\n%s\n",miwen);
}

void decrypt()
{
    char mingwen[100];
    char miwen[100];
    int k,i;
    printf("������Сд��ĸ������M����������հ״���\n");
    gets(miwen);
    for(i=0;miwen[i]!='\0';i++)
    {
        char S=miwen[i];
        for(k=0;S!=T[k];k++);

        mingwen[i]='a'+k;
    }
    mingwen[i]='\0';
    printf("���ܺ��������:\n%s\n",mingwen);
}


