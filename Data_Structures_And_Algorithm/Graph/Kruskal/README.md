#Kruskal

##算法思路
1. 将图中边安从小到大排序
2. 将选中的边的两个端点加入一个集合（若任意一个端点在一个集合内，另一个不在任何集合，则将另一个端点加入这个集合；若都不在任意集合内，则两个端点自成一个集合；若在两个不同的集合内，则将两个集合合并）
3. 抛弃边的条件：两个端点在同一个集合内

**适用状况：稀疏图，因为可能需要查询所有的边**

##图例
<img src="https://github.com/bwfullcolor/Notes/blob/master/Data_Structures_And_Algorithm/Graph/Kruskal/start.jpg">

待生成数的图

<img src="https://github.com/bwfullcolor/Notes/blob/master/Data_Structures_And_Algorithm/Graph/Kruskal/first.jpg">

选择最小的边，其两端点进入集合A

<img src="https://github.com/bwfullcolor/Notes/blob/master/Data_Structures_And_Algorithm/Graph/Kruskal/second.jpg">

选择剩余的最小的边，判断其两端点与集合A的情况。这里都不在集合A内，因此两个端点独成集合B

<img src="https://github.com/bwfullcolor/Notes/blob/master/Data_Structures_And_Algorithm/Graph/Kruskal/third.jpg">

重复选择剩余最小的边。这里端点2已在集合B中，所以将端点5加入集合B。

<img src="https://github.com/bwfullcolor/Notes/blob/master/Data_Structures_And_Algorithm/Graph/Kruskal/fourth.jpg">

重复选择。这里将3加入集合B。

<img src="https://github.com/bwfullcolor/Notes/blob/master/Data_Structures_And_Algorithm/Graph/Kruskal/fifth.jpg">

重复选择剩余最小的边。易知，端点1属于集合B，端点3属于A，此时，将AB两个集合合并。<br>
**这里选择13 14 36都可以，根据你的排序情况决定**<br>
恰好，这里已经得出最小生成树。

<img src="https://github.com/bwfullcolor/Notes/blob/master/Data_Structures_And_Algorithm/Graph/Kruskal/sixth.jpg">

假如，这里选择了36这两个端点形成的边。从图中可知，3,6属于集合A，因此其边要被舍弃，不能使用

##算法需解决的问题
如何方便的将边加入集合（可能会有2个以上的集合，而不是像上图示那样仅有2个集合）？<br>
[并查集]()

##代码示例
```cpp
```

##小部分改进
最小生成树所需结点和边数的关系：N个结点，N-1条边<br>
所以在for循环的时候，找到N-1条边就可以跳出循环，则加一个参数count记录边数，将原来的终止条件改为count > 0
