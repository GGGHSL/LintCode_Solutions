/*
611. 骑士的最短路线
	给定骑士在棋盘上的初始位置(一个2进制矩阵0表示空1表示有障碍物)，
	找到到达终点的最短路线，返回路线的长度。
	如果骑士不能到达则返回-1。

样例
例1:
	输入:
		[[0,0,0],
		 [0,0,0],
		 [0,0,0]]
		source = [2, 0] destination = [2, 2]
	输出: 2
	解释:
		[2,0]->[0,1]->[2,2]
例2:
	输入:
		[[0,1,0],
		 [0,0,1],
		 [0,0,0]]
		source = [2, 0] destination = [2, 2]
	输出:-1
说明:
	如果骑士的位置为(x,y)，他下一步可以到达以下这些位置:
		(x + 1, y + 2)
		(x + 1, y - 2)
		(x - 1, y + 2)
		(x - 1, y - 2)
		(x + 2, y + 1)
		(x + 2, y - 1)
		(x - 2, y + 1)
		(x - 2, y - 1)
注意事项:
	起点跟终点必定为空.
	骑士不能碰到障碍物.
	路径长度指骑士走的步数.
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