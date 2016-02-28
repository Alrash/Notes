#include <iostream>
#include <vector>
#include <cstdio>	//scanf
#include <algorithm>	//sort

using namespace std;

const int LEN = 1005;

struct Node
{//存储边的值和边的两个端点
	int v, u;		//端点
	int w;			//边权值

	bool operator<(const Node &node) const
	{
		if (w == this->w)
		{
			if (v == this->v)
				return w < this->w;
			return v < this->v;
		}
		else
			return w < this->w;
	}
};

vector<Node> vt;
vector<int> parent(LEN, -1);
int ans;

/*
 * 并查集使用
 * */
int find(int x)
{
	if (parent[x] == -1)
		return x;
	else
		return find(parent[x]);
}

void Kruskal()
{
	//将-1设置为所有节点的根节点
	for (int i = 0; i < vt.size(); i++)
		parent[i] = -1;

	//将边按从小到大排序
	sort(vt.begin(), vt.end());
	ans = 0;						//最小生成树，边权值置0

	int vroot, uroot;
	for (int i = 0; i < vt.size(); i++)
	{
		vroot = find(vt[i].v), uroot = find(vt[i].u);

		if (vroot != uroot)
		{
			ans += vt[i].w;
			parent[uroot] = vroot;	//将vt[i].u所在的集合，加入vt[i].v所在的集合
		}
	}
}

int main()
{
	//n图中节点数，m图中的边数
	//这里只用到m
	int n, m;
	Node tmp;

	while(scanf("%d%d", &n, &m) == 2)
	{
		vt.clear();

		for (int i = 0; i < m; i++)
		{
			cin >> tmp.v >> tmp.u >> tmp.w;
			vt.push_back(tmp);
		}

		Kruskal();

		cout << ans << endl;
	}
	
	return 0;
}
