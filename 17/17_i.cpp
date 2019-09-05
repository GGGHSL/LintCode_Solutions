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
	/**
	 * @param nums: A set of numbers
	 * @return: A list of lists
	 */
	vector<vector<int>> subsets(vector<int> &nums) {
		// write your code here
		if (nums.empty()) {
			return vector<vector<int>>{nums};
		}
		vector<vector <int>> results;
		sort(nums.begin(), nums.end());
		dfs(nums, 0, *new vector<int>, results);
		return results;
	}
private:
	void dfs(vector<int> &nums, int index, vector<int> &subset, vector<vector<int>> &results) {
		if (index == nums.size()) {
			results.push_back(*new vector<int>(subset));
			return ;
		}

		subset.push_back(nums[index]);
		dfs(nums, index + 1, subset, results);

		subset.pop_back();
		dfs(nums, index + 1, subset, results);
	}
};

int main() {
	vector<int>nums{ 0 };
	Solution s;
	vector<vector<int>> res = s.subsets(nums);

	system("pause");
	return 0;
}