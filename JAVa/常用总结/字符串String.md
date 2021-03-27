## String类

### 字符串的不可变特性

```java
String s = "hello";
//JVM虚拟机先创建字符串 hello 然后把字符串变量 s 指向它
sout(s);
s="world";
//执行这里时，JVM虚拟机先创建字符串 hello 然后把字符串变量 s指向它
sout(s);
//观察这段代码，其实原来的字符串 "hello"还在，只是无法通过变量 s
//进行访问它，因此字符串的不可变是指字符串内容不可变(但指向可以变)
```

### 空值null

```java
String s1 = null;
String s2;//没有赋初值,s2也是null
String s3 = s1;//s3也是null
String s4 = "";//指向空字符串,但不是null

```



### 创建字符串

```java
1、String greeting = "菜鸟教程";

2、char []hello = {'r','u','n','o','o','b'};
String hello = new String(hello);
//注意：String类是不可改变的,如果要改变就使用StringBuffer & StringBulider类
```

### 长度

`length`方法

### 连接字符串

`string1.concat(string2)`

`"我的名字是 ".concat("Runoob")`

`"Hello"+"runoob"+"!"`

### 创建格式化字符串

```java
方法一:	printf方法
方法二：	
String fs;
fs = String.format("浮点型变量值为"+"%f,整型变量的值为"+
                  "%d,字符串变量的值为"+
                  "%s",floatVar,intVar,stringVar);
```

### String 方法

https://www.runoob.com/java/java-string.html

## StringBuffer、StringBuilder类

这两个类的对象能够多次被修改且不产生新的未使用对象

由于 StringBuilder 相较于 StringBuffer 有速度优势，所以多数情况下建议使用 StringBuilder 类。然而在==应用程序要求线程安全==的情况下，则必须使用 StringBuffer 类。

一些常用方法

- StringBuffer append(String s)
- StringBuffer reverse()
- delete(int start,int end)
- insert(int offset,int i)
- replace(int start,int end,String str)













