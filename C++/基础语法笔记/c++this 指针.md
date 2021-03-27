程序:

```
struct Car
{
int price;
};

void Setprice(struct Car* this,int p)
{
this->price=p;
}
int main()
{
struct Car car;
Setprice(&car,20000)
return 0;
}
```

c++版本:

```
calss Car
{
public:
 int m_price;
 void Setprice(int p)
 {
 m_price=p;
 }
};
int main()
{
Car car;
car.Setprice(20000);
return 0;
}
```

this 指针的作用其实就是指向成员函数所作用的对象，所以非静态成员函数可以直接试用 ==this 来代表指向该函数作用的对象的指针==。

例如：

``` 
void Setprice(int p)
{
this->m_price=p;
this->Printprice;
}
```

