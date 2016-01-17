<h1 align="center">C++笔记</h1>
----
<!--<strong>Author:Alrash</strong>-->
<h3>Author:Alrash</h3>
<h3>此笔记均以c11及其以后标准为基础</h3>
<h3>参考网站：</h3>
http://www.cplusplus.com<br>
<br>

##【目录】
----

[0  前言](#0)<br>
[1  杂项](#1)<br>
[****1.1  参数传递](#1.1)<br>
[2  explicit关键字](#2)<br>
[****2.1  问题出现](#2.1)<br>
[****2.2  explicit解释](#2.2)<br>
[****2.3  explicit作用](#2.3)<br>
[3  ctime/time.h](#3)<br>
[****3.1  struct tm](#3.1)<br>
[****3.2  time_t(暂无)](#3.2)<br>
[****3.3  size_t(暂无)](#3.3)<br>
[****3.4  clock_t(暂无)](#3.4)<br>
[****3.5  mktime](#3.5)<br>
[********3.5.1  函数原型](#3.5.1)<br>
[********3.5.2  举例说明](#3.5.2)<br>

----
<h2 name="0">0  前言</h2>
这篇笔记仅仅是对自己所学c++语言的补充，并没有包含c++的基本语法，以及一些常用的函数，包括类的一些东西。<br>

<h2 name="1">1  杂项</h2>
<h3 name="1.1">1.1  参数传递</h3>
C++的参数传递方式有三种:引用传递、值传递、**常量引用传递**<br>
表示形式(按上述顺序)--int &count, bool sign, const vector<int> &arr。其中只有引用传递才能改变实參的实际值，另外两种不能；在无需改变实參值的情况下，对类对象，建议使用常量引用传递，对简单变量，建议使用值传递。<br>
参数传递选项总结如下:
> * (1)按值调用适用于不被函数更改的小对象(一般是简单变量)
> * (2)按常量引用调用适用于不被函数更改的大对象(类对象，复制耗时)
> * (3)引址调用适用于所有可以被函数更改的对象
<br>

<h2 name="2">2  explicit关键字</h2>
<h3 name="2.1">2.1  问题出现</h3>
在C++中，当构造函数参数为1个时，默认做一次隐式转换，将该参数转换为该类的对象(同数据类型),如下所示:

```cpp
#include <iostream>
#include <cstring>

using namespace std;

class String
{
public:
	String(int n)
	{
		str = new char[n];
	}

	String(const char *p)
	{
		str = new char[strlen(p) + 1];
		strcpy(str, p);
	}

	~String()
	{
		delete[] str;	
	}

	void print() const
	{
		cout << str << endl;
	}

	int getlength() const
	{
		return strlen(str);
	}

private:
	char *str;
};

int main()
{
	String str1(100);				//OK 分配100个字节的空字符串
	cout << str1.getlength() << " ";	str1.print();

	String str2 = 100;				//编译通过 分配100个字节的空字符串
	cout << str2.getlength() << " ";	str2.print();

	String str3 = "464";			//编译通过 相当于String str3("464");
	cout << str3.getlength() << " ";	str3.print();

	return 0;
}
```
<div align="center">
<img src="https://github.com/bwfullcolor/CPlusPlus_Notes/blob/master/pictures/1-%E6%9C%AA%E5%8A%A0explicit%E7%A8%8B%E5%BA%8F%E7%A4%BA%E6%84%8F%E5%9B%BE.png" alt=""><br>
未添加explicit关键字程序示意图
</div>
<br>
如上所示，未添加explicit时，实例str2实际相当于String str2(100)，做了一次隐式转换；有时，声明int fun(String n)后，使用fun(2)时，这时编译通过，2被隐式转换为String类型，一般我们不想这样。

<h3 name="2.2">2.2  explicit解释</h3>
explicit	英->中：明确的<br>

<h3 name="2.3">2.3  explicit作用</h3> 
为了解决1.1所讲述的问题，可以在构造函数前添加explicit关键字，例如explicit String(int n)；这时，实例化对象时，String str = 100，就无法编译通过，抑制隐式转换；同时，像int fun(String a)这样参数使用类String的情况，也无法使用fun(2)这样的情况。<br>
<br>
总结：explicit可以只对构造函数起作用，用来抑制隐式转换。<br>
<br>

<h2 name="3">3  ctime/time.h</h2>
<h3 name="3.1">3.1  struct_tm</h3>
包含日历日期和时间，分解其组成部分存储(用结构体)<br>
一般的声明形式：(struct) tm \*newtime;/(struct) tm newtime;<br>
<br>
<!--表格-->
<table>
<tr>
<td>成员项</td><td>类型</td><td>代表意义</td><td>取值范围</td>
</tr>
<tr>
<td>tm_sec</td><td>int</td><td>秒</td><td>0-60</td>
</tr>
<tr>
<td>tm_min</td><td>int</td><td>分</td><td>0-59</td>
</tr>
<tr>
<td>tm_hour</td><td>int</td><td>时</td><td>0-23</td>
</tr>
<tr>
<td>tm_mday</td><td>int</td><td>月份的日</td><td>1-31</td>
<tr>
<tr>
<td>tm_mon</td><td>int</td><td>月份</td><td>0-11</td>
</tr>
<tr>
<td>tm_year</td><td>int</td><td>年(从1900开始)</td><td> </td>
</tr>
<tr>
<td>tm_wday</td><td>int</td><td>星期</td><td>0-6</td>
<tr>
<td>tm_year</td><td>int</td><td>指一年365年的第几天(润年366)</td><td>0-365</td>
</tr>
<tr>
<td>tm_isdst</td><td>int</td><td>夏令时标识</td><td> </td>
</td>
</table>
部分说明：<br>
tm_isdst--取0,表示夏令时无影响；大于0,夏令时有作用；小于0,信息不可用<br>
除了月份的日以外，都是从0开始的(偏移量)<br>
<br>tm_sec通常取0-59.剩下的范围，以适应某些系统中的闰秒(leap seconds ?)<br>
<br>

<h3 name="3.2">3.2  time_t</h3>
<br>

<h3 name="3.3">3.3  size_t</h3>
<br>

<h3 name="3.4">3.4  clock_t</h3>
<br>

<h3 name="3.5">3.5  mktime</h3>
<h4 name="3.5.1">3.5.1  函数原型</h4>
<font color=green>
<strong>time_t mktime(struct tm \* timeptr);
</strong>
</font>
<br>
> * 作用：自动调整参数timeptr所设置的日期，返回time_t类型的日期时间。例如timeptr被赋值为*tm_year = 2016, tm_mon = 1, tm = 30*，会被自动调整成2016-3-1(参考结构体tm成员的范围，月份从0开始)，返回从1970-1-1 0:0:0到2016-3-1 0:0:0的秒数
> * 参数列表：结构体struct tm指针类型的参数
> * 返回值：返回参数timeptr对应的time_t类型的日期时间，若不能表示则为-1

<h4 name="3.5.2">3.5.2  举例说明</h4>
一般举例：
```cpp
```
<br>
引申举例(计算某日n天后的日期之类)：
```cpp
```
<br>
<br>
