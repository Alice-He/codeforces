#include<bits/stdc++.h>
using namespace std;
#define maxn 1000000+5
int n,m;
int a[maxn],b[maxn];
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    int cnt=0;int tmp=0;
    int sum1=0,sum2=0;
    for(int i=0;i<n;i++){
        sum1+=a[i];
        //cout<<i<<" "<<sum1<<" "<<tmp<<endl;
        while(tmp<m){
            if((sum2+b[tmp])<sum1){ sum2+=b[tmp];tmp++;}
            else if((sum2+b[tmp])==sum1){
                cnt++;
                sum2+=b[tmp];
                tmp+=1;
                break;
                //cout<<sum1<<" "<<sum2<<endl;
            }
            else break;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
