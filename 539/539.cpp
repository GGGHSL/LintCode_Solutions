/*
539. �ƶ���
	��һ������ nums дһ�������� 0 �ƶ������������棬����Ԫ�ر���ԭ�����˳��
����
	��1 :
		����: nums = [0, 1, 0, 3, 12],
		��� : [1, 3, 12, 0, 0].
	��2 :
		���� : nums = [0, 0, 0, 3, 1],
		��� : [3, 1, 0, 0, 0].
ע������
	1.������ԭ�����ϲ���
	2.��С��������
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
					std::swap(*fast, *slow);  // ��������ָԪ�ص����ݣ�û�н���Ԫ�ر���
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