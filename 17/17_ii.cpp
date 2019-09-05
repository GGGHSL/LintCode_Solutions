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
	void dfs(vector<int> &nums, int startIndex, vector<int> &subset, vector<vector<int>> &results) {
		results.push_back(*new vector<int>(subset));
		
		for (int i = startIndex; i != nums.size(); ++i) {
			subset.push_back(nums[i]);
			dfs(nums, i + 1, subset, results);

			subset.pop_back();  // back tracking
		}
	}
};
