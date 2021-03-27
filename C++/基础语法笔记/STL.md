## 容器一些基本操作语法

### vector

#### 初始化操作

```c++
vector<int> a; //声明向量
vector<int> a(10);  //声明一个初始大小为10 的向量
vector<int> a(10,1);  //初始大小为10，且值都为 1的向量
vector<int> b(a);  //声明并用向量a 初始化 向量 b
vector<int> b(a.begin(),a.begin()+3); //将 a 向量中从第 0 个 到第二个作为向量 b 的初始值



vector<vector<int>> b(10,vector<int>(5));  //创建一个10*5的二维向量

```

#### 插入操作

```c++
a.insert(a.begin(),1000); //将1000插入到向量a的起始位置前
a.insert(a.begin(),3,1000);//将1000分别插入到向量元素的0-2处(共三个元素)

vector<int> a(5,1);
vector<int> b(10);
b.insert(b.begin(),a.begin(),a.end())//把a.begin和a.end()之间的全部元素插入到 b.begin()前
   
```

#### 删除

```c++
b.erase(b.begin());
b.erase(b.begin(),b.begin()+3); //删除之间的元素，不包括b.begin()+3
```

#### 交换

```c++
swap(a,b) //a向量与b向量进行交换
```

#### 数据存操作

```c++
push_back //在数组最后添加一个元素
pop_back //去掉数组最后一个元素
at //得到编号位置的数据
end //得到数组的最后一个单元+1的迭代器
front //得到数组头的引用
back //得到数组最后一个单元的引用
max_size //得到vector最大可以是多大
capacity //当前vector分配的大小(元素个数)
size //当前使用数据的大小
reserve //改变当前vector所分配空间的大小
clear //清空当前的vector
empty //判断vector是否为空
    
vector<double>values;
values.reserve(20);//给values开辟内存空间，使其可以多存入20个元素，但size仍然是0，只有capacity是20
vector<double>values(size,init_value)//创建一个大小为size，初值为init_value的double-vector

```

#### 反向迭代器

- rebegin():返回一个反向的首元素
- rend():将vector反转的结束指针返回(begin-1)；

注意：vector和string 都是顺序容器，在内存中分配了一块连续的存储空间，必须预先为其分配一段空间，这个空间就是capacity，而容器中元素的个数就是size(),在容器中，capacity总是大于等于size;

#### 注意

当出现 `size>capacity`时，如果没有空间继续容纳新的元素---要保持存储空间连续

因此容器必须分配新的内存空间，==将已有的元素和新的元素拷贝到新的空间，然后释放旧的存储空间==

### string

头文件`<string>`

```c++
string str;//生成空的字符串
string s(str); //生成一个和str内容相同的字符串
string s(str,idx);//生成一个str[idx]到str末尾内容的字符串
string s(st,idx,length);//生成一个从str[idx]到str[idx+ength]的字符串
string s(c_str);//生成一个接受C风格字符串的string的对象
```

#### 查询长度和元素

```c++
string str;
str.size();//返回str的长度
str.length(); //返回str的长度
str.at[idx]; //位于idx索引的字符，越界将会抛出异常
str[idx]; //越界不会抛出异常
```

#### 比较

```c++
string str1("123456");
string str;
str.assign(str1); //直接赋值
str.assign(str1,0,3) //把str1[0:3]赋值给str(0,1,2)
str.replace(str_pos,length,s);
str.replace(str_pos,length,s_idx);
```

#### 删除

```c++
string str1("123456");
str1.erase(str1.begin(),str1.begin()+1); // 使用迭代器删除从开始到开始偏移1个字节的子串
string str1("123");
string str2("321");
str1.swap(str2);// str1和str2交换
```

#### 增加

```c++
string A("ello");
string B("HA");
B.insert(1, A); // B变为"HelloA"，意思是从B的第一位开始插入A字符串
B.insert(1, "yanchy ", 3); // 表示从B的索引为1的地方开始插入"yanchy"的后3位
B.insert(1,A,2,2);//从B的第一位开始插入A的第二位开始的前2位
B.append("123"); //追加"123"到B的末尾
B.append("123",1);//追加"123"的前1位到B的末尾

```

