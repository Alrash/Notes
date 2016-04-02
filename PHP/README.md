<h1 align="center">PHP</h1>

##暂时仅打算写下超全局数组

|元素|描述|
|----|----|
|$_SERVER['PHP_SELF']|返回当前执行脚本的文件名|
|$_SERVER['GATEWAY_INTERFACE']|返回服务器使用的CGI规范的版本|
|$_SERVER['SERVER_ADDR']|返回当前运行脚本所在的服务器的IP地址|
|$_SERVER['SERVER_NAME']|返回当前运行脚本所在的服务器的主机名(比如github.com)|
|$_SERVER['SERVER_SOFTWARE']|返回服务器的标识字符串(比如Apache/2.2.24)|
|$_SERVER['SERVER_PROTOCOL']|返回请求页面时通信协议的名称和协议(比如"HTTP/1.0")|
|$_SERVER['REQUEST_METHOD']|返回访问页面使用的请求方法(比如POST)|
|$_SERVER['REQUEST_TIME']|返回请求开始时的时间戳(比如1577687494)|
|$_SERVER['QUERY_STRING']|返回查询字符串，如果是通过查询字符串访问此页面？|
|$_SERVER['HTTP_ACCEPT']|返回来自当前请求的请求头|
|$_SERVER['HTTP_ACCEPT_CHARSET']|返回来自当前请求的Accept_Charset头(比如utf-8)|
|$_SERVER['HTTP_HOST']|返回来自当前请求的Host头|
|$_SERVER['HTTP_REFERER']|返回当前页面完整的URL(不可靠，因为不是所有用户代理都支持)|
|$_SERVER['HTTPS']|是否通过安全HTTP协议查询脚本|
|$_SERVER['REMOTE_ADDR']|返回浏览当前页面的用户的IP地址|
|$_SERVER['REMOTE_HOST']|返回浏览当前页面的用户的主机名|
|$_SERVER['REMOTE_PORT']|返回用户机器上连接到Web服务器所使用的端口号|
|$_SERVER['SCRIPT_FILENAME']|返回当前执行脚本的绝对路径|
|$_SERVER['SERVER_ADMIN']|该值指明了Apache服务器配置文件中的SERVER_ADMIN参数|
|$_SERVER['SERVER_PORT']|Web服务器使用的端口，默认为80|
|$_SERVER['SERVER_SIGNATURE']|返回服务器版本和虚拟主机名|
|$_SERVER['PATH_TRANSLATED']|当前脚本所在文件系统(非文、文档根目录)的基本路径|
|$_SERVER['SCRIPT_NAME']|返回当前脚本的路径|
|$_SERVER['SCRIPT_URI']|返回当前页面的URI|


##附录
超全局列表摘自[w3school php](http://www.w3school.com.cn/php/php_superglobals.asp), 全文手打，但并未取得同意，如有侵权，请联系我。
