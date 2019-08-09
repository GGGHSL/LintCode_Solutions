/*
178. 图是否是树
	给出n个节点，标号分别从 0 到n - 1并且给出一个无向边的列表 (给出每条边的两个顶点), 
	写一个函数去判断这张无向图是否是一棵树。

样例
样例 1:
	输入: n = 5 edges = [[0, 1], [0, 2], [0, 3], [1, 4]]
	输出: true.
样例 2:
	输入: n = 5 edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]]
	输出: false.
注意事项
	你可以假设我们不会给出重复的边在边的列表当中。
	无向边[0, 1]和[1, 0]是同一条边， 因此他们不会同时出现在我们给你的边的列表当中。
*/
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
	/**
	 * @param n: An integer
	 * @param edges: a list of undirected edges
	 * @return: true if it's a valid tree, or false
	 */
	bool validTree(int n, vector<vector<int>> &edges) {
		// write your code here
		if (n == 0) {
			return false;
		}
		if (edges.size() != n - 1) {
			// 不满足成树条件“边数=点数-1”
			return false;
		}
		for (int i = 0; i != n; ++i) {
			father.push_back(i);
		}
		for (auto e : edges) {
			int a = e[0], b = e[1];
			int rootA = find(a), rootB = find(b);
			if (rootA == rootB) {
				// a和b此前已经连通, 因此成环
				return false;
			}
			father[rootA] = rootB;  // 连通a和b
		}
		return true;
	}
private:
	vector<int> father;
	int find(int x) {
		if (father[x] == x) {
			return x;
		}
		father[x] = find(father[x]);
	}
};

int main() {

	system("pause");
	return 0;
}