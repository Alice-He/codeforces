#include<bits/stdc++.h>
using namespace std;
void cal_next(char *str,int *next,int len)
{
   next[0]=-1;
   int k=-1;
   for(int i=1;i<len;i++){
        while(k!=-1&&str[k+1]!=str[i]) k=next[k];
        if(str[i]==str[k+1]) k+=1;
        next[i]=k;
   }
}
int KMP(char *str,int slen,char *ptr,int plen)
{
    int *next=new int[plen];
    cal_next(ptr,next,plen);
    int k=-1;
    for(int i=1;i<slen;i++){
        while(k!=-1&&ptr[k+1]!=str[i]) k=next[k];
        if(ptr[k+1]==str[i]) k+=1;
        if(k==plen-1){
            //cout << "��λ��" << i-plen+1<< endl;
            //k = -1;//���³�ʼ����Ѱ����һ��
            //i = i - plen + 1;//i��λ����λ�ã����forѭ��i++���Լ�������һ��������Ĭ�ϴ�������ƥ���ַ������Բ����ص�������л������ͬѧָ������
            return i-plen+1;//������Ӧ��λ��
        }
    }
    return -1;
}
int main()
{
    char *str = "bacbababadababacambabacaddababacasdsd";
    char *ptr = "ababaca";
    int a = KMP(str, 36, ptr, 7);
    cout<<a<<endl;
    return 0;
}
