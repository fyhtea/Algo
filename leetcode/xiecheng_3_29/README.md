## 携程3.29日笔试编程题目

### 问题描述
输入为数字M和M个字符串，如下：
4
A2B3D
A5D
A3C4E
C4B

字符串描述了字母间的连接关系和距离，如A与B相连，距离为2,B与D相连，距离为3。

要求：
如果存在环，返回-1
否则返回最长路径的长度，上例输出为10。


### 解决思路
1. 字符串读取，ch='2'转换到int型可以使用ch-48,直接类型转换数值不对。
2. 建立graph，使用邻接表形式表示， vector<vector<pair<int, int>>>>,pair中first存id，second存距离。
3. 以每个节点为起点，使用bread first search来遍历它所能到达的节点，bfs使用数据结构为queue<int, int>，first记录id，second记录总dist。注意queue的API是front和pop，stack才是top和pop。
4. 使用set<int> 来记录到达过的节点id， set.count(id)用来判断是否出现环，若有则返回-1。
5. 使用int 类型记录最大长度，与queue中元素的second相比，取大者保留。


