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
