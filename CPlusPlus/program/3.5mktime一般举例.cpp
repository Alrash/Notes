/*2016-01-18 ÐÇÆÚÒ»
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