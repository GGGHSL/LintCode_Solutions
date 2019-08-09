/*
178. ͼ�Ƿ�����
	����n���ڵ㣬��ŷֱ�� 0 ��n - 1���Ҹ���һ������ߵ��б� (����ÿ���ߵ���������), 
	дһ������ȥ�ж���������ͼ�Ƿ���һ������

����
���� 1:
	����: n = 5 edges = [[0, 1], [0, 2], [0, 3], [1, 4]]
	���: true.
���� 2:
	����: n = 5 edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]]
	���: false.
ע������
	����Լ������ǲ�������ظ��ı��ڱߵ��б��С�
	�����[0, 1]��[1, 0]��ͬһ���ߣ� ������ǲ���ͬʱ���������Ǹ���ıߵ��б��С�
*/
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
	/**
	 * @param n: An integer
	 * @param edges: a list of undirected edges
	 * @return: true if it's a valid tree, or false
	 */
	bool validTree(int n, vector<vector<int>> &edges) {
		// write your code here
		if (n == 0) {
			return false;
		}
		if (edges.size() != n - 1) {
			// �������������������=����-1��
			return false;
		}
		for (int i = 0; i != n; ++i) {
			father.push_back(i);
		}
		for (auto e : edges) {
			int a = e[0], b = e[1];
			int rootA = find(a), rootB = find(b);
			if (rootA == rootB) {
				// a��b��ǰ�Ѿ���ͨ, ��˳ɻ�
				return false;
			}
			father[rootA] = rootB;  // ��ͨa��b
		}
		return true;
	}
private:
	vector<int> father;
	int find(int x) {
		if (father[x] == x) {
			return x;
		}
		father[x] = find(father[x]);
	}
};

int main() {

	system("pause");
	return 0;
}