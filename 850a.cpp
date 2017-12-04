/*
*codeforces 850-A  Five Dimensional Points
*题意:在五维空间里有n个点，如果某一个点与其他任意两个点之间的夹角严格小于90度，则称这个点为good，否则为bad，问有多少个good点？
*题解：可以知道，在二维空间里如果有5个点，则没有good点，在三维空间里如果有7个点则也没有good点，故可以推出在五维空间里，如果点的个数大于11，则直接输出0
***    然后就可以三重循环暴力解决。
*/
#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b,c,d,e;
}p[1005];
vector<int>num;
int n;
bool solo(node i,node j,node k)
{
    node ij,ik;
    ij.a=j.a-i.a;
    ij.b=j.b-i.b;
    ij.c=j.c-i.c;
    ij.d=j.d-i.d;
    ij.e=j.e-i.e;
    ik.a=k.a-i.a;
    ik.b=k.b-i.b;
    ik.c=k.c-i.c;
    ik.d=k.d-i.d;
    ik.e=k.e-i.e;
    if(ij.a*ik.a+ij.b*ik.b+ij.c*ik.c+ij.d*ik.d+ij.e*ik.e<=0) return 0;
    return 1;
}
int main()
{
    cin>>n;
    if(n==1){
        cout<<1<<endl;
        cout<<1<<endl;
        return 0;
    }
    if(n==2){
        cout<<2<<endl;
        cout<<1<<endl;cout<<2<<endl;
        return 0;
    }
    if(n>11){
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        cin>>p[i].a>>p[i].b>>p[i].c>>p[i].d>>p[i].e;
    }
    bool flag;
    for(int i=0;i<n;i++){
        flag=false;
        for(int j=0;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(solo(p[i],p[j],p[k])){
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag) num.push_back(i);
    }
    cout<<num.size()<<endl;
    for(int i=0;i<num.size();i++)
        cout<<num[i]+1<<endl;
    return 0;
}
