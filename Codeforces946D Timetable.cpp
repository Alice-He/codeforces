/*
题目：有n个字符串，代表n天的课表，1表示这个时间要上课，0表示不要上课，
一天在学校时间为第一节课到最后一节课的时间。
总共，可以逃过k次课，求至少需要在学校多少时间。
v[i][k]即第i天逃k节课的能节约的最多时间。
dp[i]表示逃掉i节课节省的最大时间
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
    /* 预处理v数组*/
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
    /*背包*/
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
