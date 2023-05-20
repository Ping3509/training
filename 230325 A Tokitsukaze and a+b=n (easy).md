## A Tokitsukaze and a+b=n (easy)

链接：

[https://ac.nowcoder.com/acm/contest/46810/A](https://ac.nowcoder.com/acm/contest/46810/A)

来源：牛客网

**easy 与 medium 的唯一区别是输入的数据范围。**  Tokitsukaze 有一个整数 nnn， 以及 222 个区间 [L1,R1][L_1,R_1][L1,R1], [L2,R2][L_2,R_2][L2,R2]。  她想知道有多少种选法，满足：从第一个区间选择一个整数 aaa (L1≤a≤R1L_1 \leq a \leq R_1L1≤a≤R1)，从第二个区间选择一个整数 bbb (L2≤b≤R2L_2 \leq b \leq R_2L2≤b≤R2)，使得 a+b=na+b=na+b=n。  对于两种选法，若 aaa, bbb 中有任意一个数不同，则算作不同的选法。

## **输入描述:**

```
第一行包含一个整数TTT (1≤T≤51 \leq T \leq 51≤T≤5)，表示测试数据组数。

对于每组测试数据：

第一行包含一个整数nnn (1≤n≤2⋅1051 \leq n \leq 2 \cdot 10^51≤n≤2⋅105)。

第二行包含两个整数L1L_1L1,R1R_1R1 (1≤L1≤R1≤1051 \leq L_1 \leq R_1 \leq 10^51≤L1≤R1≤105)。

第三行包含两个整数L2L_2L2,R2R_2R2 (1≤L2≤R2≤1051 \leq L_2 \leq R_2 \leq 10^51≤L2≤R2≤105)。
```

## **输出描述:**

```
对于每组测试数据，输出一个整数表示答案。
```

示例1

## 输入

复制

4
5
3 5
1 4
100000
1 100000
1 100000
200000
1 100000
1 100000
114
514 1919
8 10

`4
5
3 5
1 4
100000
1 100000
1 100000
200000
1 100000
1 100000
114
514 1919
8 10`

## 输出

复制

2
99999
1
0

`2
99999
1
0`

## 说明

`第一组测数据：共有 222 种选法，分别是 (3+23+23+2), (4+14+14+1)。`

枚举 *a* = *L*1 到 *R*1，*b* = *n − a*，再判断 *b* 是否在区间 [*L*2*, R*2]中，如果是，答案 +1;

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,l1,r1,l2,r2,ans;
int main(){ 
    int t;cin>>t;
    while(t--){
        ans=0;
        cin>>n>>l1>>r1>>l2>>r2;
        for(int i=l1;i<=r1;i++){
            if(n-i>=l2 && n-i<=r2) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
```