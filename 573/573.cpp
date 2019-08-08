/*
573. 邮局的建立 II
	给出一个二维的网格，每一格可以代表墙2，房子1，以及空0(用数字0,1,2来表示)，
	在网格中找到一个位置去建立邮局，使得所有的房子到邮局的距离和是最小的;
	返回所有房子到邮局的最小距离和，如果没有地方建立邮局，则返回-1.

样例
样例 1:
	输入：[[0,1,0,0,0],[1,0,0,2,1],[0,1,0,0,0]]
	输出：8
	解释： 在(1,1)处建立邮局，所有房子到邮局的距离和是最小的。
样例 2:
	输入：[[0,1,0],[1,0,1],[0,1,0]]
	输出：4
	解释：在(1,1)处建立邮局，所有房子到邮局的距离和是最小的。
挑战
	Solve this problem within O(n^3) time.

注意事项
	+ 你不能穿过房子和墙，只能穿过空地。
	+ 你只能在空地建立邮局。
*/
#include <iostream>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
	/**
	 * @param grid: a 2D grid
	 * @return: An integer
	 */
	int shortestDistance(vector<vector<int>> &grid) {
		// write your code here
		if (grid.empty() || grid[0].empty()) {
			return -1;
		}
		// 统计房子总数
		int cntHouses = 0;
		for (auto r : grid) {
			for (auto c : r) {
				if (c == 1) {
					++cntHouses;
				}
			}
		}

		int ans = -1;
		for (int i = 0; i != grid.size(); ++i) {
			for (int j = 0; j != grid[0].size(); ++j) {
				if (grid[i][j] == 0) {
					int d = bfs(grid, i, j, cntHouses);
					cout << d << endl;
					ans = (d > 0 && (ans < 0 || ans > d)) ? d : ans;
				}
			}
		}
		return ans;
	}
private:
	int bfs(vector<vector<int>> &grid, int sx, int sy, int houseNum) {
		int dx[4] = { 0, 0, 1, -1 };
		int dy[4] = { 1, -1, 0, 0 };
		std::queue<int> qx, qy;
		vector<vector<int>> visit(grid.size(), vector<int>(grid[0].size(), 0));

		qx.push(sx);
		qy.push(sy);
		visit[sx][sy] = true;

		int dist = 0, sum = 0;
		while (!qx.empty()) {
			++dist;
			int size = qx.size();
			for (int _ = 0; _ != size; ++_) {
				int cx = qx.front(), cy = qy.front();
				qx.pop();
				qy.pop();
				for (int i = 0; i != 4; ++i) {
					int nx = cx + dx[i];
					int ny = cy + dy[i];
					if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() &&
						!visit[nx][ny]) {
						visit[nx][ny] = true;

						if (grid[nx][ny] == 1) {
							// 遇到一处房子, 此支到达叶节点, 总路径和遇房数自增, 不再计入队列
							sum += dist;
							++visit[sx][sy];
						}
						if (grid[nx][ny] == 0) {  // 中间节点, 加入队列继续搜索
							qx.push(nx);
							qy.push(ny);
						}
					}
				}
			}
		}
		// 检查是否遇到了所有房子
		if (--visit[sx][sy] < houseNum) {
			return -1;
		}
		return sum;
	}
};

int main() {
	vector<vector<int>> grid = {
		{0, 1, 0, 0, 0},
		{1, 0, 0, 2, 1},
		{0, 1, 0, 0, 0}
	};
	Solution s;
	int distance = s.shortestDistance(grid);
	cout << distance << endl;
	system("pause");
	return 0;
}