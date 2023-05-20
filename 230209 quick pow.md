```cpp
int qpow(int a,int b, int p){
	if(b=0) return 1;
	else{
			int t = qpow(a, b/2, p)
			t= t * t % p;
			if(b % 2==1) t= t * a % p;
			return t % p;
	}
}
```

```cpp

#include <iostream>using namespace std;

// 计算 a^b % mod 的值
int qmi(int a, int b, int mod) {
    int res = 1 % mod; // 初始化 res 为 1
    while (b) { // 用二进制的形式枚举 b 的每一位
        if (b & 1) { // 如果当前二进制位是 1，则乘上对应的 a^2^i
            res = (long long)res * a % mod;
        }
        a = (long long)a * a % mod; // 更新 a^2
        b >>= 1; // 右移一位
    }
    return res;
}

int main() {
    int a, b, mod;
    cin >> a >> b >> mod;
    cout << qmi(a, b, mod) << endl;
    return 0;
}

```