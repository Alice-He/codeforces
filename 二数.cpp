/*
题意：我们把十进制下每一位都是偶数的数字叫做“二数”。
给定一个十进制下最多105位的数字，请你求出和这个数字的差的绝对值最小的二数，若答案不唯一，输出最小的那个。
没什么难度，找到最高位的奇数，将它+1，将它后面的都变成0，得到最近的大二数，将它-1，后面都变为8，得到最近小二数。
当最大奇数=9时，只考虑小的二数。
但是最好换成int数组搞,char类型就要清空，但是清空就会超时
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
