/*
611. ��ʿ�����·��
	������ʿ�������ϵĳ�ʼλ��(һ��2���ƾ���0��ʾ��1��ʾ���ϰ���)��
	�ҵ������յ�����·�ߣ�����·�ߵĳ��ȡ�
	�����ʿ���ܵ����򷵻�-1��

����
��1:
	����:
		[[0,0,0],
		 [0,0,0],
		 [0,0,0]]
		source = [2, 0] destination = [2, 2]
	���: 2
	����:
		[2,0]->[0,1]->[2,2]
��2:
	����:
		[[0,1,0],
		 [0,0,1],
		 [0,0,0]]
		source = [2, 0] destination = [2, 2]
	���:-1
˵��:
	�����ʿ��λ��Ϊ(x,y)������һ�����Ե���������Щλ��:
		(x + 1, y + 2)
		(x + 1, y - 2)
		(x - 1, y + 2)
		(x - 1, y - 2)
		(x + 2, y + 1)
		(x + 2, y - 1)
		(x - 2, y + 1)
		(x - 2, y - 1)
ע������:
	�����յ�ض�Ϊ��.
	��ʿ���������ϰ���.
	·������ָ��ʿ�ߵĲ���.
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


// Definition for a point.
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};


class Solution {
public:
	/**
	 * @param grid: a chessboard included 0 (false) and 1 (true)
	 * @param source: a point
	 * @param destination: a point
	 * @return: the shortest path
	 */
	int shortestPath(vector<vector<bool>> &grid, Point &source, Point &destination) {
		// write your code here
		if (grid.empty() || grid[0].empty()) {
			return -1;
		}
		if (source.x == destination.x && source.y == destination.y) {
			return 0;
		}

		vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), 0));
		int dx[8] = { 1,1,-1,-1,2,2,-2,-2 };
		int dy[8] = { 2,-2,2,-2,1,-1,1,-1 };

		std::deque<Point> q;
		q.push_back(source);
		visit[source.x][source.y] = true;

		int dist = 0;  // distance
		while (!q.empty()) {
			++dist;  // dist is going to increase 1 
			auto size = q.size();
			for (int _ = 0; _ != size; ++_) {
				Point curr = *(q.begin());
				q.pop_front();
				for (int i = 0; i != 8; ++i) {
					int nx = curr.x + dx[i];
					int ny = curr.y + dy[i];
					if (nx == destination.x && ny == destination.y) {
						return dist;
					}
					if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() &&
						!visit[nx][ny] && !grid[nx][ny]) {
						// if Point(nx, ny) satisfied conditions
						q.push_back(Point(nx, ny));
						visit[nx][ny] = true;
					}
				}
			}
		}
		return -1;
	}
};