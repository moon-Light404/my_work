`urlopen()`方法实现最基本的请求的发起，可以加入Headers等信息，就可以利用==Request类来构造请求==

`urllib.request.Request(url,data=None,headers={},origin_req_host=None,unverifiable=False, method=None)`

基本用法

```python
request = urllib.request.Request(url)
reponse = urllib.request.urlopen(request)
## 打印的是网页源码
print(reponse.read().decode('utf-8'))

```

## 参数解析

| url             | 要请求的url                                                  |
| --------------- | ------------------------------------------------------------ |
| data            | data必须是bytes(字节流）类型，如果是字典，可以用urllib.parse模块里的urlencode()编码 |
| headers         | headers是一个字典类型，是请求头。可以在构造请求时通过headers参数直接构造，也可以通过调用请求实例的add_header()方法添加。可以通过请求头伪装浏览器，默认User-Agent是Python-urllib。要伪装火狐浏览器，可以设置User-Agent为Mozilla/5.0 (x11; U; Linux i686) Gecko/20071127 Firefox/2.0.0.11 |
| origin_req_host | 指定请求方的host名称或者ip地址                               |
| unverifiable    | 设置网页是否需要验证，默认是False，这个参数一般也不用设置。  |
| method          | method是一个字符串，用来指定请求使用的方法，比如GET，POST和PUT等。 |



