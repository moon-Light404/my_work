# python爬虫分析

python是解释执行

```python
if __name__ == '__main__':	# 当程序执行时
    main()
```

 

```python

import  urllib.request

#
response = urllib.request.urlopen("http://www.baidu.com")
print(response.read().decode('utf-8'))

# 获取post请求
import urllib.parse
data = bytes(urllib.parse.urlencode({"hello":"world"}),encoding="utf-8")
response = urllib.request.urlopen("https://httpbin.org/post",data = data)
print(response.read().decode('utf-8'))

# 超时处理
try:
    response = urllib.request.urlopen("http://httpbin.org/get",timeout=0.01)
    print(response.read().decode('utf-8'))
except urllib.error.URLError as e:
    print("time out!")
# response.getreader(“Server”)
# response.getheaders
```



```python
# 伪造和模拟headers,不让服务器识破,告诉服务器我们是是什么样的浏览器，可以接收什么水平的数据和内容
url = "...."
headers = {
	"User-Agent": " ": " "	
} 
data = bytes(urllib.parse.urlencode({'name':'eric'}),encoding='utf-8')
# 封装一个对象Request
req = urllib.request.Request(url=url,data=data,headers=headers,method='POST')
response = urllib.request.urlopen(req)
print(response.read().decode('utf-8'))
```

## 提取网页的html代码

<a href = "https://blog.csdn.net/qq_37616069/article/details/80376776">最简单的方式request模块</a>

```python
# 自己生成request请求
def main():
    url = "https://www.douban.com/"
    print(askURl(url))

def askURl(url):
    head = {"User-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.90 Safari/537.36"}
    request = urllib.request.Request(url,headers=head)
    try:
        response = urllib.request.urlopen(request)
        html = response.read().decode('utf-8')
    except urllib.error.URLError as e:
        if hasattr(e,"code"):
            print(e.code)
        if hasattr(e,"reason"):
            print(e.reason)
    return html

if __name__ == '__main__':
    main()
    
    
# 使用自带的request包模块
import requests
import re

url = "http://www.douban.com/"#需要爬取图片的网页地址
page = requests.get(url).text#得到网页源码
print(page)
res = re.compile(r'src="(http.+?.jpg)"')#运用正则表达式过滤出图片路径地址
reg = re.findall(res, page)#匹配网页进行搜索出图片地址数组
#print(reg)

#循环遍历下载图片
num = 0
for i in reg:
    a = requests.get(i)
    f = open("img/%s.jpg"%num, 'wb')#以二进制格式写入img文件夹中
    f.write(a.content)
    f.close()
    print("第%s张图片下载完毕"%num)
    num = num+1

```

## BeautifulSoup4

<a href="https://cloud.tencent.com/developer/article/1445225">学习链接</a>

**对象的种类**

使用BeautifulSoup<mark>解析这段代码</mark>,能够得到一个 BeautifulSoup 的对象,并能按照标准的缩进格式的结构输出.

Beautiful Soup将复杂HTML文档转换成一个复杂的树形结构,每个节点都是Python对象,所有对象可以归纳为4种: Tag , NavigableString , BeautifulSoup , Comment .

**`Tag` **: 标签及其内容: 拿到它所找到的第一个内容

属性访问方法：`tag.name`、  `tag.attrs`、`tag['class']、tag['id']、tag.get('class')`

<mark>tag的属性操作方法与字典一样</mark>

**`NavigableString`**: 标签里的内容(字符串)    字符串常被包含在tag内.Beautiful Soup用 NavigableString 类来包装tag中的字符串:



**`BeattifulSoup`**:   整个文档

**`comment`**:  







**解析**

```python
from bs4 import BeautifulSoup
# 读取文件内容
file = open("./baidu.html","rb")
html = file.read().decode('utf-8')

# 解析文件
soup = BeautifulSoup(html) 
```

**浏览数据的方法**

- 基于bs4库HTML的格式输出 如何让<html>页面更友好的显示

<font color = "blue">`标签.prettify()`</font>

  

- 判断对象是否包含某个属性

<font color = "blue">`tag.has_attr("name")`</font>



- 包含class属性

<font color = "blue">`class_=True`</font>



- 应用正则表达式来查找包含特定文本的内容(标签里的字符串)

`find_all(text = re.compile("\d"))` #包含数字的字符串



- `limit`参数表示获取多少个

`find_all("a",limit = 3)`



- css选择器

 标签  `soup.select('title')`

类名  `soup.select(".manv")`

id  `soup.select("#u1")`

属性 `soup.select("a[class = 'bri']")`

`兄弟节点查找 bs.select(".manv ~ .bri")`

```python
soup.title

soup.title.name

soup.title.string

soup.title.parent.name
# u'head'

soup.p # 查找的第一个p标签

soup.p['class'] # 第一个p标签的class元素内容

# 字符串过滤：查找与字符串完全匹配的内容
soup.find_all('a')

# 可以传参数  查找第一个特定标签,所有用 find_all
soup.find(id == "link3")


# 从文档中找到所有<a>标签链接
for link in soup.find_all('a'):
    print(link.get('href'))
    
# 获取文字内容
soup.get_text()

```





## 正则表达式

