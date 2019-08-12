/*
447. �ڴ������в���
	* ��һ��������������ķǸ��������顣�������ܴ���������ֻ��ͨ���̶��Ľӿ�ArrayReader.get(k)�����ʵ�k����
	  (����C++����ArrayReader->get(k))��������Ҳû�а취��֪��������ж��
	* �ҵ�����������target��һ�γ��ֵ�λ�á�����㷨��Ҫ��O(logk)��ʱ�临�Ӷ�����ɣ�kΪtarget��һ�γ��ֵ�λ�õ��±ꡣ
	* ����Ҳ���target������-1��

����
���� 1:
	����: [1, 3, 6, 9, 21, ...], target = 3
	���: 1
���� 2:
	����: [1, 3, 6, 9, 21, ...], target = 4
	���: -1

��ս��
	O(logn)��ʱ�临�Ӷȣ�n��target��һ�γ��ֵ��±ꡣ
ע�����
	����������һ�����ɷ��ʵ��±꣨����Խ�磩��ArrayReader �᷵��2,147,483,647��
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