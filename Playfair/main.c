#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

void CreatTable(char*);
void GetPosition(char, int*, int*);
char GetKey(int, int);
void Encrypt(char*, char*);
void PrintTable();

char playfair_table[5][5];

void CreatTable(char *in_key)
{
    int i=0,j;
    int hash[25]={0};
    char key[26]={0};
    int key_len;
    strcpy(key, in_key);
    key_len = strlen(key);
    while(i<key_len)
    {
        //去除不是小写字母的元素
        if(!(key[i]<='z'&&key[i]>='a'))
        {
            //
            for(j=i;j<key_len-1;j++)
                key[j]=key[j+1];

            key_len--;
            continue;
        }
        //标记当前元素是否出现过
        if(hash[key[i]-'a']==0)
        {
            hash[key[i]-'a']=1;
        }else
        {
            for(j=i;j<key_len-1;j++)
                key[j]=key[j+1];

            key_len--;
            continue;
        }
        i++;
    }
    for(i=0;i<26;i++)
    {
        if(i+'a'=='z')
            continue;

        if(hash[i]==0)
        {
            hash[i]=1;
            key[key_len]=i+'a';
            key_len++;
        }
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            playfair_table[i][j]=key[5*i+j];
        }
    }
}

void GetPosition(char c,int *x,int *y)
{
    int i,j;
    int flag=0;
    outer:
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(playfair_table[i][j]==c)
            {
                *x=i;*y=j;
                flag=1;
                goto outer;
            }
        }
    }
    if(flag==0)
    {
        *x=-1;
        *y=-1;
    }
}

char GetKey(int x, int y)
{
    return playfair_table[x%5][y%5];
}


void Encrypt(char *input, char *output)
{
    int length = strlen(input);
    int i=0,j=-1,flag;
    int ax,ay,bx,by;
    int pair[2]={-1,-1};
    while(1)
    {
        //char dis[SIZE]={0};
        //int dislength=-1;
        flag=0;

        for(i=pair[1]+1;i<length;i++)
        {
            pair[0]=i;
            pair[1]=i+1;
            flag=1;
            break;
        }

        //表明上一组pair[1]是最后一位，此时while循环结束
        if(flag==0)
            break;

        flag=0;
        for(i=pair[1];i<length;i++)
        {
            pair[1]=i;
            flag=1;
            break;
        }

        //表明pair[0]是最后一位，需要补上一个x
        if(flag==0)
        {
            input[length]='x';
            pair[1]=length;
            length++;
        }
        //一组的两个字母相同时
        if(input[pair[1]]==input[pair[0]])
        {
            if(input[pair[0]]!='x')
            {
                //当前位置之后字母后移两位
                for(i=length;i>pair[1];i--)
                    input[i+2]=input[i];

                length+=2;
                input[pair[1]+1]=input[pair[1]];
                input[pair[1]]='x';
                input[pair[1]+2]='x';
            }
        }
        printf("%c,%c\n",input[pair[0]],input[pair[1]]);

        GetPosition(input[pair[0]],&ax,&ay);
        GetPosition(input[pair[1]],&bx,&by);

        if(ax==-1||ay==-1||bx==-1||by==-1)
        {
            output[++j]=pair[0];
            output[++j]=pair[1];
        }else if(ax==bx)
        {
            //output[++j]=GetKey(ax, ay+1,input[pair[1]]);
            output[++j]=GetKey(ax, ay+1);
            //for(i=0;i<=dislength;i++)
            //    output[++j]=dis[i];

            //output[++j]=GetKey(bx, by+1,input[pair[1]]);
            output[++j]=GetKey(bx, by+1);
        }else if(ay==by)
        {
            //output[++j]=GetKey(ax+1, ay,input[pair[1]]);
            output[++j]=GetKey(ax+1, ay);
            //for(i=0;i<=dislength;i++)
            //   output[++j]=dis[i];

            //output[++j]=GetKey(bx+1, by,input[pair[1]]);
            output[++j]=GetKey(bx, by+1);
        }else
        {
            //output[++j]=GetKey(ax, by,input[pair[1]]);
            output[++j]=GetKey(ax, by);
            //for(i=0;i<=dislength;i++)
            //   output[++j]=dis[i];

            //output[++j]=GetKey(bx, ay,input[pair[1]]);
            output[++j]=GetKey(bx, ay);
        }
    }
}

void PrintTable()
{
    int m,n;
    printf("密码表：\n");
    for(m=0;m<5;m++)
    {
        for(n=0;n<5;n++)
        {
            printf("%c ", playfair_table[m][n]);
        }
        printf("\n");
    }
}

int main()
{
    char key[26]={0};
    char inputStr[SIZE], outputStr[SIZE];
    memset(outputStr,0,sizeof(outputStr));
    memset(inputStr,0,sizeof(inputStr));
    printf("输入密钥：\n");
    scanf("%s", key);
    CreatTable(key);
    PrintTable();
    printf("请输入明文：\n");
    scanf("%s",inputStr);
    Encrypt(inputStr,outputStr);
    //printf("密文：%s\n", outputStr);
    return 0;
}
