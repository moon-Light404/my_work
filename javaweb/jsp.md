bin:可执行文件(startup.bat  shutdown.bat)
conf:配置文件 (server.xml)
lib:tomcat依赖的jar文件
log:日志文件(记录出错等信息)
temp:临时文件
webapps:可执行的项目(将我们开发的项目放入该目录)

work:存放jsp翻译成的java,以及编辑城的class文件
jsp >java ->class

配置tomcat` CATALINA_HOME`   bin文件根目录
配完上面后点击bin目录中的startup.bat

有可能双击会出现错误，可能是端口号冲突，可以去conf改端口号，默认是8080，
可以改成8888在server.xml中修改70行左右

访问tomcat：在浏览器中输入localhost:8888(要打开并启动后才行)
或者localhost:8888/项目名访问某个文件
状态码:
200：一切正常(看不见)
300/301：页面重定向(跳转)
404： 资源不存在
403:权限不足(访问a目录，但a目录不可见)
500:服务器内部错误(代码写错)



建项目
在webapps文件夹中建一个文件夹，该文件夹包括包括一个WEB-INF(web.xml+classes+lib)
.jsp文件与WEB-INF在同一目录下

jsp：在html中嵌套的java代码

在项目/WEB-INF/web.xml中设置 默认的 初始页面
`<welcome-file-list>
<welcome-file> </welcome-file>
</welcome-file-list>`

虚拟路径
方式一：
将web项目配置到webapps以外的目录
在server.xml中 <Host></Host>子段
`<Context docBase = "D:\study\JspProject" path="/JspProject" />`
docBase :实际路径  path：虚拟路径(绝对路径、相对路径[相对于webapps])
重启
方式二:
D:\JAVA\apache-tomcat-10.0.4\conf\Catalina\localhost中新建 "项目名.xml"文件中新增一行
`<Context docBase = "D:\study\JspProject" path="/JspProject" />`