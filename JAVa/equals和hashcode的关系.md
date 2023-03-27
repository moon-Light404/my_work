## 理解Java中equals()和hashcode()的关系

### equals()

定义在Object类中，意味着所有的java类实现了这个方法：

```java
public boolean equals(Object obj)
{
    return (this == obj);
}
```



在String类中重写了**equals**方法:

```java
public boolean equals(Object obj)
{
    if(this == obj)	return true;
    if(obj instanceof String) {
        String var = (String)obj;
        int thisvar = this.value.length;
        if(thisvar == var.value.length) {
            char[] var4 = this.value;
            char[] var5 = var.value;
            
            for(int i = 0; thisvar-- != 0; ++i) {
                if(var4[i] != var5[i])	return false;
            }
            return true;
        }
        return false;
    }
}
```

注意： == 是判断两个对象地址相等，即是否是同一个对象；具体比较比较需要看重写的 <u>equals</u>方法。



### hashCode()

首先 hash就是散列，把任意长度的输入变换成固定长度的输出，该输出就是散列值。

- hashCode主要是用于查找的快捷性，如Hashtable，HashMap等，hashCode是用来在散列存储结构中确定对象的存储地址的；
- 如果两个对象相同，那么hashCode也一定相同；反过来就不一定成立；
- 如果对象的hashCode方法被重写，对象的hashCode方法也尽量重写；



hashCode用于查找，比如哈希中的链表法，查找在哈希后在链表中的位置；然后才是用**equals**比较两个对象是否相等；

**顺序：** 如果有散列表的配合，当需要把某个对象存入到底层为散列表结构的集合中时，是先判断hashCode值，碰到相同值时再通过equals进一步判断。所以两个方法都需要重写，保证如果两个对象是相等的，它们的equals()方法应该要返回true，它们的hashCode()需要返回相同的结果。但这其实是针对当该类会在HashSet，Hashtable，HashMap等等这些本质是散列表的数据结构中用到的时候这种情况。

