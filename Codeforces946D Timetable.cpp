/*
��Ŀ����n���ַ���������n��Ŀα�1��ʾ���ʱ��Ҫ�ϿΣ�0��ʾ��Ҫ�ϿΣ�
һ����ѧУʱ��Ϊ��һ�ڿε����һ�ڿε�ʱ�䡣
�ܹ��������ӹ�k�οΣ���������Ҫ��ѧУ����ʱ�䡣
v[i][k]����i����k�ڿε��ܽ�Լ�����ʱ�䡣
dp[i]��ʾ�ӵ�i�ڿν�ʡ�����ʱ��
*/
#include<bits/stdc++.h>
using namespace std;
#define maxn 505
#define inf 0x3f3f3f
int dp[maxn],val[maxn][maxn];
char str[maxn][maxn];
int pos[maxn][maxn],num[maxn];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>str[i];
        for(int j=0;j<m;j++){
            if(str[i][j]=='1'){
                num[i]++;
                pos[i][num[i]]=j;
            }
        }
    }
    /* Ԥ����v����*/
    for(int i=0;i<n;i++){
        for(int j=0;j<=min(num[i]-1,k);j++){
            int ans=inf;
            for(int r=0;r<=j;r++){
                int s=j-r;
                ans=min(ans,pos[i][num[i]-s]-pos[i][r+1]+1);
            }
            v[i][j]=m-ans;
        }
        v[i][num[i]]=m;
    }
    /*����*/
    for(int i=0;i<n;i++){
        for(int j=k;j>=0;j--){
            for(int r=0;r<=min(j,m);r++){
                dp[j]=max(dp[j],dp[j-r]+v[i][r]);
            }
        }
    }
    cout<<n*m-dp[k]<<endl;
    return 0;

}
