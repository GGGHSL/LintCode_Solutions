/*
4. ���ֲ���
����һ��������������飨���򣩺�һ��Ҫ���ҵ�����target����O(logn)��ʱ����ҵ�target��һ�γ��ֵ��±꣨��0��ʼ�������target�������������У�����-1��

����
����  1:
	����:[1,4,4,5,7,7,8,9,9,10]��1
	���: 0
	��������:
		��һ�γ����ڵ�0��λ�á�

���� 2:
	����: [1, 2, 3, 3, 4, 5, 10]��3
	���: 2
	��������:
		��һ�γ����ڵ�2��λ��

���� 3:
	����: [1, 2, 3, 3, 4, 5, 10]��6
	���: -1
	��������:
		û�г��ֹ�6�� ����-1

��ս
	��������е���������������2^32������㷨�Ƿ�����
*/
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
	/**
	 * @param nums: The integer array.
	 * @param target: Target to find.
	 * @return: The first position of target. Position starts from 0.
	 */
	int binarySearch(vector<int> &nums, int target) {
		// write your code here
		if (nums.empty() || target < *(nums.begin()) || target > *(nums.end() - 1)) {
			return -1;
		}
		auto b = nums.begin(), e = nums.end() - 1;
		while (e - b > 1) {
			auto mid = b + (e - b) / 2;
			if (target == *mid) {
				e = mid;
			}
			else if (target > *mid) {
				b = mid;
			}
			else {
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

	system("pause");
	return 0;
}