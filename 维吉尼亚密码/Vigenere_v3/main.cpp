#include <iostream>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <string.h>

using namespace std;
const int SIZE =1000;
char cipher[SIZE];
char plain[SIZE];
char key[10];
int len;

void decrypt(){
    int i;
    for(i=0;cipher[i]!='\0';i++){
        int j = i%len;
        int k = key[j]-'a';
        plain[i] = (cipher[i]-'a'+26-k)%26+'a';
    }
    plain[i]='\0';
}

int main()
{
    ifstream infile("test.txt");
    ofstream out("ans.txt");
    string temp,str;
    if(!infile.is_open()){
        cout << "��ʧ�ܣ�\n";
    }
    while(getline(infile,temp)){
        str+=temp;
    }

    strcpy(cipher,str.c_str());

    cout << "������Сд���ܹؼ��֣�\n";
    gets(key);
    len=strlen(key);
    decrypt();
    cout << "���ܺ��:\n"<<plain<<endl;
    return 0;
}
