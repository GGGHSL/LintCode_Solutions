/*
607. 两数之和 III-数据结构设计
	设计b并实现一个 TwoSum 类。他需要支持以下操作:add 和 find。
	add -把这个数添加到内部的数据结构。
	find -是否存在任意一对数字之和等于这个值

样例
	样例 1:

	add(1);add(3);add(5);
	find(4)//返回true
	find(7)//返回false
*/
#ifndef TWOSUM
#define TWOSUM
#include <unordered_map>
#include <unordered_set>
using std::unordered_multiset;


class TwoSum {
	unordered_multiset<int> nums;
public:
	/**
	 * @param number: An integer
	 * @return: nothing
	 */
	void add(int number) {
		nums.insert(number);
	}

	/**
	 * @param value: An integer
	 * @return: Find if there exists any pair of numbers which sum is equal to the value.
	 */
	bool find(int value) {
		// write your code here
		if (nums.empty()) {
			return false;
		}
		else {
			for (auto num : nums) {
				/*
				if (num != value - num && nums.find(value - num) != nums.end())
					return true;
				else if (num == value - num && nums.count(num) > 1)
					return true;
				*/
				int cnt = num == value - num ? 2 : 1;
				if (nums.count(value - num) >= cnt) {
					return true;
				}
			}
			return false;
		}
	}
};

#endif // !TWOSUM