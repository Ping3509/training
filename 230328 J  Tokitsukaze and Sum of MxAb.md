## J  Tokitsukaze and Sum of MxAb

链接：

[https://ac.nowcoder.com/acm/contest/46810/J](https://ac.nowcoder.com/acm/contest/46810/J)

来源：牛客网

Tokitsukaze 最近对最大值与绝对值有了兴趣。  她有一个长度为 nnn 的序列 aaa。  定义  MxAb(i,j)=max(∣ai−aj∣,∣ai+aj∣)MxAb(i,j)=max(|a_i-a_j|,|a_i+a_j|)MxAb(i,j)=max(∣ai−aj∣,∣ai+aj∣)  Tokitsukaze 想知道对于所有的 iii, jjj (1≤i,j≤n1 \leq i,j \leq n1≤i,j≤n)，MxAb(i,j)MxAb(i,j)MxAb(i,j)的和为多少。  即求下列式子  ∑i=1n∑j=1nMxAb(i,j)\sum_{i=1}^{n} \sum_{j=1}^{n} MxAb(i,j)∑i=1n∑j=1nMxAb(i,j)

## **输入描述:**

```
第一行包含一个整数TTT (1≤T≤101 \leq T \leq 101≤T≤10)，表示TTT 组测试数据。

对于每组测试数据：

第一行包含一个整数nnn (1≤n≤1051 \leq n \leq 10^51≤n≤105)。

第二行包含nnn 个整数a1,a2,…,ana_1, a_2, \ldots, a_na1,a2,…,an (−105≤ai≤105-10^5 \leq a_i \leq 10^5−105≤ai≤105)。
```

## **输出描述:**

```
对于每组测试数据，输出一个整数表示答案。
```

示例1

## 输入

复制

2
1
1
2
1 -2

`2
1
1
2
1 -2`

## 输出

复制

2
12

`2
12`

## 说明

`样例1解释：第一组测试数据：MxAb(1,1)=max(∣1−1∣,∣1+1∣)=2MxAb(1,1)=max(|1-1|,|1+1|)=2MxAb(1,1)=max(∣1−1∣,∣1+1∣)=2第二组测试数据：MxAb(1,1)=max(∣1−1∣,∣1+1∣)=2MxAb(1,1)=max(|1-1|,|1+1|)=2MxAb(1,1)=max(∣1−1∣,∣1+1∣)=2MxAb(1,2)=max(∣1−(−2)∣,∣1+(−2)∣)=3MxAb(1,2)=max(|1-(-2)|,|1+(-2)|)=3MxAb(1,2)=max(∣1−(−2)∣,∣1+(−2)∣)=3MxAb(2,1)=max(∣(−2)−1∣,∣(−2)+1∣)=3MxAb(2,1)=max(|(-2)-1|,|(-2)+1|)=3MxAb(2,1)=max(∣(−2)−1∣,∣(−2)+1∣)=3MxAb(2,2)=max(∣(−2)−(−2)∣,∣(−2)+(−2)∣)=4MxAb(2,2)=max(|(-2)-(-2)|,|(-2)+(-2)|)=4MxAb(2,2)=max(∣(−2)−(−2)∣,∣(−2)+(−2)∣)=4所以总和为 2+3+3+4=122+3+3+4=122+3+3+4=12`

![Screen Shot 2023-01-30 at 21.18.07.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/ba66d4b3-55ce-439e-a156-384e495a3f80/Screen_Shot_2023-01-30_at_21.18.07.png)

```cpp
#include<bits/stdc++.h>
using namespace std;
long long n,s;
int main(){ 
    int t;cin>>t;
    while(t--){
        cin>>n; 
        s=0;
        for(int i=1;i<=n;i++){
            int x;cin>>x;
            s+=abs(x);
        }
        cout<<2*n*s<<endl;
    }
    return 0;
}
```