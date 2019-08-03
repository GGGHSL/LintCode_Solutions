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
using std::unordered_map;

class TwoSum {
public:
	/**
	 * @param number: An integer
	 * @return: nothing
	 */
	void add(int number) {
		++nums[number];
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
			for (auto b = nums.begin(); b != nums.end(); ++b) {
				auto num = (*b).first;
				if (num != value - num && nums.find(value - num) != nums.end())
					return true;
				else if (num == value - num && nums[num] > 1)
					return true;
			}
			return false;
		}
	}
private:
	unordered_map<int, size_t> nums;
};

#endif // !TWOSUM