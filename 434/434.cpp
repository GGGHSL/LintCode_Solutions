/*
434. ����ĸ���II
	����n, m, �ֱ����һ����ά���������������, ������һ����СΪk�Ķ�Ԫ����A, ��ʼ��ά����ȫ0��
	��Ԫ����A�ڵ�k��Ԫ�ش���k�β���, ���i��Ԫ��Ϊ(A[i].x, A[i].y), 
	��ʾ�Ѷ�ά�������±�ΪA[i].x��A[i].y�е�Ԫ���ɺ����Ϊ���졣 
	����ÿ�β���֮��, ��ά�����е��������������Ҫ����һ����СΪk�����顣

����
���� 1:
	����: n = 4, m = 5, A = [[1,1],[0,1],[3,3],[3,4]]
	���: [1,1,2,2]
	����:
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
���� 2:
	����: n = 3, m = 3, A = [[0,0],[0,1],[2,2],[2,1]]
	���: [1,1,2,2]
ע������
	�趨0��ʾ����, 1������, ���������������ڵ�1Ϊͬһ�����졣
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
				// ��ʼ��: father�±����Ԫ��ֵ
				father.push_back(i * m + j);
			}
		}

		for (auto op : operators) {
			if (!island[op.x][op.y]) {  // �����ظ�
				int sx = op.x, sy = op.y;
				island[sx][sy] = true;
				++cntIsland;
				for (int i = 0; i != 4; ++i) {
					int nx = sx + dx[i], ny = sy + dy[i];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && island[nx][ny]) {
						_union(sx * m + sy, nx * m + ny);  // ���������root�ϲ����ܱ����е���root��
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
	int _find(int x) {  // ��ѯroot�ڵ�, ��_union����
		if (father[x] == x) {
			return x;
		}
		return father[x] = _find(father[x]);  // �ݹ����root
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