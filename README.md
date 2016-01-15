<h1 align="center">C++笔记</h1>

##【目录】
----

[0  前言](#0)<br>
[1  explicit关键字](#1)<br>
[****1.1  问题出现](#1.1)<br>
[****1.2  explicit解释与适用情况](#1.2)<br>


<h2 name="0">0  前言</h2>
这篇笔记仅仅是对自己所学c++语言的补充，并没有包含c++的基本语法，以及一些常用的函数，包括类的一些东西。

<h2 name="1">1  explicit关键字</h2>
<h3 name="1.1">****1.1  问题出现</h3>
在C++中，当构造函数参数为1个时，默认做一次隐式转换，将该参数转换为该类的对象(同数据类型),如下所示:

```cpp
#include <iostream>
#include <cstring>

using namespace std;

class String
{
public:
	String(int n){		str = new char[n];	}

	String(const char *p)
	{
		str = new char[strlen(p) + 1];
		strcpy(str, p);
	}

	~String(){		delete[] str;	}

	void print() const{		cout << str << endl;	}

	int getlength() const{		return strlen(str);	}

private:
	char *str;
};

int main()
{
	String str1(100);				//OK 分配100个字节的空字符串
	cout << str1.getlength() << " ";	str1.print();

	String str2 = 100;				//编译通过 分配100个字节的空字符串
	cout << str2.getlength() << " ";	strr2.print();

	String str3 = "464";			//编译通过 相当于String str3("464");
	cout << str3.getlength() << " ";	str3.print();

	return 0;
}
```


<h3 name="1.2">****1.2  explicit解释与适用情况</h3>
explicit	明确的<br>
使用在类内的构造函数上<br>
