#LIS

##参考目录
<a href="https://segmentfault.com/a/1190000002641054"target="_blank">LIS算法设计</a><br>
**注意：此网站思想大部分正确，可是LIS提供的Java程序示例错误，具体可用2,1,5,3,6,4,8,9,7,10验证，应得出6，却给出5**<br>
本文档已附录改进版LIS.java<br>
<a href="http://www.felix021.com/blog/read.php?1587"target="_blank">代码正确的网站，分析未仔细看，使用C++编写</a>
思路总体与上一个差不多

##解决思路1
###算法时间复杂度
O(n^2)

###最优子结构
已知条件，LIS[i] = 已经形成的递增序列{a[x]...a[y]...a[m]} + ?a[i]的长度，即LIS[i]由a[i]决定。则有：<br>
LIS[i] = Max(LIS(j)) + 1; j < i && a[j] < a[i] ( Max(LIS(j), 取存在的a[j] < a[i]中的最大值))<br>
LIS[i] = 1; j < i，但是不存在a[j] < a[i]<br>
所以问题变成，计算Max(LIS[j])

###重叠子问题
易知，LIS[i]会重复计算，为重叠的子问题<br>
则，所建数组dp，即为记录以a[i]结尾的LIS序列的长度

###具体设计
```cpp
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
```

##解决思路2
###算法时间复杂度
O(nlogn)

###算法改进分析
解决思路1，耗时主要在得到max(LIS[i])上，则现在需要改进的地方就是查找。<br>
而查找算法最节省时间的有序组下的二分查找(O(logn))。所以这里需要构造有序组。

###算法改进设计
(这里主要采自参考目录所记录的网站)
> 1. 使用一个数组MaxV[nMaxLength]来缓存递增子序列LIS的末尾元素的最小值，nMaxLength存放此时有序数组的长度(假设现在Maxv为1 2 4，下一个元素a[i]为3，处理后Maxv为1 2 3，nMaxLength不变为3；假设现在Maxv为1 3 4，下一个元素a[i]为2，处理后Maxv为1 2 4，nMaxLength = 3)；使用另一个数组Length，来存放第i个元素可组成的最长子序列(如上面两例，第一例--Length[3] = 3, Length[4] = 3；第二例--Length[3] = 3, Length[4] = 2)，也可使用一个变量直接记录最大长度
> 2. 较小的具有较高的潜力
> 3. 基于1，现在从下边2遍历数组a
> 
> > 1. a[i] > Maxc[nMaxLength], 将a[i]插入到Maxv[nMaxLength]的末尾，之后nMaxLength(MaxV数组存放了目前为止的最长有序序列,***不一定是目前所有的数***) + 1，Length + 1
> > 2. a[i] < MaxV[nMaxLength], 使用二分查找到刚刚大于a[i]的数a[j]，替换a[j]
> > 3. 重复上述步骤
> 
> 4. 最后得到了一个有序数组MaxV，但是很遗憾，这个有序组仅是存放对应LIS的最小末尾元素，方便插入a[i]而构造的伪LIS，若求具体数组，不能作为答案输出

###个人理解
像在1 5 9 14这种情况(即使是原数组)，当插入7时，未来即使使用，也肯定使用1 5 7这个序列，而不是1 5 9。<br>
例如，假设下一个插入大于14的数，如15，序列1 5 7 14 15与序列1 5 9 14 15效果相同<br>
而假设下一个插入10，则序列为1 5 7 10，虽然与1 5 9 14效果相同，但是再插入11呢，后者不会再插入11，而前者能够得到正确长度1 5 7 10 11长度5(原序列1 5 9 14 7 10 11...)<br>
这是所谓的较小数有较大的潜力<br>
**注：数选取不好，这里有序列成为了答案之一**

###算法实现
```cpp
//未写

/*
 * 找出比key稍大的vt[i]
 */
int HalfSearch(const vector<int> &vt, int start, int end, int key);

void LIS(const vector<int> &vt)
{
}

```

##解决思路3
转化成LCS(最长公共子序列)<br>
使用原数组与排序后数组寻找子序列
