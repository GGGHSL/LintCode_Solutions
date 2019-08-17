/*
615. �γ̱�
	�������ܹ��� n �ſ���Ҫѡ����Ϊ 0 �� n - 1.
	һЩ�γ�����֮ǰ��Ҫ���������һЩ�γ̣�����Ҫѧϰ�γ� 0 ����Ҫ��ѧϰ�γ� 1����ʾΪ[0,1]
	����n�ſ��Լ����ǵ��Ⱦ��������ж��Ƿ����������пγ̣�

����
��1:
	����: n = 2, prerequisites = [[1,0]]
	���: true
��2:
	����: n = 2, prerequisites = [[1,0],[0,1]]
	���: false
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;
using std::pair;
using std::queue;

class Solution {
public:
	/*
	 * @param numCourses: a total of n courses
	 * @param prerequisites: a list of prerequisite pairs
	 * @return: true if can finish all courses or false
	 */
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		// write your code here
		auto node2indegree = getIndegree(numCourses, prerequisites);
		queue<int> q;
		int cnt = 0;
		for (auto p: node2indegree) {
			if (p.second == 0) {
				q.push(p.first);
				++cnt;
			}
		}
		
		while (!q.empty()) {
			int curr = q.front();
			q.pop();
			
			for (auto p : prerequisites) {
				if (p.second == curr) {
					int n = p.first;
					int *indegree = &node2indegree[n];
					--*indegree;
					if (*indegree == 0) {
						q.push(n);
						++cnt;
					}
				}
			}
		}
		if (cnt == numCourses) {
			return true;
		}
		else {
			return false;
		}
	}
private:
	inline unordered_map<int, int> getIndegree(int numCourses, vector<pair<int, int>>& prerequisites) {
		unordered_map<int, int> node2indegree;
		for (int node = 0; node != numCourses; ++node) {
			node2indegree[node] = 0;
		}
		for (auto p : prerequisites) {
			++node2indegree[p.first];
		}
		return node2indegree;
	}
};

int main() {

	system("pause");
	return 0;
}