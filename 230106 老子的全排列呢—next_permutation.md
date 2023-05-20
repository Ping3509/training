## 老子的全排列呢—next_permutation

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int a[9];
    for(int i=1;i<=8;i++){
        a[i]=i;
    }
    do{
        for(int i=1;i<=8;i++){cout<<a[i]<<" ";}
        cout<<endl; 
    }while(next_permutation(a+1,a+9));
    return 0;
}
```

### 解法1：**next_permutation函数**

**next_permutation函数的功能是将数组中选定范围的数按照字典序进行全排列。**

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a[5]={2,5,1,3,8};
	sort(a,a+5);//如果不排序则从当前状态开始进行全排列  
	do
	{
		for(int i=0;i<5;i++)
		cout<<a[i]<<" ";
		cout<<endl; 
	}while(next_permutation(a,a+5));
	 //(a+m，a+n)指从数组下表为m到n-1的数进行全排列 
	 return 0;
}
```

### 解法2：Dfs

[回溯算法](https://so.csdn.net/so/search?q=%E5%9B%9E%E6%BA%AF%E7%AE%97%E6%B3%95&spm=1001.2101.3001.7020)
适合：由多个步骤组成的问题，并且每个步骤都有多个选择项，所有就是类似一个树形结构。

```cpp
function dfs(参数列表){
    if(终止条件){
        存放结果
        return
    }
    for(选择：本层集合中的元素){
        处理节点
        dfs(参数列表(路径))
        回溯，撤销处理结果
    }
}
```

```cpp
#include<bits/stdc++.h>
using namespace std;
int a[10];
int check[10];
int n;
void dfs(int x){ // x step第几个盒子
    if(x==n+1){ //dfs(4)结束
        for(int i=1;i<=n;i++){
            cout<<right<<setw(5)<<a[i]; //右对齐 a[1][2][3]输出
            //第一个是123
        }
        cout<<endl;
        return;//回溯
    }
    for(int i=1;i<=n;i++){
        if(!check[i]){//if check为0 check==0
            a[x]=i; //x=1,i=1,a[1]=1
            check[i]=1; //check1，1用过了
            dfs(x+1); //移动到下一个盒子 dfs(2) 
                //x=2,(i=1不行用过了)i=2,a[2]=[2]，check2,dfs(3)
                    //x=3,(i=1不行用过了,i=2不行用过了)i=3,a[3]=[3]，check3,dfs(4)输出123 backtracking return 
                //check 3=0 3可以用了, backtracking check 2=0 2可以用了
                //到下一层 i=3,x=2,a[2]=3,dfs(3)
                    //(i=1不行用过了)i=2可以，x=3 a[3]=2
            check[i]=0;  //输出完回到这里 标记成没用过 回溯
            
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    
    cin>>n;
    dfs(1);
    return 0;
}
```

