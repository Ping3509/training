/*
## 列一列

[https://ac.nowcoder.com/acm/problem/15072](https://ac.nowcoder.com/acm/problem/15072)

map 是数和idx

然后通过idx去找数 现在前面都输入一遍

输入数字的时候，用字符串输入

*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef long long ll;
map<ll,int>mp;
ll a[N];
int main(){
    string s;
    ll idx;
    a[1]=1,a[2]=2;
    mp[a[1]]=1,mp[a[2]]=2;
    for(int i=3;i<=1e5;i++){
        a[i]=a[i-1]+a[i-2];
        mp[a[i]]=i;
    }
    while(cin>>s){
        idx=0;
        for(int i=0;i<s.size();i++){
            int x=s[i]-'0';
            idx=idx*10+x;
        }
        cout<<mp[idx]<<'\n';
    }
    return 0;
}