/*题目：
小埃和小森在玩一个数字游戏，小埃先从区间[L1, R1]里选择1个数字n1，
小森看到小埃选的数字后，从[L2,R2]里选择1个数字n2,
将n1和n2连接在一起(n1在前, n2在后)，形成一个新的数字，
若这个数字可以被mod整除，那么小森获胜，否则小埃获胜。
若两个人均采取最优策略，试问谁获胜？
题解：对于l1-r1中的数i*10，100，...，100000，如果对mod-i%mod，不能在l2-r2中找到，就是前者赢，否则就是后者赢。
*/
#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
int l1,r1,l2,r2,mod;
int m[maxn];
bool check(long long i)
{
    bool flag=false;
    long long num=i%mod;
    long long num1=i*10%mod;
    long long num2=i*100%mod;
    long long num3=i*1000%mod;
    long long num4=i*10000%mod;
    long long num5=i*100000%mod;
    if(m[mod-num]||m[mod-num1]||m[mod-num2]||m[mod-num3]||m[mod-num4]||m[mod-num5]) flag=true;
    return flag;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        memset(m,0,sizeof(m));
        cin>>l1>>r1>>l2>>r2>>mod;
        int len1=r1-l1+1;
        int len2=r2-l2+1;
        len1=min(len1,1000000);
        if(len2>=mod){
            cout<<"LOSE"<<endl; continue;
        }
        for(int i=l2;i<=r2;i++){
            m[i%mod]=1;
        }
        bool ok=false;
        for(long long i=l1;i<len1+l1;i++){
            if(!check(i)){
                ok=true;break;
            }
        }
        if(ok) cout<<"WIN"<<endl;
        else cout<<"LOSE"<<endl;
    }
    return 0;
}
