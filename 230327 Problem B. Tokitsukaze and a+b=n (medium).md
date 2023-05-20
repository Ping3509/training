## B

数据变大，用区间法

**Problem B. Tokitsukaze and a+b=n (medium)**

根据 *a* 的取值范围 [*L*1*, R*1]，我们求出能满足 *a* + *b* = *n* 的 *b* 的范围是 [*n − R*1,*n − L*1 **]，但是合法的 *b*

的范围是 [*L*2*, R*2] 。所以答案是区间 [*n − L*1*, n − R*1] 与 [*L*2*, R*2] 取交后的区间长度。\\他这题解写错了

区间取交的区间长度可以这么计算：

两个区间 [*a, b*]，[*c, d*] 取交的区间长度为：*max*(0*, min*(*d, b*) *− max*(*a, c*) + 1)

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,l1,r1,l2,r2,ans,ll,rr;
int main(){ 
    int t;cin>>t;
    while(t--){
        cin>>n>>l1>>r1>>l2>>r2;
        int L = n - r1, R = n - l1; //注意这个地方不是n-l1 n-r1，是减去右边区间，应该是第二个的做区间，
//是应该是反着的
        int ll = max(L, l2);
        int rr = min(R, r2);
        ans=max(0, rr - ll + 1);
        cout<<ans<<endl;
    }
    return 0;
}
```