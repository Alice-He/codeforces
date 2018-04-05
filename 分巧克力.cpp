#include<bits/stdc++.h>
using namespace std;
int n,k;
struct node{
    int l,w;
}a[100005];
int solve(int l,int r)
{
    int ll = l, rr = r;
    while(ll < rr){
        int mid = (ll + rr) / 2;
        int cnt = 0;
        for(int i = 1; i <= n; i++)
            cnt += (a[i].l / mid) * (a[i].r / mid);
        if(cnt > k)
            ll = mid + 1;
        else rr = mid - 1;
    }
    return rr;
}
int main()
{
    cin>>n>>k;
    int maxn=0;
    for(int i=0;i<n;i++){
        cin>>a[i].l>>a[i].w;
        maxn=max(maxn,a[i].l);
        maxn=max(maxn,a[i].w);
    }
    ans=solve(0,maxn);
    cout<<ans<<endl;
    return 0;
}
