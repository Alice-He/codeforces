/*
*codeforces 850-A  Five Dimensional Points
*����:����ά�ռ�����n���㣬���ĳһ��������������������֮��ļн��ϸ�С��90�ȣ���������Ϊgood������Ϊbad�����ж��ٸ�good�㣿
*��⣺����֪�����ڶ�ά�ռ��������5���㣬��û��good�㣬����ά�ռ��������7������Ҳû��good�㣬�ʿ����Ƴ�����ά�ռ�������ĸ�������11����ֱ�����0
***    Ȼ��Ϳ�������ѭ�����������
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
