#include <stdio.h>

void getTable();
void decrypt();
void encrypt();

char T[26]={'q','w','e','r','t','y','u', 'i','o','p','a','s','d','f', 'g','h','j','k','l','z','x','c','v','b','n','m'};

int main()
{
    getTable();
    //����
    encrypt();

    //����
    decrypt();
    return 0;
}

void getTable()
{
    printf("������26������:\n");
    gets(T);
}

void encrypt()
{
    char mingwen[100];
    int k,j,i=0,n=0;
    printf("������Сд��ĸ������M����������հ״���\n");
    gets(mingwen);
    printf("��������ܴ�����\n");
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
        printf("��%d�μ��ܺ��������:\n%s\n",j+1,mingwen);
    }

    //printf("���ܺ��������:\n%s\n",mingwen);
}

void decrypt()
{
    char miwen[100];
    int k,j,i=0,n;
    printf("������Сд��ĸ������M����������հ״���\n");
    gets(miwen);
    printf("��������ܴ�����\n");
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
        printf("��%d�ν��ܺ��������:\n%s\n",j+1,miwen);
    }
    //printf("���ܺ��������:\n%s\n",miwen);
}


