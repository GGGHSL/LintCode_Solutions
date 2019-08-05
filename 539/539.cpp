/*
539. 移动零
	给一个数组 nums 写一个函数将 0 移动到数组的最后面，非零元素保持原数组的顺序
样例
	例1 :
		输入: nums = [0, 1, 0, 3, 12],
		输出 : [1, 3, 12, 0, 0].
	例2 :
		输入 : nums = [0, 0, 0, 3, 1],
		输出 : [3, 1, 0, 0, 0].
注意事项
	1.必须在原数组上操作
	2.最小化操作数
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
	 * @param nums: an integer array
	 * @return: nothing
	 */
	//void moveZeroes(vector<int> &nums) {
	//	// write your code here
	//	int cnt = 0;
	//	
	//	for (auto it = nums.begin(); it != nums.end();) {
	//		if (*it == 0) {
	//			it = nums.erase(it);
	//			++cnt;
	//		}
	//		else {
	//			++it;
	//		}
	//	}
	//	while (cnt > 0) {
	//		nums.push_back(0);
	//		--cnt;
	//	}
	//}
	void moveZeroes(vector<int> &nums) {
		// write your code here
		auto fast = nums.begin(), slow = nums.begin();
		while (fast != nums.end()) {
			if (*fast != 0) {
				if (*slow == 0) {
					std::swap(*fast, *slow);  // 仅交换所指元素的内容，没有交换元素本身
				}
				++slow;
			}
			++fast;
		}
	}
};

int main() {
	vector<int> nums = { 0, 1, 0, 3, 12 };
	Solution s;
	s.moveZeroes(nums);

	for (auto num : nums) {
		cout << num << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}