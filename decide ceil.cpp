/*2017蓝桥杯
    方块分割

6x6的方格，沿着格子的边线剪开成两部分。

要求这两部分的形状完全相同。

试计算：一共有多少种不同的分割方法。

注意：旋转对称的属于同一种分割法。*/
#include<bits/stdc++.h>
using namespace std;
bool vis[10][10];
int ans;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

void dfs(int x,int y)
{
    if(x==6||x==0||y==6||y==0) {
        ans++;
        return;
    }
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(!vis[nx][ny]){
            vis[nx][ny]=true;
            vis[6-nx][6-ny]=true;
            dfs(nx,ny);
            vis[nx][ny]=false;
            vis[6-nx][6-ny]=false;
        }
    }

}
int main()
{
    ans=0;
    vis[3][3]=true;
    dfs(3,3);
    cout<<ans/4<<endl;
    return 0;
}
