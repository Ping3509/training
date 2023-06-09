### 线段树

线段树是一种二叉树，它能够高效地支持区间查询和区间修改操作。它的基本思想是将一个区间分成两个子区间，然后递归地构造线段树，最终形成一棵完整的线段树。

在线段树上，每个节点都表示一个区间，每个节点都存储着该区间的信息。如果要查询某个区间的信息，就从根节点开始向下遍历线段树，找到包含目标区间的节点，并计算出它的信息。如果要修改某个区间的信息，也是从根节点开始向下遍历线段树，找到包含目标区间的节点，并更新它的信息。

以下是线段树的模板：

```cpp
const int MAXN = 1e5 + 5; // 输入序列的最大长度

int a[MAXN], tree[MAXN << 2]; // 数组 a 用于存储输入序列，数组 tree 用于存储线段树

// 建树函数，l 表示当前区间的左端点，r 表示当前区间的右端点，p 表示当前节点的编号
void build(int l, int r, int p) {
    if (l == r) { // 如果区间长度为 1，即为叶节点，将叶节点的值存储到数组 tree 中
        tree[p] = a[l];
        return;
    }
    int mid = (l + r) >> 1; // 找到当前区间的中点
    build(l, mid, p << 1); // 递归建立左子树，当前节点的左孩子编号为 p << 1
    build(mid + 1, r, p << 1 | 1); // 递归建立右子树，当前节点的右孩子编号为 p << 1 | 1
    tree[p] = tree[p << 1] + tree[p << 1 | 1]; // 更新当前节点的值，为左右孩子节点的值之和
}

// 单点修改函数，l 表示当前区间的左端点，r 表示当前区间的右端点，p 表示当前节点的编号，x 表示待修改的位置，v 表示修改后的值
void modify(int l, int r, int p, int x, int v) {
    if (l == r) { // 如果找到了待修改的位置，将该位置的值更新为 v
        tree[p] = v;
        return;
    }
    int mid = (l + r) >> 1; // 找到当前区间的中点
    if (x <= mid) modify(l, mid, p << 1, x, v); // 如果待修改的位置在左子树中，递归修改左子树
    else modify(mid + 1, r, p << 1 | 1, x, v); // 如果待修改的位置在右子树中，递归修改右子树
    tree[p] = tree[p << 1] + tree[p << 1 | 1]; // 更新当前节点的值，为左右孩子节点的值之和
}

// 区间查询函数，l 表示当前区间的左端点，r 表示当前区间的右端点，p 表示当前节点的编号，ql 表示查询区间的左端点，qr 表示查询区间的右端点
int query(int l, int r, int p, int ql, int qr) {
    if (ql <= l && qr >= r) return tree[p]; // 如果当前区间被查询区间包含，直接返回当前节点的值
    int mid = (l + r) >> 1, res = 0; // 找到当前区间的中点，初始化查询结果为 0
    if (ql <= mid) res += query(l, mid, p<< 1, ql, qr); // 如果查询区间与左子树有交，递归查询左子树并更新查询结果
if (qr > mid) res += query(mid + 1, r, p << 1 | 1, ql, qr); // 如果查询区间与右子树有交，递归查询右子树并更新查询结果
return res; // 返回查询结果
}

int main() {
	int n; // 输入序列的长度
	cin >> n;
	for (int i = 1; i <= n; i++) {
	cin >> a[i]; // 读入输入序列
	}
	build(1, n, 1); // 建树
	int q; // 查询次数
	cin >> q;
	while (q--) {
	int op, x, y; // op 表示操作类型，x 和 y 表示操作涉及的参数
	cin >> op >> x >> y;
	if (op == 1) modify(1, n, 1, x, y); // 单点修改
	else cout << query(1, n, 1, x, y) << endl; // 区间查询
	}
	return 0;
}
```
上述代码实现了线段树的三个基本操作：建树、单点修改和区间查询。其中：

- 建树函数 `build`：在当前节点上递归建立左右子树，直到区间长度为 1 时将叶节点的值存储到数组 `tree` 中。
- 单点修改函数 `modify`：在当前节点上递归查找待修改的位置，直到找到叶节点，将该位置的值更新为修改后的值。
- 区间查询函数 `query`：在当前节点上递归查询查询区间与当前区间的交集，直到查询区间包含当前区间时直接返回当前节点的值，否则递归查询当前节点的左右子树，并将查询结果累加起来。

注：`<<` 运算符是左移运算符，表示将一个数的二进制位向左移动指定的位数，并在右侧用零填充。`p << 1` 和 `p << 1 | 1` 分别表示当前节点的左孩子和右孩子的编号，其中 `|` 表示按位或运算符，表示对两个数的二进制位进行或运算，如果对应位上至少有一个 1，则该位上的结果为 1，否则为 0。