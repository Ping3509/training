## H Tokitsukaze and K-Sequence

链接：

[https://ac.nowcoder.com/acm/contest/46810/H](https://ac.nowcoder.com/acm/contest/46810/H)

来源：牛客网

Tokitsukaze 有一个长度为 nnn 的序列 aaa，她想把这个序列划分成 kkk 个**非空子序列**。定义序列的值为这个序列中**只出现一次**的数字的个数。  对于 k=1…nk=1 \ldots nk=1…n，Tokitsukaze 想知道把序列 aaa 划分成 kkk 个**非空子序列**后，所有子序列的值的和最大是多少。  **请注意，子序列不一定是连续的。**

## **输入描述:**

```
第一行包含一个正整数TTT (1≤T≤101 \leq T \leq 101≤T≤10)，表示测试数据的组数。

对于每组测试数据：

第一行包含一个整数nnn (1≤n≤1051 \leq n \leq 10^51≤n≤105)。

第二行包含nnn 个整数a1,a2,…,ana_1, a_2, \ldots, a_na1,a2,…,an (1≤ai≤1051 \leq a_i \leq 10^51≤ai≤105)。
```

## **输出描述:**

```
对于每组数据，输出nnn 个整数，第iii (1≤i≤n1 \leq i \leq n1≤i≤n) 个整数表示k=ik=ik=i 时的答案。
```

示例1

## 输入

复制

1
3
2 2 1

`1
3
2 2 1`

## 输出

复制

1
3
3

`1
3
3`

## 说明

`样例1解释：当 k=1k=1k=1 时，aaa 只能划分成 [a1,a2,a3][a_1,a_2,a_3][a1,a2,a3]，即 [2,2,1][2,2,1][2,2,1]。其中只有 111 个数字只出现了一次，所以答案是 111。当 k=2k=2k=2 时，aaa 可以划分成 [a1,a3][a_1,a_3][a1,a3], [a2][a_2][a2]，即 [2,1][2,1][2,1] 和 [2][2][2]。[2,1][2,1][2,1] 中有 222 个数字只出现了一次，[2][2][2] 中有 111 个数字只出现了一次，所以答案是 2+1=32+1=32+1=3。当 k=3k=3k=3 时，aaa 只能划分成 [a1][a_1][a1], [a2][a_2][a2], [a3][a_3][a3]，即 [2][2][2], [2][2][2], [1][1][1]。所以答案是 1+1+1=31+1+1=31+1+1=3。`

示例2

## 输入

复制

2
10
1 2 3 4 2 3 2 4 2 1
1
5

`2
10
1 2 3 4 2 3 2 4 2 1
1
5`

## 输出

复制

0
7
8
10
10
10
10
10
10
10
1

`0
7
8
10
10
10
10
10
10
10
1`

![Screen Shot 2023-01-30 at 21.59.37.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/a2f3121d-0a3e-4d32-8164-6fb3bee892e8/Screen_Shot_2023-01-30_at_21.59.37.png)

![Screen Shot 2023-01-30 at 21.59.43.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/6a9f06b5-acb8-4b35-bde9-379ea3c41620/Screen_Shot_2023-01-30_at_21.59.43.png)

![Screen Shot 2023-01-30 at 22.45.35.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/d8077adb-0a35-4324-9aae-e4770e5b8382/Screen_Shot_2023-01-30_at_22.45.35.png)

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,ans,i;
int main(){ 
    int t;cin>>t;
    while(t--){
        cin>>n;
        map<int,int>mp;
        for(i=1;i<=n;i++){
            int x;cin>>x;
            mp[x]++;//先存到容器当中
        }
        ans=0;
        for(auto [i,j]: mp){
            if(j==1) ans++; //先算一遍只有一个的
        }
        for(i=1;i<=n;i++){
            cout<<ans<<endl; //上面算了 直接输出
            vector<int>v;
            for(auto [x,y]:mp){
                v.push_back(x); //存数字
            }
            for(auto x:v){
                if(mp[x]==1){ //如果数字对上的话，只有一次，就删掉，下一次就没有了。上面建立那个vector的作用就是怕删掉了
                    mp.erase(x);continue;//删掉
           
                }
                ans++;mp[x]--;//然后结果+ mp对应的次数减少
                if(mp[x]==1) ans++; //减少完了再次进行判断是否是一次 如果是就加，然后到上面直接输出
            }
        }
    }
    return 0;
}
```

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,res;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;res=0;
		map<int,int> mp;
		
		for(i=1;i<=n;i++){
			cin>>k;mp[k]++;
		}
		
		for(auto [i,j]:mp){
			if(j==1)res++;
		}
		
		for(i=1;i<=n;i++){
			cout<<res<<'\n';
			vector<int> v;
			for(auto [x,y]:mp){
				v.push_back(x);
			}
			for(auto x:v){
				if(mp[x]==1){
					mp.erase(x);continue;
				}
				res++;mp[x]--;
				if(mp[x]==1)res++;
			}
		}
	}
}
```

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,ans,i,x;
int main(){ 
    int t;cin>>t;
    while(t--){
        cin>>n;
        map<int,int>mp;
        for(i=1;i<=n;i++){
            cin>>x; mp[x]++;
        }
        ans=0;
        vector<int> d1(n + 1), d2(n + 1);
        for (auto [_, x] : mp) {
            d1[x] += x;
            d2[x - 1]++;
        }
        for (int i = 1; i <= n; i++) {
            d1[i] += d1[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            d2[i] += d2[i + 1];
        }
        for (int i = 1; i <= n; i++) {
            auto ans = d1[i] + d2[i] * (i - 1);
            std::cout << ans << "\n";
        }
    }

    return 0;
}
```