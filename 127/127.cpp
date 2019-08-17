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


/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */

struct DirectedGraphNode {
	int label;
	vector<DirectedGraphNode *> neighbors;
	DirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	/*
	 * @param graph: A list of Directed graph node
	 * @return: Any topological order for the given graph.
	 */
	vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
		// write your code here
		vector<DirectedGraphNode*> ans;
		unordered_map<DirectedGraphNode*, int> node2indegree;

		// First round:
		/* 注意: 这种写法一上来 indegree == 0 的node没有neighbors,
			    需要手动将其初始化一下, 否则node2indegree中将不包含这些点! */
		for (DirectedGraphNode* node : graph) {
			if (node2indegree.find(node) == node2indegree.end()) {
				node2indegree[node] = 0;
			}
			for (auto n : node->neighbors) {
				++node2indegree[n];
			}
		}

		// Check for zero:
		queue<DirectedGraphNode*> q;
		for (auto p : node2indegree) {
			if (p.second == 0) {
				q.push(p.first);
				ans.push_back(p.first);
			}
		}
		
		// BFS:
		while (!q.empty()) {
			auto curr = q.front();
			q.pop();
			for (auto n : curr->neighbors) {
				int *indegree = &node2indegree[n];
				--*indegree;
				if (*indegree == 0) {
					q.push(n);
					ans.push_back(n);
				}
			}
		}
		return ans;
	}
};

int main() {

	system("pause");
	return 0;
}