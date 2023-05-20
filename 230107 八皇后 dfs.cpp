/*Tabris减肥记 贪心
## 八皇后
[https://www.luogu.com.cn/problem/P1219](https://www.luogu.com.cn/problem/P1219)  
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int cnt;
int zhu[120];
int fu[120];
int chk[20];
int a[20];
void dfs(int x){
    if(x==n+1){
        if(cnt<=2){//把前三个拿出来输出
            for(int i=1;i<=n;i++){
                cout<<a[i]<<' ';
            }
            cout<<endl;
        }
        cnt++;
        return;
    }
    for(int i=1;i<=n;i++){
            if(!chk[i] && !zhu[x+i] &&  !fu[x+n-i]){
                a[x]=i;
                chk[i]=1;zhu[x+i]=1;fu[x+n-i]=1;
                dfs(x+1);
                chk[i]=0;zhu[x+i]=0;fu[x+n-i]=0;
            }
        }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    dfs(1);
    cout<<cnt<<'\n';
    return 0;
}