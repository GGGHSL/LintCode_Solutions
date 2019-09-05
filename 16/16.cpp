#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;

class Solution {
public:
	/*
	 * @param :  A list of integers
	 * @return: A list of unique permutations
	 */
	vector<vector<int>> permuteUnique(vector<int> &nums) {
		// write your code here
		if (nums.empty()) {
			return *new vector<vector <int>>{ nums };
		}
		vector<vector<int>> results;
		sort(nums.begin(), nums.end());
		dfs(nums, *new vector<bool>(nums.size(), false), *new vector<int>, results);
		return results;
	}
private:
	void dfs(vector<int> &nums, vector<bool> &visit, vector<int> &permutation, vector<vector<int>> &results) {
		if (permutation.size() == nums.size()) {
			results.push_back(permutation);
			return ;
		}
		for (int i = 0; i != nums.size(); ++i) {
			if (visit[i]) {
				continue;
			}
			if (i != 0 && nums[i] == nums[i - 1] && !visit[i - 1]) {
				continue;
			}
			permutation.push_back(nums[i]);
			visit[i] = true;
			dfs(nums, visit, permutation, results);
			permutation.pop_back();
			visit[i] = false;
		}
	}
};

int main() {

	system("pause");
	return 0;
}