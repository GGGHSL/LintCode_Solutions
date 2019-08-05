/*
521. 去除重复元素
给一个整数数组，去除重复的元素。

你应该做这些事
	1.在原数组上操作
	2.将去除重复之后的元素放在数组的开头
	3.返回去除重复元素之后的元素个数

样例
	例1:
	输入:
		nums = [1,3,1,4,4,2]
	输出:
		[1,3,4,2,?,?]
		4
	解释:
		1. 将重复的整数移动到 nums 的尾部 => nums = [1,3,4,2,?,?].
		2. 返回 nums 中唯一整数的数量  => 4.
		事实上我们并不关心你把什么放在了 ? 处, 只关心没有重复整数的部分.
	
	例2:
	输入:
		nums = [1,2,3]
	输出:
		[1,2,3]
		3
挑战
	1.O(n)时间复杂度.
	2.O(nlogn)时间复杂度但没有额外空间

注意事项
	不需要保持原数组的顺序
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_multiset;

int main() {

	system("pause");
	return 0;
}

class Solution {
public:
	/**
	 * @param nums: an array of integers
	 * @return: the number of unique integers
	 */
	//int deduplication(vector<int> &nums) {
	//	// write your code here
	//	unordered_multiset<int> cnt;
	//	cnt.insert(nums.begin(), nums.end());
	//	auto fast = nums.begin(), slow = nums.begin();
	//	while (fast != nums.end()) {
	//		cnt.insert(*fast);
	//		if (cnt.count(*fast) == 1) {
	//			if (cnt.count(*slow) > 1) {
	//				std::swap(*fast, *slow);
	//			}
	//			++slow;
	//		}
	//		++fast;
	//	}
	//	return slow - nums.begin();
	//}
	//int deduplication(vector<int> &nums) {
	//	// write your code here
	//	unordered_multiset<int> cnt;
	//	int dcnt = 0;
	//	auto it = nums.begin();
	//	for (; it != nums.end();) {
	//		cnt.insert(*it);
	//		if (cnt.count(*it) > 1) {
	//			it = nums.erase(it);
	//			++dcnt;
	//		}
	//		else {
	//			++it;
	//		}
	//	}
	//	while (dcnt > 0) {
	//		nums.push_back(0);
	//		--dcnt;
	//	}
	//	return it - nums.begin();
	//}
	//int deduplication(vector<int> &nums) {
	//	// write your code here
	//	if (nums.begin() == nums.end()) {
	//		return 0;
	//	}
	//	else if (nums.end() - nums.begin() == 1) {
	//		return 1;
	//	}
	//	std::sort(nums.begin(), nums.end());
	//	// auto n = nums.size();
	//	int cnt = 0;
	//	auto it = nums.begin() + 1;
	//	while (it != nums.end()) {
	//		if (*it == *(it - 1)) {
	//			it = nums.erase(it);
	//			++cnt;
	//		}
	//		else {
	//			++it;
	//		}
	//	}
	//	while (cnt > 0) {
	//		nums.push_back(0);
	//	}
	//	return it - nums.begin();
	//}
	int deduplication(vector<int> &nums) {
		// write your code here
		if (nums.begin() == nums.end()) {
			return 0;
		}
		else if (nums.end() - nums.begin() == 1) {
			return 1;
		}
		std::sort(nums.begin(), nums.end());
		// auto n = nums.size();
		auto it = nums.begin(), pos = nums.begin();
		for (; it != nums.end(); ++it) {
			if (*it != *pos) {
				*(++pos) = *it;
			}
		}
		return pos - nums.begin();
	}
};