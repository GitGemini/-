#include <stdio.h>
#include <stdlib.h>

void decrypt();
void encrypt();

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
    int k=3,i;
    printf("������Сд��ĸ������M����������հ״���\n");
    gets(mingwen);
    for(i=0;mingwen[i]!='\0';i++)
        miwen[i]=(mingwen[i]-'a'+k)%26+'a';

    miwen[i]='\0';
    printf("���ܺ�������ǣ�\n%s\n",miwen);
}

void decrypt()
{
    char mingwen[100];
    char miwen[100];
    int k=3,i;
    printf("������Сд��ĸ������M����������հ״���\n");
    gets(miwen);
    for(i=0;miwen[i]!='\0';i++)
        mingwen[i]=(miwen[i]-'a'-k+26)%26+'a';

    mingwen[i]='\0';
    printf("���ܺ�������ǣ�\n%s\n",mingwen);
}


