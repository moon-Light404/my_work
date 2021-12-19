
删除缺失值


```python
data = pd.DataFrame()
# dropna 默认情况下删除包含缺失值的行,创建的是新对象
cleaned = data.dropna()	
# 传入how = 'all'时，删除所有值均为NA的行
data.dropna(how = 'all')
# 删除列 参数axis = 1:
data.dropna(axis, how = 'all')
```



补全缺失值

```python
df.fillna(0) # 将所有缺失值补充为0

# 使用字典为不同列设定不同的缺失值
df.fillna({1:0.5, 2:0})	# fillna返回的是一个新对象
# inplace = True参数可以修改已存在的对象
```



删除重复值

```python
data.duplicated() # 删除重复行(与之前出现的行相同),返回布尔值
# 删除重复行
data.drop_duplicates() # 对一整行进行操作，只有当一行数据完全一样才会删除
# 对某一列删除重复的行
data.drop_duplicates(['k1'])
```

函数映射进行数据转换

![image-20211213170521725](https://cdn.jsdelivr.net/gh/moon-Light404/my-picGo@master/img/202112131705838.png)

![image-20211213170540763](https://cdn.jsdelivr.net/gh/moon-Light404/my-picGo@master/img/202112131705813.png)

```python
# 如果我们要添加`animal`列
lowercased = data['food'].str.lower()
data['animal'] = lowercased.map(meat_to_animal)
# 或者函数
data['food'].map(lambda x:meat_to_animal[x.lower()])
```



替代值

```python
data.replace(-999,np.nan) # 如果要操作源数据加上 inplace = True
# 替代多个值
data.replace([-999,-1000], np.nan)
data.replace([-999,-1000],[np.nan, 0])
data.replace({-999: np.nan, -1000: 0})
```



重命名轴索引

```python
data.rename(index={'OHIO':'INDIANA'}, columns = {'three' : 'peek'}) # 为行和列提供新的值
```

```python
data[(np.abs(data) > 3).any(1)]	# 选出所有值大于3或小于-3的行
```



字符串操作

```python
val = 'a,b,   guido'
val.split(',') 以,对字符串进行分割
pieces = [x.strip() for x in val.split(',')]
'::'.join(pieces) # ::作为分隔符粘合其他字符串序列

data = pd.Series(data)
data.isnull() # 返回布尔值
data.str.contains('gmail') # 检查每个邮件是否含有 'gmail'

```

列索引

```python
frame
output:
    a b c d
 0
 1
 2
# set_index函数
frame2 = frame.set_index(['c', 'd']) # 将'c'和'd'列作为行索引(分层索引),生成一个新的dataframe，默认情况下这些列会移除
# 使用drop = False把作为索引的列留在dataFrame中
frame2 = frame.set_index(['c', 'd'], drop = False)
# reset_index重新设置索引
frame2.reset_index() # 更新索引，从0,1,2....
```

联合合并数据集

```python
# pandas.merge 根据一个或多个键进行连接，类似于SQL的连接操作
# pandas.concat 使对象在轴向上进行粘合或 堆叠

pd.merge(df1, df2, on = 'key')

np.concatenate([arr, arr], axis = 1) # 沿l
```

