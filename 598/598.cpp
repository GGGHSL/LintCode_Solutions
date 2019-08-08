/*
598. 僵尸矩阵
	给一个二维网格，每一个格子都有一个值，2代表墙，1代表僵尸，0代表人类(数字0, 1, 2)。
	僵尸每天可以将上下左右最接近的人类感染成僵尸，但不能穿墙。
	将所有人类感染为僵尸需要多久，如果不能感染所有人则返回 -1。

样例
	例1:
	输入:
		[[0,1,2,0,0],
		[1,0,0,2,1],
		[0,1,0,0,0]]
	输出:
		2

例2:
	输入:
		[[0,0,0],
		[0,0,0],
		[0,0,1]]
	输出:
		4
*/

#include <iostream>
#include <vector>
#include <deque>
using std::cin;
using std::cout;
using std::endl;
using std::deque;
using std::vector;

int main() {

	system("pause");
	return 0;
}

class Solution {
public:
	/**
	 * @param grid: a 2D integer grid
	 * @return: an integer
	 */
	int zombie(vector<vector<int>> &grid) {
		// write your code here
		if (grid.empty() || grid[0].empty()) {
			return -1;
		}

		vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), 0));
		int dx[4] = { 0, 0, 1, -1 };
		int dy[4] = { 1, -1, 0, 0 };
		std::deque<int> qx, qy;

		// push all source point in queque at the same time.
		for (int i = 0; i != grid.size(); ++i) {
			for (int j = 0; j != grid[0].size(); ++j) {
				if (grid[i][j] == 1) {
					qx.push_back(i);
					qy.push_back(j);
					visit[i][j] = true;
				}
			}
		}

		int days = 0;
		while (!qx.empty()) {
			++days;
			auto size = qx.size();
			for (int _ = 0; _ != size; ++_) {
				int cx = *(qx.begin()), cy = *(qy.begin());
				qx.pop_front();
				qy.pop_front();
				for (int i = 0; i != 4; ++i) {
					int nx = cx + dx[i], ny = cy + dy[i];
					if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() &&
						!visit[nx][ny] && grid[nx][ny] == 0) {
						qx.push_back(nx);
						qy.push_back(ny);
						visit[nx][ny] = true;
					}
				}
			}
		}
		--days;  // exclude the extra last try

		for (int i = 0; i != grid.size(); ++i) {
			for (int j = 0; j != grid[0].size(); ++j) {
				if (grid[i][j] == 0 && !visit[i][j]) {
					return -1;
				}
			}
		}

		return days;
	}
};