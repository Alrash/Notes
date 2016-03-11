#并查集

##参考文献
[中文维基--并查集(和英版)](https://zh.wikipedia.org/zh-cn/%E5%B9%B6%E6%9F%A5%E9%9B%86)

##基本介绍
并查集是一种树型数据结构，用于处理一些不相交结合的合并及查询问题(连通性问题)。<br>
如上，我们可以使用并查集建树，而非使用带指针链式结构(虽然也差不多)。<br>
对于连通性问题，需要灵活辨析，有时逆向思路可能会得到让我们求连通性问题的题目。

###初始化问题
一般的并查集，我们除了创建一个数组记录数据项以外，还需要一个一维数组来表示其父节点是什么。这里为了统一我使用parent来表示这个数组。<br>
初始化有两种方法：全部置为-1，和置为数组下标。

###Union方法
合并森林，创建单棵树。// 创建并查集
```cpp
bool Union(int x, int y)
{
	int xt = find(x), yt = find(y);		//xroot yroot
	if(xt == yt)				//属于同一棵树
		return false;
	parent[xt] = yt;			//parent[yt] = xt;	//合并森林
	return true;
}

```

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
	//return parent[x] == x ? x : /*parent[x] = ?*/find(parent[x]);
}

```
