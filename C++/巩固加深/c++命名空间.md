## C++命名空间概括

注：一个大型软件往往由多名程序员共同开发，会使用大量的变量和函数，不可避免地会出现变量或函数码的冲突。

为了解决这种问题，C++引入了命名空间的概念

```c++
namespace Li{ //命名空间的名字
FILE fp = NULL;
}
namespace Han{
FILE fp = NULL
}
```

namespace 用来定义一个命名空间.

有一点是使用变量、函数时要指明它们所在的命名空间，以以上为例，可以这样

```c++
Li::fp = fopen("","r") ;
    //using Li::fp;
    //fp = fopen("","r");  上述的另一种写法
Han::fp = fopen("","rb+");
```

`::`叫做域解析操作符，在C++中用来指明要使用的命名空间，==而`using`声明==以后出现了未指定命名空间的变量，就使用 `Li::fp` ；同时也可选择使用其他命名空间的变量

在`using`声明后，如果有未具体指定命名空间的变量产生了冲突，还是==默认使用命名空间中Li的变量==

````c++
#include <stdio.h>
//将类定义在命名空间中
namespace Diy{
    class Student{
    public:
        char *name;
        int age;
        float score;
  
    public:
        void say(){
            printf("%s的年龄是 %d，成绩是 %f\n", name, age, score);
        }
    };
}
int main(){
    Diy::Student stu1;
    stu1.name = "小明";
    stu1.age = 15;
    stu1.score = 92.5f;
    stu1.say();
    return 0;
}
````

---



### 命名空间的特点和用法

#### 1、只能全局范围内定义

以下是错误的：

```c++
void test()
{
namespace A{
 	int a = 100;
}
namespace B{
	int a = 200;
}
	cout<< "A::a:"<<A::a<<endl;
	cout<<"B::a"<<B::a<<endl;
}
```





#### 2、命名空间嵌套     ==A::B::a==

```c++
namespace A{
	int a = 100;
	namespace B{
		int a= 2000;
	}
}
void test()
{
	cout<<A::a<<endl;
	cout<<A::B::a<<endl;
}
```



#### 3、命名空间是开放的，可以随时加入新成员

```c++
namespace A
{
  int a ;
  int b;
}
namespace A
{
int c; //加入新变量成员
}
```

#### 4、命名空间中的函数可以在 空间外定义实现

类似类 class一样， 

#### 5、无名命名空间

定义无名命名空间后，外部不能得知无名空间的成员名字，不让外部知道我的成员名字及其调用

在其他文件无法引用，只能在本文件的作用域内有效，不用加限定符限定。