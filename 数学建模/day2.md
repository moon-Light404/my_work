## 程式与函数

解释执行`<file>.m`文件

%表示注释



%%

......

%% 可以执行运行节section

<<<<<<< HEAD

=======
```matlab
function [输出变量名] = 函数名(输入变量名)
% 函数的文档

函数的代码
 % 从华氏温度到摄氏温度的转换
function F2C()
while 1
    F_degree = input('tempreature in Fahrenheit: ', 's');
    % 's'表示输入的对象以字符串来对待
    F_degree = str2num(F_degree);
    if isempty(F_degree)
        return
    end
    C_degree = (F_degree-32)*5/9;
    disp(['tempreature in Celsius: ' num2str(C_degree)])
end

```



### 函数句柄定义

```matlab
f = @x exp(-2*x);
x = 0:0.1:2;
plot(x,f(x));
```





### 常用函数

`str2num:`字符串转化为数字

`num2str:`数字转化为字符串
>>>>>>> 938d1b1 (提交文件)





