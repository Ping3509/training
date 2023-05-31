题目意思：在一个n*m中的矩阵中寻找一个L*的子矩阵，要求这个矩阵中的元素都是大于等于L的，求最大的L是多少。

分析：这是一道二维**前缀和+二分**的题目，

先用二维前缀和预处理出大于等于L的为1，小于L的为0，

然后再进行判断是否有区域符合，二分是寻找符合题目基础要求的最大L。

考虑完这两点后，就可以开始写代码了，还有一点是n*m<=1e6,建议使用vector，避免极端情况。首先咱确定vector[n]，因为二维数组开不了那么大。

**一看到求最大最小就知道应该用二分**

二分我们可以通过一开始的矩阵a，我们建一个矩阵b，如果a[i][j]大于等于我们现在的k的话那么就是1，小于的话就是0。


## AC代码

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000005;
vector<vector<int>>a,b;
int n,m;
bool check(int x){
    b = vector<vector<int>>(n + 1, vector<int>(m + 1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+(a[i][j]>=x);
          
        }
    }
     for (int i = x; i <= n; i++){
          for (int j = x; j <= m; j++){
              if(b[i][j]-b[i-x][j]-b[i][j-x]+b[i-x][j-x] == x*x)
                  return false;
              
          }
     }
     return true;
    
}

int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        cin>>n>>m;
        a = vector<vector<int>>(n + 1, vector<int>(m + 1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        int l=1,r=min(n,m)+1;
        while(l<r){
            int mid= l+r >>1;
            if(check(mid)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        cout<<l-1<<endl;
        
    }
}
```