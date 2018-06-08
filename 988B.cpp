#include<bits/stdc++.h>
using namespace std;
struct node{
    string s;
    int slen;
}a[110];
int n;
bool cmp(node x,node y)
{
    if(x.slen==y.slen) return x.s<y.s;
    return x.slen<y.slen;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].s;
        a[i].slen=a[i].s.length();
    }
    sort(a,a+n,cmp);
    bool flag=true;
    for(int k=0;k<n-1;k++){
        //cout<<a[k+1].slen<<endl;
        int len=a[k+1].slen-a[k].slen+1;
        for(int j=0;j<len;j++){
            bool f=true;
            for(int i=0;i<a[k].slen;i++){
                if(a[k+1].s[j+i]!=a[k].s[i]){
                    f=false;break;
                }
            }
            if(f) break;
            if(j==len-1&&!f) flag=false;
        }
        if(!flag) break;
    }
    if(!flag) cout<<"NO"<<endl;
    else {
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++) cout<<a[i].s<<endl;
    }
    return 0;
}
