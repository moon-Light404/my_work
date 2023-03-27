## HashSet

<u>**源码解析**</u>

```java
public HashSet() {
        map = new HashMap<>();
    }

private static final Object PRESENT = new Object(); // 这是一个空对象，在HashSet中用来占位，但本质上仍然是HashMap
public boolean add(E e) {
        return map.put(e, PRESENT)==null;
    }

public V put(K key, V value) {
        return putVal(hash(key), key, value, false, true);
    }

// Node节点
static class Node<K,V> implements Map.Entry<K,V> {
        final int hash;
        final K key;
        V value;
        Node<K,V> next;

        Node(int hash, K key, V value, Node<K,V> next) {
            this.hash = hash;
            this.key = key;
            this.value = value;
            this.next = next;
        }
}


final V putVal(int hash, K key, V value, boolean onlyIfAbsent,
                   boolean evict) {
        Node<K,V>[] tab; Node<K,V> p; int n, i;
    // 开始时tab初始化大小
        if ((tab = table) == null || (n = tab.length) == 0)
            n = (tab = resize()).length;
    // p表示该数据在table中要存放的位置上的节点,如果为空，直接将元素放在那里
        if ((p = tab[i = (n - 1) & hash]) == null)
            tab[i] = newNode(hash, key, value, null);
    // p不为空，说明已经有元素在这了，做进一步比较
        else {
            Node<K,V> e; K k;
            //(1)准备加入的key和p指向的Node结点的key 是同一对象
            //(2)p指向的Node结点的key 和准备加入的key equals()比较后相同
            if (p.hash == hash &&
                ((k = p.key) == key || (key != null && key.equals(k))))
                e = p;
            // 判断 p 是不是红黑树，如果是就调用 putTreeVal方法
            else if (p instanceof TreeNode)
                e = ((TreeNode<K,V>)p).putTreeVal(this, tab, hash, key, value);
            else {
                // 依次和该链表中的元素比较
                for (int binCount = 0; ; ++binCount) {
                    // 链表中最后一个元素，比较完了都没有一样的，直接挂在链表的后面
                    if ((e = p.next) == null) {
                        p.next = newNode(hash, key, value, null);
                        // 判断该链表是否达到8个结点，调用treeifyBin()对这个链表进行树化，
                        // 注意，转成红黑树时，要进行判断，条件
                        // if (tab == null || (n = tab.length) < MIN_TREEIFY_CAPACITY)
           // resize(); 如果条件成立，先扩容table
                        if (binCount >= TREEIFY_THRESHOLD - 1) // -1 for 1st
                            treeifyBin(tab, hash);
                        break;
                    }
                    if (e.hash == hash &&
                        ((k = e.key) == key || (key != null && key.equals(k))))
                        break; // 发现 key 相同直接退出
                    p = e;
                }
            }
            // 存在相同的key
            if (e != null) { // existing mapping for key
                V oldValue = e.value;
                if (!onlyIfAbsent || oldValue == null)
                    e.value = value;
                afterNodeAccess(e);
                return oldValue;
            }
        }
        ++modCount;
    	// 当增加一个元素(不管是不是在一个链表上)，都算增加一个，此时超过阈值也会引起扩容
        if (++size > threshold)
            resize();
        afterNodeInsertion(evict);
        return null; // 返回null
    }
```



HashSet的存储过程：

向HashSet中添加元素 a，首先调用元素 a所在类的hashCode方法，计算 a 的哈希值，此哈希值通过某种算法算出 a 在 table Node数组中存放位置(索引)， 判断此位置上是否已有元素，若此位置为空，直接添加即可； 位置不为空，为链表或单元素，则比较 hash值，不一致则添加，一致则调用 equals 方法比较，结果为false才添加。



1、HashSet底层是HashMap，第一次添加时，table数组扩容到16，临界值(threshold)是 16*加载因子(loadFactor 0.75) = 12

2、如果 table 数组使用到了临界值 12， 就会扩容到 16 * 2 = 32， 新的临界值就是 32 * 0.75 = 24..

3、在java8中，如果一条链表的元素个数到达 TREEIFY_THRESHOLD(默认是 8 )，并且 table 的大小 >= MIN_TREEIFY_CAPACITY(默认64)， 就会进行树化，否则仍然采用数组扩容机制。





**测试**

定义一个Employee类，该类包含：private成员属性name，age要求：

认为name和age相同时是相同员工，不能添加到HashSet集合中

```java
public class HashSetTest {
    public static void main(String[] args)
    {
        HashSet hashSet = new HashSet();
        
    }
}

class Employee {
    private String name;
    private int age;
    
    public Employee(String name, int age)
    {
        this.name = name;
        this.age = age;
    }
    
    public String getName()
    {
        return name;
    }
    
    public int getAge()
    {
        return age;
    }
    
    public void setName(String name)
    {
        this.name = name;
    }
    
    public void setAge(int age)
    {
        this.age = age;
    }
    
    public void ToString()
    {
        .....
    }
    
    // 如果name和age相同，返回相同的hash值;
    // 注意：但是name和age不相同也有可能返回相同的hash
	@Override
    public int hashCode() {
        return Objects.hash(name, age);
    }
    
    @Override
    public boolean equals(Object o) {
        if (this == o)	return true;
        if (o == null || getClass() != o.getClass())	return false;
        Employee employee = (Employee) o;
        return age == employee.age && Objects.equals(name, employee.name);
    }
}
```



