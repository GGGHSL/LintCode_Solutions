#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
public:
	/*
	 * @param A: an integer array
	 * @param k: a postive integer <= length(A)
	 * @param target: an integer
	 * @return: A list of lists of integer
	 */
	vector<vector<int>> kSumII(vector<int> &A, int k, int target) {
		// write your code here
		if (A.empty()) {
			return *new vector<vector<int>>{ A };
		}
		vector<vector<int>> results;
		dfs(A, k, target, 0, *new vector<int>, results);
		return results;
	}
private:
	void dfs(vector<int> &A, int k, int target, 
		int startIndex, vector<int> &subset, vector<vector<int>> &results) {
		if (target < 0) {
			return;
		}
		if (subset.size() == k && target == 0) {
			results.push_back(*new vector<int>(subset));
			return;
		}
		for (int i = startIndex; i != A.size(); ++i) {
			subset.push_back(A[i]);
			// 题目同一个数不可以重复使用
			dfs(A, k, target - A[i], i + 1, subset, results);
			subset.pop_back();
		}
	}
};

int main() {

	system("pause");
	return 0;
}