## D  Tokitsukaze and Energy Tree

链接：

[https://ac.nowcoder.com/acm/contest/46810/D](https://ac.nowcoder.com/acm/contest/46810/D)

来源：牛客网

Tokitsukaze 有 nnn 个节点的有根能量树，根为 111。最开始，树上每个节点的能量都是 000。   现在 Tokitsukaze 有 nnn 个能量球，第 iii 个能量球拥有 viv_ivi 能量。她想把这 nnn 个能量球分别放置在能量树的每个节点上，使能量树的每个节点都恰好有一个能量球。  Tokitsukaze 每次只能放置一个能量球，所以她将进行 nnn 次操作。每一次操作，她会选择一个能量球，再选择一个没有能量球的能量树节点 xxx，把刚刚选择的能量球放置在节点 xxx 上。在这之后，Tokitsukaze 能获得以 xxx 为根的子树中的所有能量球的能量 (包括节点 xxx 的能量球能量)。  在放置完所有能量球后，Tokitsukaze 可能获得的总能量最多是多少？

## **输入描述:**

```
第一行包含一个整数nnn(1≤n≤2⋅105)(1 \leq n \leq 2 \cdot 10^5)(1≤n≤2⋅105)。

第二行包含n−1n-1n−1 个整数f2,f3,…,fnf_2, f_3,\ldots,f_nf2,f3,…,fn (1≤fi≤i−11 \leq f_i \leq i-11≤fi≤i−1)，表示节点iii 的父亲是fif_ifi。

第三行包含nnn 个整数v1,v2,…,vnv_1,v_2, \ldots, v_nv1,v2,…,vn (1≤vi≤1051 \leq v_i \leq 10^51≤vi≤105)，分别表示能量球的能量。
```

## **输出描述:**

```
输出一个整数，表示 Tokitsukaze 可能获得的最多总能量。
```

![Screen Shot 2023-01-30 at 21.26.36.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/4d302ee2-8a4b-4ad3-8a97-2d7ca13af7c5/Screen_Shot_2023-01-30_at_21.26.36.png)

![Screen Shot 2023-01-30 at 21.28.01.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/c4a544af-aac9-4704-b98f-440b730d1310/Screen_Shot_2023-01-30_at_21.28.01.png)

其实跟一开始想的用最大的×最深的，是一样的，升序好做一点

问题主要在于不会树dfs

没有搞懂vec的作用

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =200010;
int n;
vector<int> g[N];
ll en[N],dep[N]; //energy
void dfs(int now,int d){
    dep[now]=d;
    for(auto to :g[now]) dfs(to, d+1); 
}
int main(){ 
    int n;cin>>n;
    for(int i=2;i<=n;i++){//从第二个
        int x;cin>>x;
        g[x].push_back(i);
    }     
    for(int i=1;i<=n;i++) cin>>en[i];
    dfs(1,1);
    sort(en+1,en+1+n);
    sort(dep+1,dep+1+n);
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+= dep[i]*en[i];
    }
    cout<<ans;
    return 0;
}
```