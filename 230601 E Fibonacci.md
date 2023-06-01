# E Fibonacci

https://oj.acm.cust.team/problem/6999

签到题， 由于输入量过大需要关闭同步流。 计算时首先预处理前 1e6 项的斐波那契数列并 求出该数列的前缀和

O (1) 查询第 r 项和第 l- 1 项 1 的前缀和，两数相减就是第 l 项到 第 r 项值和。

是l~r,所以前缀和减的时候是r - (l-1)

注意由于数据较大取模后第r项的前缀和可能小于 l-1项前缀和，所以求值时

要加mod再取模

取模可以保证数据在一个限定范围内

在进行计算时，经常会遇到非常大的数值，超过计算机可以表示的范围。为了避免数值溢出和减小计算的复杂度，我们通常会在计算过程中取模。

取模操作是取除以一个特定数（通常是一个较大的质数）的余数。在计算中，取模操作可以帮助我们将结果限制在一个固定的范围内，防止数值溢出。

```cpp
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
typedef long long ll; 
const int N = 1e6;
const int mod = 1e9+7;
int l,r;
ll f[N+10],sum[N+10];
void init(){
    f[1]=f[2]=1;
    for(int i=3;i<=N;++i) f[i]=(f[i-1]+f[i-2])%mod;
    for(int i=1;i<=N;++i) sum[i]=(sum[i-1]+f[i])%mod;
}
int main(){ 
    IOS;
    init();
    int t;cin>>t;
    while(t--){
        cin>>l>>r;
        cout<<(sum[r]-sum[l-1]+mod)%mod<<endl;
    }
    return 0;
}
```