## 京东4.9日笔试编程题目

### 问题1
输入为数字t和t个数字n，如下：

2

10
5

t表示有t个数字输入n。

要求：
计算n的分解n=X*Y, X为奇数，Y为偶数，如果有多组满足的xy，输出Y最小的一组，中间用空格分开，没有则输出“NO”。上例输出为：

5 2
No


### 问题2
输入为字符串string，长度小于50。从字符串中移除0或多个字符，使其成为回文串，求有多少种方法。移除的字符构成序列不同则认为是不同的方法。

例如输入：AAB 输出：4。 输入：ABA 输出：5;


### 问题3
象棋中的马从左下角(0,0)开始移动k步，棋盘8x8.则移动到(X,Y)出一共有多少种方法。结果可能会非常大，取模1000000007，即%1000000007。

例如输入：
2
3 3

输出：2

