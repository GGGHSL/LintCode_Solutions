/* https://www.lintcode.com/problem/combination-sum/description */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;
using std::accumulate;

class Solution {
public:
	/**
	 * @param candidates: A list of integers
	 * @param target: An integer
	 * @return: A list of lists of integers
	 */
	vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
		// write your code here
		if (candidates.empty()) {
			return *new vector<vector <int>>{ candidates };
		}

		sort(candidates.begin(), candidates.end());
		vector<vector <int>> results;
		dfs(candidates, target, 0, *new vector<int>, results);
		return results;
	}
private:
	void dfs(vector<int> &candidates, int target, 
			 int startIndex, vector<int> &subset, vector<vector <int>> &results) {
		if (target < 0) {
			return;
		}
		if (target == 0) {
			results.push_back(*new vector<int>(subset));
			return;
		}
		
		for (int i = startIndex; i != candidates.size(); ++i) {
			if (i != 0 && candidates[i] == candidates[i - 1] && i > startIndex) {
				continue;
			}
			subset.push_back(candidates[i]);
			// 从i开始, 因为可以选自己; target每次减去新加入的数
			dfs(candidates, target - candidates[i], i, subset, results);
			subset.pop_back();
		}
	}
};

int main() {
	vector<int> candidates{ 2,3,6,7 };
	int target = 7;
	Solution s;
	s.combinationSum(candidates, target);

	system("pause");
	return 0;
}