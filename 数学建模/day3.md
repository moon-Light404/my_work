### 微分计算

$f(x)=x^3-2x-5$的微分

`p[1 0 -2 -5]`各项系数



- ==$polyval$==方法

`polyval()` 多项式估值运算，语法格式`y = ployval(p,x)`,输入变量p是长度为n+1的向量，表示一个函数。x可以是一个数，也可以是一个矩阵或者一个向量，该指令计算的是在X中任意元素处多项式p的估值。



- ==$plot$==方法

`plot(X,Y)`创建Y中数据对X中对应值的二维线图

画出$9x^3-5x^2+3x+7$

```matlab
a = [9,-5,3,7]; x = -2:0.01:5;
f = polyval(a,x);
plot(x,f,'lineWidth',2);
xlabel('x'); ylabel('f(x)');
set(gca,'Fontsize',14)
```

- ==$ployder$==微分方法

```matlab
p = [5 0 -2 0 1]
ployder(p)

// result:
20 0 -4 0 // 微分的系数变成4位了

// 求某个数的微分值
polyval(polyder(p),7) // 前面的向量代表一个函数，后面是某个x

a = [20 -7 5 10];

```









