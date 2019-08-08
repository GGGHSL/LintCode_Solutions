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
	/**
	 * @param grid: a 2D grid
	 * @return: An integer
	 */
	int shortestDistance(vector<vector<int>> &grid) {
		// write your code here
		if (grid.empty() || grid[0].empty()) {
			return -1;
		}
		// ͳ�Ʒ�������
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
							// ����һ������, ��֧����Ҷ�ڵ�, ��·��������������, ���ټ������
							sum += dist;
							++visit[sx][sy];
						}
						if (grid[nx][ny] == 0) {  // �м�ڵ�, ������м�������
							qx.push(nx);
							qy.push(ny);
						}
					}
				}
			}
		}
		// ����Ƿ����������з���
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