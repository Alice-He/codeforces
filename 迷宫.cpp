/*2017À¶ÇÅ±­c/c++A×é*/
#include<bits/stdc++.h>
using namespace std;
char mp[15][15];
bool vis[15][15];
int ans;
void dfs(int i,int j)
{
    if(i<0||i>9||j>9||j<0){
        ans++;return;
    }
    if(mp[i][j]=='L'&&!vis[i][j]){
        vis[i][j]=true;
        dfs(i,j-1);
    }
    else if(mp[i][j]=='R'&&!vis[i][j]){
        vis[i][j]=true;
        dfs(i,j+1);
    }
    else if(mp[i][j]=='U'&&!vis[i][j]){
        vis[i][j]=true;
        dfs(i-1,j);
    }
    else if(mp[i][j]=='D'&&!vis[i][j]){
        vis[i][j]=true;
        dfs(i+1,j);
    }
    return ;
}
int main()
{
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            cin>>mp[i][j];
    ans=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            dfs(i,j);
            memset(vis,0,sizeof(vis));
        }
    }
    cout<<ans<<endl;
    return 0;
}
