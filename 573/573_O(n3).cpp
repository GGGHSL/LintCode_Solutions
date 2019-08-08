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
	struct Point {
		int x, y, dis;
		Point() { }
		Point(int xx, int yy, int dist) : x(xx), y(yy), dis(dist) { }
	};
	/**
	 * @param grid a 2D grid
	 * @return an integer
	 */
	int shortestDistance(vector<vector<int>>& grid) {
		// Write your code here
		if (grid.size() == 0)
			return 0;
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int>> dis(n, vector<int>(m, 0));  // 用于记录每处空地到各房子的最短距离和(房子、墙的dis为0)
		vector<vector<int> > visit_num(n, vector<int>(m, 0));  // 用于记录每处空地所能到达的房子数

		int house_num = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++)
				if (grid[i][j] == 1) {
					++house_num;
					bfs(Point(i, j, 0), grid, dis, visit_num);
				}
		}

		int ans = INT_MAX;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++)
				if (grid[i][j] == 0 && visit_num[i][j] == house_num) {
					ans = ans < dis[i][j] ? ans : dis[i][j];
				}
		}
		return ans == INT_MAX ? -1 : ans;
	}

private:
	void bfs(Point curr, vector<vector<int>> &grid, vector<vector<int>> &dis, vector<vector<int>> &visit_num) {
		int n = grid.size();
		int m = grid[0].size();
		int dx[4] = { 0, 0, 1, -1 };
		int dy[4] = { 1, -1, 0, 0 };
		vector<vector<bool>> flag(n, vector<bool>(m, false));

		std::queue<Point> q;
		q.push(curr);

		while (!q.empty()) {
			curr = q.front();
			q.pop();
			++visit_num[curr.x][curr.y];  // 但凡进入队列的, 即与当前房屋连通, 记次数+1(只访问一次, 因此只会自增1).

			for (int i = 0; i != 4; i++) {
				int nx = curr.x + dx[i];
				int ny = curr.y + dy[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m
					&& grid[nx][ny] == 0 && !flag[nx][ny]) {
					dis[nx][ny] += (curr.dis + 1);
					flag[nx][ny] = true;
					q.push(Point(nx, ny, curr.dis + 1));
				}
			}
		}
	}
};