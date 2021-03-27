## 格式

`class 子类 extends 父类`

<a href="https://imgchr.com/i/B9EVk4"><img src="https://s1.ax1x.com/2020/10/20/B9EVk4.md.png" alt="B9EVk4.md.png" border="0"></a>

==需要注意的是 Java 不支持多继承，但支持多重继承==

## 继承关键字

### extends

### implements

使用implements关键字可以相当于使java具有多继承的特性，可以同时继承多个接口

```java
public interface A{
    public void eat();
    public void sleep();
}
public interface B{
    public void show();
}
public class C implements A,B{//继承两个接口
    
}
```

### super和this

super:对父类成员的访问

this:..............

### 构造器

子类是不继承父类的构造器（构造方法或者构造函数）的，它只是调用（隐式或显式）

- 父类构造器有参，子类中显示通过`super`调用父类构造器
- 父类构造器无参，子类构造器不需要使用`super`，自动调用父类的无参构造器





































