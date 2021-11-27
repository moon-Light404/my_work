### NumPy中的Ndarray对象

N维数组ndarray对象，是一系列<mark>同类型对象</mark>的集合，以0下标开始索引

```python
import numpy as np
np.array(object,dtype = None,copy = True,order = None,subok=False,ndmin=0)
```

- object：数组或嵌套的列
- order：创建数组的样式，C为行方向，F为列方向，A为任意
- ndmin：指定生成数组的最小维度

```python
import numpy as np 
a = np.array([[1,  2],  [3,  4]])  
print (a)

import numpy as np 
a = np.array([1, 2, 3, 4, 5], ndmin =  2)  
print (a)
```



### NumPy数据类型

| 名称       | 描述                                                         |
| :--------- | :----------------------------------------------------------- |
| bool_      | 布尔型数据类型（True 或者 False）                            |
| int_       | 默认的整数类型（类似于 C 语言中的 long，int32 或 int64）     |
| intc       | 与 C 的 int 类型一样，一般是 int32 或 int 64                 |
| intp       | 用于索引的整数类型（类似于 C 的 ssize_t，一般情况下仍然是 int32 或 int64） |
| int8       | 字节（-128 to 127）                                          |
| int16      | 整数（-32768 to 32767）                                      |
| int32      | 整数（-2147483648 to 2147483647）                            |
| int64      | 整数（-9223372036854775808 to 9223372036854775807）          |
| uint8      | 无符号整数（0 to 255）                                       |
| uint16     | 无符号整数（0 to 65535）                                     |
| uint32     | 无符号整数（0 to 4294967295）                                |
| uint64     | 无符号整数（0 to 18446744073709551615）                      |
| float_     | float64 类型的简写                                           |
| float16    | 半精度浮点数，包括：1 个符号位，5 个指数位，10 个尾数位      |
| float32    | 单精度浮点数，包括：1 个符号位，8 个指数位，23 个尾数位      |
| float64    | 双精度浮点数，包括：1 个符号位，11 个指数位，52 个尾数位     |
| complex_   | complex128 类型的简写，即 128 位复数                         |
| complex64  | 复数，表示双 32 位浮点数（实数部分和虚数部分）               |
| complex128 | 复数，表示双 64 位浮点数（实数部分和虚数部分）               |

```python
# int8, int16, int32, int64四种数据类型可以使用字符 'i1'、'i2'、'i3'、'i4'来表示
```



<mark>结构化数据类型</mark>

```python
dt = np.dtype([('age',np.int8)])
print(dt)
# [('age', 'i1')]
a = np.array([(10,),(20,),(30,)],dtype = dt)
print(a)
# 输出为 [(10,) (20,) (30,)]

# 类型字段名可以用于存取实际的 age 列
print(a['age'])	# [10 20 30]

# 结构化 student类型
student = np.dtype([('name','S20'), ('age','i1'), ('marks','f4')])
a = np.array([('abc', 21,50),('xyz',18,75),dtype = student])
print(a)
```



### NumPy数组属性

| 属性             | 说明                                                         |
| :--------------- | :----------------------------------------------------------- |
| ndarray.ndim     | 秩，即轴的数量或维度的数量                                   |
| ndarray.shape    | 数组的维度，对于矩阵，n 行 m 列                              |
| ndarray.size     | 数组元素的总个数，相当于 .shape 中 n*m 的值                  |
| ndarray.dtype    | ndarray 对象的元素类型                                       |
| ndarray.itemsize | ndarray 对象中每个元素的大小，以字节为单位                   |
| ndarray.flags    | ndarray 对象的内存信息                                       |
| ndarray.real     | ndarray元素的实部                                            |
| ndarray.imag     | ndarray 元素的虚部                                           |
| ndarray.data     | 包含实际数组元素的缓冲区，由于一般通过数组的索引获取元素，所以通常不需要使用这个属性。 |

