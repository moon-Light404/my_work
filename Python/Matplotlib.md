## Pyplot绘图

`plot()`函数

**画单条线**

```python
plot(x, y, [fmt], data = None, **kwargs)
```

画多条线

```python
plot(x, y, [fmt], x2, y2, [fmt2], **kwargs)
```



- x、y：点或线的节点，数据可以为列表或数组
- fmt：可选，定义基本格式(如颜色、标记和线条样式)
- **kwargs：可选，用在二维图上，设置指定属性，如标签、线宽度

```python
plot(x,y)
plot(x,y, 'bo')
plot(y)
```

![image-20211118155959606](https://cdn.jsdelivr.net/gh/moon-Light404/my-picGo@master/img/202111181559716.png)

![image-20211118160049564](https://cdn.jsdelivr.net/gh/moon-Light404/my-picGo@master/img/202111181602652.png)

![image-20211118160115035](https://cdn.jsdelivr.net/gh/moon-Light404/my-picGo@master/img/202111181601122.png)

```python
xpoints = np.array([1, 8])
ypoints = np.array([3, 10])

plt.plot(xpoints, ypoints, 'o')
# 只会在坐标图上出现点


xpoints = np.array([1, 2, 6, 8])
ypoints = np.array([3, 8, 1, 10])

plt.plot(xpoints, ypoints)
plt.show()
# 出现折线，一点连一点
```



### 绘图标记

<mark>marker</mark>

```python
plt.plot(ypoints, marker = 'o') # 单独给点标记样式
plt.show()
```



**fmt参数**

```python
fmt = '[marker][line][color]'   标记、线条、颜色
```





### 轴标签和标题

- plt.xlabel("标签名")
- plt.ylabel("标签名")
- plt.title("图标题")

```python
zhfont1 = matplotlib.font_manager.FontProperties(fname="SourceHanSansSC-Bold.otf", size=18)
font1 = {'color':'blue','size':20}
font2 = {'color':'darkred','size':15}
plt.title("标题", fontproperties=字体库,fontdict = font1(字体设置的字典)loc = "位置")

plt.xlabel("x轴"，fontproperties=zhfont1,loc = "")

```



### 网格线

```python
plt.plot(x, y)
plt.grid()
plt.show()

plt.grid(axis = 'x') # 设置只有在y轴方向出现网格线

```



### 绘制多图

#### subplot(nrows, ncols, index) 行、列、编号

```python
plt.subplot(2,2,1)
plt.plot(x,y)
分成2*2部分，在第1个部分作图
```



#### subplots()



### 散点图

菜鸟教程https://www.runoob.com/matplotlib/matplotlib-scatter.html







### 柱形图

`matplotlib.pyplt.bar(x, height, width=0.8, bottom = None,*,align = 'center',data = None, **kwargs)`

**x**：浮点型数组，柱形图的 x 轴数据
**height**：浮点型数组，柱形图的高度

**width**：浮点型数组，柱形图的宽度

**bottom**：浮点型数组，底座的 y 坐标，默认0

**align**：柱形图与 x 坐标的对齐方式，'center' 以 x 位置为中心，这是默认值。 'edge'：将柱形图的左边缘与 x 位置对齐。要对齐右边缘的条形，可以传递负数的宽度值及 align='edge'。

***\*kwargs：**：其他参数。

