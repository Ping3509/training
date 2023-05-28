#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,h[300005],m=0;
ll cnt1,cnt2,tmp,ans;
ll solve(int m){
    cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        tmp=m-h[i];
        cnt1+=tmp%2;
        cnt2+=tmp/2;
    }
    if(cnt1>cnt2) return cnt1*2-1;
    if(cnt1==cnt2) return cnt2*2;
    long long extra2=cnt2-cnt1;
    cnt1+=extra2/3*2;
    cnt2-=extra2/3;
    extra2=cnt2-cnt1; 
    if(extra2==2) return 2*cnt2-1;
    return 2*cnt2;
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>h[i];
        }
        sort(h,h+n);
        m=h[n-1];
        ans=min(solve(m),solve(m+1));
        cout<<ans<<endl;
    }
}


统计必须在奇数天浇水的次数。先默认剩下的高度差都使用偶数天来浇水。

然后可能会得到：

1. 奇数天>偶数天：奇 偶 奇 偶 奇 偶 ... 奇 偶 奇 (空) 奇 (空) 奇 (空) 奇
    
    这种情况下，把任何偶数天浇水拆成两个奇数天浇水都只能增加总天数，所以这就是最佳答案。
    
    总天数=奇数天*2-1。
    
2. 奇数天=偶数天：奇 偶 奇 偶 奇 偶 ... 奇 偶 奇 偶
    
    同样，把任何偶数天浇水拆成两个奇数天浇水都只能增加总天数。
    
    总天数=奇数天*2。
    
3. 奇数天<偶数天：奇 偶 奇 偶 奇 偶 ... 奇 偶 (空) 偶 (空) 偶 (空) 偶
    
    在第一个空出现之前，都没有优化空间了，所以只需要考虑第一个空及更往后的部分。
    
    分情况讨论：
    
    1. 多了一个偶数天：(空) 偶——无法优化
    2. 多了两个偶数天：(空) 偶 (空) 偶——奇 偶 奇
    3. 多了三个偶数天：(空) 偶 (空) 偶 (空) 偶 ——奇 偶 奇 偶
    4. 多了更多偶数天：每三个偶数天可以拆成“奇 偶 奇 偶”。对三取模的部分再按照情况1或情况2来考虑。

目标高度可能是所有树中最高的高度，也可能是最高的高度+1；后者在有些情况下可以通过减少必须在奇数天浇水的数量来减少总天数。（如：1 1 1 1 1 1 2）对两种可能的目标高度分别计算，取最优答案即可。