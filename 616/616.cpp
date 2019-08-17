/*
616. 安排课程
	你需要去上n门课，这些课被标号为 0 到 n-1。
	有一些课程需要“前置课程”，比如如果你要上课程0，你需要先学课程1，我们用一个匹配来表示他们： [0,1]

	给你课程的总数量和一些前置课程的需求，返回你为了学完所有课程所安排的学习顺序。
	可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。

样例
例1:
	输入: n = 2, prerequisites = [[1,0]]
	输出: [0,1]
例2:
	输入: n = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
	输出: [0,1,2,3] or [0,2,1,3]
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
	 * @return: the course order
	 */
	vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
		// write your code here
		unordered_map<int, int> node2indegree;
		for (int i = 0; i != numCourses; ++i) {
			node2indegree[i] = 0;
		}
		unordered_map<int, vector<int>> node2node;
		for (auto p : prerequisites) {  // p.first <- p.second
			++node2indegree[p.first];
			node2node[p.second].push_back(p.first);
		}

		vector<int> ans;
		queue<int> q;
		for (auto p : node2indegree) {
			if (p.second == 0) {
				q.push(p.first);
				ans.push_back(p.first);
			}
		}
		
		while (!q.empty()) {
			int curr = q.front();
			q.pop();

			vector<int> neighbors = node2node[curr];
			for (int n : neighbors) {
				int *indegree = &node2indegree[n];
				--*indegree;
				if (*indegree == 0) {
					q.push(n);
					ans.push_back(n);
				}
			}
		}
		if (ans.size() < numCourses) {
			return {};
		}
		else {
			return ans;
		}
	}
};


int main() {

	system("pause");
	return 0;
}