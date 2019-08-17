/*
605. �����ع�
	�ж��Ƿ����� org ��Ψһ���� seqs�ع��ó���
	org��һ���ɴ�1��n�����������ж��ɵ����У�1 �� n �� 10^4��
	�ع���ʾ��ϳ�seqs��һ����̵ĸ����� (��˼�ǣ�һ����̵�����ʹ������ seqs������ж�������������)��
	�ж��Ƿ����ҽ���һ���ܴ�seqs�ع����������У��������������org��

����
��1:
	����:org = [1,2,3], seqs = [[1,2],[1,3]]
	���: false
	����:
		[1,2,3] ������Ψһ���Ա��ع��������У��������ع��� [1,3,2]
��2:
	����: org = [1,2,3], seqs = [[1,2]]
	���: false
	����:
		���ع���������ֻ�� [1,2].
��3:
	����: org = [1,2,3], seqs = [[1,2],[1,3],[2,3]]
	���: true
	����:
		���� [1,2], [1,3], �� [2,3] ����Ψһ�ع��� [1,2,3].
��4:
	����:org = [4,1,5,2,6,3], seqs = [[5,2,6,3],[4,1,5,2]]
	���:true
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
			// ��ʼ���Է�©�����Ϊ0�ĵ�
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
			if (q.size() != 1) {  // ��ֻһ�ֿ��ܵ�����
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
		if (it != org.end()) {  // seqs����Ķ���
			return false;
		}
		return true;
	}
};


int main() {

	system("pause");
	return 0;
}