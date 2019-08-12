/*
141. x的平方根
	实现int sqrt(int x)函数，计算并返回x的平方根。

样例
样例 1:
	输入:  0
	输出: 0
样例 2:
	输入: 3
	输出: 1

	样例解释：
	返回对x开根号后向下取整的结果。
样例 3:
	输入: 4
	输出: 2

挑战
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
			int val = x / mid;  // 可能会越界变为负值
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