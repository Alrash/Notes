#并查集

##参考文献
[中文维基--并查集(和英版)](https://zh.wikipedia.org/zh-cn/%E5%B9%B6%E6%9F%A5%E9%9B%86)

##基本介绍
并查集是一种树型数据结构，用于处理一些不相交结合的合并及查询问题。

###find方法
查找结点x属于哪个集合
```cpp
int parent[N];		//all -1
int find(int x)
{
	if (parent[x] == -1)
		return x;
	else
		return find(parent[x]);
}

int parent[N];		//0 1 2 3...
int find(int x)
{
	if (parent[x] == x)
		return x;
	else
		return find(parent[x]);
}

```
