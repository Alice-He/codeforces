/*2017���ű�
    ����ָ�

6x6�ķ������Ÿ��ӵı��߼����������֡�

Ҫ���������ֵ���״��ȫ��ͬ��

�Լ��㣺һ���ж����ֲ�ͬ�ķָ����

ע�⣺��ת�ԳƵ�����ͬһ�ַָ��*/
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
