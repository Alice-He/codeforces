/*
��Ŀ��
һ��������n���ڵ㣬��1��ŵ�n�����ڵ�ı��Ϊp������ÿ���ڵ��val[i]ֵ��
����f(i)Ϊ�Ա��iΪ���ڵ�������У��������ڵ㣩������val[j]�Ǻ���������val[i]��Լ���Ľڵ������
������i*f(i)�ĺ͡��𰸶�1e9+7ȡģ��
��⣺���ȴ�������еĺ�Լ����
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
ll num[vp];//num[i]��¼��ǰi��Ϊp�ĺ�Լ��ʱ+p��ֵ
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
void init() //�������Լ��
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
        }/*����*/
        for(int i=1;i<=n;i++)
            scanf("%d",&val[i]);
        vv[p]=true;
        dfs(p);
        cout<<ans<<endl;
    }
    return 0;
}
