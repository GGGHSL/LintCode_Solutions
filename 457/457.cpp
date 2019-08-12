#include <iostream>
/*
457. 经典二分查找问题
	在一个排序数组中找一个数，返回该数出现的任意位置，如果不存在，返回-1。

样例
样例 1：
	输入：nums = [1,2,2,4,5,5], target = 2
	输出：1 或者 2
样例 2：
	输入：nums = [1,2,2,4,5,5], target = 6
	输出：-1
挑战
	O(logn)的时间
*/

#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
public:
	/**
	 * @param nums: An integer array sorted in ascending order
	 * @param target: An integer
	 * @return: An integer
	 */
	int findPosition(vector<int> &nums, int target) {
		// write your code here
		if (nums.empty() || target < *(nums.begin()) || target > *(nums.end() - 1)) {
			return -1;
		}
		auto b = nums.begin(), e = nums.end() - 1;
		while (e - b > 1) {
			auto mid = b + (e - b) / 2;
			if (*mid == target) {
				return mid - nums.begin();
			}
			else if (*mid < target) {
				b = mid;
			}
			else {  // *mid > target
				e = mid;
			}
		}
		if (*b == target) {
			return b - nums.begin();
		}
		else if (*e == target) {
			return e - nums.begin();
		}
		else {
			return -1;
		}
	}
};

int main() {
	Solution s;
	vector<int> nums = { 1,2,4,5,5,6,6,6 };
	int pos = s.findPosition(nums, 5);
	cout << pos << endl;
	system("pause");
	return 0;
}