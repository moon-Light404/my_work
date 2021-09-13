## SwingWorker类

GUI时间处理和绘图代码在一个被称为<b>*事件分发线程*</b>的特殊线程中执行。如果一个事件需要很长的事件处理，线程就不能顾及到队列中的其他任务。为了解决这个问题，可以运行费时的任务来处理单独线程中的事件。SwingWorker是一个实现Runnable的抽象类，可以定义一个任务来扩展SwingWorker，使用任务产生的结果来运行费时的任务并更新GUI。



## swing程序一般有3个类型的线程

- 初始化线程：就是main函数，用来启动GUI
- 用户事件调度线程EDT：负责对GUI组件进行渲染和刷新，只有一个，处理的就是事件队列里面的事情，通过调用事件处理器来响应用户交互。所有事件处理都是在EDT上进行的
- 任务线程：对响应时的数据处理



> 注意事项

1、其他线程上访问UI组件和事件处理器都是不安全的，有可能造成界面的更新和绘制错误。

2、在EDT上执行耗时性任务会发生阻塞队列，会觉得界面很卡，所以，要尽可能的不要在EDT上编写耗时性的代码。

3、应当使用<mark>独立的任务线程</mark>来<mark>执行耗时性的任务</mark>。





> SwingWorker功能

解决大部分的线程不安全问题，通过它使任务线程和EDT各负其责，EDT实现绘制和刷新，任务线程实现与界面无关的耗时性的操作，将EDT线程仅用于GUI任务。



> 同步与异步

- 同步是程序在发起请求后开始处理事件并等待处理的结果或等待请求执行完毕，在此之前程序被block住直到请求完成。
- 异步是当前程序发起请求后立即返回，当前程序不会立即处理该事件并等待处理的结果，请求是在稍后的某一时间才被处理。

 串行与并行：

- 串行是指多个要处理请求顺序执行，处理完一个再处理下一个；容易阻塞。
- 并行可以理解为并发，是同时处理多个请求（实际上我们只能理解为是这样，特别是CPU数目少于线程数的机器而言，真正意义的并发是不存在的，各个线程只是断断续续地交替地执行）。





> SwingWorker类介绍	class SwingWorker<T,V>

参数类型

​		T    该 SwingWorker 中 doInBackground 和 get 方法返回的结果类型，就是最终结果的类型

​		V   用于执行中间结果的类型  SwingWorker  中的public 和 process 方法处理的数据类型，中间结果的类型



继承的接口

Runnable, Future<T>, RunnableFuture<T>



方法

`protected abstract T doInBackground()`

​	首先这个方法必须要重写，这里是处理一个swingworker实例的最后计算结果，当这个函数执行完后，说明这个线程的所有顺序执行的程序已经执行完了

`protected void done()`

​	doInBackground，在EDT中执行

`void execute()`

​	用来开启线程，swingworker实例对象调用，一旦执行这个方法，swingworker就进入了工作线程

`T get()`

​	等待doInBackground计算完成，返回doInBackground的返回值

`boolean isDone()`



`protected void process(List<V> chunks)`

​	在事件调度线程上异步接收来自publish方法的数据块，即中间结果，当任务线程执行时，它可以发布类型为V的中间结果，通过覆盖process方法来处理中间结果。任务对象的父类会在EDT线程上激活process方法，因此在process方法中程序可以安全的更新UI组件。这个方法线程安全的实现了DET与任务线程之间的交互。过程是这样的，当从任务线程调用publish方法时，在DET上自动执行process方法。

`**protected void publish(V chunks)**`

发送数据chunks到 process(java.util.List<V>)方法中的list列表中。这个方法是自动在DET上被调用的。是由任务对象的父类将其激活的。



> SwingWorker具体过程

一个SwingWorker的生命周期涉及三个状态、三个线程

- PENDING：初始状态，被创建时的状态。
- STARTED：调用 doInBackground后的状态。
- DONE：doInBackground方法完成后的状态。 
- 当前线程：在这个线程上调用了execute()方法。它在工作线程上执行SwingWorker，并立即返回，因为是异步的。
- 工作线程：在这个线程上调用了doInBackground()方法。 这是所有背景活动都应该发生的地方。
- 事件调度线程EDT：所有Swing相关活动发生在此线程上。
  

一般当前线程是EDT，当在当前线程中执行excute方法后，在工作线程上执行swingworker（注意为什么不是直接进入工作线程呢，是因为是并发执行的，具体什么时候看CPU)，即调用doInBackground方法，这时候，状态由PENDING进入STARTED。在此方法中，如果希望获得中间结果，可以用publish(V chunk)方法，chunk是中间结果，一旦publish，就会将chunk送入process(List<V> chunks)方法中的chunks列表中，并且这个process方法在EDT中自动执行，这个方法非常漂亮的实现了任务线程与EDT之间的交互。当doInBackground方法执行完后，会使状态值STARTED变为DONE状态，并且自动执行在EDT中自动执行done方法，注意done是在EDT中执行的，所以这里也实现了交互，在done方法里调用get方法获取doInBackground的返回值。到此，整个swingworker就被执行完了，而且它只能够执行一次。

https://www.cnblogs.com/monopole/p/7832840.html