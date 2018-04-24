/*
题目：
一棵树，有n个节点，从1编号到n。根节点的编号为p。给出每个节点的val[i]值，
定义f(i)为以编号i为根节点的子树中（包括根节点），所有val[j]是合数并且是val[i]的约数的节点个数。
求所有i*f(i)的和。答案对1e9+7取模。
题解：首先处理出所有的合约数。
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define maxn 20010
#define vp 10005
int val[maxn];
int n,p;
vector<int>g[maxn],h[vp];
bool vis[vp],vv[maxn];
ll ans;
ll num[vp];//num[i]记录当前i作为p的合约数时+p的值
void dfs(int p)
{
    for(int i=0;i<h[val[p]].size();i++){
        int tmp=h[val[p]][i];
        num[tmp]+=p;
    }
    cout<<p<<" "<<val[p]<<" "<<num[val[p]]<<endl;
    ans=(ans+num[val[p]])%mod;
    for(int i=0;i<g[p].size();i++){
        int tmp=g[p][i];
        if(!vv[tmp]){
            vv[tmp]=true;dfs(tmp);
        }
    }
    for(int i=0;i<h[val[p]].size();i++){
        int tmp=h[val[p]][i];
        num[tmp]-=p;
    }
}
void init() //处理出合约数
{
    int m=sqrt(vp+0.5);
    vis[1]=vis[0]=true;
    for(int i=2;i<=m;i++){
        if(!vis[i])
            for(int j=i*i;j<vp;j+=i) vis[j]=true;
    }
    for(int i=4;i<vp;i++){
        if(vis[i])
            for(int j=4;j<=i;j++)
                if(vis[j]&&i%j==0) h[i].push_back(j);
    }

}

int main()
{
    int t,u,v;
    scanf("%d",&t);
    init();
    while(t--){
        scanf("%d %d",&n,&p);
        for(int i=0;i<maxn;i++)
            g[i].clear();
        memset(vv,0,sizeof(vv));
        ans=0;
        for(int i=0;i<n-1;i++){
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }/*建树*/
        for(int i=1;i<=n;i++)
            scanf("%d",&val[i]);
        vv[p]=true;
        dfs(p);
        cout<<ans<<endl;
    }
    return 0;
}
