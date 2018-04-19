/*��Ŀ��
С����Сɭ����һ��������Ϸ��С���ȴ�����[L1, R1]��ѡ��1������n1��
Сɭ����С��ѡ�����ֺ󣬴�[L2,R2]��ѡ��1������n2,
��n1��n2������һ��(n1��ǰ, n2�ں�)���γ�һ���µ����֣�
��������ֿ��Ա�mod��������ôСɭ��ʤ������С����ʤ��
�������˾���ȡ���Ų��ԣ�����˭��ʤ��
��⣺����l1-r1�е���i*10��100��...��100000�������mod-i%mod��������l2-r2���ҵ�������ǰ��Ӯ��������Ǻ���Ӯ��
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
