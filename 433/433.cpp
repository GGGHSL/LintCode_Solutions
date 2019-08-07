/*
433. 岛屿的个数
给一个 01 矩阵，求不同的岛屿的个数。0代表海，1代表岛，
如果两个1相邻，那么这两个1属于同一个岛。
我们只考虑上下左右为相邻。

样例
样例 1：
	输入：
		[
		  [1,1,0,0,0],
		  [0,1,0,0,1],
		  [0,0,0,1,1],
		  [0,0,0,0,0],
		  [0,0,0,0,1]
		]
	输出：
		3
样例 2：
	输入：
		[
		  [1,1]
		]
	输出：
		1
*/

#include <iostream>
#include <vector>
#include <deque>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::deque;

int main() {
	
	system("pause");
	return 0;
}

class Solution {
public:
	/**
	 * @param grid: a boolean 2D matrix
	 * @return: an integer
	 */
	int numIslands(vector<vector<bool>> &grid) {
		// write your code here
		if (grid.empty() || grid[0].empty()) {
			return 0;
		}
		vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), 0));
		int ans = 0;
		for (int i = 0; i != grid.size(); ++i) {
			for (int j = 0; j != grid[0].size(); ++j) {
				if (grid[i][j] && !visit[i][j]) {
					++ans;
					bfs(grid, visit, i, j);
				}
			}
		}
		return ans;
	}
private:
	void bfs(vector<vector<bool>> &grid, vector<vector<bool>> &visit, int sx, int sy) {
		int dx[4] = { 0, 0, 1, -1 };
		int dy[4] = { 1, -1, 0, 0 };
		deque<int> qx;
		deque<int> qy;
		
		qx.push_back(sx);
		qy.push_back(sy);
		visit[sx][sy] = true;

		while (!qx.empty()) {
			int cx = *(qx.begin());
			int cy = *(qy.begin());
			qx.pop_front();
			qy.pop_front();
			for (int i = 0; i != 4; ++i) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() &&
					!visit[nx][ny] && grid[nx][ny]) {
					qx.push_back(nx);
					qy.push_back(ny);
					visit[nx][ny] = true;
				}
			}
		}
	}
};