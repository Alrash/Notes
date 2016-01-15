<h1 align="center">C++笔记</h1>

##【目录】
----

[0  前言](#0)<br>
[1  explicit关键字](#1)<br>
[****1.1  问题出现](#1.1)<br>
[****1.2  explicit解释](#1.2)<br>
[****1.3  explicit作用](#1.3)<br>


<h2 name="0">0  前言</h2>
这篇笔记仅仅是对自己所学c++语言的补充，并没有包含c++的基本语法，以及一些常用的函数，包括类的一些东西。

<h2 name="1">1  explicit关键字</h2>
<h3 name="1.1">1.1  问题出现</h3>
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

<h3 name="1.2">1.2  explicit解释</h3>
explicit	英->中：明确的<br>

<h3 name="1.3">1.3  explicit作用</h3> 
为了解决1.1所讲述的问题，可以在构造函数前添加explicit关键字，例如explicit String(int n)；这时，实例化对象时，String str = 100，就无法编译通过，抑制隐式转换；同时，像int fun(String a)这样参数使用类String的情况，也无法使用fun(2)这样的情况。<br>
<br>
总结：explicit可以只对构造函数起作用，用来抑制隐式转换。<br>
