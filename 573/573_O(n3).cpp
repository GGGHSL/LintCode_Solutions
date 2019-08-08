/*
573. �ʾֵĽ��� II
	����һ����ά������ÿһ����Դ���ǽ2������1���Լ���0(������0,1,2����ʾ)��
	���������ҵ�һ��λ��ȥ�����ʾ֣�ʹ�����еķ��ӵ��ʾֵľ��������С��;
	�������з��ӵ��ʾֵ���С����ͣ����û�еط������ʾ֣��򷵻�-1.

����
���� 1:
	���룺[[0,1,0,0,0],[1,0,0,2,1],[0,1,0,0,0]]
	�����8
	���ͣ� ��(1,1)�������ʾ֣����з��ӵ��ʾֵľ��������С�ġ�
���� 2:
	���룺[[0,1,0],[1,0,1],[0,1,0]]
	�����4
	���ͣ���(1,1)�������ʾ֣����з��ӵ��ʾֵľ��������С�ġ�
��ս
	Solve this problem within O(n^3) time.

ע������
	+ �㲻�ܴ������Ӻ�ǽ��ֻ�ܴ����յء�
	+ ��ֻ���ڿյؽ����ʾ֡�
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
		vector<vector<int>> dis(n, vector<int>(m, 0));  // ���ڼ�¼ÿ���յص������ӵ���̾����(���ӡ�ǽ��disΪ0)
		vector<vector<int> > visit_num(n, vector<int>(m, 0));  // ���ڼ�¼ÿ���յ����ܵ���ķ�����

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
			++visit_num[curr.x][curr.y];  // ����������е�, ���뵱ǰ������ͨ, �Ǵ���+1(ֻ����һ��, ���ֻ������1).

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