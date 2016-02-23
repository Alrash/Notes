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
