## Java常类

## 1、字符串相关类 String

- String 是一个final类，代表<mark>不可变</mark>的字符序列
- 字符串是<mark>常量</mark>，用双引号括起来，它们的值在创建之后不能更改

- String 实现类Serializable接口：表示字符串是支持序列化的
- 实现了Comparable接口：可以比较大小
- String内部定义了final byte[] value 用于存储字符串数据

一旦一个String对象在内存中创建，它将是不可改变的，所有的String类中方法并不是改变String对象自己，而是重新创建一个新的String对象。

例如：c1和c3都执行同一个对象"abc"，当执行语句`c1 = "han"`时，并没有改变堆中"abc"对象的值，而是重新创建了一个新的String对象，但此时c3的值仍然"abc"。

![image-20210715115327525](https://cdn.jsdelivr.net/gh/moon-Light404/my-picGo/img/202111022103830.png)

### 1.1String 创建方法

- 五种方法

![image-20210715194830114](https://cdn.jsdelivr.net/gh/moon-Light404/my-picGo/img/202111022103763.png)

```java
String s1 = "java";
String s2 = "java";
// 通过字面量定义的方式：此时的s1和s2的数据java声明在方法区中的字符串常量池中。
// ~~ s1 == s2  true
    
    
String s3 = new String("java");
String s4 = new String("java");
// 通过new的方式：此时的s3和s4保存的地址值，是在堆空间中开辟空间以后对应的地址值。
// s3 == s4  false

```

![image-20210715200124938](https://cdn.jsdelivr.net/gh/moon-Light404/my-picGo/img/202111022103742.png)

![image-20210715201030564](https://cdn.jsdelivr.net/gh/moon-Light404/my-picGo/img/202111022103316.png)

<mark>常量池中不会放两个相同的字符串</mark>

---

### 1.2字符串拼接的比较

```java
public class stringTest {
    @Test
    public void test1() {
        String s1 = "java";
        String s2 = "hadoop";
        String s3 = "javahadoop";
        String s4 = "java" + "hadoop"; // 两个字面量拼接变为一个字面量
        String s5 = "java" + s2; // 变量拼接，在堆中新建(和new类似)
        String s6 = s1 + "hadoop";
        
        System.out.println(s3 == s4); // true
        System.out.println(s3 == s5); // false
        System.out.println(s3 == s6); // false
        System.out.println(s5 == s6); // false
    }
}
```



> 常量与常量的拼接结果在常量池，且常量池中不会存在相同内容的常量。
>
> 只要其中有一个是变量，结果就在堆中	

![image-20210715202504618](https://cdn.jsdelivr.net/gh/moon-Light404/my-picGo/img/202111022104880.png)

---



### 1.3String常用方法

- s.length()：字符串的长度
- s.charAt(int index)：返回某索引处的字符
- s.isEmpty()：判断是否是空字符串
- s.toLowerCase()：将String中的所有字符转换为小写
- s.toUpperCase()：将String中的所有字符转换为大写
- s.trim()：返回字符串的副本，忽略前导空白和尾部空白
- s.equals()
- s.equalsIgnoreCase(String anotherString)：比较字符串，忽略大小写
- s.concat(String str)：等价于  "+"
- int compareTo(String anotherString)：比较两字符串大小
- String substring(int beginIndex)：
- String substring(int beginIndex,int endIndex)：返回一个新字符串，[begin,end)

![image-20210715205358227](https://cdn.jsdelivr.net/gh/moon-Light404/my-picGo/img/202111022104215.png)

---



![image-20210715205704518](https://cdn.jsdelivr.net/gh/moon-Light404/my-picGo/img/202111022104896.png)



---

### 1.4 String 与包装类的转换

```java
// 包装类
// String --> 基本数据类型、包装类
String str1 = "123";
int num = Integer.parseInt(str1);
Boolean.parseBoolean(str1).....
    
    
// 基本数据类型、包装类 --> String 类型
 String str3 = num + "";
String str2 = String.valueOf(num);
```



### 1.5 String与char[ ]的转换

- toCharArray( )： String 转化为char型数组

```java
char arr[] = {'h','e','l','l','o'};
String str1 = new String(arr); 
```



### 1.6 String 和字节的转换

```java
// 字节数组->String(构造方法)
	public String(byte[] value)
    public String(byte[] value,int offset,int count)

// String->字节数组
    public byte[] getBytes()
    public byte[] getBytes(String charsetName) -> 按照某种字符编码
    
```

一个中文字符UTF-8格式下占 3 个字节，gbk编码下占 2 个字节

## 2.StringBuffer、StringBuilder

### 2.1 特性和比较

> StringBuffer、StringBuilder类的对象能够被多次的修改，并且不产生新的对象
>
> 在使用 StringBuffer 类时，每次都会对 StringBuffer 对象本身进行操作，而不是生成新的对象，所以如果需要对字符串进行修改推荐使用 StringBuffer。

- StringBuilder速度更快，但是它不是线程安全的(不能同步访问)，StringBuffer是线程安全的

### 2.2StringBuffer常用方法

- public StringBuffer append(String s)  将字符串追加到字符序列
- public StringBuffer  reverse()  将此字符序列用其反转形式取代
- public delete(int start, int end)  移除此序列的子字符串中的字符
- public insert(int offset,String str)  插入字符串到序列中
- replace(int start, int end, String str)  替换字符





----



## 3.Scanner类

```java
// 构造方法
/* Scanner(InputStream is)
构造一个文本扫描器，它生成的值是从指定的值输入流扫描的
   System.in 是一个标准的输入流，属于InputStream*/
// 成员方法
/*
	boolean hasNext(): 是否有下一个数
	String next(): 获取下一个数
	String nextline(): 获取一行数据
	int nextInt(): 获取下一个int数据
*/

// 输入数据的方式
scan.hasNext(): 从输入流中读取一个字符串
while(scan.hasNext): 一直读取，输入几个读取几个
scan.hasNextline: 从输入流中读取一行(换行分隔)
    
```

scan.hasNext()会等待用户输入数据(输入完成之后回车)，但是最后只会读取一个字符串；而scan.hasNextline()读取一行



---

## 4.Number类和包装类

![image-20210720183615684](https://cdn.jsdelivr.net/gh/moon-Light404/my-picGo/img/202111022104979.png)

## 5.比较器接口 Comparable和Comparator

### 5.1Comparable接口(实现接口)



像String、包装类等实现了Comparable接口，重写compareTo(this)方法，给出了比较两个对象的方法

- 让需要比较的类实现`Comparable接口` <mark>implements Comparabe</mark>

- 实现<mark>CompareTo方法</mark>

compareTo函数实现升序排列

![image-20210724150417863](https://cdn.jsdelivr.net/gh/moon-Light404/my-picGo/img/202111022104486.png)



### 5.2 Comparator接口(临时实现)

当元素的类型没有实现java.lang.Comparable接口而又不方便修改代码，
或者实现了java.lang.Comparable接口的排序规则不适合当前的操作，
 那么可以考虑使用 Comparator 的对象来排序
   2.重写`compare(Object o1,Object o2)`方法，比较o1和o2的大小：
  如果方法返回正整数，则表示o1大于o2；
 如果返回0，表示相等；
 返回负整数，表示o1小于o2。

```java
public class ComparatorTest {
    @Test
    public void test() {
        String [] arr = {"AA","CC","KK","MM","GG","JJ","DD"};
        Arrays.sort(arr, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                if(o1 instanceof String && o2 instanceof String) {
                    String s1 = (String) o1;
                    String s2 = (String) o2;
                    return -s1.compareTo(s2); // 从大到小排序
                }
                throw new RuntimeException("输入类型不一致");
            }
        });
        System.out.println(Arrays.toString(arr));
    }
}
```



> 对比
>
> - Comparable接口的方式一旦一定，保证Comparable接口实现类的对象在任何位置都可以比较大小。
> - Comparator接口属于临时性的比较。

## 6. Arrays 工具类

Arrays是一个工具类，包含很多操作数组的方法，这个Arrays类里均为 static 修饰的方法(通过类名调用)，可以直接通过 Arrays.xxx 的形式调用

- `int binarySearch(type[] a, type key)`

使用二分法查询 key 在 a 数组中出现的索引， 如果不包含key元素值返回负数，要求数组升序排列



- `int binarySearch(type[] a,int fromIndex,int toIndex, type key)`

指定数组中 索引区间的元素，数组升序排列



- `type[] copyOf(type[] original, int length)`

把 orignal 数组复制成一个新数组，其中 length 是新数组的长度，返回一个数组

如果 length 小于 original 的长度，则新数组就是原数组的前面 length 个元素

如果 length 大于 original的长度，则新数组的前面是 original 的所有元素。



- `copyOfRange(type[] original, int from, int to)`

只复制 original 数组的form 索引到 to 索引的元素,返回<mark>一个数组</mark>



- `boolean equals(type[] a, type[] a2)`：判断两个数组是否相同
- `void fill(type[] a, type val)`：给数组所有元素赋值
- `void fill(type[] a, int fromIndex, int toIndex,,type val)`：给特定区间的元素赋值

- `void sort(type [] a)`：给数组排序
- `void sort(type[] a, int fromIndex, int toIndex)`
- `String toString(type [] a)`

该方法将一个数组装换成一个字符串，多个数组元素之间使用英文逗号

- `List<T> asList(T.... a)`  参数是T，是数组元素的class，不能使用原生数据类型的数组作为参数

```java
// alist的用法
int [] myArray = {1, 2, 3};
        List myList = Arrays.asList(myArray);
        System.out.println(myList);
// Output---->[[I@256216b3] hashcode的对象当传入一个原生数据类型数组时，asList 的真正得到的参数就不是数组中的元素，而是数组对象本身！此时List 的唯一元素就是这个数组。

Integer [] myArray = {1, 2, 3};
        List myList = Arrays.asList(myArray);
        System.out.println(myList);
// Output----> [1, 2, 3]
```







