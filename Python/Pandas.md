### Series数据结构

类似表格中的一个列，一维数组，可以保存任何数据类型

<mark>索引 + 列</mark>

```python
pandas.Series(data,index,dtype,name,copy)
```

- data：一组数据(ndarray类型)
- index：数据索引标签，如不指定，默认从0开始
- dtype：默认自己判断
- name：名称
- copy：拷贝数据，默认false

> 创建Series

```python
a = [1,2,3]
myvar = pd.Series(a)
myvar1 = pd.Series(a,index = ['x', 'y', 'z']) # 指定索引值

# 字典创建
sites = {1: "Google", 2:"Runnob", 3:"WiKi"}
myvar = pd.Series(sites,index = [1,2])
```





### DataFrame数据结构

表格型、含有一组有序的列，每列可以是不同的值类型。既有行索引又有列索引，可以看成由Series组成的字典。类似于二维数组结构

```
pandas.DataFrame(data, index, columns, dtype, copy)
```

- index：索引值、或者可以称为行标签
- columns：列标签、默认为RangeIndex(0、1、2....)

```python
# 默认情况下        
    0   1
0  Google  10
1  Runoob  12
2    Wiki  13
```

> 创建DataFrame

```python
# 列表
data =  [['Google',10],['Runoob',12],['Wiki',13]]
df = pd.DataFrame(data,columns=['Site','Age'],dtype=float)

# ndarrays创建
data = {'Site':['Google','Runoob','WiKi'],'Age':[10,12,13]}
df = pd.DataFrame(data)
#     Site   Age
#0  Google  10.0
#1  Runoob  12.0
#2    Wiki  13.0

# 使用字典创建
data = [{'a':1 ,'b':2}, {'a':5,'b':10,'c':20}]
df = pd.DataFrame(data)
  #a   b     c
#0  1   2   NaN
#1  5  10  20.0
```

> loc属性返回指定行的数据

```python
df.loc[0]
df.loc[1]
# 返回的结果其实是一个Series数据

data = {
  "calories": [420, 380, 390],
  "duration": [50, 40, 45]
}

# 数据载入到 DataFrame 对象
df = pd.DataFrame(data)
print(df)
# 返回第一行和第二行
print(df.loc[[0, 1]])
#结果
   calories  duration
0       420        50
1       380        40
2       390        45
   calories  duration
0       420        50
1       380        40
#返回的是DataFrame数据
---------------------
```





### Pandas CSV文件

读取 `read_csv`

```python
# 以纯文本形式存储表格数据(数字和文本)
df = pd.read_csv('ba.csv')
print(df.to_string) #to_string() 用于返回 DataFrame 类型的数据
```



存储`to_csv()`

```python
df.to_csv('site.csv')
```





### JSON

存储和交换文本信息的语法，类似XML

将json装换为pandas.DataFrame

```python
df = pd.DataFrame(S)
```



> 从Url中读取JSON数据

`pd.read_json(url)`

```python
URL = 'https://static.runoob.com/download/sites.json'
df = pd.read_json(URL)
```

> 处理.json文件

![image-20211118002151140](https://cdn.jsdelivr.net/gh/moon-Light404/my-picGo@master/img/202111181531248.png)

```python
df = pd.read_json('net.json')


with open('net.json','r') as f:
    data = json.loads(f.read())
# 展平数据
df_net_list = pd.json_normalize(data,record_path=['students'])
```

![image-20211118002212211](https://cdn.jsdelivr.net/gh/moon-Light404/my-picGo@master/img/202111181531544.png)

`data = json.loads(f.read())`

**json_normalize()** 使用了参数 **record_path** 并设置为 **['students']** 用于展开内嵌的 JSON 数据 **students**。

```python
# 展平数据
df_nested_list = pd.json_normalize(
    data,
    record_path =['students'],
    meta=['school_name', 'class']
)
```



![image-20211118002250901](https://cdn.jsdelivr.net/gh/moon-Light404/my-picGo@master/img/202111181531854.png)