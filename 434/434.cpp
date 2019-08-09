/*
434. 岛屿的个数II
	给定n, m, 分别代表一个二维矩阵的行数和列数, 并给定一个大小为k的二元数组A, 初始二维矩阵全0。
	二元数组A内的k个元素代表k次操作, 设第i个元素为(A[i].x, A[i].y), 
	表示把二维矩阵中下标为A[i].x行A[i].y列的元素由海洋变为岛屿。 
	问在每次操作之后, 二维矩阵中岛屿的数量。你需要返回一个大小为k的数组。

样例
样例 1:
	输入: n = 4, m = 5, A = [[1,1],[0,1],[3,3],[3,4]]
	输出: [1,1,2,2]
	解释:
		0.  00000
			00000
			00000
			00000
		1.  00000
			01000
			00000
			00000
		2.  01000
			01000
			00000
			00000
		3.  01000
			01000
			00000
			00010
		4.  01000
			01000
			00000
			00011
样例 2:
	输入: n = 3, m = 3, A = [[0,0],[0,1],[2,2],[2,1]]
	输出: [1,1,2,2]
注意事项
	设定0表示海洋, 1代表岛屿, 并且上下左右相邻的1为同一个岛屿。
*/

#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}

};

class Solution {
public:
	/**
	 * @param n: An integer
	 * @param m: An integer
	 * @param operators: an array of point
	 * @return: an integer array
	 */
	vector<int> numIslands2(int n, int m, vector<Point> &operators) {
		// write your code here
		vector<int> result;
		if (operators.empty()) {
			return result;
		}
		vector<vector<bool>> island(n, vector<bool>(m, false));
		int dx[4] = { 0, 0, 1, -1 };
		int dy[4] = { 1, -1, 0, 0 };
		for (int i = 0; i != n; ++i) {
			for (int j = 0; j != m; ++j) {
				// 初始化: father下标等于元素值
				father.push_back(i * m + j);
			}
		}

		for (auto op : operators) {
			if (!island[op.x][op.y]) {  // 避免重复
				int sx = op.x, sy = op.y;
				island[sx][sy] = true;
				++cntIsland;
				for (int i = 0; i != 4; ++i) {
					int nx = sx + dx[i], ny = sy + dy[i];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && island[nx][ny]) {
						_union(sx * m + sy, nx * m + ny);  // 将新增点的root合并到周边已有岛的root上
					}
				}
			}
			result.push_back(cntIsland);
		}
		return result;
	}
private:
	vector<int> father;
	int cntIsland = 0;
	int _find(int x) {  // 查询root节点, 由_union调用
		if (father[x] == x) {
			return x;
		}
		return father[x] = _find(father[x]);  // 递归查找root
	}
	void _union(int a, int b) {
		int rootA = _find(a), rootB = _find(b);
		if (rootA != rootB) {
			father[rootA] = rootB;
			--cntIsland;
		}
	}
};

int main() {
	vector<Point> ops{ {0, 0}, { 1, 1 }, { 1, 0 }, { 0, 1 } };
	Solution s;
	auto ans = s.numIslands2(2, 2, ops);
	for (auto _ : ans) {
		cout << _ << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}