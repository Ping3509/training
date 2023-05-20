# A **Running Miles**

### 230515

[](https://www.luogu.com.cn/problem/CF1826D?contestId=109920)

这道题是一个数组问题。题目给出了一个长度为 n 的数列，表示街道上每个位置的美丽值。现在需要选择一个区间 [l, r]，使得在这个区间内的前三大的美丽值之和减去区间长度 (r - l) 的值最大。

解题思路可以分为以下几步：

1. 遍历数组，找到数组中前三大的数值以及对应的索引。
2. 遍历数组，计算每个位置作为区间起点的情况下，选择的区间终点的最大值。对于每个起点位置，可以通过比较当前位置与前三大数值对应的索引，确定区间终点的选择范围。
3. 在遍历过程中记录最大值，并返回结果。

具体的实现步骤如下：

1. 读取输入的测试用例数量 t。
2. 对于每个测试用例，读取数组长度 n 和美丽值数组。
3. 初始化变量 max_value 为负无穷大，用于记录最大的结果值。
4. 遍历数组，找到前三大的美丽值以及对应的索引。
5. 遍历数组，对于每个起点位置，确定区间终点的选择范围。
6. 计算当前起点位置和终点位置对应的美丽值之和减去区间长度，并更新 max_value。
7. 输出 max_value。

**rbegin()指向最后一个元素，rend()指向第一个元素**，和begin()相等。

[D. Running Miles - onlyblues - 博客园](https://www.cnblogs.com/onlyblues/p/17375929.html)

```
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

int a[N];
int l[N], r[N];

void solve() {
    int n;
    cin >> n;
    l[0] = r[n + 1] = -INF;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        l[i] = max(l[i - 1], a[i] + i);
    }
    for (int i = n; i; i--) {
        r[i] = max(r[i + 1], a[i] - i);
    }
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        ret = max(ret, a[i] + l[i - 1] + r[i + 1]);
    }
    cout << ret << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
```

**`l`** 和 **`r`** 来存储在每个位置上的最大值。数组 **`l`** 存储了当前位置之前的数中的最大值加上对应的索引，数组 **`r`** 存储了当前位置之后的数中的最大值减去对应的索引。

通过两个循环分别计算出 **`l`** 和 **`r`** 数组的值后，再通过一个循环计算最终的结果。在这个循环中，我们计算当前位置的美景值 **`a[i]`** 加上 **`l[i-1]`** 和 **`r[i+1]`** 的和，并取最大值作为结果。