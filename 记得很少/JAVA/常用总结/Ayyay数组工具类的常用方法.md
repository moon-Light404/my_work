Array -- 操作数组的工具类  java.util包中

### 1.boolean equals(array1,array2):比较两==数组==是否相等

`返回true 或 false`



### 2.void sort(array)对数组中的元素进行升序排列

java中toString ()方法用于返回一个字符串表示的 Number 对象值

```java
public static void main(String[] args) {
		// TODO Auto-generated method stub
		int []score= {79,65,93,64,88};
		Arrays.sort(score);
		for(int i=0;i<5;i++) {
		System.out.println(score[i]);
		}
		
		String str = Arrays.toString(score);//把数组变为字符串
		System.out.println(str);//以数组形式输出
		
	}
//运行结果：
64
65
79
88
93
[64, 65, 79, 88, 93]
```

### 3. toString(array):把数组array转换成一个字符串

```java
public static void main(String[] args) {
		// TODO Auto-generated method stub
               //toString:把一个数组转换成一个字符串
	       //定义 一个数组
		int[] a={1,2,3};
		System.out.println(a);//打印出的是hashcode码
		System.out.println(Arrays.toString(a));//打印出的是数组
        }

```

### 4.void fill(array,val):把数组array所有元素都赋值为val

```java
int []num = {1,2,3};
Arrays.fill(num,6);
System.out.println(Arrays.toString(num));//打印结果[6,6,6]
```

### 5.int binarySearch(array,val):查询元素val在数组array中的下标



### 6.copy(array,length):把数组array复制成一个长度为length 的新数组

```java
int []a={1,2,3};
int []b = Arrays.copyOf(a,a.length);//原数组  原数组长度
System.out.println(Arrays.toString(b));


```



