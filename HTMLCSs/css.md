

## CSS 常见属性



#### 文字属性

- <font color="red">`font-style: 取值`</font>

作用：规定文字样式

`italic 斜体 normal 正常的`



- <font color="red">`font-weight: 取值`</font>

作用：规定文字粗细

`bold加粗 bolder更粗 lighter细线`



- <font color="red">`font-size`</font>

作用；规定文字大小



- <font color="red">`font-family:取值`</font>

作用：规定文字字体，如果取值是中文用引号括起来，字体必须是电脑里已经安装过的

- 文字属性的缩写

```html
font: style weight size family;
font:italic bold 10px "楷体";
```



#### 文体属性

- <font color="red">`text-decoration`</font>

`文本装饰`

`underline:下划线 lint-through:删除线 overline:上划线 none: 什么都没有，可以去掉超链接的下划线`



- <font color="red">`text-align`</font>

  `文本水平对齐方式`

`left right center`



- <font color="red">`text-indent`</font>

`文本缩进`

`取值 2em代表2个文字的宽度`



- <font color="red">`text-transform`</font>

取值:`capitalize | uppercase | lowercase | none`



- <font color="red">`text-shadow`</font>

取值:数值

- <font color="red">`line-height`</font>

  行高,行间距离

取值：`normal`  `数字`  `%` `inherit(继承父元素)`

















## CSS三种写法

<font color="green">行内样式</font>

写在对应标签的style属性里面

```html
<body>
    <div style = 'background-color:red'>
        123
    </div>
</body>
```

<font color="green">内页样式</font>

写在HTML页面里面的style标签里面

```html
<head>
   	<style>
        .calssname{
            .....
        }
    </style>
</head>
```

<font color="green">外部样式 <u>link</u></font>

```html
<head>
    <link rel = "stylesheet" href = "common1.css"/>
</head>

```

---



## css选择器

### 基本选择器

<u><font color = "blue">通用选择器</font></u>

- 选择所有元素

语法:    *



- 元素选择器

语法：   `elementname(元素名称)`



- 类选择器

匹配所有class属性为`classname`的元素

语法：  `.classname`





- ID选择器

按照`id`属性选择与之匹配的元素。一个文档中，每个ID属性都市唯一的。

语法:   `#idname`



- 属性选择器 <a href = "https://developer.mozilla.org/zh-CN/docs/Web/CSS/Attribute_selectors">链接</a>

按照给定的属性选择匹配的元素

语法:    `[attr] [attr=value] [attr~=value] [attr^=value]`

`[]中表示选择的属性`

例子:`[autoplay]选择所有具有 autoplay 属性的元素`

---



### 分组选择器

`,`将不同的选择器组合在一起，

`div, span`会陪陪所有`<span>`和`<div>`元素



---



### 组合器

<u><font color = "blue">后代组合器</font></u>

后代元素：被包含在祖先元素中的元素

<a href = "https://blog.csdn.net/qq2071114140/article/details/90274620">链接</a>



` `（空格） 组合器选择前一个元素的后代节点

语法    `A B`

例子 `div span`匹配直接嵌套在任意`<div>`元素之内的`<span>`元素



<font color="blue">直接子代选择器</font>

子元素：被父元素直接包含的元素

`>`  组合器选择前一个元素的==直接子代节点==

例子:`ul > li`匹配直接子代如果是嵌套在内层的不算



<font color="blue">`一般兄弟组合器`</font>

`~` 组合器选择兄弟元素(无嵌套，同层次元素)，后一个节点在前一个节点后面的任意位置

例子：`p ~ span`匹配`<p>`元素后的所有`<span>`元素



<font color="blue">紧邻兄弟组合器</font>

`+`组合器选择相邻元素，后一个元素紧跟在前一个之后

---





### 选择器优先级
`important > 行间内联 > ID > 类class > 标签 | 伪类 | 属性选择 > 伪对象 > 继承 > 通配符`

 

### 伪类

<a href = "https://www.w3school.com.cn/css/css_pseudo_classes.asp">教程链接</a>

- 伪类用于定义元素的特殊状态

==注意==:`a:hover`必须在CSS定义中的`a:link`和`a:visited`之后,`a:active`必须在`a:hover`之后

```html
// 未访问的链接
a:link{ 
	color: #FF0000;
}
// 已访问的链接
a:visited{
	color: #00FF00;
}
// 鼠标悬停
a:hover{
 	color: #0000FF;
}
// 已选择
a:active{
	color： #0000FF;
}
```



- <font color="blue">`first-child`伪类</font>

`:first-child`伪类与指定的元素匹配:该元素是另一个元素的第一个子元素

```html
// 匹配第一个p元素
p:first-child{
	color: blue;
}
// 匹配<p>元素中的首个<i>元素
p i:first-child{
	color: blue;
}

// 匹配所有首个<p>元素中的所有<i>元素
p:first-child i{
	color: blue;
}
```



- <font color="blue">其他伪类</font>



- <font color="blue">CSS - lang 伪类</font>

可以对不同的语言定义特殊的规则

`:lang`为属性为"lang = en"的<q>元素定义引号:

```html
<style>
    q:lang(en){
        quotes: "~" "~"; // 结束和开始
    }
</style>

<body>
    <p>
        some text <q lang = "en">文字段落</q>
    </p>
</body>
```





### 伪元素

语法  `::`

```
selector::pseudo-element{
	property: value;
}
```



- <font color = "blue">`::first-line`</font>

- 只用于块级元素

为文本的首行添加特殊样式



- <font color = "blue">`first-letter`</font>

向文本的首字母添加样式

只用与块级元素

- <font color = "blue">`::before`</font>

在元素内容之前插入一些内容

```html
h1::before{
	content: url(smiler.gif)
}
// content配合 ::before和::after插入内容
```



- <font color = "blue">`::after`</font>

在元素之后插入



- <font color = "blue">`::selection`</font>

使鼠标所选文本显示特定样式

## CSS背景

- <font color = "blue">`background-color`</font>
- <font color = "blue">`background-image`</font>

背景图片

```html
body{
	background-image: url("图片路径");
}
```



- <font color = "blue">`background-repeat`</font>

默认情况下，`background-image` 属性在水平和垂直方向上都重复图像。某些图像应只适合水平或垂直方向上重复，否则它们看起来会很奇怪

`background-repeat: repeat-x`只在水平重复

`no-repeat` 只显示一次

- <font color = "blue">`background-attachment`</font>

属性指定背景图像是应该滚动还是固定的（不会随页面的其余部分一起滚动）`scroll` `fixed`

- <font color = "blue">`background-position`</font>

指定图片的位置

- <font color = "blue">`opacity`</font>  不透明度

- 简写

```html
body {
  background: #ffffff url("tree.png") no-repeat 	right top;
}
// 分别是color image repeat attachment position
```



## `margin`

`*margin*` 属性为给定元素设置所有四个（上下左右）方向的外边距属性。也就是 [`margin-top`](https://developer.mozilla.org/zh-CN/docs/Web/CSS/margin-top)，[`margin-right`](https://developer.mozilla.org/zh-CN/docs/Web/CSS/margin-right)，[`margin-bottom`](https://developer.mozilla.org/zh-CN/docs/Web/CSS/margin-bottom)，和 [`margin-left`](https://developer.mozilla.org/zh-CN/docs/Web/CSS/margin-left) 四个外边距属性设置的[简写](https://developer.mozilla.org/zh-CN/docs/Web/CSS/Shorthand_properties)。

