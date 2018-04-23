#include<bits/stdc++.h>
using namespace std;
#define maxn 1028
#define n 32
char s[maxn];
int ans;
bool buf[n][n];
void dfs(int& p,int c,int d,int len)
{
    char ch=s[p++];
    if(ch=='p'){
        dfs(p,c+len/2,d,len/2);
        dfs(p,c,d,len/2);
        dfs(p,c,d+len/2,len/2);
        dfs(p,c+len/2,d+len/2,len/2);
    }
    else if(ch=='f'){
        for(int i=c;i<c+len;i++)
            for(int j=d;j<d+len;j++)
                if(buf[i][j]==false){
                    //cout<<"true"<<endl;
                    buf[i][j]=true;
                    ans++;
                }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        ans=0;
        memset(buf,0,sizeof(buf));
        for(int i=0;i<2;i++){
            scanf("%s",s);
            int p=0;
            dfs(p,0,0,n);
        }
        printf("There are %d black pixels.\n",ans);
    }
    return 0;
}
