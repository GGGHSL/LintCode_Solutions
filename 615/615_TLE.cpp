/*
615. 课程表
	现在你总共有 n 门课需要选，记为 0 到 n - 1.
	一些课程在修之前需要先修另外的一些课程，比如要学习课程 0 你需要先学习课程 1，表示为[0,1]
	给定n门课以及他们的先决条件，判断是否可能完成所有课程？

样例
例1:
	输入: n = 2, prerequisites = [[1,0]]
	输出: true
例2:
	输入: n = 2, prerequisites = [[1,0],[0,1]]
	输出: false
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