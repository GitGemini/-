#include <stdio.h>
#include <stdlib.h>

void decrypt();

int main()
{
    //����
    decrypt();
    return 0;
}

void decrypt()
{
    char mingwen[100];
    char miwen[100];
    int k,i;
    printf("������Сд��ĸ������M����������հ״���\n");
    gets(miwen);
    for(k=1;k<=25;k++)
    {
        for(i=0;miwen[i]!='\0';i++)
        mingwen[i]=(miwen[i]-'a'-k+26)%26+'a';

        mingwen[i]='\0';
        printf("��%d�ֿ��ܵ������ǣ�\n%s\n",k,mingwen);
    }
}
