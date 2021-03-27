从给出的数中选出来加起来的和是 K 的倍数，在满足倍数的条件下取得最大。

![image-20210326211938318](https://cdn.jsdelivr.net/gh/moon-Light404/my_picgo/img/20210326211938.png)



`f[i-1][j-w%k]` 防止第二维为负数变为`f[i-1][j+k-w%k]`

`a%b` ->`(a+b)%b`

<img src ="https://cdn.jsdelivr.net/gh/moon-Light404/my_picgo/img/20210327101959.png" style="zoom:50%;" />
<img src ="https://cdn.jsdelivr.net/gh/moon-Light404/my_picgo/img/20210327102006.png" style="zoom:50%;" />