#### 输入

```c++
ccstring s1,s2;
cin >> s1;// 使用istream的>>重载运算符读入s1
getline(cin,s1);//使用函数getline读入
getline(cin,s2,' ');//使用getline读入，并且以空格分界，空格及之后的东西全部会被忽略


```

#### 查找

```c++
string s1("123456");
s1.find('1',0);//从索引0开始寻找字符1
s1.find("12",0);//从索引0开始寻找目标串12
s1.find(s2,0);//从索引0寻找s2表示的字符串
```

其中`find_first_of()`寻找目标串第一次出现的位置；`find_last_of()`用于寻找最后一次出现的位置

#### 迭代器

```c++
string s("123");
string s2(s.begin(),s.end());//通过迭代器构造s2
transform(s.begin(),s.end(),toupper);//toupper是把小写字母变成大写字母
for (auto iter = s.begin();iter!=s.end();iter++)
    cout << *iter;// 通常遍历s的方法
```

### array

头文件`<array>`

类似C的数组，长度恒定，不需要自己管理内存，访问时不需要实现知道长度

std:array

```c++
array<double,100> data;// 长度为100的数组，值为定义的
array<double,100> data{}; //创建一个100，各个值均为0的数组
array<double,100> data{1.0,2.0,3.0,4.0}//前四个值被赋值
```

#### 访问

```c++
data[1]; // 用索引直接访问，会有越界风险
data.at(1); //避免了越界风险
std::get<idx>(array_obj); //使用模板函数get<n>()获取第n位的数据，这个n不可以是循环变量，必须是编译时可以确定的值
```

#### 比较赋值

```c++
std::array<double,4> these {1.0, 2.0, 3.0, 4.0};
std::array<double,4> those {1.0, 2.0, 3.0, 4.0};
std::array<double,4> them {1.0, 3.0, 3.0, 2.0};
these == those; // 判断所有元素是否都相等
them = those; //只要类型相同，长度相同，就可以直接赋值。
them[0] = 2.0; //可以直接通过索引修改值，也可以使用at成员函数修改，避免越界。

```

###  list

提供双向链表的构建方法，底层是一个带头节点的双向循环链表，任意位置插入和删除 时间复杂度 `O(1)`

`<list`

#### 创建

```c++
list<string> words;//创建一个空的双向链表
list<string> words(20);//创建一个有20个结点的双向链表
list<double> values(size,value);//创建一个有size个结点，每个结点的值为value的双向链表
list<double> save_value{values};//使用另一个list来初始化
list<int> a(first,last) //声明一个列表，元素初始值来源于区间指定的序列
```

####  插入，删除

```c++
names.push_front("Ian"); // 在表首插入一个字符串
names.push_back("Kitty"); // 在表尾插入一个字符串
names.emplace_front("Ian");// 更高效的插入
names.emplace_back("Kitty");// 更高效的插入
names.insert(++begin(data),"Me"); //在第一个位置插入字符串"Me"

std:list<int> numbers{2,5,2,3,6,7,8,2,9};
numbers.clear(); //清空整个双向链表
numbers.remove(value);//清除整个双向链表中所有值为value的节点
numbers.remove_if([] (int n){return n%2 == 0};)
    //一个一元断言，以一元断言的结果进行清除
numbers.unique(); //清除整个双向链表中重复的元素

front() //容器的头部元素
back()  //容器的最后一个元素
pop_front //删除头部第一个元素
pop_back //删除尾部第一个元素
 
a.assign(n,val); //将a中的所有元素替换成n 个val 元素
b.assign(a.begin(),a.end())//把a开始到结束的数据赋给 b 
```

==swap(a,b) 或者 a.swap(b)都可以实现 a 和 b 的交换==

==reverse()== 逆置

#### 排序和合并

