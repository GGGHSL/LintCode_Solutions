/*
607. ����֮�� III-���ݽṹ���
	���b��ʵ��һ�� TwoSum �ࡣ����Ҫ֧�����²���:add �� find��
	add -����������ӵ��ڲ������ݽṹ��
	find -�Ƿ��������һ������֮�͵������ֵ

����
	���� 1:

	add(1);add(3);add(5);
	find(4)//����true
	find(7)//����false
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