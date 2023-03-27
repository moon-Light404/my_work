### java内部类详解

https://www.cnblogs.com/dolphin0520/p/3811445.html

内部类初识

在java中，可以将一个类定义在另一个类里面或一个方法里面，这样的类称为内部类，广泛意义上的内部类一般来说包括：成员内部类、局部内部类、匿名内部类和静态内部类。



1、成员内部类

最普通的内部类，定义在<mark>另一个类的内部</mark>，如下：

```java
class Circle {
    public Circle(double radius) {
        ...
    }
    
    class Draw { // 内部类
        public void draw() {
            ////
        }
    }
}
```

成员内部类可以<mark>访问外部类的所有成员属性和方法</mark>(包括private和静态成员)。



> 注意

当成员内部类拥有和外部类同名的成员变量和方法时，会发生<mark>隐藏现象</mark>,即默认访问内部类的成员，如果要访问外部类的同名成员

> 外部类.this.成员变量



> 外部类访问成员内部类的成员：创建一个成员内部类的对象，再通过指向这个对象的引用来访问。

```java
class Circle {
    public double radius = 0;
    public Circle(double radius) {
        ...
       getDrawInstance().draw(); // 通过实例来访问成员内部类的方法或属性
    }
    
   	private Draw getDrawInstance() {
        return new Draw();
    }
    class Draw { // 内部类
        public void draw() {
            ////
        }
    }
}
```



> 如果要创建成员内部类的对象，前提是必须存在一个外部类的对象

```java
public class Test {
    public static void main(String [] args) {
        // 第一张方法
        Outter outter = new Outter();
        Outter.Inner inner = outter.new Inner();
        //第二种方法
        Outter.Inner inner1 = outter.getInnerInstance();
    }
}
class Outter {
    private Inner inner = null;
    public Outter() {
        
    }
    public Inner getInnerInstance() {
        if(inner == null)	inner = new Inner();
        return Inner(;
    }
    
    
    class Inner {
        public Inner() {
            
        }
    }
}
```