```c++
list<string> names {"Jane","Jim","Jules","Janet"};
name.sort() //无参排序,升序排列(如果可能)

list<int> myvalues{2,4,6,8,14};
list<int> yourvalues{-2,1,7,10};
myvalues.merge(yourvalues); //合并两个链表，两个链表都必须是升序，合并后，yourvalues为空

list<string> mywords{"three","six","eight"};
list<string> yourwords{"seven","four","nine"};
mywords.splice(++begin(mywords),yourwords,++begin(yourwords));
//把yourwords的一部分粘贴到mywords的指定位置

//输出链表中的元素(迭代器)
mywords.splice(++std::begin(mywords),yourwords,++std::begin(yourwords));
auto it = mywords.begin();
cout<<*it<<" ";
++it;
while(it!=mywords.end())
{
    cout<<*it<<" ";
    ++it;
}


```

### stack

头文件`<stack>`  ==后进先出==

```c++
empty()  //堆栈为空返回真
pop()   //移除栈顶元素
push()  //在栈顶增加元素
size()  //返回栈中元素数目
top()  //返回栈顶元素 
```



### deque 双端队列

```c++
deque<int> a_deque; //size =0 的deque
deque<int> deques(10);//创建一个size = 10 
deque<std:string> words{"1","2","3"};//初始化
deque<int> deque_2 {deques};//使用另一个deque初始化
//deque没有 capacity 属性，deque的capacity总是和size相等
```

####  访问和修改

```c++
words.at(idx); //返回word伴随着越界检查
words[idx];
words.resize(size);
words.resize(size,init_value);  //其余和vector一样
```

#### 添加和删除

```c++
push_front //队头插入数据
push_back //队尾插入数据
pop_front //弹出队首数据，不返回队首数据
pop_back() // 弹出队尾数据，不返回队尾数据
    
```

### queue

只能访问queue<T> 容器适配器的第一个和最后一个元素，==只能在末尾添加元素，只能从头部移除元素== FIFO原则

```c++
std:queue<std::string> words;

std::queue<std::string> copy_words{words};//使用拷贝函数

```

#### 操作方法

```c++
front() //返回第一个元素引用，如果queue为空，返回值是未定义的
back()  //返回最后一个元素的引用
push(const T&obj)  //在queue尾部添加一个元素的副本，通过调用底层容器的成员函数push_back()完成的

pop()//删除弹出第一个元素   
size() //返回元素个数
empty()  //如果没有元素的话，返回true
emplace()  //在队尾调用构造函数生成对象
 queue<int,list<int>> q2;
```

###  deque和queue的区别

deque双端队列操作是可以在==队头队尾进行入队出队操作==

queue只能修改队头(删除头部元素)



### 双端队列

头指针 front      尾指针   rear

起始位 front == rear

但是当rear == front 时无法判断是队满还是队空。所以选择==牺牲一个空间==，每个尾元素后面就是rear指向的空间

则： `队满`: ==front = (rear + 1) % MAX_SIZE==

`队空`: ==front = rear==

```c++
include <iostream>
using namespace std;
const int MAX_QUEUE_SIZE = 50;
template<typename T>
class xqQueue{
    private:
        T* base;
        int front;
        int rear;
        int size;
    public:
    	xqQueue();
    	bool insert(T);
    	bool delete_(T*);
        bool isEmpty();
    	bool isfull();
    	void print();
   };
template<typename T>
xqQueue<T>::xqQueue()
{
    base = new T[MAX_QUEUE_SIZE];
    front = rear = 0;
    size = MAX_QUEUE_SIZE;
}
//判断队空
 template<typename T>
    bool xqQueue<T>::isEmpty() {
        if (rear == front)
            return true;
 
        return false;
    }
//判断对满
template<typename T>
bool xqQueue<T>::isfull(){
    if ((rear + 1) % size == front) {
            cout << "queue is full!" << endl;
            return false;
        }
    else
        return true
}


//插入元素
 template<typename T>
    bool xqQueue<T>::insert(T num) {
 		if (isfull())
        {
            return false;
        }
        base[rear % size] = num;
        rear = (rear + 1) % size;
    }



//打印队列元素
template<typename T>
    void xqQueue<T>::print() {
        if (isEmpty()) {
            cout << "queue is empty!" << endl;
            return;
        }
 
        int p = front;
        int q = rear;
        while (p % size != q) {
            cout << base[p] << ' ';
            p = (p+1)%size;
        }
        cout << endl;
    }

template<typename T>
	void 
```







