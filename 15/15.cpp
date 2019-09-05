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
	 * @param nums: A list of integers.
	 * @return: A list of permutations.
	 */
	vector<vector<int>> permute(vector<int> &nums) {
		// write your code here
		if (nums.empty()) {
			return *new vector<vector <int>>{ nums };
		}
		vector<vector <int>> results;
		dfs(nums, *new vector<bool>(nums.size(), false), *new vector<int>, results);
		return results;
	}
private:
	void dfs(vector<int> &nums, vector<bool> &visit, vector<int> &permutation, vector<vector <int>> &results) {
		if (permutation.size() == nums.size()) {  // leaf nodes
			results.push_back(permutation);
			return;
		}
		for (int i = 0; i != nums.size(); ++i) {
			if (visit[i]) {
				continue;
			}
			permutation.push_back(nums[i]);
			visit[i] = true;
			dfs(nums, visit, permutation, results);
			// back tracking
			permutation.pop_back();
			visit[i] = false;
		}
	}
};

int main() {

	system("pause");
	return 0;
}