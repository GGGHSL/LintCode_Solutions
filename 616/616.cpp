/*
616. ���ſγ�
	����Ҫȥ��n�ſΣ���Щ�α����Ϊ 0 �� n-1��
	��һЩ�γ���Ҫ��ǰ�ÿγ̡������������Ҫ�Ͽγ�0������Ҫ��ѧ�γ�1��������һ��ƥ������ʾ���ǣ� [0,1]

	����γ̵���������һЩǰ�ÿγ̵����󣬷�����Ϊ��ѧ�����пγ������ŵ�ѧϰ˳��
	���ܻ��ж����ȷ��˳����ֻҪ����һ�־Ϳ����ˡ����������������пγ̣�����һ�������顣

����
��1:
	����: n = 2, prerequisites = [[1,0]]
	���: [0,1]
��2:
	����: n = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
	���: [0,1,2,3] or [0,2,1,3]
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