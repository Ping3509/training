## Jelly

[https://ac.nowcoder.com/acm/problem/201613](https://ac.nowcoder.com/acm/problem/201613)

[https://www.cnblogs.com/liyexin/p/12757473.html](https://www.cnblogs.com/liyexin/p/12757473.html)

```cpp
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 105;
const int INF = 0x3f3f3f3f;

// 方向数组，分别表示六个方向
const int dx[6] = {0, 0, 0, 0, -1, 1};
const int dy[6] = {0, 0, -1, 1, 0, 0};
const int dz[6] = {-1, 1, 0, 0, 0, 0};

char jelly[MAXN][MAXN][MAXN];  // 存储果冻
int dis[MAXN][MAXN][MAXN];     // 存储到每个点的最短路

struct Node {
    int x, y, z;
};

bool check(int x, int y, int z, int n) {
    return x >= 1 && x <= n && y >= 1 && y <= n && z >= 1 && z <= n && jelly[x][y][z] != '*';
}

int bfs(int n) {
    memset(dis, INF, sizeof(dis));  // 初始化dis数组为INF
    dis[1][1][1] = 0;                // 初始点到自己的最短路为0
    queue<Node> q;
    q.push({1, 1, 1});  // 将起点加入队列
    while (!q.empty()) {
        Node cur = q.front();
        q.pop();
        for (int i = 0; i < 6; i++) {  // 枚举六个方向
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            int nz = cur.z + dz[i];
            if (check(nx, ny, nz, n) && dis[nx][ny][nz] == INF) {  // 如果这个方向是可行的且没有被访问过
                dis[nx][ny][nz] = dis[cur.x][cur.y][cur.z] + 1;     // 更新到该点的最短路
                q.push({nx, ny, nz});                              // 将该点加入队列
            }
        }
    }
    if (dis[n][n][n] == INF) {  // 判断是否无法到达终点
        return -1;
    } else {
        return dis[n][n][n];
    }
}

int main() {
    int n;
    cin >> n;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> jelly[i][j][k];
            }
        }
    }
    cout << bfs(n) << endl;  // 输出最短路长度
    return 0;
}
```