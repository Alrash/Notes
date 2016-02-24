<h1 align="center">C++笔记</h1>
----
<!--<strong>Author:Alrash</strong>-->
<h3>Author:Alrash</h3>
<h3>此笔记均以c11及其以后标准为基础</h3>
<h3>参考网站：</h3>
http://www.cplusplus.com<br>
<a href="http://www.cnblogs.com/jiabei521/p/3335676.html">c++ const 关键字的使用方法</a><br>
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
[4  set容器](#4)<br>
[****4.1  set与multiset](#4.1)<br>
[5  map容器](#5)<br>
[6  next_permutation](#6)<br>
[****6.1  部分说明](#6.1)<br>
[****6.2  函数原型](#6.2)<br>
[****6.3  相似功能函数prev_permutation](#6.3)<br>
[7  const](#7)<br>

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
<img src="https://github.com/bwfullcolor/Notes/blob/master/CPlusPlus/pictures/1-%E6%9C%AA%E5%8A%A0explicit%E7%A8%8B%E5%BA%8F%E7%A4%BA%E6%84%8F%E5%9B%BE.png" alt=""><br>
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
/*2016-01-18 星期一
 */
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	time_t now;
	tm *info;

	time(&now);
	info = localtime(&now);
	cout << info->tm_year + 1900 << " " << info->tm_mon + 1 << " " << info->tm_mday << endl;
	cout << info->tm_wday << endl;

	return 0;
}
```
<div align="center">
<img src="https://github.com/bwfullcolor/Notes/blob/master/CPlusPlus/pictures/3.5-mktime%E4%B8%80%E8%88%AC%E4%B8%BE%E4%BE%8B%E7%A4%BA%E6%84%8F%E5%9B%BE.png" alt="" ><br>
一般举例示意图
</div>
<br>
引申举例(计算某日n天后的日期之类)：
```cpp
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	tm info;					//使用指针提示未初始化错误，故用普通变量

	//设置日期，精确到秒(因为是已经过的秒数)
	info.tm_year = 2016 - 1900;	//根据localtime(time *t)输出的结果，是以1900年为起始年份
	info.tm_mon = 0;			//struct tm中tm_mon的取值范围
	info.tm_mday = 18;
	info.tm_hour = 0;
	info.tm_min = 0;
	info.tm_sec = 0;

	mktime(&info);
	//2016-01-18星期一
	cout << "2016-01-18星期一" << endl;
	cout << info.tm_wday << endl << endl;

	info.tm_mday += 20;

	mktime(&info);
	//应得到2016-02-07星期天
	cout << "应得到2016-02-07星期天" << endl;
	cout << info.tm_year + 1900 << " " << info.tm_mon + 1 << " " << info.tm_mday << endl;
	cout << info.tm_wday << endl;

	return 0;
}
```
<div align="center">
<img src="https://github.com/bwfullcolor/Notes/blob/master/CPlusPlus/pictures/3.5-mktime%E8%AE%A1%E7%AE%97n%E5%A4%A9%E5%90%8E%E7%9A%84%E6%97%A5%E6%9C%9F%E7%A4%BA%E4%BE%8B%E7%A4%BA%E6%84%8F%E5%9B%BE.png" alt=" "><br>
计算2016年1月18日20天后的日期和星期
</div>
<br>

<h2 name="4">4  set容器</h2>
<h3 name="4.1">4.1  set与multiset</h3>
需包含的头文件：<br>
```
#include <set>

/*
 *using std::set;
 *using std::multiset;
 */
```
<p>  表示集合的容器，set与multiset的区别仅是set内不允许重复，而multiset允许重复</p>
##其余带补充
<br>

<h2 name="5">5  map容器</h2>

<h2 name="6">6  next_permutation</h2>
<h3 name="6.1">6.1  部分说明</h3>
permutation 中文翻译：排列，置换<br>
功能：按顺序全排列数组，得到下一个升序序列(比本数组序列大)。**注：不一定循环排列一次(具体见代码说明)**<br>
例如，原数组为1 2 3，使用一次即可得到1 3 2，并且返回true；返回false的情况，得到序列小于本数组的序列<br>
需包含的头文件：<br>
```
#include <algorithm>

/*
 *using std:next_permutation;
 */
```
代码说明：
```cpp
// next_permutation example
#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort

int main() {
	int myints[] = { 1,2,3 };

	std::sort(myints, myints + 3);

	std::cout << "The 3! possible permutations with 3 elements:\n";
	do {
		std::cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';
	} while (std::next_permutation(myints, myints + 3));

	std::cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';

	std::cout << "\nNow, it runs twice.\n";

	myints[0] = 3;
	myints[1] = 1;
	myints[2] = 2;

	do {
		std::cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';
	} while (std::next_permutation(myints, myints + 3));

	std::cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';

	return 0;
}
```
<div align="center">
<img src="https://github.com/bwfullcolor/Notes/blob/master/CPlusPlus/pictures/6.1-next_permutation%E4%BB%A3%E7%A0%81%E8%AF%B4%E6%98%8E.png" alt=" "><br>
取得1 2 3的全排列以及查看next_permutation终止情况
</div>

实例代码：
```cpp
/*
 * 本程序主要解决的问题：使用1-9九个数，自由组合成分子、分母，使得结果等于1/3，问分子，分母分别是多少
 * 解决思路：1.要得到1/3，并且只有九个数，则分子4位，分母5位（极有可能是 **** / 1****）
 *           2.仅需全排列1-9，找出符合分子分母
 */
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a[9];
	for (int i = 1; i < 10; i++) a[i - 1] = i;		//1 2 3 4 5 6 7 8 9

	do
	{
		int x = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];				//得到分子
		int y = a[4] * 10000 + a[5] * 1000 + a[6] * 100 + a[7] * 10 + a[8];	//等到分母
		if (3 * x == y)														//符合的答案
			cout << x << "/" << y << endl;
	}while(next_permutation(a, a + 9));										//全排列

	return 0;
}
```

<h3 name="6.2">6.2  函数原型</h3>
```cpp
//default
template <class BidirectionalIterator>
bool next_permutation (BidirectionalIterator first,
                         BidirectionalIterator last);

//参数3，比较顺序，默认小于
template <class BidirectionalIterator, class Compare>
bool next_permutation (BidirectionalIterator first,
                         BidirectionalIterator last, Compare comp);
```

<h3 name="6.3">6.3  相似功能函数prev_permutation</h3>
prev_permutation与next_permutation一样，属于algorithm头文件，但是功能与其相反，是产生上一个序列(最小1 2 3)

<h2 name="7">7  const</h2>
