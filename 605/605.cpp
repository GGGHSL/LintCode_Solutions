/*
605. 序列重构
	判断是否序列 org 能唯一地由 seqs重构得出。
	org是一个由从1到n的正整数排列而成的序列，1 ≤ n ≤ 10^4。
	重构表示组合成seqs的一个最短的父序列 (意思是，一个最短的序列使得所有 seqs里的序列都是它的子序列)。
	判断是否有且仅有一个能从seqs重构出来的序列，并且这个序列是org。

样例
例1:
	输入:org = [1,2,3], seqs = [[1,2],[1,3]]
	输出: false
	解释:
		[1,2,3] 并不是唯一可以被重构出的序列，还可以重构出 [1,3,2]
例2:
	输入: org = [1,2,3], seqs = [[1,2]]
	输出: false
	解释:
		能重构出的序列只有 [1,2].
例3:
	输入: org = [1,2,3], seqs = [[1,2],[1,3],[2,3]]
	输出: true
	解释:
		序列 [1,2], [1,3], 和 [2,3] 可以唯一重构出 [1,2,3].
例4:
	输入:org = [4,1,5,2,6,3], seqs = [[5,2,6,3],[4,1,5,2]]
	输出:true
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
	/**
	 * @param org: a permutation of the integers from 1 to n
	 * @param seqs: a list of sequences
	 * @return: true if it can be reconstructed only one or false
	 */
	bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
		// write your code here
		// construct graph & indegree map
		if (org.empty()) {
			return true;
		}
		if (seqs.empty() || seqs[0].empty()) {
			return false;
		}

		unordered_map<int, vector<int>> node2neighbors;
		unordered_map<int, int> node2indegree;
		for (auto vec : seqs) {
			// 初始化以防漏掉入度为0的点
			if (node2indegree.find(vec.front()) == node2indegree.end()) {
				node2indegree[vec.front()] = 0;
			}
			for (auto it = vec.begin(); it + 1 != vec.end(); ++it) {
				node2neighbors[*it].push_back(*(it + 1));
				++node2indegree[*(it + 1)];
			}
		}
		
		// find topSort
		queue<int> q;
		for (auto p : node2indegree) {
			if (p.second == 0) {
				q.push(p.first);
			}
		}
		auto it = org.begin();
		while (!q.empty()) {
			if (q.size() != 1) {  // 不只一种可能的排序
				return false;
			}
			int curr = q.front();
			q.pop();
			if (curr != *it) {
				return false;
			}
			++it;
			for (int neighbor : node2neighbors[curr]) {
				int *indegree = &node2indegree[neighbor];
				--*indegree;
				if (*indegree == 0) {
					q.push(neighbor);
				}
			}
		}
		if (it != org.end()) {  // seqs构造的短了
			return false;
		}
		return true;
	}
};


int main() {

	system("pause");
	return 0;
}