![image-20210320211445451](https://cdn.jsdelivr.net/gh/moon-Light404/my_picgo/img/20210320211452.png)


![image-20210320211803359](https://cdn.jsdelivr.net/gh/moon-Light404/my_picgo/img/20210320211803.png)

<font color = "blue">`\D`非数字</font>


![image-20210320212428150](https://cdn.jsdelivr.net/gh/moon-Light404/my_picgo/img/20210320212428.png)



![image-20210320212638419](https://cdn.jsdelivr.net/gh/moon-Light404/my_picgo/img/20210320212638.png)

```python
# 创建模式对象
pat = re.compile("AA") # 正则表达式，用来验证其他的字符串
m = pat.search("ABCAA")# search字符串被校验的内容
# <re.Match object; span = (3,5), match ='AA'>

# 无模式对象
m = re.search("asd","Aasd") # 前面的字符串是规则，后面的字符串是被校验的对象

print(re.findall("a","ASDaDFGAa")) # 前面是规则(正则表达式)，后面是被校验的字符串
print(re.findall("[A-Z]","ASDaDFGAa"))
#['A','S','D','D','F','G','A']

print(re.sub("a","A","abcdcasd"))# 找到a用A替换
# AbcdcAsd


```

在正则表达式中，被比较的字符串前面加上 r ，不用担心转义字符的问题

```python
a = r"\aabd=\'"
print(a)
# \aabd-\'
# 如果没有加, \' 就是 '
```

### 正则表达式注意点

`.*` 与 `.?`的区别

比如说匹配输入串A: 101000000000100

- 使用 1.*1 将会匹配到1010000000001, 匹配方法: 先**匹配至输入串A的最后, 然后向前匹配**, 直到可以匹配到1, 称之为<mark>贪婪匹配</mark>(匹配的是最后一个1)

- 使用 1.*?1 将会匹配到101, 匹配方法:* 匹配下一个1之前的所有字符, 称之为<mark>非贪婪匹配</mark>。

`?` -> <mark>贪婪匹配</mark>

1. `.*`
. 表示 匹配除换行符 \n 之外的任何单字符，*表示零次或多次。所以.*在一起就表示任意字符出现零次或多次。没有?表示贪婪模式。比如a.*b，它将会匹配<mark>最长的以a开始，以b结束的字符串</mark>。如果用它来搜索aabab的话，它会匹配整个字符串aabab。这被称为贪婪匹配。
又比如模式src=`.*`， 它将会匹配最长的以 src=` 开始，以`结束的最长的字符串。用它来搜索$ <img src=``test.jpg` width=`60px` height=`80px`/> 时，将会返回 src=``test.jpg` width=`60px` height=`80px`$

2. `.*?`
?跟在*或者+后边用时，表示懒惰模式。也称<mark>非贪婪模式</mark>。就是匹配尽可能少的字符。就意味着匹配任意数量的重复，但是在能使整个匹配成功的前提下使用最少的重复。
a.*?b匹配最短的，以a开始，以b结束的字符串。如果把它应用于aabab的话，它会匹配aab（第一到第三个字符）和ab（第四到第五个字符）。
又比如模式 src=`.*?`，它将会匹配 src=` 开始，以 ` 结束的尽可能短的字符串。且开始和结束中间可以没有字符，因为*表示零到多个。用它来搜索 $<img src=``test.jpg` width=`60px` height=`80px`/> 时，将会返回 src=``$。

3. `.+?`
同上，?跟在*或者+后边用时，表示懒惰模式。也称非贪婪模式。就意味着匹配任意数量的重复，但是在能使整个匹配成功的前提下使用最少的重复。
a.+?b匹配最短的，以a开始，以b结束的字符串，但<mark>a和b中间至少要有一个字符</mark>。如果把它应用于ababccaab的话，它会匹配abab（第一到第四个字符）和aab（第七到第九个字符）。注意此时匹配结果不是ab,ab和aab。因为a和b中间至少要有一个字符。
又比如模式 src=`.+?`，它将会匹配 src=` 开始，以 ` 结束的尽可能短的字符串。且开始和结束中间必须有字符，因为+表示1到多个。用它来搜索 <img $src=``test.jpg` width=`60px` height=`80px`/> 时，将会返回 src=``test.jpg$`。注意与.*?时的区别，此时不会匹配src=``，因为src=` 和 ` 之间至少有一个字符。
————————————————

原文链接：https://blog.csdn.net/sinat_32336967/article/details/94761771



```python
findlink = re.compile(r'<a href="(.*?)">') 
# 里面的()表示的是要查询的一个组，link中的数据只是一个http://....网址
link = re.findall(findlink,string)
```





### findall总结

- `re.compile`用于编译正则表达式，生成正则表达式(Pattern)对象

`re.compile(pattern,匹配模式)`



- `findall`在字符串中找到<mark>正则表达式所匹配的所有子串</mark>，返回一个列表，否则为空列表

```python
1、`findall(规则表达式字符串， 被查找的字符串)`
2、 pattern = re.compile(r'\d+')
res1 = pattern.findall(被查找的字符串,start,end) #左闭右开

```



- `bs4中的find_all`

```python
1、soup = BeautifulSoup(htm,'html.parser')

2、pid = soup.find_all('a',{'class':'sister'})
	for i in pid:
        print i.get('href')
        
3、pid = soup.find_all('p',id = 'hehe')


4、利用正则搜索标签
soup.find_all(id=re.compile("he$"))
多属性
soup.find_all('a',attrs={'href':re.compile('^http'),'id':'link1'})

检索个数限制
soup.find_all('a',limit=2)
```



- `soup`可以通过`soup+标签名称`获取html中第一个匹配的标签内容

  





