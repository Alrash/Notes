/*
 * 最长公共子序列：
 * 状态转移方程：dp[i][j] = 0  i = 0, j = 0
 *                        = dp[i - 1][j - 1] + 1            str1[i] = str2[j] && i，j > 0
 *                        = max(dp[i - 1][j], dp[i][j - 1]) str1[i] != str2[j] && i, j > 0
 * */
#include <iostream>
#include <string>
#include <algorithm>

#define N 1005

using namespace std;

int dp[N][N];
int ans[N][N];

void printSub(int x, int y, string str)
{
	if (x == 0 || y == 0)
		return;

	if (ans[x][y] == 1)
	{
		printSub(x - 1, y - 1, str);
		cout << str[x - 1];
	}
	else if (ans[x][y] = 2)
		printSub(x, y - 1, str);
	else
		printSub(x - 1, y, str);
}

int main()
{
	string str1, str2;

	cin >> str1 >> str2;

	for (int i = 0; i <= str1.length(); i++)
		for (int j = 0; j <= str2.length(); j++)
			dp[i][j] = 0;

	for (int i = 0; i < str1.length(); i++)
		for (int j = 0; j < str2.length(); j++)
		{
			if (str1[i] == str2[j])
			{
				dp[i + 1][j + 1] = dp[i][j] + 1;
				ans[i + 1][j + 1] = 1;						//左上
			}
			else if (dp[i][j + 1] < dp[i + 1][j])
			{
				dp[i + 1][j + 1] = dp[i + 1][j];
				ans[i + 1][j + 1] = 2;						//left
			}
			else
			{
				dp[i + 1][j + 1] = dp[i][j + 1];
				ans[i + 1][j + 1] = 3;						//above
			}
		}

	cout << dp[str1.length()][str2.length()] << endl;

	printSub(str1.length(), str2.length(), str1);
	cout << endl;

	return 0;
}
