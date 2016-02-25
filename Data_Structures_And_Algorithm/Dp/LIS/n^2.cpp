#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

#define N 100005

using namespace std;

vector<int> dp(N, 1);				//当vt[i]最小时，为1
vector<int> ans(N, -1);				//前去结点为-1

/*
 * 时间复杂度O(n^2)
 */
void LIS(const vector<int> &vt)
{
	for (int i = 1; i < vt.size(); i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{//LIS[i] = max(LIS[j]) +? 1
			if (vt[i] > vt[j])
			{// + 1
				if (dp[i] < dp[j] + 1)
				{
					dp[i] = dp[j] + 1;
					ans[i] = j;
				}
			}
			else if (vt[i] == vt[j])
			{// = max(LIS[j])
				if (dp[i] < dp[j])
				{
					dp[i] = dp[j];
					ans[i] = ans[j];
				}
			}
		}
	}
}

void print(int root, const vector<int> &vt)
{
	if (ans[root] == -1)
		cout << vt[root];
	else
	{
		print(ans[root], vt);
		cout << endl << vt[root];
	}
}

int main()
{
	int n;
	vector<int> vt;

	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		vt.push_back(rand());

	for (int i = 0; i < vt.size(); i++)
		cout << vt[i] << endl;
	cout << endl;

	LIS(vt);
	int pos = 0;
	for (int i = 1; i < vt.size(); i++)
		pos = dp[i] > dp[pos] ? i : pos;
	print(pos, vt);

	return 0;
}
