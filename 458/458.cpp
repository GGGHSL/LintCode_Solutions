/*
458. Ŀ�����λ��
	��һ���������飬�ҵ� target ���һ�γ��ֵ�λ�ã����û���ֹ����� -1

����
���� 1��
	���룺nums = [1,2,2,4,5,5], target = 2
	�����2
���� 2��
	���룺nums = [1,2,2,4,5,5], target = 6
	�����-1
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
	 * @param nums: An integer array sorted in ascending order
	 * @param target: An integer
	 * @return: An integer
	 */
	int lastPosition(vector<int> &nums, int target) {
		// write your code here
		int b = 0, e = nums.size() - 1;
		if (nums.empty() || target < nums[b] || target > nums[e]) {
			return -1;
		}
		while (b + 1 < e) {
			int mid = b + (e - b) / 2;
			if (nums[mid] == target) {
				b = mid;
			}
			else if (target < nums[mid]) {
				e = mid;
			}
			else {
				b = mid;
			}
		}
		if (nums[e] == target) {
			return e;
		}
		else if (nums[b] == target) {
			return b;
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