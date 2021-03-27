# 背包问题汇总

### 01背包问题(easy)

有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。

第 i 件物品的体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。

输入格式

第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。

接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 ii 件物品的体积和价值。

输出格式

输出一个整数，表示最大价值。

数据范围

0<N,V≤10000<N,V≤1000
0<vi, wi ≤10000<vi, wi≤1000

输入样例

```
4 5
1 2
2 4
3 4
4 5
```

输出样例：

```
8
```

 用集合和状态DP分析:

![image-20210303204651735](https://cdn.jsdelivr.net/gh/moon-Light404/my_picgo/img/20210316160614.png) 



```c++
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int v[N], w[N]; // 体积和价值
int f[N][N]; // f[i][j], j体积下前i个物品的最大价值

int main() {
	int n, m;
	cin >> n >> m; // n件物品和背包容量m

	for (int i = 1; i <= n; i++)
		cin >> v[i] >> w[i];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) { // 此背包有选与不选两种情况
			if (j < v[i]) { // 如果背包容量比这件物品的体积还小
				f[i][j] = f[i - 1][j]; // 那么此时这个物品就不用管
//				cout << i << ' ' << j << ' ' << f[i][j] << endl;
			} else
				f[i][j] = max(f[i - 1][j - v[i]] + w[i], f[i - 1][j]); // 状态转移方程,有两种情况取或者不取
//			cout << i << ' ' << j << ' ' << f[i][j] << endl;
		}

	// f[i][j] 表示 体积为j下前i个物品的价值最大值
	cout << f[n][m] << endl;

	return 0;
}


 // 优化版本
#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1010;
int v[N], w[N];
int f[N];
int main()
{
    int n, m;
    cin >> n >>m;
    for(int i = 1; i <= n;i++)
        cin >> v[i] >> w[i];
        
    for(int i = 1;i <= n;i++)
        for(int j = m; j >= v[i];j--)
        {
                f[j] = max(f[j - v[i]] + w[i],f[j]);
        }
    cout << f[m]<< endl;
    return 0;
}
```



---



### 完全背包问题

有 NN 种物品和一个容量是 VV 的背包，每种物品都有无限件可用。

第 ii 种物品的体积是 vivi，价值是 wiwi。

求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。

输入格式

第一行两个整数，N，VN，V，用空格隔开，分别表示物品种数和背包容积。

接下来有 NN 行，每行两个整数 vi,wivi,wi，用空格隔开，分别表示第 ii 种物品的体积和价值。

输出格式

输出一个整数，表示最大价值。

数据范围

0<N,V≤10000<N,V≤1000
0<vi,wi≤10000<vi,wi≤1000

输入样例

```
4 5
1 2
2 4
3 4
4 5
```

输出样例：

```
10
```

![img](https://cdn.jsdelivr.net/gh/moon-Light404/my_picgo/img/20210316160756.png)



简单写法:

```c++
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;
int v[N], w[N];
int f[N][N]; // f[i][j]表示从前i个物品中选且 V <= j 最大价值，每件物品可重复选取
int main()
{
    int n, m; // 物品总数和背包容积
    cin >> n >> m;
    for(int i = 1; i <= n;i++)  cin >> v[i] >> w[i];
    
    for(int i = 1; i <= n;i++)
        for(int j = 1; j <= m;j++)
        {
            f[i][j] = f[i - 1][j]; // 第i件物品一件也不取
            if(j >= v[i])
            {
                f[i][j] = max(f[i-1][j], f[i][j - v[i]] + w[i]);
            }
           
        }
    cout << f[n][m];
    return 0;
}
```



<a href = "https://www.acwing.com/video/945/">代码优化</a>变为==一维数组==

优化写法

```c++
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;
int v[N], w[N];
int f[N]; // f[i][j]表示从前i个物品中选且 V <= j 最大价值，每件物品可重复选取
int main()
{
    int n, m; // 物品总数和背包容积
    cin >> n >> m;
    for(int i = 1; i <= n;i++)  cin >> v[i] >> w[i];
    
    for(int i = 1; i <= n;i++)
        for(int j = m; j >= v[i];j--)
        {
                f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    cout << f[m];
    return 0;
}
```



---

### 多重背包问题

有 N 种物品和一个容量是 V 的背包。

第 i 种物品最多有 s 件，每件体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。

输入格式

第一行两个整数，N，VN，V，用空格隔开，分别表示物品种数和背包容积。

接下来有 NN 行，每行三个整数 vi,wi,sivi,wi,si，用空格隔开，分别表示第 ii 种物品的体积、价值和数量。

输出格式

输出一个整数，表示最大价值。

数据范围

0<N,V≤1000<N,V≤100
0<vi,wi,si≤1000<vi,wi,si≤100

输入样例

```c++
4 5
1 2 3
2 4 1
3 4 3
4 5 2
```

输出样例：

```c++
10
```

本题是01背包问题的一个演化，01背包问题中一个背包只有选与不选两种情况，在多重背包问题中每个背包(有s个背包)`s+1`种选取方法,只要再加1个循环循环取得数量即可。

```c++
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 110;
int v[N], w[N], s[N];
int f[N]; // f[i]表示体积为i的背包可以获得的最大价值 
int main()
{
    int n, m; // 物品总数和背包容积
    cin >> n >> m;
    for(int i = 1; i <= n;i++)  cin >> v[i] >> w[i] >> s[i];
    
    for(int i = 1; i <= n;i++)
        for(int j = m; j >= v[i];j--) // 从m开始
        {
            for(int k = 1; k <= s[i] &&  k * v[i] <= j;k++)
                f[j] = max(f[j], f[j - k * v[i]] + k *  w[i]);
        }
    cout << f[m];
    return 0;
}

```
#### 标准朴素写法
```c++
#include <iostream>
#include <algorithm>

using namespace std;
const int N = 110;

int v[N], w[N], s[N]; 
 // f[i][j] 表示前i件物品总重量(且总重量 <= j)的最大价格
int f[N][N]; 
int n, m;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> v[i] >> w[i] >> s[i];

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            for(int k = 0; k <= s[i]; k ++){
                if(j >=  k * v[i]){
                    f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
                }
            }
        }
    }

    cout << f[n][m] << endl;

    return 0;
}


```

