/*
141. x��ƽ����
	ʵ��int sqrt(int x)���������㲢����x��ƽ������

����
���� 1:
	����:  0
	���: 0
���� 2:
	����: 3
	���: 1

	�������ͣ�
	���ض�x�����ź�����ȡ���Ľ����
���� 3:
	����: 4
	���: 2

��ս
O(log(x))
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
	 * @param x: An integer
	 * @return: The sqrt of x
	 */
	int sqrt(int x) {
		// write your code here
		if (x == 1 || x == 0) {
			return x;
		}
		int start = 1, end = x;
		while (start + 1 < end) {
			int mid = start + (end - start) / 2;
			int val = x / mid;  // ���ܻ�Խ���Ϊ��ֵ
			if (val == mid) {
				return mid;
			}
			else if (mid > val) {
				end = mid;
			}
			else {
				start = mid;
			}
		}
		if (end > x / end) {
			return start;
		}
		else {
			return end;
		}
	}
};

int main() {
	Solution s;
	int ans = s.sqrt(999999999);
	cout << ans << endl;
	system("pause");
	return 0;
}