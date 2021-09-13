获取本地ip

```java
 initComponents();//在此处后面添加：

  try {

​      InetAddress addr = InetAddress.getLocalHost();

​      txtHostName.setText( addr.getHostAddress());
​    } catch (UnknownHostException e) {

​      e.printStackTrace();

​    }
```



## TCP 中常用的类和方法

### Socket类

`Socket(InetAddress address,int port)`

创建一个流套接字并

 

`Socket(String host,int port)`

创建一个流套接字并将其连接到指定主机上的指定端口号。

 

`Socket(InetAddress address,int port,InetAddress localAddr,int localPort)`

创建一个套接字并将其连接到指定远程地址上的指定远程端口

 

`Socket(String host,int port,InetAddress localAddr,int localPort)`

创建一个套接字并将其连接到指定远程主机上的指定远程端口。

 

`Close()`

关闭套接字

 

`Connect(SocketAddress endpoint)`

将此套接字连接到服务器。

```java
SocketAddress server = new InetSocketAddress(“localhost”,5000);

Socket clientSocket = new Socket();

clientSocket.connect(server);
```





 

Connect(SocketAddress endpoint,int timeout) 设置一个超时值

 

`getInetAddress()` 返回套接字的地址

 

 

`getInputStream()` 返回套接字的输入流

 

 

`getLocalPort()` 返回此套接字绑定的本地端口

 

`getOutputStream()` 返回套接字的输出流

 

`getPort()`   套接字连接的远程端口



### ServerSocket类

`ServerSocket(int port)`

创建绑定到特定端口的服务器套接字

 

`accept()`

侦听并接受到此套接字的连接

 

`getInetAddress()`

返回此服务器套接字的本地地址

 

![image-20210913203452860](TCP通信总结/image-20210913203452860.png)

