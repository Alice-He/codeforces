
#include<bits/stdc++.h>
using namespace std;
int a[200005];
typedef pair<int,int>pir;
map<int,pir>mp;
int main()
{
    int k,n;
    cin>>k;
    for(int i=1;i<=k;i++){
        cin>>n;
        int sum=0;
        for(int j=1;j<=n;j++){
            cin>>a[j];
            sum+=a[j];
        }
        for(int j=1;j<=n;j++){
            pir tmp=mp[sum-a[j]];

            if(tmp==make_pair(0,0)) mp[sum-a[j]]=make_pair(i,j);//cout<<tmp.first<<" true"<<tmp.second<<endl;
            else if(tmp.first!=i) {cout<<"YES\n"<<tmp.first<<" "<<tmp.second<<"\n"<<i<<" "<<j<<endl;return 0;}
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
