/*
447. 在大数组中查找
	* 给一个按照升序排序的非负整数数组。这个数组很大以至于你只能通过固定的接口ArrayReader.get(k)来访问第k个数
	  (或者C++里是ArrayReader->get(k))，并且你也没有办法得知这个数组有多大。
	* 找到给出的整数target第一次出现的位置。你的算法需要在O(logk)的时间复杂度内完成，k为target第一次出现的位置的下标。
	* 如果找不到target，返回-1。

样例
样例 1:
	输入: [1, 3, 6, 9, 21, ...], target = 3
	输出: 1
样例 2:
	输入: [1, 3, 6, 9, 21, ...], target = 4
	输出: -1

挑战：
	O(logn)的时间复杂度，n是target第一次出现的下标。
注意事项：
	如果你访问了一个不可访问的下标（比如越界），ArrayReader 会返回2,147,483,647。
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/**
 * Definition of ArrayReader:
 *
 * class ArrayReader {
 * public:
 *     int get(int index) {
 *          // return the number on given index,
 *          // return 2147483647 if the index is invalid.
 *     }
 * };
 */
class ArrayReader {
public:
	int get(int index) { }
};

class Solution {
public:
	/*
	 * @param reader: An instance of ArrayReader.
	 * @param target: An integer
	 * @return: An integer which is the first index of target.
	 */
	int searchBigSortedArray(ArrayReader *reader, int target) {
		// write your code here
		if (reader->get(0) == target) {
			return 0;
		}
		int idx = 0;
		while (reader->get(idx) <= target) {
			if (reader->get(idx) == target) {
				break;
			}
			idx = 2 * idx + 1;
		}
		int start = 0, end = idx;
		while (start + 1 < end) {
			int mid = start + (end - start) / 2;
			int val = reader->get(mid);
			if (target == val) {
				end = mid;
			}
			else if (target > val) {
				start = mid;
			}
			else {
				end = mid;
			}
		}
		if (reader->get(start) == target) {
			return start;
		}
		else if (reader->get(end) == target) {
			return end;
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