### 1.`PreparedStatement`的说明



1`PreparedStatement` 实例包含已编译的 `SQL` 语句。这就是使语句“准备好”。包含于 `PreparedStatement `对象中的 `SQL` 语句可具有一个或多个 IN 参数。IN参数的值在 SQL 语句创建时未被指定。相反的，该语句为每个 IN 参数保留一个问号（“？”）作为占位符。每个问号的值必须在该语句执行之前，通过适当的`setXXX` 方法来提供。

2 由于 `PreparedStatement` 对象已预编译过，所以其执行速度要快于 `Statement` 对象。因此，多次执行的 `SQL` 语句经常创建为 `PreparedStatement `对象，以提高效率。

一般用法：

```java
// 实例化一个PreparedStatement和结果集
PreparedStatement premt = null;
ResultSet rs = null;

// 得到sql语句
conn 为Connection类型
premt = conn.preparedStatement("sql语句"); // String sql = "...."

// 执行SQL，获得结果集
rs = premt.executeQuery(); // 查询结果

// 结果输出
while(rs.next()) // 遍历每一条记录
{
    Sysout(rs.getString(1)+rs.getString(2)+...);
}
```

---

`Class.forName()说明`

我们知道`Class.forName( )`静态方法的目的是为了动态加载类，但是一般来说，一个类`forName`只是要求`JVM`查找并加载指定的类，最终的目的是要`newInstance（）`去把它实例化对象的，但是这里并没有，那它的作用是什么？

其实在`JVM`加载指定类的过程中，如果类中有静态初始化内容的话，`JVM`就会执行该部分代码，于此同时`JDBC`规范要求任何一个`driver`类必须向`DriverManger`类去注册自己，也就是说此例中加载的`com.mysql.jdbcDriver`中一定是有一段代码类似。

---

### `setString方法`

```java
String sql = "select name from user where user id=?And password=?" 
pstmt = con.prepareStatement(sql);
pstmt.setString(1,request.getParameter("id"));
pstmt.setString(2,request,getParameter("password"));
rs = pstmt.executeQuery();
```

