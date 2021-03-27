### 枚举

java中枚举是一个特殊的类，一般表示一组常量

例子；

```java
enum Color{
    RED,GREEN,BLUE;
}
public class Test
{
    public static void main(String []args)
    {
        Color c1 = Color.RED;
        Sout(c1);
}
}
//RED
```

当然上面的`enum Color`也可以放在 Test 类中

每个枚举值都是`public static final`的

### 迭代枚举元素

==`for(Color Var : Color.values())`==

`Color.values`可以赋给一个 `Color`类型的数组

### values(),ordinal(),valueOf()方法

- values()返回枚举类中所有的值
- ordinal()方法可以找到每个枚举常量的索引
- valueOf()返回指定字符串值的枚举常量

### 枚举类中的成员函数和方法

- 构造函数只能使用 `private`修饰符
- 可以包括具体方法也可抽象方法









