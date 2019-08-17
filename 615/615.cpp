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
#include <map>
#include <queue>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;
using std::pair;
using std::queue;
using std::multimap;
using std::for_each;

class Solution {
public:
	/*
	 * @param numCourses: a total of n courses
	 * @param prerequisites: a list of prerequisite pairs
	 * @return: true if can finish all courses or false
	 */
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		// write your code here
		unordered_map<int, int> node2indegree;
		for (int node = 0; node != numCourses; ++node) {  // ��ʼ��in-degrees
			node2indegree[node] = 0;
		}
		multimap<int, int> node2node;
		for (auto p : prerequisites) {
			++node2indegree[p.first];
			node2node.insert(pair<int, int>(p.second, p.first));
		}
		
		queue<int> q;
		int cnt = 0;
		for (auto p : node2indegree) {
			if (p.second == 0) {
				q.push(p.first);
				++cnt;
			}
		}

		while (!q.empty()) {
			int curr = q.front();
			q.pop();
			
			auto end = node2node.upper_bound(curr);
			for (auto it = node2node.lower_bound(curr); it != end; ++it) {
				int neighbor = it->second;
				int *indegree = &node2indegree[neighbor];
				--*indegree;
				if (*indegree == 0) {
					q.push(neighbor);
					++cnt;
				}
			}
		}
		return cnt == numCourses
	}
};