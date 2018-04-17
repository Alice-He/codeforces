#include<bits/stdc++.h>
using namespace std;
#define maxn 100
int num[maxn];
void solve(int p)
{
    int v;
    cin>>v;
    if(v==-1) return ;
    num[p]+=v;
    solve(p-1);
    solve(p+1);
}
bool init()
{
    int v;
    cin>>v;
    if(v==-1) return false;
    memset(num,0,sizeof(num));
    int pos=maxn/2;
    num[pos]=v;

    solve(pos-1);
    solve(pos+1);
}
int main()
{
    int cse=1;
    while(init()){
        int p=0;
        while(num[p]==0) p++;
        cout<<"Case "<<cse++<<":\n"<<num[p++];
        while(num[p]){
            cout<<" "<<num[p++];
        }
        cout<<"\n\n";
    }
    return 0;
}
