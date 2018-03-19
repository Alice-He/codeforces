#include<bits/stdc++.h>
using namespace std;
int main()
{
    int l,r,a;
    cin>>l>>r>>a;
    int num=abs(l-r);
    int ans=0;
    if(num<=a) ans=(l+r+a)/2;
    else ans=min(l,r)+a;
    cout<<ans*2<<endl;
    return 0;
}
