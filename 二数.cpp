/*
���⣺���ǰ�ʮ������ÿһλ����ż�������ֽ�������������
����һ��ʮ���������105λ�����֣����������������ֵĲ�ľ���ֵ��С�Ķ��������𰸲�Ψһ�������С���Ǹ���
ûʲô�Ѷȣ��ҵ����λ������������+1����������Ķ����0���õ�����Ĵ����������-1�����涼��Ϊ8���õ����С������
���������=9ʱ��ֻ����С�Ķ�����
������û���int�����,char���;�Ҫ��գ�������վͻᳬʱ
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
#define maxn 100005
char str[maxn];
int a[maxn],num1[maxn],num2[maxn];
void prt(int x)
{
    int len=strlen(str);
    int pos1=len;
    if(x==1){
        for(int i=0;i<len;i++){
            if(num1[i]!=0){
                pos1=i;break;
            }
        }
        if(pos1==len) printf("0\n");
        else {
            for(int i=pos1;i<len;i++)
                printf("%d",num1[i]);
            printf("\n");
        }
    }
    else if(x==2){
        for(int i=0;i<len;i++){
            if(num2[i]!=0){
                pos1=i;break;
            }
        }
        if(pos1==len) printf("0\n");
        else {
            for(int i=pos1;i<len;i++)
                printf("%d",num2[i]);
            printf("\n");
        }
    }
    else if(x==0){
        for(int i=0;i<len;i++){
            if(a[i]!=0){
                pos1=i;break;
            }
        }
        if(pos1==len) printf("0\n");
        else {
            for(int i=pos1;i<len;i++)
                printf("%d",a[i]);
            printf("\n");
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",str);
        int len=strlen(str);
        bool flag1=false;
        int flag2=0;
        int pos=550;
        for(int i=0;i<len;i++)
            a[i]=str[i]-'0';
        for(int i=0;i<len;i++){
            if(a[i]%2){
                num2[i]=a[i]-1;pos=i;
                if(a[i]==9){ flag1=true;break;}
                num1[i]=a[i]+1;break;
            }
            num1[i]=a[i];
            num2[i]=a[i];
        }
        for(int i=pos+1;i<len;i++){
            num1[i]=0;
            num2[i]=8;
        }
        if(flag1) prt(2);
        else{
            for(int i=0;i<len;i++){
                int a1,a2;
                if(num1[i]<=a[i]||a[i]<=num2[i]){
                    a1=num1[i]+10-a[i];
                    a2=a[i]+10-num2[i];
                }
                else{
                    a1=num1[i]-a[i];
                    a2=a[i]-num2[i];

                }
                if(a1>a2){
                    flag2=1;
                    break;
                }
                else if(a2>a1){
                    flag2=2;
                    break;
                }
            }
            if(flag2==2) prt(1);
            else if(flag2==1||(flag2==0&&flag1!=550)) prt(2);
            else  prt(0);
        }
    }
    return 0;
}
