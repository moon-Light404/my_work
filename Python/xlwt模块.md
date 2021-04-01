# 简介

python操作Excel表格的模块有很多：

1、xlrd： 读取 xls 格式Excel文件数据；
2、xlwt： 将数据写入 xls 格式Excel文件；
3、openpyxl： 读取、写入 xlsx 格式Excel文件；
4、pandas： 通过 xlrd 与 xlwt 模块实现xls 格式Excel文件的读写操作；
5、win32com： 获取 Excel 应用接口，实现Excel 文件的读写。

这里介绍 xlwt 模块将数据写入Excel的基本操作

- 建立工作簿，增加sheet表

建立工作簿对象------新建sheet表------将数据写入------保存文件

```python
import xlwt

# 新建工作簿
work_book = xlwt.Workbook(encoding = 'utf-8',style_compression=0)
#增加sheet表
work_sheet = work_book.add_sheet('Test')
# add_sheet(self,sheetname,cell_overwrite_ok=False)

#写入数据
work_sheet.write(x,y,信息) # x,y坐标(从0开始)
# 保存文件
work_book.save(savepath) 
```



- 单元格写入数据、合并

合并单元格并写入数据

```python
work_sheet.merge(2,3,0,3)
#merge(self,r1,r2,c1,c2,style=Style.default_style):
# r1起始行 r2合并终止行 c1 c2类似

work_sheet.write_merge(4,4,0,3,'合并单元格数据')
```

![image-20210327210704570](https://cdn.jsdelivr.net/gh/moon-Light404/my_picgo@master/img/20210327210812.png)

- 插入位图

```python
# 插入位图
work_sheet.insert_bitmap('01.bmp',5,0)
"insert_bitmap(self, filename, row, col, x = 0, y = 0, scale_x = 1, scale_y = 1):"

#filename:文件名称
#row：行 col：列
#x，y：设定单元格的x，y距离
#scale：缩放比例
注意：图片必须为bmp位图，且需为24位真色彩，会PhotoShop的可以自己调整一下图片。
```



```python
import xlwt

# 新建工作簿
book = xlwt.Workbook()

#增加sheet表
work_sheet = book.add_sheet('Test')

#单元格
work_sheet.write(0,0,'Hello World')

# 将列表数据写入单元格
test_list = [str(i) for i in range(5)]
work_sheet.write_rich_text(1,0,test_list)

# 合并单元格
work_sheet.write_merge(4,4,0,3,'合并单元格数据')

# 插入位图
work_sheet.insert_bitmap('01.bmp',5,0)
work_sheet.insert_bitmap('01,bmp',5,8,x=50,y=50,scale_x=0.5,scale_y=0.5)

#保存文件
book.save('Test.xls')

```

<img src="https://cdn.jsdelivr.net/gh/moon-Light404/my_picgo@master/img/20210327211825.png" alt="image-20210327211824957" style="zoom:67%;" />



- 获取sheet表对象属性

获得当前sheet表属性

```python
print(work_sheet.get_name())

# 设置名称
work_sheet.set_name('Test_rename')

```













